#include <iostream>
#include <string>
#include "prenda.h"

using namespace std;

// Getters
int Prenda::get_id(){
    return this->id;
}
string Prenda::get_nombre(){
    return this->nombre;
}
string Prenda::get_tipo(){
    return this->tipo;
}
string Prenda::get_seccion(){
    return this->seccion;
}
string Prenda::get_calidad(){
    return this->calidad;
}
float Prenda::get_precio_u(){
    return this->precio_u;
}
int Prenda::get_stock(){
    return this->stock;
}

// Setters
void Prenda::set_id(int value){
    this->id = value;
}
void Prenda::set_nombre(string value){
    this->nombre = value;
}
void Prenda::set_tipo(string value){
    this->tipo = value;
}
void Prenda::set_seccion(string value){
    this->seccion = value;
}
void Prenda::set_calidad(string value){
    this->calidad = value;
}

void Prenda::set_precio_u(float value){
    this->precio_u = value;
}
void Prenda::set_stock(int value){
    this->stock = value;
}