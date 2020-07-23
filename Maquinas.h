#ifndef MAQUINAS_H_INCLUDED
#define MAQUINAS_H_INCLUDED

class Maquina
{

private:
    int Id;
    char Marca[15];
    int Sector;
    int NumeroSerie;
    int Estado;
    bool EstadoLogico;
public:
    bool Cargar();
    void Mostrar();
    bool Guardar();
    bool Guardar(int);
    bool Leer(int);
    int BuscarMaquina(int);
    int CantidadMaquinas();
    bool BackUpMaquinas(Maquina *);

    //gets

    int getId();
    char *getMarca();
    int getSector();
    int getNumeroSerie();
    int getEstado();
    bool getEstadoLogico();

    //sets

    void setEstado(int);
    void setEstadoLogico();

};

//Funciones globales clase Maquinas

bool NuevaMaquina();
bool ModificarMaquina();
bool EliminarMaquina();
void ListarMaquinaID();
void ListarMaquinas();

#endif // MAQUINAS_H_INCLUDED
