#include <iostream>
#include "vendedor.h"
#include <string>

using namespace std;

string Vendedor::get_nombre()
{
    return this->nombre;
}

string Vendedor::get_apellido()
{
    return this->apellido;
}

string Vendedor::get_codigo()
{
   return this->codigo;
}