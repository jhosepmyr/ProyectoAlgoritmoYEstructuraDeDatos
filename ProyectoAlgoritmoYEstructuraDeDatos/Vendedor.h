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
        setProductosPropios();// al momento de instanciar se obtiene la lista de productos del vendedor especifico
    }
    void setProductosPropios() { //elimina los productos que no son del vendedor que inica sesion
        string auxID = this->nombre + this->contra;
        this->productosPropios = this->productos; //primero la lista adquiere todos los productos
        for (int i = 0; i < productosPropios.longitud(); i++) {
            if (productosPropios.obtenerPos(i).getIdentificador() != auxID) { //utiliza el id de producto (que es la username+id)
                productosPropios.eliminaPos(i);
                i--;
            }
        }
        /*
        string auxID = this->nombre + this->contra;
        for (int i = 0; i < productos.longitud(); i++) {
            if (productos.obtenerPos(i).getIdentificador() == auxID) { //utiliza el id de producto (que es la username+id)
                productosPropios.agregaFinal(productos.obtenerPos(i));
            }
        }*/
    }
    void mostrarMisProductos() {
        setProductosPropios();
        productosPropios.MostrarDatosPROD(); //se obtiene la lista de productos del vendedor especifico
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

        productos.agregaFinal(Producto(Nombre, precio, tipo, this->nombre + this->contra)); //falta actualizar en doc 
        //productosPropios.agregaFinal(Producto(Nombre, precio, tipo, this->nombre + this->contra));
        //cout << "Carga de archivo exitosa. Press any key to continue....";
        cin.get();
        cin.ignore();
    }
};