#pragma once
#include "Interfaz.h"
#include "Login.h"
#include "conio.h"
#define ABAJO 80
#define ARRIBA 72

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
            Console::SetCursorPosition(17, 12);
            cout << "Iniciar sesion";
            Console::SetCursorPosition(17, 14);
            cout << "Registrarse";
            Console::SetCursorPosition(17, 16);
            cout << "Funcionamiento\n";
            Console::SetCursorPosition(17, 18);
            cout << "Mostrar los integrantes\n";
            Console::SetCursorPosition(17, 20);
            cout << "Salir";
            Console::SetCursorPosition(9, 22);
            cout << "Selecciona una opcion moviendo la flecha\n";
            Console::SetCursorPosition(19, 24);
            cout << "PRESIONA ENTER";
            int x = 41, y = 12;
            while (true) {
                //borrar
                Console::SetCursorPosition(x, y); cout << "  ";
                //mover
                if (_kbhit()) {
                    char tecla = getch();
                    if (tecla == ABAJO) y += 2;
                    if (tecla == 13) {
                        if (y == 12) opcion = '1';
                        if (y == 14) opcion = '2';
                        if (y == 16) opcion = '3';
                        if (y == 18) opcion = '4';
                        if (y == 20) opcion = '5';
                        break;
                    }
                }
                Console::SetCursorPosition(x, y); cout << "<-";
                _sleep(100);
            }
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