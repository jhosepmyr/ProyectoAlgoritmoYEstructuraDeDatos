#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Usuario {
protected:
    string nombre;
    string contra;
    string nombreArchivo;
    int numUsuarios;
    int ID;
public:
    Usuario() : nombre(""), contra("") {}
    Usuario(string _nombre, string _contra) : nombre(_nombre), contra(_contra) {}

    int getNumUsuarios() {
        return this->numUsuarios;
    } //servira para nombre de carpeta por usuario
    int getID() {
        return this->ID;
    }//IMPLEMENTAR, es para crear txt por usuario
    string getNombre() {
        return this->nombre;
    }
    string getContra() {
        return this->contra;
    }
    string getNombreArchivo() {
        return nombreArchivo;
    }
};