#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int Dia;
        int Mes;
        int Anio;
        int Hora;
        int Minutos;
        int Segundos;
    public:
        Fecha Ahora();

        bool EsMenorAHoy();
        void ConvertirADiasHorasMinutosSegundos(int);
        void NumeroSerieaFecha(int);
        int NumeroSerie();
        bool EsBisiesto(int);
        Fecha MasDias(int cantidadDias);
        //Getters
        int getDia(){return Dia;}
        int getMes(){return Mes;}
        int getAnio(){return Anio;}
        int getHora(){return Hora;}
        int getMinutos(){return Minutos;}
        //setters
        void setDia(int d){Dia=d;}
        void setMes(int m){Mes=m;}
        void setAnio(int a){Anio=a;}
        void setHora(int h){Hora=h;}
        void setMinutos(int mi){Minutos=mi;}
        void setSegundos(int s){Segundos=s;}
        void MostrarFecha();
};


#endif // FECHA_H_INCLUDED
