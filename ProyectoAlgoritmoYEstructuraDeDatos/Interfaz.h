#pragma once
#include <iostream>

using namespace System;
using namespace std;

class Interfaz {
protected:
    //int* opcion;
    //int* tipoUsuario;
    char opcion;
    char tipoUsuario;
    //Inventario objInventario;
public:
    Interfaz(){}
    void mostrarInterfaz(){}

    void resultadosOpcionSeleccionada(){}

    void validarOpcion() {
        auto opcionValida = [](char op)->bool {return op == '0' || op == '1' || op == '2' || op == '3' || op == '4' || op == '5' ; }; //lambda
        if (!opcionValida(this->opcion) || !opcionValida(this->tipoUsuario)) {
            cout << "Seleccione una opcion valida.\n" << endl;
            this->tipoUsuario = '0';
            this->opcion = '0';
            system("pause>0");
        }
    }
};