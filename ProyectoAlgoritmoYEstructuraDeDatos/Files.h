#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Lista.h"
#include "Producto.h"
using namespace std;

class Files {
	//Se pasara los datos de txt a sus clases respectivas
private:
	string nombreUsuario;
	string apellidoUsuario;
public:
	Files() {};
	Files(string nombre, string apellido) {
		this->nombreUsuario = nombre;
		this->apellidoUsuario = apellido;
	}

	//getNombreArchivoPropio-> no se utiliza en nada por ahora
	string getNombreArchivoPropio() {
		// Ruta relativa desde la ubicación del archivo Files.h hasta la carpeta de Archivos
		string nombreArchivoPropio = "InformacionUsuarios/" + this->nombreUsuario + this->apellidoUsuario + ".txt";
		// Intentar abrir el archivo en modo lectura
		ifstream archivoEntrada(nombreArchivoPropio);

		if (archivoEntrada.is_open()) {
			archivoEntrada.close();
			//cout << "El archivo existe." << endl;
		}
		else {
			// El archivo no existe, crearlo
			ofstream archivoSalida(nombreArchivoPropio, std::ios::out);

			if (archivoSalida.is_open()) {
				archivoSalida.close();
				//cout << "El archivo no existía y ha sido creado." << endl;
			}
			else {
				cout << "Error al crear el archivo." << endl;
			}
		}
		return nombreArchivoPropio;
	}

	Lista<Producto> getProductos(string datosProductos = "DatosProductos.txt") {
		Lista<Producto> auxList;
		ifstream archivo(datosProductos);
		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				auto parseLine = [&]() {
					istringstream iss(linea);
					string nombre, tipo, identificador, codigoVendedor;
					int precio;
					iss >> nombre >> precio >> tipo >> identificador >> codigoVendedor;
					return Producto(nombre, precio, tipo, identificador, codigoVendedor);
				};
				Producto product = parseLine();
				auxList.agregaFinal(product);
			}
			archivo.close();
		}
		else {
			cerr << "Error al abrir el archivo." <<endl;
		}
		return auxList;
	}

	void actualizarProductosTxt(Lista<Producto> productos, string datosProductos = "DatosProductos.txt") {
		ofstream archivoEscritura(datosProductos);
		if (!archivoEscritura.is_open()) {
			cout << "Error al abrir el archivo " << endl;
			return;
		}

		auto createLine = [](Producto producto) {
			return producto.getNombre() + " " +
				to_string(static_cast<int>(producto.getPrecio())) + " " +
				producto.getTipo() + " " +
				producto.getIdentificador() + " " +
				producto.getCodigoVendedor();
		};

		for (int n = 0; n < productos.longitud(); ++n) {
			// Escribir la línea en el nuevo formato
			archivoEscritura << createLine(productos.obtenerPos(n)) << endl;
		}

		archivoEscritura.close();
	}
};
