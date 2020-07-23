#include <iostream>
#include "PlanProduccion.h"
#include "Fecha.h"
using namespace std;

#include "rlutil.h"
using namespace rlutil;

const char *PATH_PLAN = "Plan.dat";

bool PlanProduccion::Cargar(){

cout<< "MAQUINA Nro: ";
cin>> MaquinaNro;
cout<< "PRODUCTO: ";
cin>> CodProducto;
FechaProd=Fecha(0, 0, 0, 0, 0, 0);
FechaProd.MostrarFecha();
anykey();
return true;

}

bool IniciarPlan()
{
    PlanProduccion reg;
    if (reg.Cargar())
    {
//        if (reg.Guardar())
//        {
//            return true;
//        }
    }
    return false;
}

