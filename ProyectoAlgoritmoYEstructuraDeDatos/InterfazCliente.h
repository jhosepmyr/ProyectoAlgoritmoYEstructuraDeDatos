#pragma once
#include "Interfaz.h"
#include "Cliente.h"
#include <sstream>

using namespace std;

class InterfazCliente : public Interfaz {
private:
	Cliente* clienteAux;
    Files datosActualizados;

public:
	InterfazCliente(string _nombre, string _contra) {
		this->clienteAux = new Cliente(_nombre, _contra);
        this->tipoUsuario = '1';
	}

    int MenuCliente() {
            system("cls");
            this->opcion = '0';
            for (int x = 2; x <= 57; x++) {//dibuja linea 
                Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            for (int x = 2; x <= 57; x++) { //dibuja linea 
                Console::SetCursorPosition(x, 36); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(20, 8);
            cout << "BIENVENIDO " + this->clienteAux->getNombre() << endl;
            Console::SetCursorPosition(20, 12);
            cout << "MENU DE OPCIONES";
            Console::SetCursorPosition(18, 15);
            cout << "1. Informacion personal";
            Console::SetCursorPosition(18, 17);
            cout << "2. Modificar informacion\n";
            Console::SetCursorPosition(18, 19);
            cout << "3. Mostrar Productos\n";
            Console::SetCursorPosition(18, 21);
            cout << "4. Mi carrito de compras\n";
            Console::SetCursorPosition(18, 23);
            cout << "5. Historial de pedidos\n";
            Console::SetCursorPosition(18, 25);
            cout << "6. Cerrar sesion\n";
            Console::SetCursorPosition(10, 27);
            cout << "Selecciona una opcion ingresando el numero\n\n";
            Console::SetCursorPosition(10, 28);
            cout << "Opcion: ";
            cin >> this->opcion;
            //validarOpcion();
            resultadosOpcionSeleccionada();
            system("pause>0");
            if (this->opcion > 6 || this->opcion < 1) { return MenuCliente(); }
            else return 0;
    }

	void mostrarInterfaz() {

        MenuCliente();
        this->clienteAux = nullptr;
        cout << "SESION CERRADA\n";
		system("pause>0");
		return;
	}

    void resultadosOpcionSeleccionada() {
        system("cls");
        switch (this->opcion) {
        case '1': {
            this->clienteAux->mostrarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '2': {
            this->clienteAux->actualizarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '3': {
            this->clienteAux->mostrarProductos();
            this->opcion = '0';
            break;
        }
        case '4': {
            this->clienteAux->mostrarPedido();
            this->opcion = '0';
            break;
        }
        case '5': {
            this->clienteAux->mostrarPedidos();
            this->opcion = '0';
            break;
        }

        case '6': {
            this->clienteAux->actualizarDatosSesionATxt();
            this->clienteAux->actualizarDatosProductosTxt();
            break;
        }
        }
    }

};