#pragma once
#include "Interfaz.h"
#include "Cliente.h"

using namespace std;

class InterfazCliente : public Interfaz {
private:
	Cliente* clienteAux;

public:
	InterfazCliente(string _nombre, string _contra) {
		this->clienteAux = new Cliente(_nombre, _contra);
        this->tipoUsuario = '1';
	}
	void mostrarInterfaz() {
        do {
            system("cls");
            this->opcion = '0';
            cout << "BIENVENIDO "+ this->clienteAux->getNombre() << endl;
            cout << "1. Informacion personal\n";
            cout << "2. Modificar informacion\n";
            cout << "3. Mostrar Productos\n";
            cout << "4. Mi carrito de compras\n";
            cout << "5. Cerrar sesion\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            cin >> this->opcion;
            validarOpcion();
            system("cls");
            resultadosOpcionSeleccionada();
            system("pause");
        } while (this->opcion != '5');
        this->clienteAux = nullptr;
        cout << "\nSESION CERRADA\n";
		system("pause>0");
		return;
	}

    void resultadosOpcionSeleccionada() {
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
            this->clienteAux->ProductoMasCaro();
            this->opcion = '0';
            break;
        }
        case '6': {

        }
        }
    }
};