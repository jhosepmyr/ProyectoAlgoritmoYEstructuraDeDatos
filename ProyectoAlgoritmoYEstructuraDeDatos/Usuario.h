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
    Pila<Producto> carrito;
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
        int opc = 0;
        string indetificadorAUX= "";
        this->productos.MostrarDatosPROD();
        cout <<endl<< "Desea agregar algun elemento al carrito(1:SI, 2: NO):"; cin >> opc;
        if (opc == 1) {
            cout << "Elija el producto que desea agregar al carrito(INGRESE EL ID):";
            cin >> indetificadorAUX;
            carrito.push(productos.buscarporID(indetificadorAUX));
        }
        else;
    }

    void ProductoMasCaro() {
        this->productos.buscarPRODMAYVALOR();
    }

    void MostarCarrito() {
        carrito.mostrarDATOS();
    }


};