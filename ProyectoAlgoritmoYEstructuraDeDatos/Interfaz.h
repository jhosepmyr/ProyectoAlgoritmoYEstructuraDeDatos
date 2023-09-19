#pragma once
#include <iostream>
#include "Usuario.h"
#include "Inventario.h"

using namespace System;
using namespace std;

class Interfaz {
protected:
    //int* opcion;
    //int* tipoUsuario;
    char opcion;
    char tipoUsuario;
    Inventario objInventario;
public:
    Interfaz(){}
};