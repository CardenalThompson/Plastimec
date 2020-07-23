#include <iostream>
#include <clocale>
#include <iomanip>
#include "Maquinas.h"
#include "Funciones.h"
using namespace std;

#include "rlutil.h"
using namespace rlutil;

const char *PATH_MAQUINAS = "Maquinas.dat";
const char *PATH_BKP_MAQUINAS = "Maquinas.bkp";

bool Maquina::Cargar()
{
    cls();
    cout<< "MAQUINA Nro: ";
    cin>> Id;
    cout<< "MARCA: ";
    cin.ignore();
    cin.getline(Marca, 15);
    cout<< "SECTOR: ";
    cin>>Sector;
    cout<< "NUMERO DE SERIE: ";
    cin>> NumeroSerie;
    cout<<"ESTADO: ";
    cin>>Estado;
    if(Estado<1||Estado>3)
    {
        return false;
    }
    EstadoLogico=true;
    return true;
}

void Maquina::Mostrar()
{

    cout<< "MAQUINA Nro: "<<Id<<endl;
    cout<< "MARCA: "<<Marca<<endl;
    cout<< "SECTOR: ";
    if(Sector==1)
    {
        cout<< "Inyeccion"<<endl;
    }
    if(Sector==2)
    {
        cout<< "Soplado"<<endl;
    }
    if(Sector==3)
    {
        cout<< "Inyeccion-Soplado"<<endl;
    }
    cout<< "NUMERO DE SERIE: "<<NumeroSerie<<endl;
    cout<< "ESTADO: ";
    if(Estado==1)
    {
        cout<< "Activa"<<endl;
    }
    if(Estado==2)
    {
        cout<< "En Mantenimiento"<<endl;
    }
    anykey();
}


bool Maquina::Guardar()
{
    bool guardado;
    FILE *M;
    M = fopen(PATH_MAQUINAS, "ab");
    if(M==NULL)
    {
        return false;
    }
    guardado = fwrite(this, sizeof(Maquina), 1, M);
    fclose(M);
    return guardado;
}

bool Maquina::Guardar(int pos)
{
    bool guardado = false;
    FILE *M;
    M = fopen(PATH_MAQUINAS, "rb+");
    if (M == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(M, pos * sizeof(Maquina), SEEK_SET);
        guardado = fwrite(this, sizeof(Maquina), 1, M);
    }
    fclose(M);
    return guardado;
}

bool Maquina::Leer(int pos)
{
    bool resultado = false;
    FILE *M;
    M = fopen(PATH_MAQUINAS, "rb");
    if (M == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(M, pos * sizeof(Maquina), SEEK_SET);
        resultado = fread(this, sizeof(Maquina), 1, M);
    }
    fclose(M);
    return resultado;
}

int Maquina::BuscarMaquina(int Id)
{
    Maquina reg;
    int i = 0;
    while(reg.Leer(i))
    {
        if (reg.getId() == Id)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int Maquina::CantidadMaquinas()
{
    int bytes, cantidad;
    FILE *m;
    m = fopen(PATH_MAQUINAS, "rb");
    if (m == NULL)
    {
        return 0;
    }
    fseek(m, 0, SEEK_END);
    bytes = ftell(m);
    cantidad = bytes / sizeof(Maquina);
    fclose(m);
    return cantidad;
}

bool Maquina::BackUpMaquinas(Maquina *vec)
{

    bool val= false, escribio;

    FILE * P;
    P= fopen(PATH_MAQUINAS, "rb");

    if(P == NULL)
    {

        return 0;
    }
    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Maquina);

    vec= (Maquina *) malloc(cant *sizeof(Maquina));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Maquina), cant, P);
    fclose(P);


    FILE * C1;

    C1 = fopen(PATH_BKP_MAQUINAS,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Maquina), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}

