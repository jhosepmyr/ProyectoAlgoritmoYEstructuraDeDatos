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
            resultadosOpcionSeleccionada();
            system("pause>0");
        } while (this->opcion!= '5');

        Console::SetCursorPosition(20, 30);
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
                cout << endl;
                Console::ForegroundColor = ConsoleColor::Green;
                cout << "\t\t    Funcionamiento" << endl;
                cout << "   Guru Shop es una aplicacion de gestion de ventas\n";
                cout << "  que utiliza una estructura orientada a objetos con\n"; 
                cout << "  clases como Cliente, Vendedor y Pedido. Hace uso de\n";
                cout << " estructuras de datos como Listas, Colas y Pilas, junto\n"; 
                cout << "  con plantillas, funciones lambda y recursividad para\n";
                cout << " optimizar las operaciones.Su objetivo es ofrecer a los\n";
                cout << "  usuarios la capacidad de explorar productos, realizar\n";
                cout << " pedidos y administrar transacciones de manera eficiente.";
                Console::SetCursorPosition(14, 35);
                Console::ForegroundColor = ConsoleColor::Blue;
                cout << "Presiona ENTER para volver";
                this->opcion = '0';
                break;
            }
            case '4': {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::SetCursorPosition(21, 26);
                cout << "Los duenios son:";
                Console::SetCursorPosition(20, 28);
                cout << "Jhosepmyr Orlando";
                Console::SetCursorPosition(24, 30);
                cout << "Elmer Riva";
                Console::SetCursorPosition(22, 32);
                cout << "Jose Martinez";
                Console::SetCursorPosition(14, 34);
                Console::ForegroundColor = ConsoleColor::Blue;
                cout << "Presiona ENTER para volver";
                this->opcion = '0';
                break;
            }
        }
    }
};