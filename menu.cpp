#include <iostream>
#include <fstream>
#include "menu.h"
#include "entidades/cotizacion.h"
#include "entidades/vendedor.h"
#include "entidades/tienda.h"
#include <ctime>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

//Vendedor(unico - padre) + sus variables
Vendedor v;
string v_nombre = v.get_nombre();
string v_apellido = v.get_apellido();
string v_codigo = v.get_codigo();

//Tienda(unico - padre) + sus variables
Tienda t;
string t_nombre = t.get_nombre();
string t_direccion = t.get_direccion();

Cotizacion* ultimo_elemento_lista(Cotizacion *lista){
    Cotizacion *aux = lista;
    while (aux->next != NULL){
        aux = aux->next;
    }
    return aux;
}

Cotizacion* insertar_elemento(Cotizacion *lista, Cotizacion *elemento){
    if (lista == NULL){
        elemento->set_id(1);
        lista = elemento;
    }
    else{
        // Obtener el id del ultimo elemento de la lista y a esto le sumo 1
        elemento->set_id(ultimo_elemento_lista(lista)->get_id() + 1);
        // Necesito posicionarme en el último nodo de la lista enlazada
        Cotizacion *aux = lista; // Creamos un nodo auxiliar para recorrer la lista enlazada
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = elemento;
    }
    return lista;
}

int largo_lista(Cotizacion *lista){
    int contador = 0;
    Cotizacion *aux = lista;
    while (aux != NULL){
        contador++;
        aux = aux->next;
    }
    return contador;
}

void imprimir_lista(Cotizacion *lista){
    Cotizacion *aux = lista;
    while (aux != NULL){
        cout << "ID Cotizacion" << aux->get_id() << ":" << endl;
        cout << "Fecha & Hora: " << aux->get_datetime() << endl;
        cout << "Codigo Vendedor: " << v_codigo << endl;
        cout << "Prenda: " << aux->get_prenda()->get_nombre() << endl;
        cout << "Precio unitario: $" << aux->get_prenda()->get_precio_u()<< endl;
        cout << "Cantidad de unidades cotizadas: " << aux->get_unidades_cot()<< endl;
        cout << "Precio total: $" << aux->get_total_cot() << endl << endl;
        aux = aux->next;
    }
}

