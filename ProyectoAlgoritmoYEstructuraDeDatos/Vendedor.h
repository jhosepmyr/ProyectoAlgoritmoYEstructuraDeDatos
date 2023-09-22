#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
//#include "Files.h"--> esta en Usuario.h
using namespace std;

class Vendedor : public Usuario {
private:
    Lista<Producto> productosPropios;
    //implementar con el ID Ejem: vendedor10.txt
public:
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->datosInicioSesion = "DatosSesionVendedores.txt";
        getInformacionPersonalTxt();
    }
    void setProductosPropios() { 
        string auxID = this->nombre + this->contra;
        for (int i = 0; i < productos.longitud(); i++) {
            if (productos.obtenerPos(i).getIdentificador() == auxID) { //utiliza el id de producto (que es la username+id)
                Producto aux = productos.obtenerPos(i);
                productosPropios.agregaFinal(aux);
            }
        }
    }

    void mostrarMisProductos() {
        system("cls");
        productosPropios.MostrarDatosPROD();
        system("pause");
    }

    void aniadirProducto() {
        string Nombre;
        double precio;
        string tipo;
        string identificador;
        system("cls");
        cout << "Ingresar datos de producto.\n";

        cout << "Nombre: "; cin >> Nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Tipo (comestible | noComestible): "; cin >> tipo;

        Producto aux(Nombre, precio, tipo, this->nombre + this->contra);

        productos.agregaFinal(aux);
        productosPropios.agregaFinal(aux);
        cin.get();
        cin.ignore();
    }
};