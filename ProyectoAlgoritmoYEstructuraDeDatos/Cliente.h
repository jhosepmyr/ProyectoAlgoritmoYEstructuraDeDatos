#pragma once
#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Pedido.h"

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
                this->productos.eliminarporID(identificadorAux);
            }
        } while (opc!='2');

        this->pedidos.push(pedido);
    }

    void mostrarPedido() {
        this->pedido.mostrarPila();
    }

	/*void actualizarDatosSesion(string rutaArchivoDatos, Cliente persona) {
		ifstream archivoLectura(rutaArchivoDatos);
		string contenidoArchivo;
		if (archivoLectura.is_open())
		{
			string linea;

			while (getline(archivoLectura, linea))
			{
				bool verificarNombre = linea.find(persona.getNombre()) != string::npos;
				bool verificarContra = linea.find(persona.getContra()) != string::npos;
				if (verificarContra && verificarNombre)
				{
					string nuevaLinea = persona.getNombre() + " " +
						persona.getContra() + " " +
						persona.getApellido() + " " +
						persona.getCorreoElectronico() + " " +
						to_string(persona.getNumeroCelular()) + " " +
						persona.getDireccion() + " " +
						to_string(persona.getGenero()) + " " +
						to_string(persona.getDNI());
					contenidoArchivo += nuevaLinea + "\n";
				}
				else
				{
					contenidoArchivo += linea + "\n";
				}
			}
			archivoLectura.close();
			ofstream archivoEscritura(rutaArchivoDatos);
			archivoEscritura << contenidoArchivo;
			archivoEscritura.close();

			//cout << "Datos actualizados en el archivo exitosamente." <<endl;
		}
		else {
			//cerr << "Error al abrir el archivo para lectura." <<endl;
		}
	}*/
};