#include <iostream>
#include <clocale>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include "Terminales.h"
#include "Fecha.h"
#include "Maquinas.h"
#include "Productos.h"
#include "MateriasPrimas.h"
#include "Funciones.h"
using namespace std;

#include "rlutil.h"
using namespace rlutil;

const char *PATH_TERMINALES = "Terminales.dat";

bool Terminal::Iniciar()
{
    Terminal _terminal;
    Producto _producto;
    Fecha _fecha;
    Maquina _maquina;
    int posicionMaquina;
    cout<< "Numero maquina: "; //id maquina
    cin>>IdMaquina;
    posicionMaquina = _maquina.BuscarMaquina(IdMaquina);
    if(posicionMaquina < 0)
    {
        msj_error ("No existe la maquina");
        return false;
    }
    if(!_terminal.VerificarDisponibilidad(IdMaquina))//if(_maquina.FechaFin>_fecha.Ahora){Finalizar???s-n. s{funcion finanticipado guardar historial}n{return}
    {
        char op;
        cout<< "desea interrumpir la produccion actual?";
        cin>> op;
        if(op == 'n' || op == 'N')
        {
            return false;
        }
        else
        {
            _terminal.setFechaFin(_fecha.Ahora());
            //_terminal.setCantidadTotal();
            _terminal.Guardar(posicionMaquina);
        }
    }
    cout<<endl;
    cout<<"CODIGO DE PRODUCTO: ";
    cin>>CodProducto;
    int posicionProducto = _producto.BuscarProducto(CodProducto);
    if(posicionProducto < 0)
    {
        msj_error("No existe el Producto");
        anykey();
        return false;
    }
    _producto.Leer(posicionProducto);
    cout<< "CANTIDAD A PRODUCIR: ";
    cin>>Cantidad;
    if(Cantidad <= 0)
    {
        msj_error("La cantidad ingresada es incorrecta");
        return false;
    }

    CantidadTotal = Cantidad * _producto.getScrap();
    FechaInicio = _fecha.Ahora();
    FechaFin = CalcularFechaFin(_producto);

    Mostrar();
    anykey();
    return true;
}

bool Terminal::Guardar()
{
    bool guardado;
    FILE *T;
    T = fopen(PATH_TERMINALES, "ab");
    if(T==NULL)
    {
        return false;
    }
    guardado = fwrite(this, sizeof(Terminal), 1, T);
    fclose(T);
    return guardado;
}

bool Terminal::Guardar(int pos)
{
    bool guardado = false;
    FILE *T;
    T = fopen(PATH_TERMINALES, "rb+");
    if (T == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(T, pos * sizeof(Terminal), SEEK_SET);
        guardado = fwrite(this, sizeof(Terminal), 1, T);
    }
    fclose(T);
    return guardado;
}

bool Terminal::Leer(int pos)
{
    bool resultado = false;
    FILE *T;
    T = fopen(PATH_TERMINALES, "rb");
    if (T == NULL)
    {
        return false;
    }
    if (pos >= 0)
    {
        fseek(T, pos * sizeof(Terminal), SEEK_SET);
        resultado = fread(this, sizeof(Terminal), 1, T);
    }
    fclose(T);
    return resultado;
}

