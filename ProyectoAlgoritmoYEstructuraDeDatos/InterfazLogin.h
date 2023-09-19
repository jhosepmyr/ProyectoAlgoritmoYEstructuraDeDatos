#pragma once
#include "Interfaz.h"
#include "Login.h"

using namespace std;

class InterfazLogin : public Interfaz {
private:
    Login *login;
public:
    InterfazLogin(){
        login = new Login();
        this->tipoUsuario = 0;
        this->opcion = 1;
    }

    void ventanaIngreso() {
        do {
            dibujarInterfaz();
            cin >> this->opcion;       
            if (this->opcion == 1 || this->opcion == 2)
            {
                Console::SetCursorPosition(5, 22);
                cout << "Tipo de Usuario (Cliente: 1, Vendedor: 2): ";
                cin >> this->tipoUsuario;
            }
            validarOpcion();
            system("cls");
            generarInterfazTipoUsuario(); //metodo donde esta la llamada a la clase Login
        } while (this->opcion < 1|| this->opcion > 3);
    }
    
    void validarOpcion() {
        auto opcionValida = [](int op)->bool {return op == 1 || op == 2 || op == 3; }; //lambda
        if (!opcionValida(this->opcion) || !opcionValida(this->tipoUsuario)) {
            this->opcion = 4;
            this->tipoUsuario = 4;

            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(17, 24); cout << "Seleccione una opción válida." << endl;
            system("pause>0");
        }
    }

    void dibujarInterfaz() {
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

            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(21, 12);
            cout << "1. Iniciar sesión";
            Console::SetCursorPosition(22, 14);
            cout << "2. Registrarse";
            Console::SetCursorPosition(22, 16);
            cout << "3. Salir";
            Console::SetCursorPosition(9, 18);
            cout << "Selecciona una opcion ingresando el número\n";
            Console::SetCursorPosition(23, 20);
            cout << "Opción: ";
    }

    void generarInterfazTipoUsuario() {
        switch (this->opcion) {
            case 1: {
                if (this->tipoUsuario == 1) {
                    this->login->iniciarSesion<Cliente, InterfazCliente>();
                }
                if (this->tipoUsuario == 2)
                {
                    this->login->iniciarSesion<Vendedor, InterfazVendedor>();
                }
                this->opcion = 4;
                break;
            }
            case 2: {
                if (this->tipoUsuario == 1) {
                    this->login->registrarse<Cliente>();
                } 
                if (this->tipoUsuario == 2)
                {
                    this->login->registrarse<Vendedor>();
                }
                this->opcion = 4;
                break;
            }
        }
    }
};