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
			cout << "El archivo existe." << endl;
		}
		else {
			// El archivo no existe, crearlo
			ofstream archivoSalida(nombreArchivoPropio, std::ios::out);

			if (archivoSalida.is_open()) {
				archivoSalida.close();
				cout << "El archivo no existía y ha sido creado." << endl;
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
				string nombre, tipo, identificador;
				float precio;
				// Utiliza algún método de procesamiento de cadena para separar los valores
				// de la línea, por ejemplo, asumiendo que los valores están separados por espacios:
				istringstream iss(linea);
				iss >> nombre >> precio >> tipo >> identificador;
				// Crea un nuevo objeto Producto y agrégalo al vector
				Producto product(nombre, precio, tipo, identificador);
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
		ifstream archivo(datosProductos);
		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo " << endl;
			return;
		}
		string contenidoArchivo;
		string linea;
		int n = 0;

		while (n < productos.longitud()) {
			string nuevaLinea = productos.obtenerPos(n).getNombre() + " " +
								to_string(productos.obtenerPos(n).getPrecio()) + " " +
								productos.obtenerPos(n).getTipo() + " " +
								productos.obtenerPos(n).getIdentificador();
			contenidoArchivo += nuevaLinea + "\n";
			n++;
		}
		archivo.close();
		ofstream archivoEscritura(datosProductos);
		archivoEscritura << contenidoArchivo;
		archivoEscritura.close();
	}
};
