#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Sucursal {
private:
    int id;
    string nombre;

public:
    Sucursal(int id, string nombre) : id(id), nombre(nombre) {}

    int getId() { return id; }

    string getNombre() { return nombre; }
};