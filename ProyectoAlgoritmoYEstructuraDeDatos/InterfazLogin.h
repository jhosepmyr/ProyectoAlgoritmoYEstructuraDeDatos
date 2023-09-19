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
            //dibujarInterfaz();
            string auxOpcion;
            cout << "1. Iniciar sesión";
            Console::SetCursorPosition(22, 14);
            cout << "2. Registrarse";
            Console::SetCursorPosition(22, 16);
            cout << "3. Salir";
            Console::SetCursorPosition(9, 18);
            cout << "Selecciona una opcion ingresando el número\n";
            Console::SetCursorPosition(23, 20);
            cout << "Opción: ";
            cin >> auxOpcion;
            this->opcion = std::stoi(auxOpcion);
            if (*opcion == 1 || *opcion == 2)
            {
                Console::SetCursorPosition(5, 22);
                cout << "Tipo de Usuario (Cliente: 1, Vendedor: 2): ";
                cin >> tipoUsuario;
            }
            //validarOpcion(this->opcion, this->tipoUsuario);
            //generarInterfazTipoUsuario(this->opcion, this->tipoUsuario);

        } while (opcion < 1 || opcion > 3);
    }

    void dibujarInterfaz() {
        do {
            Console::Clear();
            for (int x = 2; x <= 57; x++) {//dibuja la linea 
                Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }

            cout << R"(

                    _______      _______.
                   /  _____|    /       |
                  |  |  __     |   (----`
                  |  | |_ |     \   \    
                  |  |__| | .----)   |   
                   \______| |_______/  v1.0  
            )";
            for (int x = 2; x <= 57; x++) { //dibuja la linea 
                Console::SetCursorPosition(x, 36); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
        } while (opcion < 1 || opcion > 3);
    }
};