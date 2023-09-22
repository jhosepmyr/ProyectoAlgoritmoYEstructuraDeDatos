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
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra){
        this->datosInicioSesion = "DatosSesionVendedores.txt";

    }
    void mostrarMisProductos() {
        Lista<Producto> auxProductos;
        Files archivoProductos;
        auxProductos = archivoProductos.getProductos();
        string auxID = this->nombre + this->contra;
        for (int i = 0; i < auxProductos.longitud();i++) {
            if (auxProductos.obtenerPos(i).getIdentificador() == auxID) {
                auxProductos.obtenerPos(i).mostrarDatos();
            }
        }
    }
};