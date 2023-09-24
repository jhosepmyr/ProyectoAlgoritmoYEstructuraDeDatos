#pragma once
#include <iostream>
#include "InterfazCliente.h"
#include "InterfazVendedor.h"
using namespace std;

class Login {
private:
public:
	Login(){}
    // función con template para iniciar sesión

    template <typename T, class tipoInterfaz>
    void iniciarSesion() {
        string nombre, contra;
        cout << "INICIO DE SESIÓN" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Contraseña: ";
        cin >> contra;

        //uso de template,
        T* auxUsuario = new T(nombre, contra);

        ifstream archivoLectura(auxUsuario->getDatosInicioSesion());
        
        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getDatosInicioSesion() << endl;
            return;
        }

        string linea;
        bool credencialesCorrectas = false;

        while (getline(archivoLectura, linea)) {
            // Separar la línea en nombre de usuario y contraseña
            istringstream iss(linea);
            string storedNombre, storedContra;
            if (iss >> storedNombre >> storedContra) {
                if (nombre == storedNombre && contra == storedContra) {
                    credencialesCorrectas = true;
                    break;
                }
            }
        }

        archivoLectura.close();

        if (credencialesCorrectas) {
            cout << "Inicio de sesión exitoso." << endl;
            tipoInterfaz* auxInterfazUsuario = new tipoInterfaz(nombre, contra);
            auxInterfazUsuario->mostrarInterfaz();
            delete auxInterfazUsuario;
        }
        else {
            cout << "Inicio de sesión fallido. Nombre o contraseña incorrectos." << endl;
        }

        cout << "Presiona ENTER para volver";
        system("pause>0");
        system("cls");
    }

    // template para registrarse, admite todos los tipos de usuario
    template <typename T>
    void registrarse() {
        system("cls");
        string nombre, contra;
        cout << "REGISTRO DE NUEVO USUARIO" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Contraseña: ";
        cin >> contra;

        T* auxUsuario = new T(nombre, contra);

        if (verificarUsuarioExistente(nombre, contra, auxUsuario->getDatosInicioSesion())) {
            cout << "Registro fallido: Nombre de usuario ocupado en el sistema" << endl;
        }
        else {
            agregarNuevoUsuario(nombre, contra, auxUsuario->getDatosInicioSesion());
        }

        cout << "Presiona ENTER para volver";
        system("pause>0");
        system("cls");
    }

    bool verificarUsuarioExistente(string nombreUsuario, string contraUsuario,string archivo) {
        ifstream archivoLectura(archivo);

        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            return false;
        }

        string linea;

        while (getline(archivoLectura, linea)) {
            // Separar la línea en nombre de usuario y contraseña
            istringstream iss(linea);
            string storedNombre, storedContra;
            if (iss >> storedNombre >> storedContra) {
                if (nombreUsuario == storedNombre && contraUsuario == storedContra) {
                    archivoLectura.close();
                    return true; // El usuario ya existe en el sistema
                }
            }
        }

        archivoLectura.close();
        return false; // El usuario no existe
    }
    
    void agregarNuevoUsuario(string nombre, string contra,string archivo) {
        // Abre el archivo en modo de escritura sin agregar
        ofstream archivoEscritura(archivo, ios_base::app);

        if (!archivoEscritura.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            return;
        }
        // Escribe los datos del nuevo usuario al final del archivo
        archivoEscritura << nombre << " " << contra << endl;
        archivoEscritura.close();

        cout << "Registro exitoso." << endl;
    }

 };
