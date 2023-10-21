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
    string ID;

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
        this->ID = "ninguno";
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
    void setID(string _ID) {
        ID = _ID;
    }
    string getID() {
        return this->ID;
    }

    //actualiza toda la informacion del archivo txt de datos de sesion
    void setTodaInformacion(string _nombre, string _contra,string _id, string _apellido, string _correo, string _num, string _direccion, string _genero, string _DNI) {
        // Utilización de funciones lambda para actualizar los miembros
        auto updateMember = [](string& member, const string& value) {
            if (value != "ninguno") {
                member = value;
            }
        };
        updateMember(this->nombre, _nombre);
        updateMember(this->contra, _contra);
        updateMember(this->ID, _id);
        updateMember(this->apellido, _apellido);
        updateMember(this->correoElectronico, _correo);
        updateMember(this->numeroCelular, _num);
        updateMember(this->direccion, _direccion);
        updateMember(this->genero, _genero);
        updateMember(this->DNI, _DNI);
    }

    void mostrarDatosPersonales() {
        for (int x = 2; x <= 57; x++) {//dibuja la linea 
            Console::SetCursorPosition(x, 5); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
        }
        for (int x = 2; x <= 57; x++) { //dibuja la linea 
            Console::SetCursorPosition(x, 32); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
        }

        Console::SetCursorPosition(19, 5); Console::ForegroundColor = ConsoleColor::White;
        cout << "INFORMACION PERSONAL" << endl;
        auto mostrarDato = [this](const string& label, const string& dato) {
            if (dato != "ninguno") {
                cout << label << dato << endl;
            }
        };
        Console::SetCursorPosition(2, 9);
        mostrarDato("Nombre: ", this->nombre);
        Console::SetCursorPosition(2, 11);
        mostrarDato("Apellido: ", this->apellido);
        Console::SetCursorPosition(2, 13);
        mostrarDato("ID: ", this->ID);
        Console::SetCursorPosition(2, 15);
        mostrarDato("CorreoElectronico: ", this->correoElectronico);
        Console::SetCursorPosition(2, 18);
        mostrarDato("Numero de celular: ", this->numeroCelular);
        Console::SetCursorPosition(2, 20);
        mostrarDato("Direccion: ", this->direccion);
        Console::SetCursorPosition(2, 22);
        mostrarDato("Genero: ", this->genero);
        Console::SetCursorPosition(2, 24);
        mostrarDato("DNI: ", this->DNI);

        Console::SetCursorPosition(16, 28); Console::ForegroundColor = ConsoleColor::Cyan;
        cout << "Presiona ENTER para volver";
    }

    void actualizarDatosPersonales() {
        do {
            system("cls");
            for (int x = 2; x <= 57; x++) {//dibuja la linea 
                Console::SetCursorPosition(x, 5); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            for (int x = 2; x <= 57; x++) { //dibuja la linea 
                Console::SetCursorPosition(x, 32); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }

            this->opcionUsuario = '0';
            Console::SetCursorPosition(19, 5); Console::ForegroundColor = ConsoleColor::White;
            cout << "CONFIGURACION DE PERFIL"<< endl;
            Console::SetCursorPosition(2, 7);
            cout << "0.Nombre\n";
            Console::SetCursorPosition(2, 9);
            cout << "1.Apellido\n";
            Console::SetCursorPosition(2, 11);
            cout << "2.Correo electronico\n";
            Console::SetCursorPosition(2, 13);
            cout << "3.Numero de celular\n";
            Console::SetCursorPosition(2, 15);
            cout << "4.Direccion\n";
            Console::SetCursorPosition(2, 17);
            cout << "5.Genero\n";
            Console::SetCursorPosition(2, 19);
            cout << "6.DNI\n";
            Console::SetCursorPosition(2, 21);
            cout << "7.Salir\n";
            Console::SetCursorPosition(2, 23);
            cout << "Selecciona una opcion ingresando el numero\n\n";
            Console::SetCursorPosition(2, 25);
            cout << "Opcion: ";
            cin >> this->opcionUsuario;
            //validarOpcion();
            Console::SetCursorPosition(2, 27); Console::ForegroundColor = ConsoleColor::Green;

            // Función lambda para actualizar datos
            auto actualizarDato = [this](string& dato, const string& label) {
                cout << "Actualizar " << label << ": ";
                string newDato;
                cin >> newDato;
                dato = newDato;
                this->opcionUsuario = '0';
            };
            switch (this->opcionUsuario) {
            case '0':
                actualizarDato(this->nombre, "nombre");
                break;
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
                string id;
                string correoElectronico;
                string numeroCelular;
                string direccion;
                string genero;
                string DNI;
                istringstream iss(linea);
                iss >> nombre >> contra>> id >> apellido >> correoElectronico >> numeroCelular >> direccion >> genero >> DNI;
                setTodaInformacion(nombre, contra,id, apellido, correoElectronico, numeroCelular, direccion, genero, DNI);
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
                    this->ID + " " +
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