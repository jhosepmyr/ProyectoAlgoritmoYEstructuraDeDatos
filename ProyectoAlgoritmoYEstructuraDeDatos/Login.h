#pragma once
#include <iostream>
#include "InterfazCliente.h"
#include "InterfazVendedor.h"
using namespace std;

class Login {
private:

public:
	Login(){}
    // función con template para Login
    template <typename T, class tipoInterfaz>
    void iniciarSesion() {
        string nombre, contra;
        cout << "INICIO DE SESIÓN"<<endl;
        cout << "Nombre: "<<endl;
        cin >> nombre;
        cout << endl;
        cout << "Contraseña: " << endl;
        cout << endl;
        cin >> contra;
        cout << endl;

        //uso de template,
        T* auxUsuario = new T(nombre, contra);

        ifstream archivoLectura(auxUsuario->getDatosInicioSesion());

        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getDatosInicioSesion() << endl;
            return;
        }

        string linea;

        while (getline(archivoLectura, linea)) {
            bool verificarNombre = linea.find(nombre);
            bool verificarContra = linea.find(contra);
            // Verifica si la línea contiene el nombre y la contraseña separados por un espacio
            if (verificarContra && verificarNombre) {
                cout << "Inicio de sesion exitoso." << endl << endl;
                cout << "Presiona ENTER para continuar";
                system("pause>0");
                system("cls");
                tipoInterfaz* auxInterfazUsuario= new tipoInterfaz(nombre, contra);
                auxInterfazUsuario->mostrarInterfaz();
                //auxUsuario
                delete auxUsuario;
                auxUsuario = nullptr;
                return;
            }
        }
        archivoLectura.close(); //cierra archivo

        cout << "Inicio de sesion fallido. Nombre o contraseña incorrectos." << endl;
        cout << "Presiona ENTER para volver";
        system("pause>0");
        system("cls");
        delete auxUsuario;
        auxUsuario = nullptr;
        return;

    }

    // template registrarse, admite todos los tipos de usuario
    template <typename T>
    void registrarse() {
        system("cls");
        string nombre, contra;
        cout << "REGISTRO DE NUEVO USUARIO"<<endl;
        cout << "Nombre: "<<endl;
        cin >> nombre;
        cout << endl;
        cout << "Contraseña: " << endl;
        cin >> contra;
        cout << endl;

        //uso del template
        T* auxUsuario = new T(nombre, contra);

        ofstream archivoEscritura(auxUsuario->getDatosInicioSesion(), ios::app); // Abre el archivo en modo de escritura
        ifstream archivoLectura(auxUsuario->getDatosInicioSesion()); //abre archivo en modo lectura

        if (!archivoEscritura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getDatosInicioSesion() << endl;
            return;
        }

        string linea;
        while (getline(archivoLectura, linea)) { 
            //para validar que no haya un usuario con el mismo nombre
            // Verifica si la línea contiene el nombre y la contraseña separados por un espacio
            if (linea == nombre + " " + contra) {
                cout << "Registro fallido: Nombre de usuario ocupado en el sistema";
                system("pause>0");
                delete auxUsuario;
                auxUsuario = nullptr;
                system("cls");
                return;
            }

        }
        // Escribe los datos del nuevo usuario en una sola línea
        archivoEscritura << nombre << " " << contra <<endl;
        cout << endl;
        archivoEscritura.close();

        cout << "Registro exitoso." << endl << endl;
        cout << "Presiona ENTER para volver";
        system("pause>0");
        system("cls");

        delete auxUsuario;
        auxUsuario = nullptr;
    }
 };
