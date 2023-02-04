#include <iostream>
#include "tienda.h"
#include <string>

using namespace std;



string Tienda::get_nombre()
{
    return this->nombre;
}

string Tienda::get_direccion()
{
    return this->direccion;
}