bool RestaurarMaquinas(Maquina *vec)
{

    bool val= false, escribio;

    FILE * C;
    C= fopen(PATH_BKP_MAQUINAS, "rb");

    if(C == NULL)
    {

        return 0;
    }
    fseek(C, 0, SEEK_END);

    int cant= ftell(C)/sizeof(Maquina);

    vec= (Maquina *) malloc(cant *sizeof(Maquina));

    if(vec==NULL)

        return 0;

    fseek(C, 0, SEEK_SET);

    fread(&vec[0], sizeof(Maquina), cant, C);
    fclose(C);


    FILE * C1;

    C1 = fopen(PATH_MAQUINAS,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Maquina), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}


//gets

int Maquina::getId()
{
    return Id;
}

char* Maquina::getMarca()
{
    return Marca;
}

int Maquina::getSector()
{
    return Sector;
}

int Maquina::getNumeroSerie()
{
    return NumeroSerie;
}

int Maquina::getEstado()
{
    return Estado;
}
bool Maquina::getEstadoLogico()
{
    return EstadoLogico;
}
//sets

void Maquina::setEstado(int _Estado)
{
    Estado = _Estado;
}
void Maquina::setEstadoLogico()
{
    EstadoLogico = false;
}


///Funciones globales clase maquina


bool NuevaMaquina()
{
    Maquina reg;
    if (reg.Cargar())
    {
        if (reg.Guardar())
        {
            return true;
        }
    }
    return false;
}

bool ModificarMaquina()
{
    cls();
    Maquina reg;
    int ID, estado;
    int pos;
    cout << "MAQUINA NUMERO: ";
    cin >> ID;
    pos = reg.BuscarMaquina(ID);
    if (pos >= 0)
    {
        cls();
        reg.Leer(pos);
        reg.Mostrar();
        cout<<endl;
        cout<< "ESTADO DE LA MAQUINA: ";
        cin>>estado;
        if(estado>0&&estado<=3)
        {
            reg.setEstado(estado);
            if(reg.Guardar(pos))
            {
                msj_ok("Estado Modificado con exito");
            }
            else
            {
                msj_error("No se pudo modificar el estado");
            }
        }
    }
    else
    {
        msj_error("Maquina Inexistente");
    }
    return false;
}

bool EliminarMaquina()
{
    cls();
    Maquina reg;
    int ID;
    int pos;
    char Confirma;
    cout << "Numero de Maquina: ";
    cin >> ID;
    pos = reg.BuscarMaquina(ID);
    if (pos >= 0)
    {
        cls();
        reg.Leer(pos);
        reg.Mostrar();

        cout << endl;
        cout << "¿Desea eliminar esta Maquina?:S-N ";
        cin >> Confirma;
        if (Confirma == 's'||Confirma == 'S')
        {
            reg.setEstadoLogico();
            if (reg.Guardar(pos))
            {
                msj_ok("Maquina eliminada correctamente");
            }
            else
            {
                msj_error("No se pudo eliminar la Maquina");
                return false;
            }
        }
    }
    else
    {
        msj_error("No existe la Maquina");
    }

    return false;
}

void ListarMaquinaID()
{
    cls();
    Maquina reg;
    int ID;
    int pos;
    cout << "Numero de Maquina: ";
    cin >> ID;
    pos = reg.BuscarMaquina(ID);
    if (pos >= 0)
    {
        cls();
        reg.Leer(pos);
        reg.Mostrar();
    }
}

void ListarMaquinas()
{
    Maquina reg;
    int i = 0;
    cls();
    cout << "Listado de Maquinas" << endl;
    cout << "------------------------" << endl;
    cout << left;
    cout << setw(10) << "Numero";
    cout << setw(20) << "Marca";
    cout << setw(20) << "Numero de Serie";
    cout << setw(10) << "Sector";
    cout << setw(10) << "Estado"<<endl;

    while(reg.Leer(i++))
    {
        bool activo = reg.getEstado();
        if(activo==true)
        {
            cout << setw(10) << reg.getId();
            cout << setw(20) << reg.getMarca();
            cout << setw(20) << reg.getNumeroSerie();
            cout << setw(10) << reg.getSector();
            cout << setw(10) << reg.getEstado();
            cout << endl;
        }
    }
    cin.ignore();
    anykey();
}
