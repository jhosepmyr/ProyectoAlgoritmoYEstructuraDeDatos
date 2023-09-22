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
    string genero;
    //char genero;
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
        this->apellido = "ninguno";
        this->correoElectronico = "ninguno";
        this->numeroCelular = 0;
        this->direccion = "ninguno";
        this->genero = "ninguno";
        this->DNI = 0;
        this->productos = this->personal.getProductos();
        this->opcionUsuario = '0';
    }

    //GETTERS Y SETTERS

    string getNombre() {
        return this->nombre;
    }
    string getContra() {
        return this->contra;
    }
    string getApellido() {
        return this->apellido;
    }
    string getCorreoElectronico() {
        return this->correoElectronico;
    }
    int getNumeroCelular() {
        return this->numeroCelular;
    }
    string getDireccion() {
        return this->direccion;
    }
    string getGenero() {
        return this->genero;
    }
    int getDNI() {
        return this->DNI;
    }
    string getDatosInicioSesion() {
        return datosInicioSesion;
    }

    //actualiza toda la informacion del archivo txt de datos de sesion
    void setTodaInformacion(string _nombre, string _contra, string _apellido, string _correo, int _num, string _direccion, string _genero, int _DNI) {
        this->nombre = _nombre;
        this->contra = _contra;
        this->apellido = _apellido;
        this->correoElectronico = _correo;
        this->numeroCelular = _num;
        this->direccion = _direccion;
        this->genero = _genero;
        this->DNI = _DNI;
    }

    void mostrarDatosPersonales() {
        cout << "INFORMACION PERSONAL" << endl;
        cout << "Nombre: " + this->nombre << endl;
        if(this->apellido!="ninguno") cout << "Apellido: " + this->apellido << endl;
        if(this->correoElectronico!="ninguno") cout << "CorreoElectronico: " + this->correoElectronico << endl;
        if(this->numeroCelular!=0) cout << "Numero de celular: " + to_string(this->numeroCelular) << endl;
        if(this->direccion!="ninguno") cout << "Direccion: " + this->direccion << endl;
        if(this->genero!= "ninguno") cout << "Genero: " + this->genero << endl;
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
        } while (this->opcionUsuario != '7');
    }

    void resultadosOpcionSeleccionada() {
        int opcionNumerica;
        string opcionString;
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
                cin >> opcionString;
                this->genero = opcionString;
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

    void actualizarDatosProductosTxt() {
        this->personal.actualizarProductosTxt(this->productos);
    }

    void ProductoMasCaro() {
        this->productos.buscarPRODMAYVALOR();
    }

    void getInformacionPersonalTxt() {

        ifstream archivoLectura(this->datosInicioSesion);
        string contenidoArchivo;

        if (!archivoLectura.is_open())
        {
            cout << "Error al abrir el archivo " << this->getDatosInicioSesion() << endl;
            return;
        }
        string linea;
        while (getline(archivoLectura, linea))
        {
            bool verificarNombre = linea.find(this->nombre) != string::npos;
            bool verificarContra = linea.find(this->contra) != string::npos;
            if (verificarContra && verificarNombre)
            {
                string nombre;
                string apellido;
                string contra;
                string correoElectronico;
                int numeroCelular;
                string direccion;
                string genero;
                int DNI;
                istringstream iss(linea);
                iss >> nombre >> contra >> apellido >> correoElectronico >> numeroCelular >> direccion >> genero >> DNI;
                setTodaInformacion(nombre, contra, apellido, correoElectronico, numeroCelular, direccion, genero, DNI);
                return;
            }
        }
        archivoLectura.close();
        ofstream archivoEscritura(this->datosInicioSesion);
        archivoEscritura << contenidoArchivo;
        archivoEscritura.close();
    }

    void actualizarDatosSesionATxt() {
        ifstream archivoLectura(this->datosInicioSesion);
        string contenidoArchivo;
        if (!archivoLectura.is_open())
        {
            cout << "Error al abrir el archivo " << endl;
            return;
        }

        string linea;
        while (getline(archivoLectura, linea))
        {
            bool verificarNombre = linea.find(this->nombre) != string::npos;
            bool verificarContra = linea.find(this->contra) != string::npos;
            if (verificarContra && verificarNombre)
            {
                string nuevaLinea = this->nombre + " " +
                    this->contra + " " +
                    this->apellido + " " +
                    this->correoElectronico + " " +
                    to_string(this->numeroCelular) + " " +
                    this->direccion + " " +
                    this->genero + " " +
                    to_string(this->DNI);
                contenidoArchivo += nuevaLinea + "\n";
            }
            else
            {
                contenidoArchivo += linea + "\n";
            }
        }
        archivoLectura.close();
        ofstream archivoEscritura(this->datosInicioSesion);
        archivoEscritura << contenidoArchivo;
        archivoEscritura.close();

        //cout << "Datos actualizados en el archivo exitosamente." <<endl;
    }
};