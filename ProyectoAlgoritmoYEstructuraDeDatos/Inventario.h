//Inventario.h
#pragma once
#include "Lista.h"
#include "Controller.h"

using namespace std;
class Inventario {
private:
    int numProductos;
    //Controller *objController;

public:
    Inventario() {
        //objController = new Controller();
    }
    void listarProductos() {
        //objController->mostrarLSTPRDCTS();
    }

    void aplicarFiltros(); //esto para ordenar de acuerdo a precio, de acuerdo a tiempo de ingreso, categoria

};
