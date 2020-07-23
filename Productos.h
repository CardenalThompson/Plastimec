#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Producto{

private:
    int CodProducto;
    char Nombre[30];
    int Cliente;
    int Material;
    char Color[10];
    int NumCavidades;
    float Scrap;
    float Ciclo;
    float Peso;
    int Tipo;
    bool Estado;
public:
    bool Cargar();
    void Mostrar();
    bool Guardar();
    bool Guardar(int);
    bool Leer(int);
    int BuscarProducto(int);
    int CantidadProductos();
    bool BackUpProductos(Producto *);
    //gets
    int getCodigo();
    char* getNombre();
    int getCliente();
    int getMaterial();
    char* getColor();
    int getNumCavidades();
    float getCiclo();
    float getPeso();
    int getTipo();
    float getScrap();
    bool getEstado();

    //sets
    void setCodigo(int);
    void setNombre(char *);
    void setMaterial(int);
    void setNumCavidades(int);
    void setCiclo(float);
    void setEstado();
    void setColor(char *);
    void setScrap(float);
};

//Funciones globales clase Producto

bool NuevoProducto();
bool ModificarProducto();
bool EliminarProducto();
void ListarProductoID();
void ListarProductos();

#endif // PRODUCTOS_H_INCLUDED
