#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"

using namespace std;

class Vendedor : public Usuario {
private:
    string nombreArchivoVendedorEspecifico; //implementar con el ID Ejem: vendedor10.txt
public:
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra){
        this->datosInicioSesion = "DatosSesionVendedores.txt";
    }
    
};