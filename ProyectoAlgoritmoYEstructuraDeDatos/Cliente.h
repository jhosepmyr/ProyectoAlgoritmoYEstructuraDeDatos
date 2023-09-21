#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Pedido.h"
#include "Pila.h"

using namespace std;

class Cliente : public Usuario {
private:
    string nombreArchivoClienteEspecifico; //implementar con el ID Ejem: cliente10.txt
    Pedido pedido;
    Pila<Pedido> pedidos;
public:
    Cliente(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->datosInicioSesion = "DatosSesionClientes.txt";
    }

    void mostrarProductos() {
        char opc = '0';
        do
        {
            system("cls");
            //muestra producto actualizados
            this->productos.MostrarDatosPROD();
            cout << endl << "Desea agregar algun elemento al carrito(1:SI, 2: NO):";
            cin >> opc;
            if (opc == '1') {
                string identificadorAux = "";
                cout << "Elija el producto que desea agregar al carrito(INGRESE EL ID):";
                cin >> identificadorAux;
                //se busca de la lista de productos por identificar y lo retorna
                Producto productoAux = this->productos.buscarporID(identificadorAux);
                //el producto retornado se agrega al unico pedido
                this->pedido.agregaraCarrito(productoAux);
                //el pedido se agrega a la pila pedidos
                this->pedidos.push(pedido);
                this->productos.eliminarporID(identificadorAux);
            }
        } while (opc!='2');

    }
};