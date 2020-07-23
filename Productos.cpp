#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#include "Productos.h"
#include "Funciones.h"
#include "rlutil.h"
using namespace rlutil;

const char *PATH_PRODUCTOS= "Productos.dat";
const char *PATH_BKP_PRODUCTOS = "Productos.bkp";
bool Producto::Cargar()
{
    cout<< "CODIGO DE PRODUCTO: ";
    cin>>CodProducto;
    cout<< "PRODUCTO: ";
    cin.ignore();
    cin.getline(Nombre, 30);
    cout<< "CLIENTE:";
    cin>>Cliente;
    cout<< "MATERIAL: ";
    cin>>Material;
    cout<< "COLOR: ";
    cin.ignore();
    cin.getline(Color, 10);
    cout<< "Nro DE CAVIDADES: ";
    cin>>NumCavidades;
    cout<< "CICLO : ";
    cin>>Ciclo;
    cout<< "PESO DEL ENVASE: ";
    cin>>Peso;
    cout<< "SCRAP ESTIMADO: ";
    cin>>Scrap;
    cout<< "SECTOR :";
    cin>>Tipo;
    Estado=true;
    return true;
}

void Producto::Mostrar()
{
    if(Estado==true)
    {
        cout<< "CODIGO DE PRODUCTO: "<<CodProducto<<endl;
        cout<< "PRODUCTO: "<<Nombre<<endl;
        cout<< "CLIENTE: "<<Cliente<<endl;
        cout<< "MATERIAL: "<<Material<<endl;
        cout<< "COLOR:"<<Color<<endl;
        cout<< "Nro DE CAVIDADES: "<<NumCavidades<<endl;
        cout<< "CICLO: "<<Ciclo<<endl;
        cout<< "PESO DEL ENVASE: "<<Peso<<endl;
        cout<< "SCRAP ESTIMADO: "<<Scrap<<endl;
        cout<< "SECTOR: ";
        if(Tipo==1)
        {
            cout<< "Inyeccion"<<endl;
        }
        if(Tipo==2)
        {
            cout<< "Soplado"<<endl;
        }
        if(Tipo==3)
        {
            cout<< "Inyeccion-Soplado"<<endl;
        }
    }
    else
    {
        cout<< "No existe el Producto"<<endl;
    }
}

bool Producto::Guardar()
{
    bool guardado;
    FILE *P;
    P = fopen(PATH_PRODUCTOS, "ab");
    if(P==NULL)
    {
        return false;
    }
    guardado = fwrite(this, sizeof(Producto), 1, P);
    fclose(P);
    return guardado;
}

bool Producto::Guardar(int pos)
{
    bool guardado = false;
    FILE *P;
    P = fopen(PATH_PRODUCTOS, "rb+");
    if (P == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(P, pos * sizeof(Producto), SEEK_SET);
        guardado = fwrite(this, sizeof(Producto), 1, P);
    }
    fclose(P);
    return guardado;
}

bool Producto::Leer(int pos)
{
    bool resultado = false;
    FILE *P;
    P = fopen(PATH_PRODUCTOS, "rb");
    if (P == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(P, pos * sizeof(Producto), SEEK_SET);
        resultado = fread(this, sizeof(Producto), 1, P);
    }
    fclose(P);
    return resultado;
}

int Producto::BuscarProducto(int Codigo)
{
    Producto reg;
    int i = 0;
    while(reg.Leer(i))
    {
        if (reg.getCodigo() == Codigo)
        {
            return i;
        }
        i++;
    }
    return -1;
}

///gets

int Producto::getCodigo()
{
    return CodProducto;
}

char* Producto::getNombre()
{
    return Nombre;
}

int Producto::getCliente()
{
    return Cliente;
}

int Producto::getMaterial()
{
    return Material;
}

char* Producto::getColor()
{
    return Color;
}

int Producto::getNumCavidades()
{
    return NumCavidades;
}
float Producto::getScrap()
{
    return Scrap;
}

float Producto::getCiclo()
{
    return Ciclo;
}

float Producto::getPeso()
{
    return Peso;
}

int Producto::getTipo()
{
    return Tipo;
}
bool Producto::getEstado()
{
    return Estado;
}

