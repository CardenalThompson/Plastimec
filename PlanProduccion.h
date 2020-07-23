#include "Fecha.h"
#ifndef PLANPRODUCCION_H_INCLUDED
#define PLANPRODUCCION_H_INCLUDED

class PlanProduccion{
private:
    int MaquinaNro;
    int CodProducto;
    int Estado;
    Fecha FechaProd;
    int Cantidad;
public:
    bool Cargar();
    void Mostrar();
    //getters
  //setters
};

bool IniciarPlan();

#endif // PLANPRODUCCION_H_INCLUDED
