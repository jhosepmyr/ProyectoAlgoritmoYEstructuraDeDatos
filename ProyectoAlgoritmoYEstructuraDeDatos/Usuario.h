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
    string numeroCelular;
    string direccion;
    string genero;
    string DNI;

    string datosInicioSesion;//archivo donde se guarda las contrasenas y usuarios
    Files personal;
    char opcionUsuario;

    Lista<Producto> productos;

public:
    Usuario(string _nombre, string _contra) : personal(_nombre, _contra) {
        this->nombre = _nombre;
        this->contra = _contra;
        this->apellido = "ninguno";
        this->correoElectronico = "ninguno";
        this->numeroCelular = "ninguno";
        this->direccion = "ninguno";
        this->genero = "ninguno";
        this->DNI = "ninguno";
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
    string getNumeroCelular() {
        return this->numeroCelular;
    }
    string getDireccion() {
        return this->direccion;
    }
    string getGenero() {
        return this->genero;
    }
    string getDNI() {
        return this->DNI;
    }
    string getDatosInicioSesion() {
        return datosInicioSesion;
    }

    //actualiza toda la informacion del archivo txt de datos de sesion
    void setTodaInformacion(string _nombre, string _contra, string _apellido, string _correo, string _num, string _direccion, string _genero, string _DNI) {
        // Utilización de funciones lambda para actualizar los miembros
        auto updateMember = [](string& member, const string& value) {
            if (value != "ninguno") {
                member = value;
            }
        };
        updateMember(this->nombre, _nombre);
        updateMember(this->contra, _contra);
        updateMember(this->apellido, _apellido);
        updateMember(this->correoElectronico, _correo);
        updateMember(this->numeroCelular, _num);
        updateMember(this->direccion, _direccion);
        updateMember(this->genero, _genero);
        updateMember(this->DNI, _DNI);
    }

    void mostrarDatosPersonales() {
        cout << "INFORMACION PERSONAL" << endl;
        auto mostrarDato = [this](const string& label, const string& dato) {
            if (dato != "ninguno") {
                cout << label << ": " << dato << endl;
            }
        };

        mostrarDato("Nombre", this->nombre);
        mostrarDato("Apellido", this->apellido);
        mostrarDato("CorreoElectronico", this->correoElectronico);
        mostrarDato("Numero de celular", this->numeroCelular);
        mostrarDato("Direccion", this->direccion);
        mostrarDato("Genero", this->genero);
        mostrarDato("DNI", this->DNI);
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

            // Función lambda para actualizar datos
            auto actualizarDato = [this](string& dato, const string& label) {
                cout << "Actualizar " << label << ": " << endl;
                cin >> dato;
                this->opcionUsuario = '0';
            };
            switch (this->opcionUsuario) {
            case '1':
                actualizarDato(this->apellido, "apellido");
                break;
            case '2':
                actualizarDato(this->correoElectronico, "correo electronico");
                break;
            case '3':
                actualizarDato(this->numeroCelular, "numero de celular");
                break;
            case '4':
                actualizarDato(this->direccion, "direccion");
                break;
            case '5':
                actualizarDato(this->genero, "genero");
                break;
            case '6':
                actualizarDato(this->DNI, "DNI");
                break;
            }

        } while (this->opcionUsuario != '7');
    }

    //Modificacion y obtencion de datos

    void actualizarDatosProductosTxt() {
        this->personal.actualizarProductosTxt(this->productos);
    }

    void getInformacionPersonalTxt() {

        ifstream archivoLectura(this->datosInicioSesion);

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
                string numeroCelular;
                string direccion;
                string genero;
                string DNI;
                istringstream iss(linea);
                iss >> nombre >> contra >> apellido >> correoElectronico >> numeroCelular >> direccion >> genero >> DNI;
                setTodaInformacion(nombre, contra, apellido, correoElectronico, numeroCelular, direccion, genero, DNI);
                return;
            }
        }
        archivoLectura.close();
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
                    this->numeroCelular + " " +
                    this->direccion + " " +
                    this->genero + " " +
                    this->DNI;
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
    }

    //EXTRA

    void ProductoMasCaro() {
        this->productos.ordenarPorPrecioAscendente();
    }
};