void menu(){
    string lineBuffer; // Donde se guardará la información de la linea
    // Cargamos la informacion de la base de datos

    ifstream archivo("base_datos.csv");
    string cell;
    int intcell;
    while (getline(archivo, lineBuffer)){
        //cout << endl << "Nuevo elemento!" << endl;
        Prenda nueva_prenda;
        // Output the text from the file
        stringstream s(lineBuffer);

        // ID
        getline(s, cell, ',');
        //cout << "ID: " << cell << endl;
        intcell = stoi(cell);
        nueva_prenda.set_id(intcell);

        // Nombre
        getline(s, cell, ',');
        //cout << "Nombre: " << cell << endl;
        nueva_prenda.set_nombre(cell);

        // Tipo
        getline(s, cell, ',');
        //cout << "Tipo: " << cell << endl;
        nueva_prenda.set_tipo(cell);

        // Seccion
        getline(s, cell, ',');
        //cout << "Seccion: " << cell << endl;
        nueva_prenda.set_seccion(cell);

        // Calidad
        getline(s, cell, ',');
        //cout << "Calidad: " << cell << endl;
        nueva_prenda.set_calidad(cell);

        // Stock
        getline(s, cell, ',');
        //cout << "Stock: " << cell << endl;
        intcell = stoi(cell);
        nueva_prenda.set_stock(intcell);
    }

    // Close the file
    archivo.close();

    Cotizacion *lista_cotizaciones = NULL;
    int c_cot; // Cantidad de cotizaciones
    int opcion1;
    int opcion2;

    string id;
    string nombre;
    string tipo;
    string seccion;
    string calidad;
    int stock;

    int cantidad_cotizacion = 0;
    float total_cotizacion = 0;
    float precio_unitario = 0;
    time_t now;
    string dt;

    vector<string> sub_menu;

    do{
        system("cls");

        int stock_desc = 0;

        cout << "COTIZADOR EXPRESS - MENU PRINCIPAL\n";
        cout << "----------------------------------------------\n";
        cout << t_nombre <<" | " <<  t_direccion << "\n" ;
        cout << "----------------------------------------------\n";
        cout << v_nombre <<" " <<  v_apellido  <<" | " <<  v_codigo << "\n" ;
        cout << "----------------------------------------------\n";
        cout << "\n";
        cout << "SELECCIONE UNA OPCION DEL MENU\n";
        cout << "1 - Historial de Cotizaciones\n";
        cout << "2 - Realizar Cotizaciones\n";
        cout << "3 - Salir\n";
        cout << "Por favor eliga: ";
        cin >> opcion1;

        system("cls");

        if (opcion1 == 1){
            c_cot = largo_lista(lista_cotizaciones);
            if (c_cot > 0){
               
                cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES\n";
                cout << "----------------------------------------------\n";
                cout << "Ha hecho un total de " << c_cot << " cotizacion(es):\n";
                cout << "----------------------------------------------"<< endl;
                                
                imprimir_lista(lista_cotizaciones);           
    
            }
            else{
                cout << "No hay cotizaciones" << endl;
            }

            system("pause");
        }

        else if (opcion1 == 2){
            /*
            
            Elegir tipo de la prenda

            */

            archivo.open("base_datos.csv");
            archivo.clear();
            archivo.seekg(0, archivo.beg);
            while (getline(archivo, lineBuffer)){
                stringstream s(lineBuffer);

                // ID
                getline(s, cell, ',');

                // Nombre
                getline(s, cell, ',');

                // Tipo
                getline(s, cell, ',');
                
                if (!count(sub_menu.begin(), sub_menu.end(), cell)){
                    sub_menu.push_back(cell);
                }
            }
            archivo.close();

            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << "Tipos de prenda:" << endl;
            cout << "-" << endl;

            for (int i = 0; i < sub_menu.size(); i++){
                cout << i << ". " << sub_menu[i] << endl;
            }
            cout << "-"<< endl;
            cout << "Elija un tipo: ";
            cin >> opcion2;

            tipo = sub_menu[opcion2];
            sub_menu.clear();

            /*
            
            Elegir seccion del tipo de prenda

            */

            archivo.open("base_datos.csv");
            archivo.clear();
            archivo.seekg(0, archivo.beg);
            while (getline(archivo, lineBuffer)){
                stringstream s(lineBuffer);

                // ID
                getline(s, cell, ',');

                // Nombre
                getline(s, cell, ',');

                // Tipo
                getline(s, cell, ',');
                
                if (cell == tipo){
                    // Seccion
                    getline(s, cell, ',');

                    if (!count(sub_menu.begin(), sub_menu.end(), cell)){
                        sub_menu.push_back(cell);
                    }
                }
            }
            archivo.close();

            system("cls");


            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << "Tipos de " << tipo << ": " << endl;
            cout << "-" << endl;

            for (int i = 0; i < sub_menu.size(); i++){
                cout << i << ". " << sub_menu[i] << endl;
            }
            cout << "-"<< endl;
            cout << "Elija un tipo de " << tipo << ": ";
            cin >> opcion2;

            seccion = sub_menu[opcion2];
            sub_menu.clear();

            system("cls");

            /*
            
            Elegir calidad de la prenda

            */
            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << "Calidad: " << endl;
            cout << "-" << endl;
            cout << "1. Standard" << endl;
            cout << "2. Premium" << endl;
            cout << "-"<< endl;
            cout << "Elija la calidad de la prenda:";
            cin >> opcion2;

            if (opcion2 == 1){
                calidad = "standard";
            }
            else{
                calidad = "premium";
            }

            system("cls");

            /*
            
            Elegir prenda

            */
            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << "Prendas disponibles: " << endl;
            cout << "-" << endl;

            archivo.open("base_datos.csv");
            archivo.clear();
            archivo.seekg(0, archivo.beg);
            while (getline(archivo, lineBuffer)){
                stringstream s(lineBuffer);

                // ID
                getline(s, cell, ',');
                id = cell;

                // Nombre
                getline(s, cell, ',');
                nombre = cell;

                // Tipo
                getline(s, cell, ',');
                
                if (cell == tipo){
                    // Seccion
                    getline(s, cell, ',');

                    if (cell == seccion){
                        // Calidad
                        getline(s, cell, ',');

                        if (cell == calidad){
                            cout << id << ". " << nombre << endl;
                        }
                    }
                }
            }
            archivo.close();

            cout << "-"<< endl;
            cout << "Elija una prenda: ";
            cin >> opcion2;

            Prenda *nueva_prenda = new Prenda();

            system("cls");

            /*
            
            Buscamos la prenda seleccionada y vamos creando un objeto de tipo prenda con sus
            respectivos datos

            */

            archivo.open("base_datos.csv");
            archivo.clear();
            archivo.seekg(0, archivo.beg);
            while (getline(archivo, lineBuffer)){
                // Output the text from the file
                stringstream s(lineBuffer);

                // ID
                getline(s, cell, ',');
                if (stoi(cell) == opcion2){
                    nueva_prenda->set_id(stoi(cell));

                    // Nombre
                    getline(s, cell, ',');
                    nueva_prenda->set_nombre(cell);

                    // Tipo
                    getline(s, cell, ',');
                    nueva_prenda->set_tipo(cell);

                    // Seccion
                    getline(s, cell, ',');
                    nueva_prenda->set_seccion(cell);

                    // Calidad
                    getline(s, cell, ',');
                    nueva_prenda->set_calidad(cell);

                    // Stock
                    getline(s, cell, ',');
                    nueva_prenda->set_stock(stoi(cell));

                    break;
                }
            }
            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << "Prenda seleccionada:" << endl;
            cout << "-" << endl;
            cout << "ID: " << nueva_prenda->get_id() << endl;
            cout << "Nombre: " << nueva_prenda->get_nombre() << endl;
            cout << "Tipo: " << nueva_prenda->get_tipo() << endl;
            cout << "Seccion: " << nueva_prenda->get_seccion() << endl;
            cout << "----------------------------------------------"<< endl;
            //Precio unitario
            cout << endl << "Ingrese el precio unitario de la prenda a cotizar: ";
            cin >> precio_unitario;     
            cout << "----------------------------------------------"<< endl;

            nueva_prenda->set_precio_u(precio_unitario);  



            //Stock
            system("cls");
            cout << "COTIZADOR EXPRESS - COTIZAR"<< endl;
            cout << "----------------------------------------------"<< endl;
            cout << endl << "INFORMACION:" << endl;
            cout << endl <<  "EXISTE " << nueva_prenda->get_stock() << " UNIDADES DE STOCK DE LA PRENDA SELECCIONADA:" << endl;
            cout << "----------------------------------------------"<< endl;
            cout << endl << "Ingrese la cantidad de unidades a cotizar: ";
            cin >> cantidad_cotizacion;
       

            //Manejo de descuentos   
              
            float descuento_tipo = 1;
            float descuento_calidad = 1;
            float desc_final = 1;
            float desc_calidad = 1;
            //tipo prenda
            //pantalon
            
            desc_final = total_cotizacion = cantidad_cotizacion * precio_unitario;

            if(nueva_prenda->get_seccion() == "chupin"){
                desc_final = total_cotizacion -  (total_cotizacion * 0.12);
            }                         
           
            //camisa
            if(nueva_prenda->get_seccion() == "manga_corta"){
            desc_final = total_cotizacion -  (total_cotizacion * 0.1);        
                if(nueva_prenda -> get_id() == 1 || nueva_prenda -> get_id() == 2 || nueva_prenda -> get_id() == 5 || nueva_prenda -> get_id() == 6){
                desc_final = desc_final +  (desc_final * 0.03);    
            }         
        
            }else if (nueva_prenda -> get_id() == 1 || nueva_prenda -> get_id() == 2 || nueva_prenda -> get_id() == 5 || nueva_prenda -> get_id() == 6){
                desc_final = total_cotizacion +  (total_cotizacion * 0.03);   
            }

            //premium
            if(nueva_prenda->get_calidad() == "premium"){ // es premium
                desc_final = desc_final + (desc_final * 0.3);
            }
            
            
                       



            system("cls");
            if(nueva_prenda->get_stock() < cantidad_cotizacion){
                free(nueva_prenda);
                cout << endl << "EXCEDE EL STOCK" << endl;
            }
            else{
                Cotizacion *nueva_cotizacion = new Cotizacion();

                now = time(0);
                dt = ctime(&now);

                nueva_cotizacion ->set_unidades_cot(cantidad_cotizacion);

                nueva_cotizacion->set_datetime(dt);

                nueva_cotizacion->set_prenda(nueva_prenda);
                
                nueva_cotizacion->set_total_cot(desc_final);
                
                lista_cotizaciones = insertar_elemento(lista_cotizaciones, nueva_cotizacion);

                cout << endl << endl << "Cotizacion agregada con exito." << endl;
                cout << "-"<< endl;
            }
            system("pause");
        }

    }while (opcion1 != 3);
}