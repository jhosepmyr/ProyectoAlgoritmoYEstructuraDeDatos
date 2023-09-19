#pragma once
#include <iostream>
#include <fstream>
using namespace std;
using namespace System;

class Usuario {
protected:
    string nombre;
    string contra;
    int numUsuarios;
    int ID = 1;
public:
    Usuario() : nombre(""), contra("") {}
    Usuario(string _nombre, string _contra) : nombre(_nombre), contra(_contra) {}

    int getNumUsuarios(); //servira para nombre de carpeta por usuario
    int getID(); //IMPLEMENTAR, es para crear txt por usuario
};

class Cliente : public Usuario {
private:
    string nombreArchivo;
    string nombreArchivoClienteEspecifico; //implementar con el ID Ejem: cliente10.txt
public:
    Cliente(string _nombre, string _contra) : Usuario(_nombre, _contra), nombreArchivo("cliente.txt") {}

    string getNombreArchivo() {
        return nombreArchivo;
    }

};

class Vendedor : public Usuario {
private:
    string nombreArchivo;
    string nombreArchivoVendedorEspecifico; //implementar con el ID Ejem: vendedor10.txt
public:
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra), nombreArchivo("vendedor.txt") {}

    string getNombreArchivo() {
        return nombreArchivo;
    }
};