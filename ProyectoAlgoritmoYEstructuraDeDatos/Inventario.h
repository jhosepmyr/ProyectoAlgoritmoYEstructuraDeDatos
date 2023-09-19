//Inventario.h
#pragma once
#include "Electrodomesticos.h"
#include "Muebles.h"
#include "Lista.h"
#include "Controller.h"

using namespace std;
class Inventario {
private:
    int numProductos;
    Controller* objController;

public:
    Inventario() {
        objController = new Controller();
    }
    void listarProductos() {
        objController->MostrarDatosELECTRO(0);
        objController->MostrarDatosMUEBLE(0);
    }

    void aplicarFiltros(); //esto para ordenar de acuerdo a precio, de acuerdo a tiempo de ingreso, categoria

};