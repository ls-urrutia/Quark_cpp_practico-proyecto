#include <iostream>
#include <string>

using namespace std;

class Prenda {
private:
    int id;
    string nombre;
    string tipo;
    string seccion;
    string calidad;
    int stock;
    float precio_u;
public:
    // Getters
    int get_id();
    string get_nombre();
    string get_tipo();
    string get_seccion();
    string get_calidad();
    float get_precio_u();
    int get_stock();

    // Setters
    void set_id(int value);
    void set_nombre(string value);
    void set_tipo(string value);
    void set_seccion(string value);
    void set_calidad(string value);
    void set_precio_u(float value);
    void set_stock(int value);
};