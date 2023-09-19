#pragma once
#include <iostream>
#include <fstream>
using namespace std;
using namespace System;

class Login {
public:
	Login(){}
    // función con template para Login
    template <typename T>
    int iniciarSesion() {
        string nombre, contra;
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(21, 24);
        cout << "INICIO DE SESIÓN";
        Console::SetCursorPosition(20, 26);
        cout << "Nombre: ";
        cin >> nombre;
        Console::SetCursorPosition(20, 28);
        cout << "Contraseña: ";
        cin >> contra;

        //uso de template
        T* auxUsuario = new T(nombre, contra);

        ifstream archivoLectura(auxUsuario->getNombreArchivo()); //llamada al archivo txt

        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getNombreArchivo() << endl;
            return false;
        }

        string linea;

        while (getline(archivoLectura, linea)) {
            // Verifica si la línea contiene el nombre y la contraseña separados por un espacio
            if (linea == nombre + " " + contra) {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::SetCursorPosition(16, 29);  cout << "Inicio de sesion exitoso." << endl;
                Console::ForegroundColor = ConsoleColor::Blue;
                Console::SetCursorPosition(14, 31); cout << "Presiona ENTER para continuar";
                system("pause>0");
                delete auxUsuario;
                auxUsuario = nullptr;
                return 2;
            }

        }
        archivoLectura.close(); //cierra archivo

        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(1, 30); cout << "Inicio de sesion fallido. Nombre o contraseña incorrectos." << endl;
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(14, 32); cout << "Presiona ENTER para volver";
        system("pause>0");

        delete auxUsuario;
        auxUsuario = nullptr;
        return 4; // Retorna un valor que no coincide con la condición de parada del do-while en el main
    }

    // template registrarse, admite todos los tipos de usuario
    template <typename T>
    void registrarse() {
        string nombre, contra;
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(16, 24);
        cout << "REGISTRO DE NUEVO USUARIO";
        Console::SetCursorPosition(20, 26);
        cout << "Nombre: ";
        cin >> nombre;
        Console::SetCursorPosition(20, 28);
        cout << "Contraseña: ";
        cin >> contra;

        //uso del template
        T* auxUsuario = new T(nombre, contra);

        ofstream archivoEscritura(auxUsuario->getNombreArchivo(), ios::app); // Abre el archivo en modo de escritura
        ifstream archivoLectura(auxUsuario->getNombreArchivo()); //abre archivo en modo lectura

        if (!archivoEscritura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getNombreArchivo() << endl;
            return;
        }

        string linea;
        while (getline(archivoLectura, linea)) { //para validar que no haya un usuario con el mismo nombre
            // Verifica si la línea contiene el nombre y la contraseña separados por un espacio
            if (linea == nombre + " " + contra) {
                Console::SetCursorPosition(2, 30);
                Console::ForegroundColor = ConsoleColor::Red;
                cout << "Registro fallido: Nombre de usuario ocupado en el sistema";
                system("pause>0");
                delete auxUsuario;
                auxUsuario = nullptr;
                return;
            }

        }
        // Escribe los datos del nuevo usuario en una sola línea
        archivoEscritura << nombre << " " << contra << "\n";
        archivoEscritura.close();

        Console::SetCursorPosition(18, 30);
        Console::ForegroundColor = ConsoleColor::Green;
        cout << "Registro exitoso." << endl;

        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(15, 32); cout << "Presiona ENTER para volver";
        system("pause>0");

        delete auxUsuario;
        auxUsuario = nullptr;
    }
 };
