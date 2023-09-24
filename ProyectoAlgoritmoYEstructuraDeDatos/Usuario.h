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
            resultadosOpcionSeleccionada();
        } while (this->opcionUsuario != '7');
    }

    void resultadosOpcionSeleccionada() {
        //int opcionNumerica;
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
                cin >> opcionString;
                this->numeroCelular = opcionString;
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
                cin >> opcionString;
                this->DNI = opcionString;
                this->opcionUsuario = '0';
                break;
            }
        }
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