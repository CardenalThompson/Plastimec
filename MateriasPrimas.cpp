#include <iostream>
#include <cstdio>
#include <iomanip>
#include "MateriasPrimas.h"
#include "Funciones.h"
using namespace std;
#include "rlutil.h"
using namespace rlutil;

const char *PATH_MATERIASPRIMAS = "MateriasPrimas.dat";

bool MateriaPrima::Cargar()
{
    cout<< "CODIGO: ";
    cin>>Codigo;
    cout<< "MARCA: ";
    cin.ignore();
    cin.getline(Marca, 15);
    cout<< "TIPO: ";
    cin.getline(Tipo, 6);
    cout<< "STOCK ACTUAL: ";
    cin>>StockActual;
    cout<< "STOCK MINIMO: ";
    cin>>StockMinimo;
    return true;
}

void MateriaPrima::Mostrar()
{

    cls();
    cout<< "CODIGO: "<<Codigo<<endl;
    cout<< "MARCA: "<<Marca<<endl;
    cout<< "TIPO: "<<Tipo<<endl;
    cout<< "STOCK ACTUAL: "<<StockActual<<endl;
    cout<< "STOCK MINIMO: "<<StockMinimo<<endl;
    cout<<endl;
    anykey();
}

bool MateriaPrima::Guardar()
{
    bool guardado;
    FILE *M;
    M = fopen(PATH_MATERIASPRIMAS, "ab");
    if(M==NULL)
    {
        return false;
    }
    guardado = fwrite(this, sizeof(MateriaPrima), 1, M);
    fclose(M);
    return guardado;
}

bool MateriaPrima::Guardar(int pos)
{
    bool guardado = false;
    FILE *M;
    M = fopen(PATH_MATERIASPRIMAS, "rb+");
    if (M == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(M, pos * sizeof(MateriaPrima), SEEK_SET);
        guardado = fwrite(this, sizeof(MateriaPrima), 1, M);
    }
    fclose(M);
    return guardado;
}

bool MateriaPrima::Leer(int pos)
{
    bool resultado = false;
    FILE *M;
    M = fopen(PATH_MATERIASPRIMAS, "rb");
    if (M == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(M, pos * sizeof(MateriaPrima), SEEK_SET);
        resultado = fread(this, sizeof(MateriaPrima), 1, M);
    }
    fclose(M);
    return resultado;
}

///gets

int MateriaPrima::getCodigo()
{
    return Codigo;
}
char* MateriaPrima::getMarca()
{
    return Marca;
}

char* MateriaPrima::getTipo()
{
    return Tipo;
}

int MateriaPrima::getStockActual()
{
    return StockActual;
}

int MateriaPrima::getStockMinimo()
{
    return StockMinimo;
}

bool MateriaPrima::getEstado()
{
    return Estado;
}

///sets

void MateriaPrima::setStockActual(int _StockActual)
{
    StockActual = _StockActual;
}

void MateriaPrima::setStockMinimo(int _StockMinimo)
{
    StockMinimo = _StockMinimo;
}

void MateriaPrima::setEstado()
{
    Estado = false;
}


///Fuciones globales clase materia prima

bool NuevaMateriaPrima()
{
    MateriaPrima reg;
    if (reg.Cargar())
    {
        if (reg.Guardar())
        {
            return true;
        }
    }
    return false;
}

int BuscarMateriaPrima(int Codigo)
{
    MateriaPrima reg;
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

bool ModificarMaterial()
{
    cls();
    int opcion, cantidad;
    int codigo;
    int pos;
    cout << "CODIGO DE MATERIAL: ";
    cin.ignore();
    cin>>codigo;
    pos = BuscarMateriaPrima(codigo);
    if (pos >= 0)
    {
        cls();
        MateriaPrima reg;
        reg.Leer(pos);
        reg.Mostrar();
        cout<< endl;
        cout<< "1 - Stock"<<endl;
        cout<< "2 - Stock Minimo"<<endl;
        cout<<endl;
        cout<< "Escoja una opción: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            cout<<"Nuevo Stock: ";
            cin>>cantidad;
            if (cantidad >= 0)
            {
                reg.setStockActual(cantidad);
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
                msj_error("No existe el Material");
                anykey();
            }
            return false;
            break;
        case 2:
            cout<<"Nuevo Stock Minimo: ";
            cin>>cantidad;
            if (cantidad >= 0)
            {
                reg.setStockMinimo(cantidad);
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
                msj_error("No existe la Materia Prima");
                anykey();
            }
            return false;
            break;
        default:
            return false;
            break;
        }
    }
    return false;
}

bool EliminarMateriaPrima()
{
    cls();
    int Codigo;
    int pos;
    char Confirma;
    cout << "Codigo de Materia Prima: ";
    cin >> Codigo;
    pos = BuscarMateriaPrima(Codigo);
    if (pos >= 0)
    {
        cls();
        MateriaPrima reg;
        reg.Leer(pos);
        reg.Mostrar();

        cout << endl;
        cout << "¿Seguro desea eliminar?: ";
        cin >> Confirma;
        if (Confirma == 's'||Confirma == 'S')
        {
            reg.setEstado();
            if (reg.Guardar(pos))
            {
                msj_ok("Material eliminado correctamente");
                anykey();
            }
            else
            {
                msj_error("No se pudo eliminar el Material");
                anykey();
            }
        }
    }
    else
    {
        msj_error("No existe el Material");
        anykey();
    }

    return false;
}

void ListarMaterialID()
{
    cls();
    int Codigo;
    int pos;
    cout << "Codigo de Material: ";
    cin >> Codigo;
    pos = BuscarMateriaPrima(Codigo);
    if (pos >= 0)
    {
        cls();
        MateriaPrima reg;
        reg.Leer(pos);
        reg.Mostrar();
    }
}

void ListarMateriasPrimas()
{
    MateriaPrima reg;
    int i = 0;
    cls();
    cout << "Listado de Materiales" << endl;
    cout << "------------------------" << endl;
    cout << left;
    cout << setw(10) << "Código";
    cout << setw(15) << "Marca";
    cout << setw(6) << "Tipo";
    cout << setw(20) << "Stock Actual (kgs)";
    cout << setw(20) << "Stock Minimo(Kgs)"<<endl;

    while(reg.Leer(i++))
    {
        bool activo = reg.getEstado();
        if(activo==true)
        {
            cout << setw(10) << reg.getCodigo();
            cout << setw(15) << reg.getMarca();
            cout << setw(6) << reg.getTipo();
            cout << setw(20) << reg.getStockActual();
            cout << setw(20) << reg.getStockMinimo()<<endl;
            cout << endl;
        }
    }
    cin.ignore();
    anykey();
}