///sets

void Producto::setCodigo(int _Codigo)
{
    CodProducto = _Codigo;
}

void Producto::setNombre(char *_Nombre)
{
    strcpy(Nombre, _Nombre);
}

void Producto::setMaterial(int _Material)
{
    Material = _Material;
}

void Producto::setNumCavidades(int _NumCavidades)
{
    NumCavidades = _NumCavidades;
}

void Producto::setScrap(float _Scrap)
{
    Scrap = _Scrap;
}

void Producto::setCiclo(float _Ciclo)
{
    Ciclo = _Ciclo;
}

void Producto::setEstado()
{
    Estado = false;
}

void Producto::setColor(char *_Color)
{
    strcpy(Color, _Color);
}

///Funciones globales clase Producto



bool NuevoProducto()
{
    Producto reg;
    if (reg.Cargar())
    {
        if (reg.Guardar())
        {
            return true;
        }
    }
    return false;
}

bool ModificarProducto()
{
    cls();
    Producto reg;
    int codigo, opcion, valorI;
    char valorC[50];
    float valorF;
    int pos;
    cout << "CODIGO DE PRODUCTO: ";
    cin >> codigo;
    pos = reg.BuscarProducto(codigo);
    if (pos >= 0)
    {
        cls();
        reg.Leer(pos);
        reg.Mostrar();
        cout<< endl;
        cout<< "1 - Material"<<endl;
        cout<< "2 - Color"<<endl;
        cout<< "3 - Nro de Cavidades"<<endl;
        cout<< "4 - Ciclo"<<endl;
        cout<<endl;
        cout<< "Escoja una opción: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            cout<<"Nuevo Material: ";
            cin>>valorI;
            if (valorI >= 0)
            {
                reg.setMaterial(valorI);
                if (reg.Guardar(pos))
                {
                    msj_ok("Registro modificado correctamente");
                    anykey();
                    return true;
                }
                else
                {
                    msj_error("No se pudo modificar el Registro");
                    anykey();
                }
            }
            else
            {
                msj_error("No existe el Producto");
                anykey();
            }
            return false;
            break;
        case 2:
            cout<<"Nuevo Color: ";
            cin.getline(valorC, 50);
            if (valorC >= 0)
            {
                reg.setColor(valorC);
                if (reg.Guardar(pos))
                {
                    msj_ok("Registro modificado correctamente");
                    anykey();
                    return true;
                }
                else
                {
                    msj_error("No se pudo modificar el Registro");
                    anykey();
                }
            }
            else
            {
                msj_error("No existe el Producto");
                anykey();
            }
            return false;
            break;
        case 3:
            cout<<"Cantidad de cavidades: ";
            cin>>valorI;
            if (valorI >= 0)
            {
                reg.setNumCavidades(valorI);
                if (reg.Guardar(pos))
                {
                    msj_ok("Registro modificado correctamente");
                    anykey();
                    return true;
                }
                else
                {
                    msj_error("No se pudo modificar el Registro");
                    anykey();
                }
            }
            else
            {
                msj_error("No existe el Producto");
                anykey();
            }
            return false;
            break;
        case 4:
            cout<<"Nuevo tiempo de Ciclo: ";
            cin>>valorF;
            if (valorF >= 0)
            {
                reg.setCiclo(valorF);
                if (reg.Guardar(pos))
                {
                    msj_ok("Registro modificado correctamente");
                    anykey();
                    return true;
                }
                else
                {
                    msj_error("No se pudo modificar el Registro");
                    anykey();
                }
            }
            else
            {
                msj_error("No existe el Producto");
                anykey();
            }
            return false;
            break;
        default:
            msj_error("Opcion Incorrecta");
            anykey();
            return false;
            break;
        }
    }
    return false;
}

