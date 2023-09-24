#pragma once
#include <iostream>
#include "Usuario.h"

using namespace std;

class Vendedor : public Usuario {
private:
    Lista<Producto> productosPropios;

public:
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->datosInicioSesion = "DatosSesionVendedores.txt";
        getInformacionPersonalTxt();
    }

    void setProductosPropios() {
        string auxID = this->nombre + this->contra;
        for (int i = 0; i < productos.longitud(); i++) {
            if (productos.obtenerPos(i).getIdentificador() == auxID) { //utiliza el id de producto (que es la username+id)
                Producto aux = productos.obtenerPos(i);
                productosPropios.agregaFinal(aux);
            }
        }
    }

    void mostrarMisProductos() {
        system("cls");
        productosPropios.MostrarDatosPROD();
        system("pause");
    }

    void opcionesMisProductos() {
        auto MENU = []() {
            cout << "MODIFICACION DE MIS PRODUCTOS " << endl;
            cout << "1. Agrega un nuevo producto\n";
            cout << "2. Modificar un producto\n";
            cout << "3. Elimina un producto\n";
            cout << "4. Salir\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            };
        do {
            system("cls");
            this->opcionUsuario = '0';
            MENU();
            cin >> this->opcionUsuario;
            //validarOpcion();
            system("cls");
            modificacionMisProductos();
            system("pause");
        } while (this->opcionUsuario != '4');
        system("pause>0");
        return;
    }

    void aniadirProducto() {
        string Nombre;
        double precio;
        string tipo;
        string identificador;
        system("cls");
        cout << "Ingresar datos de producto.\n";

        cout << "Nombre: "; cin >> Nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Tipo (comestible | noComestible): "; cin >> tipo;

        Producto aux(Nombre, precio, tipo, this->nombre + this->contra);

        productos.agregaFinal(aux);
        productosPropios.agregaFinal(aux);
        cin.get();
        cin.ignore();
    }

    void eliminarProducto() {
        string id;
        //system("cls");
        cout << "Ingresar el identificador del producto a eliminar.\n";
        cout << "ID:"; cin >> id;
        this->productosPropios.eliminarporID(id);
    }

    void modificarProducto() {
        string id;
        string nombre;
        int precio;
        string tipo;
        //system("cls");
        cout << "\nIngresar el identificador del producto a modificar.\n";
        cout << "ID:"; cin >> id;
        cout << "\nIngresar el nuevo nombre\n";
        cin >> nombre;
        this->productosPropios.buscarporID(id).setNombre(nombre);
        cout << "\nIngresar el nuevo precio\n";
        cin >> precio;
        this->productosPropios.buscarporID(id).setPrecio(precio);
        cout << "\nIngresar el nuevo tipo\n";
        cin >> tipo;
        this->productosPropios.buscarporID(id).setTipo(tipo);
    }

    void modificacionMisProductos() {
        switch (this->opcionUsuario)
        {
        case '1': {
            aniadirProducto();
            this->opcionUsuario = '0';
            break;
        }
        case '2': {
            mostrarMisProductos();
            modificarProducto();
            this->opcionUsuario = '0';
            break;
        }
        case '3': {
            mostrarMisProductos();
            eliminarProducto();
            this->opcionUsuario = '0';
            break;
        }
        }
    }
};