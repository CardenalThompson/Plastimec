#ifndef MATERIASPRIMAS_H_INCLUDED
#define MATERIASPRIMAS_H_INCLUDED

class MateriaPrima{
    private:
        int Codigo;
        char Marca[15];
        char Tipo[6];
        int StockActual;
        int StockMinimo;
        bool Estado;
    public:
        bool Cargar();
        void Mostrar();
        bool Guardar();
        bool Guardar(int);
        bool Leer(int);

        //gets
        int getCodigo();
        char* getMarca();
        char* getTipo();
        int getStockActual();
        int getStockMinimo();
        bool getEstado();
        //sets
        void setStockActual(int);
        void setStockMinimo(int);
        void setEstado();
};

//Funciones globales Materias primas

bool NuevaMateriaPrima();
int BuscarMateriaPrima(int);
bool ModificarMaterial();
bool EliminarMateriaPrima();
void ListarMaterialID();
void ListarMateriasPrimas();

#endif // MATERIASPRIMAS_H_INCLUDED
