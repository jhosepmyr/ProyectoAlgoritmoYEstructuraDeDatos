#pragma once
#include "Interfaz.h"
#include "Vendedor.h"

using namespace std;

class InterfazVendedor : public Interfaz {
private: 
    Vendedor* vendedorAux;
public:
    InterfazVendedor(string _nombre, string _contra) {
        this->vendedorAux = new Vendedor(_nombre, _contra);
        this->vendedorAux->setProductosPropios();
        this->tipoUsuario = '2';
    }

    void mostrarInterfaz() {
        do {
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
            cout << "BIENVENIDO " + this->vendedorAux->getNombre() << endl;
            Console::SetCursorPosition(20, 12);
            cout << "MENU DE OPCIONES";
            Console::SetCursorPosition(18, 15);
            cout << "1. Informacion personal\n";
            Console::SetCursorPosition(18, 17);
            cout << "2. Modificar informacion\n";
            Console::SetCursorPosition(18, 19);
            cout << "3. Mis Productos\n";
            Console::SetCursorPosition(18, 21);
            cout << "4. Modificar productos\n";
            Console::SetCursorPosition(18, 23);
            cout << "5. Salir\n";
            Console::SetCursorPosition(10, 25);
            cout << "Selecciona una opcion ingresando el numero\n\n";
            Console::SetCursorPosition(10, 26);
            cout << "Opcion: ";
            cin >> this->opcion;
            validarOpcion();
            resultadosOpcionSeleccionada();
            system("pause>0");
        } while (this->opcion != '5');
        this->vendedorAux = nullptr;
        Console::SetCursorPosition(20, 29);
        cout << "SESION CERRADA\n";
        Console::SetCursorPosition(14, 32);
        Console::ForegroundColor = ConsoleColor::Blue;
        cout << "Presiona ENTER para volver";
        system("pause>0");
    }

    void resultadosOpcionSeleccionada() {
        switch (this->opcion) {
        case '1': {
            system("cls");
            this->vendedorAux->mostrarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '2': {
            system("cls");
            this->vendedorAux->actualizarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '3': {
            system("cls");
            this->vendedorAux->mostrarMisProductos();
            this->opcion = '0';
            break;
        }
        case '4': {
            system("cls");
            this->vendedorAux->opcionesMisProductos();
            this->opcion = '0';
            break;
        }
        case '5': {
            this->vendedorAux->actualizarDatosSesionATxt();
            this->vendedorAux->actualizarDatosProductosTxt();
            break;
        }
        }
    }
};