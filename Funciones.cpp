#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
#include "Funciones.h"
#include "Fecha.h"
#include "MateriasPrimas.h"
#include "Maquinas.h"
#include "Productos.h"
#include "rlutil.h"
using namespace rlutil;

void msj_error(const char *msj, int x, int y){
    if (x==-1 && y==-1){
            y = trows()-1;
            x = 0;
    }
    gotoxy(x,y);
    setColor(LIGHTRED);
    cout << "> " << msj << endl;
    setColor(WHITE);
}
void msj_ok(const char *msj, int x, int y){
    if (x==-1 && y==-1){
            y = trows()-1;
            x = 0;
    }
    gotoxy(x,y);
    setColor(LIGHTBLUE);
    cout << "> " << msj << endl;
    setColor(WHITE);
}