int Terminal::Buscar(int Id)
{
    Terminal reg;
    int i = 0;
    while(reg.Leer(i))
    {
        if (reg.getIdMaquina() == Id)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int Terminal::BuscarUltimoPorMaquina(int idMaquina)
{
    Terminal _terminal;
    int i = 0;
    int posicion = -1;
    while(_terminal.Leer(i))
    {
        if (_terminal.getIdMaquina() == idMaquina)
        {
            posicion = i;
        }
        i++;
    }

    return posicion;
}

bool Terminal::VerificarDisponibilidad(int idMaquina)
{
    Fecha _fecha;
    int posicionTerminal;
    int posicionUltimaTerminaPorMaquina;
    Terminal _terminal;

    posicionUltimaTerminaPorMaquina = _terminal.BuscarUltimoPorMaquina(idMaquina);

    if (posicionUltimaTerminaPorMaquina < 0)
    {
        return true;
    }

    _terminal.Leer(posicionUltimaTerminaPorMaquina);

    if (_terminal.getFechaFin().EsMenorAHoy())
    {
        return true;
    }

    return false;
}

Fecha Terminal::CalcularFechaFin(Producto _producto)
{
    Fecha fecha;
    Fecha fechaAux;
    fecha.setAnio(0);
    fecha.setMes(0);
    fecha.setDia(0);
    fecha.setHora(0);
    fecha.setMinutos(0);
    fecha.setSegundos(0);

    fechaAux.setAnio(0);
    fechaAux.setMes(0);
    fechaAux.setDia(0);
    fechaAux.setHora(0);
    fechaAux.setMinutos(0);
    fechaAux.setSegundos(0);

    Fecha fechaFin;
    fechaFin.Ahora();

    float cantidadSegundos = (Cantidad / _producto.getNumCavidades()) * _producto.getCiclo();
    fecha.ConvertirADiasHorasMinutosSegundos(cantidadSegundos);

    fechaFin = fechaFin.MasDias(fecha.getDia());
    fechaFin.setHora(fecha.getHora());
    fechaFin.setMinutos(fecha.getMinutos());

    return fechaFin;
}

//Fecha Terminal::MostrarFechaInicio()
//{
//    Terminal terminal;
//    cout<<terminal.FechaInicio.Dia<<"/"<<terminal.FechaInicio.Mes<<"/"<<terminal.FechaIncio.Anio<<" ";
//    cout<<terminal.FechaInicio.Hora<<":"<<terminal.FechaInicio.Minutos<<endl;
//
//}
//Fecha MostrarFechaFin()
//{
//    Terminal terminal;
//    cout<<terminal.FechaFin.Dia<<"/"<<terminal.FechaFin.Mes<<"/"<<terminal.FechaFin.Anio<<" ";
//    cout<<terminal.FechaFin.Hora<<":"<<terminal.FechaFin.Minutos<<endl;
//}

///Getters

int Terminal::getCodProducto()
{
    return CodProducto;
}
int Terminal::getCantidad()
{
    return Cantidad;
}
int Terminal::getCantidadTotal()
{
    return CantidadTotal;
}
Fecha Terminal::getFechaFin()
{
    return FechaFin;
}
Fecha Terminal::getFechaInicio()
{
    return FechaInicio;
}

///Setters

void Terminal::setCodProducto(int _codproducto)
{
    CodProducto = _codproducto;
}

void Terminal::setFechaFin(Fecha _fechaFin)
{
    FechaFin = _fechaFin;
}

int Terminal::getIdMaquina()
{
    return IdMaquina;
}


bool NuevaTerminal()
{
    Terminal reg;
    if (reg.Iniciar())
    {
        if (reg.Guardar())
        {
            return true;
        }
    }
    return false;
}

void Terminal::Mostrar()
{
    cout<< "MAQUINA: "<<IdMaquina<<endl;
    cout<< "CODIGO DE PRODUCTO: "<<CodProducto<<endl;
    cout<< "CANTIDAD: "<<Cantidad<<endl;
    cout<< "CANTIDAD TOTAL: "<<CantidadTotal<<endl;
    cout<< "FECHA INICIO: ";
    FechaInicio.MostrarFecha();
    cout<< "FECHA FIN: ";
    FechaFin.MostrarFecha();
    cout<<endl;
}
void ListarTerminales()
{
    Terminal terminal;
    Maquina _maquina;
    int i = 0;
    cls();
    cout << "          Produccion        " << endl;
    cout << "----------------------------" << endl;
    cout << left;
    cout << setw(10) << "Maquina";
    cout << setw(10) << "Producto";
    cout << setw(20) << "Cantidad deseada";
    cout << setw(16) << "Cantidad Total";
    cout << setw(25) << "Fecha Inicio";
    cout << setw(25) << "Fecha Fin"<<endl;

    while(terminal.Leer(i++))
    {
        cout << setw(10) << terminal.getIdMaquina();
        cout << setw(10) << terminal.getCodProducto();
        cout << setw(20) << terminal.getCantidad();
        cout << setw(16) << terminal.getCantidadTotal();
        Fecha f1=terminal.getFechaInicio();
        Fecha f2=terminal.getFechaFin();
        cout << setw(25) << f1.getDia()<<"/"<<f1.getMes()<<"/"<<f1.getAnio()<<" || "<<f1.getHora()<<":"<<f1.getMinutos();
        cout << setw(25) << f2.getDia()<<"/"<<f2.getMes()<<"/"<<f2.getAnio()<<" || "<<f2.getHora()<<":"<<f2.getMinutos()<<endl;
        cout << endl;
    }
    cin.ignore();
    anykey();
}
