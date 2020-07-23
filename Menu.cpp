#include <iostream>

using namespace std;

#include "rlutil.h"
using namespace rlutil;
#include "Menu.h"
#include "Productos.h"
#include "Maquinas.h"
#include "PlanProduccion.h"
#include "MateriasPrimas.h"
#include "Funciones.h"
#include "Terminales.h"

void MenuPrincipal(){

    int opcion;
    while(true)
    {
    cls();
        cout<<"          MENÚ PRINCIPAL           "<<endl;
        cout<<"                                   "<<endl;
        cout<<endl;
        cout<<"- 1 - MONITOR                      "<<endl;
        cout<<"- 2 - PRODUCTOS                    "<<endl;
        cout<<"- 3 - MAQUINAS                     "<<endl;
        cout<<"- 4 - MATERIAS PRIMAS              "<<endl;
        cout<<"- 5 - PLAN DE PRODUCCION           "<<endl;
        cout<<"- 6 - REPORTES                     "<<endl;
        cout<<"- 7 - CONFIGURACIÓN                "<<endl;
        cout<<endl;
        cout<<"- 0 - SALIR DEL PROGRAMA           "<<endl;
        cout<<endl;
        cout << "- SELECCIONE UNA OPCION: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
//            Monitor();
            break;
        case 2:
            MenuProductos();
            break;
        case 3:
            MenuMaquinas();
            break;
        case 4:
            MenuMateriasPrimas();
            break;
        case 5:
            MenuPlan();
            break;
        case 6:
//            Reportes();
            break;
        case 7:
//            MenuConfiguracion();
            break;

        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
}
}

void MenuProductos(){

    int opcion;
    while(true)
    {
        cls();
        cout<<"         PRODUCTOS                 "<<endl;
        cout<<"                                   "<<endl;
        cout<<endl;
        cout<<"- 1 - NUEVO PRODUCTO               "<<endl;
        cout<<"- 2 - MODIFICAR EXISTENTE          "<<endl;
        cout<<"- 3 - MOSTRAR PRODUCTO             "<<endl;
        cout<<"- 4 - LISTAR TODOS                 "<<endl;
        cout<<"- 5 - ELIMINAR                     "<<endl;
        cout<<endl;
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        cout<<endl;
        cout << "- SELECCIONE UNA OPCION: ";
        cin>>opcion;

    switch(opcion)
        {
        case 1:
            NuevoProducto();
            break;
        case 2:
            ModificarProducto();
            break;
        case 3:
            ListarProductoID();
            break;
        case 4:
            ListarProductos();
            break;
        case 5:
            EliminarProducto();
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
        anykey();
}
}

void MenuMaquinas(){


    int opcion;
    while(true)
    {
    cls();
        cout<<"          MÁQUINAS                 "<<endl;
        cout<<"                                   "<<endl;
        cout<<endl;
        cout<<"- 1 - NUEVA MÁQUINA                "<<endl;
        cout<<"- 2 - MODIFICAR EXISTENTE          "<<endl;
        cout<<"- 3 - MOSTRAR MAQUINA              "<<endl;
        cout<<"- 4 - LISTAR TODAS                 "<<endl;
        cout<<"- 5 - ELIMINAR                     "<<endl;
        cout<<endl;
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        cout<<endl;
        cout << "- SELECCIONE UNA OPCION: ";
        cin>>opcion;

    switch(opcion)
        {
        case 1:
            NuevaMaquina();
            break;
        case 2:
            ModificarMaquina();
            break;
        case 3:
            ListarMaquinaID();
            break;
        case 4:
            ListarMaquinas();
            break;
        case 5:
            EliminarMaquina();
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
        anykey();
}
}

void MenuMateriasPrimas(){

    int opcion;
    while(true)
    {
    cls();
        cout<<"         MATERIAS PRIMAS           "<<endl;
        cout<<"                                   "<<endl;
        cout<<endl;
        cout<<"- 1 - CARGAR NUEVA                 "<<endl;
        cout<<"- 2 - MODIFICAR EXISTENTE          "<<endl;
        cout<<"- 3 - LISTAR X CODIGO              "<<endl;
        cout<<"- 4 - LISTAR TODAS                 "<<endl;
        cout<<"- 5 - ELIMINAR                     "<<endl;
        cout<<endl;
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        cout<<endl;
        cout << "- SELECCIONE UNA OPCION: ";
        cin>>opcion;

    switch(opcion)
        {
        case 1:
            NuevaMateriaPrima();
            break;
        case 2:
            ModificarMaterial();
            break;
        case 3:
            ListarMaterialID();
            break;
        case 4:
            ListarMateriasPrimas();
            break;
        case 5:
            EliminarMateriaPrima();
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
        anykey();
}
}

void MenuPlan(){

    int opcion;
    while(true){
    cls();
        cout<<"            PRODUCCIÓN             "<<endl;
        cout<<endl;
        cout<<"- 1 - INICIAR PRODUCCION           "<<endl;
        cout<<"- 2 - LISTAR PROCESOS              "<<endl;
        cout<<endl;
        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
        cout<<endl;
        cout << "- SELECCIONE UNA OPCION: ";
        cin>>opcion;

        switch(opcion){
    case 1:
        NuevaTerminal();
        break;
    case 2:
        ListarTerminales();
        break;
    case 3:
//        Monitor();
        break;
    case 0:
        return;
        break;
    default: cout<< "OPCIÓN INCORRECTA"<<endl;
        break;
        }
    anykey();
    }
}

//void MenuConfiguracion(){
//
//    int opcion;
//    while(true){
//    cls();
//        cout<<"            PRODUCCIÓN             "<<endl;
//        cout<<endl;
//        cout<<"- 1 - BACK UP DEL SISTEMA          "<<endl;
//        cout<<"- 2 - RESTAURAR SISTEMA            "<<endl;
//        cout<<endl;
//        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
//        cout<<endl;
//        cout << "- SELECCIONE UNA OPCION: ";
//        cin>>opcion;
//
//        switch(opcion){
//    case 1:
////        MenuBKP();
//        break;
//    case 2:
////        MenuRestaurar();
//        break;
//    case 0:
//        return;
//        break;
//    default: cout<< "OPCIÓN INCORRECTA"<<endl;
//        break;
//        }
//    anykey();
//    }
//}

//void MenuConfiguracion(){
//
//    int opcion;
//    while(true){
//    cls();
//        cout<<"          BACK Up SISTEMA          "<<endl;
//        cout<<endl;
//        cout<<"- 1 - TODOS                        "<<endl;
//        cout<<"- 2 - PRODUCTOS                    "<<endl;
//        cout<<"- 2 - MAQUINAS                     "<<endl;
//        cout<<"- 2 - MATERIAS PRIMAS              "<<endl;
//        cout<<"- 2 - TERMINALES                   "<<endl;
//        cout<<endl;
//        cout<<"- 0 - VOLVER AL MENÚ PRINCIPAL     "<<endl;
//        cout<<endl;
//        cout << "- SELECCIONE UNA OPCION: ";
//        cin>>opcion;
//
//        switch(opcion){
//    case 1:
////        Bkptodos();
//        break;
//    case 2:
//        BackUpProductosglobal();
//        break;
//    case 3:
//        BackUpMaquinasglobal();
//        break;
//    case 4:
////        BackUpMateriasPrimas();
//        break;
//    case 5:
////        BackUpTerminales();
//        break;
//
//    case 0:
//        return;
//        break;
//    default: cout<< "OPCIÓN INCORRECTA"<<endl;
//        break;
//        }
//    anykey();
//    }
//}
