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
        this->tipoUsuario = '0';
        this->opcion = '0';
    }

    void mostrarInterfaz() {
        do {
            system("cls");
            this->tipoUsuario = '0';
            this->opcion = '0';

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
            cout << "1. Iniciar sesion";
            Console::SetCursorPosition(22, 14);
            cout << "2. Registrarse";
            Console::SetCursorPosition(20, 16);
            cout << "3. Funcionamiento\n";
            Console::SetCursorPosition(18, 18);
            cout << "4. Mostrar los integrantes\n";
            Console::SetCursorPosition(22, 20);
            cout << "5. Salir";
            Console::SetCursorPosition(9, 22);
            cout << "Selecciona una opcion ingresando el numero\n";
            Console::SetCursorPosition(23, 24);
            cout << "Opcion: ";
            cin >> this->opcion;      
           
            if (this->opcion == '1' || this->opcion == '2')
            {
                Console::SetCursorPosition(5, 26);
                cout << "Tipo de Usuario (Cliente: 1, Vendedor: 2): ";
                cin >> this->tipoUsuario;
            }
            validarOpcion();
            system("cls");
            resultadosOpcionSeleccionada();
            system("pause");
        } while (this->opcion!= '5');

        Console::SetCursorPosition(5, 20);
        cout << "REGRESE PRONTO\n";
    }
   
    //metodo donde esta la llamada a la clase Login
    void resultadosOpcionSeleccionada() {
        switch (this->opcion) {
            case '1': {
                if (this->tipoUsuario == '1') {
                    this->login->iniciarSesion<Cliente, InterfazCliente>();
                }
                if (this->tipoUsuario == '2')
                {
                    this->login->iniciarSesion<Vendedor, InterfazVendedor>();
                }
                this->opcion = '0';
                break;
            }
            case '2': {
                if (this->tipoUsuario == '1') {
                    this->login->registrarse<Cliente>();
                } 
                if (this->tipoUsuario == '2')
                {
                    this->login->registrarse<Vendedor>();
                }
                this->opcion = '0';
                break;
            }
            case '3': {
                cout << "informacion mostrada" << endl;
                this->opcion = '0';
                break;
            }
            case '4': {
                cout << "los duenos son:" << endl;
                this->opcion = '0';
                break;
            }
        }
    }
};