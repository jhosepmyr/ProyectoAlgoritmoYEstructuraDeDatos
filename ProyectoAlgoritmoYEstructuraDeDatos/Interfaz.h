#pragma once
#include <iostream>
#include "Usuario.h"
#include "Inventario.h"

using namespace System;
using namespace std;

class Interfaz {
protected:
    int *opcion;
    int *tipoUsuario;
    Inventario objInventario;
public:
    Interfaz(){}
};