#pragma once
#include "Interfaz.h"
#include "Login.h"
#include "Usuario.h"
#include <string>

using namespace System;
using namespace std;

class InterfazLogin : public Interfaz {
private:
    Login *login;
public:
    InterfazLogin(){
        this->opcion=0;
    }

    void ventanaIngreso() {
        do {
            cout << "1. Iniciar sesión\n";
            cout << "2. Registrarse\n";
            cout << "3. Salir\n";
            cout << "Selecciona una opcion ingresando el número\n\n";
            cout << "Opción: ";
            if (opcion == 1 || opcion == 2)
            {
                Console::SetCursorPosition(5, 22);
                cout << "Tipo de Usuario (Cliente: 1, Vendedor: 2): ";
                cin >> tipoUsuario;
            }
            validarOpcion();
            generarInterfazTipoUsuario();

        } while (opcion < 1 || opcion > 3);
    }

    void validarOpcion() {
        auto opcionValida = [](char op) {return op == '1' || op == '2' || op == '3'; };

        if (!opcionValida(this->opcion) || !opcionValida(this->tipoUsuario)) {
            //Console::ForegroundColor = ConsoleColor::Red;
            //Console::SetCursorPosition(17, 24); 
            cout << "Seleccione una opción válida.\n" << endl;
            system("pause>0");
        }
    }

    void dibujarInterfaz() {
        do {
            for (int x = 2; x <= 57; x++) {
                //dibuja la linea 
                //Console::SetCursorPosition(x, 2); 
                //Console::ForegroundColor = ConsoleColor::Cyan; ; 
                cout << (char)219;
            }
            cout << "\n";
            cout << R"(

                    _______      _______.
                   /  _____|    /       |
                  |  |  __     |   (----`
                  |  | |_ |     \   \    
                  |  |__| | .----)   |   
                   \______| |_______/  v1.0  
            )";
            cout << "\n";
            for (int x = 2; x <= 57; x++) { //dibuja la linea 
                //Console::SetCursorPosition(x, 36); 
                //Console::ForegroundColor = ConsoleColor::Cyan; ; 
                cout << (char)219;
            }
            cout << "\n";
        } while (opcion < 1 || opcion > 3);
    }
    void generarInterfazTipoUsuario() {
        switch (this->opcion) {
            //llamada a funciones template
            case '1': {
                if (tipoUsuario == 1) {
                    this->login->iniciarSesion<Cliente>();
                }
                else {
                    this->login->iniciarSesion<Vendedor>();
                }
                break;
            }
            case '2': {
                if (tipoUsuario == 1) {
                    this->login->registrarse<Cliente>();
                } 
                else {
                    this->login->registrarse<Vendedor>();
                }
                this->opcion = 4;
                break;
            }
        }
    }
};