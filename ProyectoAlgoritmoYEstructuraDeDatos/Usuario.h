#pragma once
#include <iostream>
#include <fstream>
#include "Files.h"
#include "Pila.h"
using namespace std;

class Usuario {
protected:

    string nombre;
    string apellido;
    string contra;
    string datosInicioSesion;//archivo donde se guarda las contrasenas y usuarios
    Files personal;
    Lista<Producto> productos;
    int ID = 1;
public:
    Usuario() : nombre(""), contra(""), personal(){};
    Usuario(string _nombre, string _contra) : personal(_nombre, _contra) {
        this->nombre = _nombre;
        this->contra = _contra;
        this->productos = this->personal.getProductos();
    }

    int getID() {
        return this->ID;
    }
    string getNombre() {
        return this->nombre;
    }
    string getApellido() {
        return this->apellido;
    }
    string getContra() {
        return this->contra;
    }
    string getDatosInicioSesion() {
        return datosInicioSesion;
    }

    void mostrarDatosPersonales() {
        cout << "INFORMACION PERSONAL" << endl;
        cout << "Nombre: " + this->nombre << endl;
        cout << "Apellido: " + this->apellido << endl;
        cout << "Contrasena: " + this->contra << endl;
    }

    void mostrarProductos() {
    }

    void ProductoMasCaro() {
        this->productos.buscarPRODMAYVALOR();
    }


};