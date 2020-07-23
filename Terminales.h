#ifndef TERMINALES_H_INCLUDED
#define TERMINALES_H_INCLUDED
#include "Fecha.h"
#include "Productos.h"

class Terminal{
protected:
    int IdMaquina;
    int CodProducto;
    Fecha FechaInicio;
    Fecha FechaFin;
    int Cantidad;
    int CantidadTotal;  //cantidad + porcentaje Scrap segun producto
public:
    bool Iniciar();
    bool Cargar();
    void Mostrar();
    bool Guardar();
    bool Guardar(int);
    bool Leer(int);
    int Buscar(int);
    int BuscarUltimoPorMaquina(int);
    bool VerificarDisponibilidad(int);
    Fecha CalcularFechaFin(Producto);

    //getters
    int getIdMaquina();
    int getCodProducto();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    int getCantidad();
    int getCantidadTotal();
//    int getAnioInicio(){return FechaInicio.getAnio;}
//    int getMesInicio(){return FechaInicio.getMes;}
//    int getDiaInicio(){return FechaInicio.getDia;}
//    int getHoraInicio(){return FechaInicio.getHora;}
//    int getMinutosInicio(){return FechaInicio.getMinutos;}
//    int getAnioFin(){return FechaFin.getAnio;}
//    int getMesFin(){return FechaFin.getMes;}
//    int getDiaFin(){return FechaFin.getDia;}
//    int getHoraFin(){return FechaFin.getHora:}
//    int getMinutosFin(){return FechaFin.getMinutos;}
    //setters
    void setIdMaquina(int);
    void setCodProducto(int);
    void setFechaInicio(int);
    void setFechaFin(Fecha);
    void setCantidad(int);
    void setCantidadTotal(int);
};

bool NuevaTerminal();
void ListarTerminales();

#endif // TERMINALES_H_INCLUDED
