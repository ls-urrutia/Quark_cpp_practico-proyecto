#include <iostream>
#include <string>
#include "prenda.h"

using namespace std;

class Cotizacion {
    private:
        int id_cotizacion;
        string datetime_cotizacion;
        int codigo_vendedor;
        Prenda *prenda;
        int unidades_cot;
        float total_cot;
    public:
        // GETTERS
        int get_id();
        string get_datetime();
        Prenda* get_prenda();
        int get_unidades_cot();
        float  get_total_cot();

        // SETTERS
        void set_id(int);
        void set_datetime(string);
        void set_prenda(Prenda *prenda);
        void set_unidades_cot(int);
        void set_total_cot(float);

        Cotizacion *next = NULL;
};