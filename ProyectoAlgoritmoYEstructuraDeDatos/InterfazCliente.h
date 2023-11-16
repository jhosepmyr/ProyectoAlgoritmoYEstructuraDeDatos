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
            Console::SetCursorPosition(18, 14);
            cout << "1. Informacion personal";
            Console::SetCursorPosition(18, 16);
            cout << "2. Modificar informacion\n";
            Console::SetCursorPosition(18, 18);
            cout << "3. Mostrar Productos\n";
            Console::SetCursorPosition(18, 20);
            cout << "4. Mi carrito de compras\n";
            Console::SetCursorPosition(18, 22);
            cout << "5. Historial de pedidos\n";
            Console::SetCursorPosition(18, 24);
            cout << "6. Comentarios de comunidad\n";
            Console::SetCursorPosition(18, 26);
            cout << "7. Cerrar sesion\n";
            Console::SetCursorPosition(10, 27);
            cout << "Selecciona una opcion ingresando el numero: ";
            cin >> this->opcion;
            //validarOpcion();
            resultadosOpcionSeleccionada();
            system("pause>0");
            Console::SetWindowSize(60, 40);
            if (this->opcion!='7') { return MenuCliente(); }
            else return 0;
    }

	void mostrarInterfaz() {

        MenuCliente();
        this->clienteAux = nullptr;
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
            Console::SetWindowSize(90, 40);
            this->clienteAux->mostrarPedidos();
            this->opcion = '0';
            break;
        }
        case '6': {

            break;
        }
        case '7': {
            this->clienteAux->actualizarDatosSesionATxt();
            this->clienteAux->actualizarDatosProductosTxt();
            Console::SetCursorPosition(15, 10); Console::ForegroundColor = ConsoleColor::Green; cout << "SESION CERRADA EXITOSAMENTE";
            break;
        }
        }
    }

};