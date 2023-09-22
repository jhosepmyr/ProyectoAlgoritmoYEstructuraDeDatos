#pragma once
#include <iostream>
#include <fstream>
#include "Files.h"
#include "Pila.h"
using namespace std;

class Usuario {
protected:

    string nombre;
    string apellido;
    string contra;
    string correoElectronico;
    int numeroCelular;
    string direccion;
    char genero;
    int DNI;

    string datosInicioSesion;//archivo donde se guarda las contrasenas y usuarios
    Files personal;

    char opcionUsuario;

    Lista<Producto> productos;
public:
    //Usuario() : nombre(""), contra(""), personal(){};
    Usuario(string _nombre, string _contra) : personal(_nombre, _contra) {
        this->nombre = _nombre;
        this->contra = _contra;
        this->apellido = "";
        this->correoElectronico = "";
        this->numeroCelular = 0;
        this->direccion = "";
        this->genero = '-';
        this->DNI = 0;
        this->productos = this->personal.getProductos();
        this->opcionUsuario = '0';
    }

    string getNombre() {
        return this->nombre;
    }
    string getApellido() {
        return this->apellido;
    }
    string getContra() {
        return this->contra;
    }
    string getDatosInicioSesion() {
        return datosInicioSesion;
    }

    void mostrarDatosPersonales() {
        cout << "INFORMACION PERSONAL" << endl;
        cout << "Nombre: " + this->nombre << endl;
        if(this->apellido!="") cout << "Apellido: " + this->apellido << endl;
        if(this->correoElectronico!="") cout << "CorreoElectronico: " + this->correoElectronico << endl;
        if(this->numeroCelular!=0) cout << "Numero de celular: " + to_string(this->numeroCelular) << endl;
        if(this->direccion!="") cout << "Direccion: " + this->direccion << endl;
        if(this->genero!='-') cout << "Genero: " + to_string(this->genero) << endl;
        if(this->DNI!=0) cout << "DNI: " + to_string(this->DNI) << endl;
    }

    void actualizarDatosPersonales() {
        do {
            system("cls");
            this->opcionUsuario = '0';
            cout << "CONFIGURACION DE PERFIL"<< endl;
            cout << "1.Apellido:\n";
            cout << "2.Correo electronico\n";
            cout << "3.Numero de celular\n";
            cout << "4.Direccion\n";
            cout << "5.Genero\n";
            cout << "6.DNI\n";
            cout << "7.Salir\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            cin >> this->opcionUsuario;
            //validarOpcion();
            system("cls");
            resultadosOpcionSeleccionada();
            //ActualizarDatos()---->del atributo File que actualize el archivo txt con los datos nuevos
            system("pause");
        } while (this->opcionUsuario != '7');
    }

    void resultadosOpcionSeleccionada() {
        int opcionNumerica;
        string opcionString;
        char opcionChar;
        switch (this->opcionUsuario) {
            case '1': {
                cout << "Actualizar apellido: "<<endl;
                cin >> opcionString;
                this->apellido = opcionString;
                this->opcionUsuario = '0';
                break;
            }
            case '2': {
                cout << "Actualizar correo electronico: " << endl;
                cin >> opcionString;
                this->correoElectronico = opcionString;
                this->opcionUsuario = '0';
                break;
            }
            case '3': {
                cout << "Actualizar numero de celular: " << endl;
                cin >> opcionNumerica;
                if (typeid(opcionNumerica) == typeid(int)) { this->numeroCelular = opcionNumerica; }
                else { cout << "Valor no permitido" << endl; }
                this->opcionUsuario = '0';
                break;
            }
            case '4': {
                cout << "Actualizar direccion: " << endl;
                cin >> opcionString;
                this->direccion = opcionString;
                this->opcionUsuario = '0';
                break;
            }
            case '5': {
                cout << "Actualizar genero: " << endl;
                cin >> opcionChar;
                if (typeid(opcionChar) == typeid(char)) { this->genero = opcionChar; }
                else { cout << "Valor no permitido" << endl; }
                this->opcionUsuario = '0';
                break;
            }
            case '6': {
                cout << "Actualizar DNI: " << endl;
                cin >> opcionNumerica;
                if (typeid(opcionNumerica) == typeid(int)) { this->DNI = opcionNumerica; }
                else { cout << "Valor no permitido" << endl; }
                this->opcionUsuario = '0';
                break;
            }
        }
    }

    void ProductoMasCaro() {
        this->productos.buscarPRODMAYVALOR();
    }
};