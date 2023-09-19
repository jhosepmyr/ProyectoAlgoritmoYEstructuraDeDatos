#pragma once
#include "Interfaz.h"
#include "Login.h"
#include "InterfazCliente.h"
#include "InterfazVendedor.h"

using namespace std;

class InterfazLogin : public Interfaz {
private:
    Login *login;
public:
    InterfazLogin(){
        login = new Login();
        this->tipoUsuario = 0;
    }

    void ventanaIngreso() {
        do {
            cout << "1. Iniciar sesion\n";
            cout << "2. Registrarse\n";
            cout << "3. Salir\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            cin >> this->opcion;       
            if (this->opcion == '1' || this->opcion == '2')
            {
                cout << "Tipo de Usuario (Cliente: 1, Vendedor: 2):\n ";
                cin >> this->tipoUsuario;
            }
            validarOpcion();
            system("cls");
            generarInterfazTipoUsuario();
        } while (this->opcion < 1 || this->opcion > 3);
    }
    
    void validarOpcion() {
        auto opcionValida = [](char op)->bool {return op == '1' || op == '2' || op == '3'; };
        if (!opcionValida(this->opcion) || !opcionValida(this->tipoUsuario)) {
            cout << "Seleccione una opcion valida.\n" << endl;
            this->opcion = 4;
            this->tipoUsuario = 4;
            system("pause>0");
        }
    }

    void dibujarInterfaz() {
        do {
            for (int x = 2; x <= 57; x++) {
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
            for (int x = 2; x <= 57; x++) { 
                cout << (char)219;
            }
            cout << "\n";
        } while (opcion < 1 || opcion > 3);
    }

    void generarInterfazTipoUsuario() {
        switch (this->opcion) {
            case '1': {
                if (this->tipoUsuario == '1') {
                    this->login->iniciarSesion<Cliente, InterfazCliente>();
                }
                if (this->tipoUsuario == '2')
                {
                    this->login->iniciarSesion<Vendedor, InterfazVendedor>();
                }
                this->opcion = 4;
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
                this->opcion = 4;
                break;
            }
        }
    }
};