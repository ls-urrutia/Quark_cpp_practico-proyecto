#include <iostream>
#include "cotizacion.h"
#include <string>

using namespace std;

// Getters

int Cotizacion::get_id()
{
    return this->id_cotizacion;
}

string Cotizacion::get_datetime()
{
    return this->datetime_cotizacion;
}

Prenda* Cotizacion::get_prenda()
{
    return this->prenda;
}

int Cotizacion::get_unidades_cot()
{
    return this->unidades_cot;
}

float Cotizacion::get_total_cot()
{
    return this->total_cot;
}

// Setters

void Cotizacion::set_id(int id)
{
    this->id_cotizacion = id;
}

void Cotizacion::set_datetime(string date)
{
    this->datetime_cotizacion = date;
}

void Cotizacion::set_prenda(Prenda *prenda)
{
    this->prenda = prenda;
}

void Cotizacion::set_unidades_cot(int unidades_cot)
{
    this->unidades_cot = unidades_cot;
}


void Cotizacion::set_total_cot(float total_cotizacion)
{
    this->total_cot = total_cotizacion;
}