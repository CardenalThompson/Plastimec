#include <iostream>
#include <string.h>
#include <ctime>
#include "Fecha.h"
using namespace std;
#include "rlutil.h"
using namespace rlutil;


Fecha Fecha::Ahora()
{
    Fecha reg;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    reg.Anio=tmPtr->tm_year+1900;
    reg.Mes=tmPtr->tm_mon+1;
    reg.Dia=tmPtr->tm_mday;
    reg.Hora=tmPtr->tm_hour;
    reg.Minutos=tmPtr->tm_min;
    reg.Segundos=tmPtr->tm_sec;
    return reg;
}

void Fecha::ConvertirADiasHorasMinutosSegundos(int cantidadSegundos)
{
    int totalSeconds = cantidadSegundos;
    int seconds = (totalSeconds % 60);
    int minutes = (totalSeconds % 3600) / 60;
    int hours = (totalSeconds % 86400) / 3600;
    int days = (totalSeconds % (86400 * 30)) / 86400;

    Dia = days;
    Hora = hours;
    Minutos = minutes;
}

bool Fecha::EsMenorAHoy()
{
    Fecha _fechaHoy;
    _fechaHoy = _fechaHoy.Ahora();
    int cantidadDesdeHoy = _fechaHoy.NumeroSerie();
    int cantidadDesdeFechaFin = NumeroSerie();

    if (cantidadDesdeHoy > cantidadDesdeFechaFin){
        return true;
    }
    else if(cantidadDesdeHoy == cantidadDesdeFechaFin){
        if (_fechaHoy.getHora() > getHora()){
            return true;
        }
        else if(_fechaHoy.getHora() == getHora()){
            if (_fechaHoy.getMinutos() > getMinutos()){
                return true;
            }
        }
    }

    return false;
}

bool Fecha::EsBisiesto(int a)
{
    bool bisiesto=false;
    if(a%4==0)
        bisiesto=true;
    if((a%100==0) && (a%400!=0))
        bisiesto=false;
    return bisiesto;
}

int Fecha::NumeroSerie()
{
    int cont=0,i;
    for(i=1900; i<Anio; i++)
        if(EsBisiesto(i)) cont++;
    int vmes[]= {31,28,31,30,31,30,31,31,30,31,31,31},suma=0;
    if(EsBisiesto(Anio)) vmes[1]=29;
    for(int i=0; i<Mes-1; i++)  suma+=vmes[i];
    int cantdias=(Anio-1900)*365+cont+suma+Dia;
    return cantdias;
}

void Fecha::NumeroSerieaFecha(int ns)
{
  int suma=0, dia_adicional, suma_ant;
  int anio_real=1900;
  while(ns>suma)
    {
    dia_adicional=(EsBisiesto(anio_real)?1:0);
    suma_ant=suma;
    suma+=365+dia_adicional;
    anio_real++;
    }
   Anio=anio_real-1;
   //Cantidad de días pasados desde anio
  int dias_anio_actual=ns-suma_ant,i=0;
  int vmes[]={31,28,31,30,31,30,31,31,30,31,31,31};
  if(EsBisiesto(Anio)) vmes[1]=29;
  suma=0;
  while(dias_anio_actual>suma) suma+=vmes[i++];
  Mes=i;
  Dia=dias_anio_actual-(suma-vmes[i-1]);
 }

Fecha Fecha::MasDias(int cantidadDias)
{
     Fecha aux;
 int  ns=NumeroSerie()+cantidadDias;
 aux.NumeroSerieaFecha(ns);
 return aux;
}

void Fecha::MostrarFecha()
{
    cout<<Dia<<"/"<<Mes<<"/"<<Anio<<" ";
    cout<<Hora<<":"<<Minutos;
}
