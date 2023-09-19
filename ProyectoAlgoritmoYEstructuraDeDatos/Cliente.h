#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"

using namespace std;

class Cliente : public Usuario {
private:
    string nombreArchivoClienteEspecifico; //implementar con el ID Ejem: cliente10.txt
public:
    Cliente(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->nombreArchivo = "DatosSesionClientes.txt";
    }

};