bool EliminarProducto()
{
    cls();
    Producto reg;
    int Codigo;
    int pos;
    char Confirma;
    cout << "Codigo de Producto: ";
    cin >> Codigo;
    pos = reg.BuscarProducto(Codigo);
    if (pos >= 0)
    {
        cls();
        reg.Leer(pos);
        reg.Mostrar();

        cout << endl;
        cout << "Desea eliminar este producto: ";
        cin >> Confirma;
        if (Confirma == 's'||Confirma == 'S')
        {
            reg.setEstado();
            if (reg.Guardar(pos))
            {
                msj_ok("Producto eliminado correctamente");
                anykey();
                return true;
            }
            else
            {
                msj_error("No se pudo eliminar el Produco");
                anykey();
            }
        }
    }
    else
    {
        msj_error("No existe el Producto");
        anykey();
    }

    return false;
}

void ListarProductoID()
{
    cls();
    int Codigo;
    int pos;
    Producto _producto;
    cout << "Codigo de Producto: ";
    cin >> Codigo;
    pos = _producto.BuscarProducto(Codigo);
    if (pos >= 0)
    {
        cls();
        Producto reg;
        reg.Leer(pos);
        reg.Mostrar();
    }
}

void ListarProductos()
{
    Producto reg;
    int i = 0;
    cls();
    cout << "Listado de Productos" << endl;
    cout << "------------------------" << endl;
    cout << left;
    cout << setw(10) << "Código";
    cout << setw(20) << "Nombre";
    cout << setw(20) << "Cliente";
    cout << setw(10) << "Material";
    cout << setw(10) << "Color";
    cout << setw(10) << "Cavidades";
    cout << setw(10) << "Ciclo";
    cout << setw(10) << "Peso";
    cout << setw(10) << "Scrap (%)";
    cout << setw(10) << "Sector" << endl;

    while(reg.Leer(i++))
    {
        bool activo = reg.getEstado();
        if(activo==true)
        {
            cout << setw(10) << reg.getCodigo();
            cout << setw(20) << reg.getNombre();
            cout << setw(20) << reg.getCliente();
            cout << setw(10) << reg.getMaterial();
            cout << setw(10) << reg.getColor();
            cout << setw(10) << reg.getNumCavidades();
            cout << setw(10) << reg.getCiclo();
            cout << setw(10) << reg.getPeso();
            cout << setw(10) << reg.getScrap();
            cout << setw(10) << reg.getTipo()<<endl;
            cout << endl;
        }
    }
    cin.ignore();
    anykey();
}

bool Producto::BackUpProductos(Producto *vec)
{

    bool val= false, escribio;

    FILE * P;
    P= fopen(PATH_PRODUCTOS, "rb");

    if(P == NULL)
    {

        return 0;
    }
    fseek(P, 0, SEEK_END);

    int cant= ftell(P)/sizeof(Producto);

    vec= (Producto *) malloc(cant *sizeof(Producto));

    if(vec==NULL)

        return 0;

    fseek(P, 0, SEEK_SET);

    fread(&vec[0], sizeof(Producto), cant, P);
    fclose(P);


    FILE * C1;

    C1 = fopen(PATH_BKP_PRODUCTOS,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Producto), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}

int Producto::CantidadProductos()
{
    int bytes, cantidad;
    FILE *m;
    m = fopen(PATH_PRODUCTOS, "rb");
    if (m == NULL)
    {
        return 0;
    }
    fseek(m, 0, SEEK_END);
    bytes = ftell(m);
    cantidad = bytes / sizeof(Producto);
    fclose(m);
    return cantidad;
}

bool RestaurarProductos(Producto *vec)
{

    bool val= false, escribio;

    FILE * C;
    C= fopen(PATH_BKP_PRODUCTOS, "rb");

    if(C == NULL)
    {

        return 0;
    }
    fseek(C, 0, SEEK_END);

    int cant= ftell(C)/sizeof(Producto);

    vec= (Producto *) malloc(cant *sizeof(Producto));

    if(vec==NULL)

        return 0;

    fseek(C, 0, SEEK_SET);

    fread(&vec[0], sizeof(Producto), cant, C);
    fclose(C);


    FILE * C1;

    C1 = fopen(PATH_PRODUCTOS,"wb");

    if(C1 == NULL)
    {
        free(vec);
        return 0;
    }

    escribio = fwrite(&vec[0], sizeof(Producto), cant, C1);

    if(escribio==true)

        val= escribio;

    fclose(C1);
    free(vec);

    return val;

}
