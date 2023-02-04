#include <iostream>
#include <string>

using namespace std;

class Vendedor {
private:
    string nombre = "Luis";
    string apellido = "Urrutia";
    string codigo = "V0139";
public:
    //GETTERS
    string get_nombre();
    string get_apellido();
    string get_codigo();
};