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
            cout << "1. Iniciar sesion\n";
            cout << "2. Registrarse\n";
            cout << "3. Funcionamiento\n";
            cout << "4. Mostrar los integrantes\n";
            cout << "5. Salir\n";
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
            resultadosOpcionSeleccionada();
            system("pause");
        } while (this->opcion!= '5');

        cout << "\nREGRESE PRONTO\n";
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