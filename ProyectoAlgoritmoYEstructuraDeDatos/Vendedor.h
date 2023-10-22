#pragma once
#include <iostream>
#include "Usuario.h"
#include <random>
#include <set>

using namespace std;

class Vendedor : public Usuario {
private:
    Lista<Producto> productosPropios;

public:
    Vendedor(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->datosInicioSesion = "DatosSesionVendedores.txt";
        getInformacionPersonalTxt();
    }

    // Generar un ID aleatorio de 7 cifras alfanuméricas sin repeticiones
    string generarIDUnico() {
        string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(0, caracteres.size() - 1);
        set<string> IDsExistentes;

        while (true) {
            string nuevoID;
            for (int i = 0; i < 7; i++) {
                nuevoID += caracteres[distribution(generator)];
            }

            // Verificar que el nuevo ID no se repita en el archivo TXT
            if (!existeIDEnArchivo(nuevoID, "DatosProductos.txt")) {
                return nuevoID;
            }
        }
    }
    // Verificar que el ID no se repita en el archivo de productos

    bool existeIDEnArchivo(const string& id, const string& rutaTxt) {
        ifstream archivo(rutaTxt);
        string linea;
        while (getline(archivo, linea)) {
            // Parsear la línea para obtener el ID (asumiendo el formato "nombre precio tipo idUnico codigoVendedor")
            string token;
            istringstream ss(linea);
            ss >> token >> token >> token >> token;  // Saltar nombre, precio y tipo
            if (token == id) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

    void setProductosPropios() {
        //string auxID = this->nombre + this->contra;
        string auxID = this->ID;
        for (int i = 0; i < productos.longitud(); i++) {
            string codigoProducto = productos.obtenerPos(i).getCodigoVendedor();
            if (codigoProducto == auxID) {
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
        string identificador = generarIDUnico();
        system("cls");
        cout << "Ingresar datos de producto.\n";
        cout << "Nombre: "; cin >> Nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Tipo (comestible | noComestible): "; cin >> tipo;

        Producto aux(Nombre, precio, tipo, identificador, this->ID);

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
        this->productos.eliminarporID(id);
    }

    void modificarProducto() {
        string id;
        string nombre;
        int precio;
        string tipo;
        //system("cls");
        cout << "\nIngresar el identificador del producto a modificar.\n";
        cout << "ID:"; 
        cin >> id;
        if (this->productosPropios.existeID(id,1))
        {
            Producto auxProduct = this->productosPropios.buscarporID(id, 1);
            this->productosPropios.eliminarporID(id);
            this->productos.eliminarporID(id);
            cout << "\nIngresar el nuevo nombre\n";
            cin >> nombre;
            auxProduct.setNombre(nombre);
            cout << "\nIngresar el nuevo precio\n";
            cin >> precio;
            auxProduct.setPrecio(precio);
            cout << "\nIngresar el nuevo tipo\n";
            cin >> tipo;
            auxProduct.setTipo(tipo);
            this->productosPropios.agregaFinal(auxProduct);
            this->productos.agregaFinal(auxProduct);
        }
        else
        {
            cout << "\nNo se puedo encontrar el ID ingresado.\n";
        }
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