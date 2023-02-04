#include <iostream>
#include <string>

using namespace std;

class Tienda {
public:
    //GETTERS
    string get_nombre();
    string get_direccion();
private:
    string prendas[5];
    string nombre = "Quark Clothes";
    string direccion = "Florida 948 902, C1005 CABA, Argentina" ;
};