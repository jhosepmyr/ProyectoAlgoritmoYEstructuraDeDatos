#pragma once
#include "Interfaz.h"
#include "Login.h"
#include "conio.h"
#include "Cola.h"
#include "Grafo.h"
#include "HashTable.h"
#include "Sucursal.h"
#define ABAJO 80
#define ARRIBA 72

using namespace std;

class InterfazLogin : public Interfaz {
private:
    Login *login;
    HashTabla<Grafo>grfs;
    Grafo gp[3];
    vector<string>keys = { "Peru", "Chile", "Argentina" };
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
            cout << "Mostrar conexion entre sucursales\n";
            Console::SetCursorPosition(17, 22);
            cout << "Salir";
            Console::SetCursorPosition(9, 24);
            cout << "Selecciona una opcion moviendo la flecha\n";
            Console::SetCursorPosition(19, 26);
            cout << "PRESIONA ENTER";
            int y = 12;
            while (true) {
                //borrar
                Console::SetCursorPosition(41, y); cout << "  ";
                //mover
                if (_kbhit()) {
                    char tecla = getch();
                    if (tecla == ABAJO && y < 22) y += 2;
                    if (tecla == ARRIBA && y > 12) y -= 2;
                    if (tecla == 13) {
                        if (y == 12) opcion = '1';
                        if (y == 14) opcion = '2';
                        if (y == 16) opcion = '3';
                        if (y == 18) opcion = '4';
                        if (y == 22) opcion = '5';
                        if (y == 20)opcion = '6';
                        break;
                    }
                }
                Console::SetCursorPosition(41, y); cout << "<-";
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
        } while (this->opcion!= '5');

        Console::SetCursorPosition(20, 30);
        cout << "REGRESE PRONTO\n";
    }
   
    void setGrafos() {
        for (int i = 0; i < 3; i++) {
            //Agregar vertices
            if (i == 0) {
                gp[i].agregar_vertice(0, "GuruShop-Miraflores");
                gp[i].agregar_vertice(1, "GuruShop-Lima");
                gp[i].agregar_vertice(2, "GuruShop-Rimac");
                gp[i].agregar_vertice(3, "GuruShop-Monterrico");
                gp[i].agregar_vertice(4, "GuruShop-Lince");
            }
            if (i == 1) {
                gp[i].agregar_vertice(0, "GuruShop-Providencia");
                gp[i].agregar_vertice(1, "GuruShop-Macul");
                gp[i].agregar_vertice(2, "GuruShop-Quilicura");
                gp[i].agregar_vertice(3, "GuruShop-Pudahuel");
                gp[i].agregar_vertice(4, "GuruShop-Huechuraba");
            }
            if (i == 2) {
                gp[i].agregar_vertice(0, "GuruShop-Palermo");
                gp[i].agregar_vertice(1, "GuruShop-Belgrano");
                gp[i].agregar_vertice(2, "GuruShop-Recoleta");
                gp[i].agregar_vertice(3, "GuruShop-Caballito");
                gp[i].agregar_vertice(4, "GuruShop-Floresta");
            }
            //Crear conexiones aristas
            gp[i].agregar_arista(0, 1);
            gp[i].agregar_arista(1, 2);
            gp[i].agregar_arista(2, 3);
            gp[i].agregar_arista(3, 4);
            gp[i].agregar_arista(4, 0);
        }
        //Insertar en HashTable
        grfs.insertar(keys[0], gp[0]);
        grfs.insertar(keys[1], gp[1]);
        grfs.insertar(keys[2], gp[2]);
    }

    int opciones_grafos() {
        int opc = 0;
        cout << endl << "1.Mostrar conexion entre sedes de Lima - Peru";
        cout << endl << "2.Mostrar conexion entre sedes de Santiago - Chile";
        cout << endl << "3.Mostrar conexion entre sedes de Buenos Aires - Argentina";
        cout << endl << "4.Salir";
        cout << endl << ".Ingrese la opcion deseada: "; cin >> opc;
        if (opc > 4 || opc < 1) { system("cls"); return opciones_grafos(); }
        else return opc;
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
                system("cls");
                Console::SetCursorPosition(10, 10);
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
                system("pause");
                break;
            }
            case '4': {
                system("cls");
                Cola<string>* integrantes;
                integrantes = new Cola<string>();
                integrantes->enqueue("Jhosepmyr Orlando");
                integrantes->enqueue("Elmer Riva");
                integrantes->enqueue("Jose Martinez");
                Console::ForegroundColor = ConsoleColor::Green;
                Console::SetCursorPosition(21, 12);
                cout << "Los duenios son:";
                Console::SetCursorPosition(20, 14);
                integrantes->dequeue();
                Console::SetCursorPosition(24, 16);
                integrantes->dequeue();
                Console::SetCursorPosition(22, 18);
                integrantes->dequeue();
                Console::SetCursorPosition(14, 20);
                Console::ForegroundColor = ConsoleColor::Blue;
                cout << "Presiona ENTER para volver";
                this->opcion = '0';
                system("pause");
                break;
            }
            case'6': {
                system("cls");
                //Configurar Grafo y HashTable
                int op = 0;
                setGrafos();
                while (true) {
                    op = opciones_grafos();
                    if (op == 4) break;
                    system("cls");
                    grfs.imprimir_grafos(keys[op - 1]);
                    cout << endl;
                    cout << endl;
                    grfs.caminoMinimoEntreSucursales(keys[op - 1]);
                    system("pause");
                    system("cls");
                }
                this->opcion = '0';
                break;

            }

        }
    }
};