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
				Producto* product = new Producto(nombre, precio, tipo, identificador);
				auxList.agregaFinal(*product);
			}
			archivo.close();
		}
		else {
			cerr << "Error al abrir el archivo." <<endl;
		}
		return auxList;
	}
//private:
//	//Atributos
//	ofstream fileWrite;
//	ifstream fileRead;
//	int n;
//	int* IDs;
//	string texto;
//	string* Nombres;
//	double* Precios;
//	string* estado;
//	string* material;
//	int* t_vidas;
//public:
//	Files() {
//		n = ContarPROCUCTOSFILE(); IDs = new int[n]; Nombres = new string[n]; Precios = new double[n];
//		estado = new string[n]; material = new string[n]; t_vidas = new int[n];
//	}
//	int ContarPROCUCTOSFILE() {//CONTAR LINEAS DEL FILE ENTRE PARAMETROS IGUAL A CANTIDAD DE PROCUTOS 
//		fileRead.open("Productos.txt", ios::in);
//		if (fileRead.is_open()) {
//			string line;
//			int lineCount = 0;
//
//			while (getline(fileRead, line)) {
//				lineCount++;
//			}
//			return (lineCount/6);
//		}
//	}
//
//	void DatosProductos() {
//
//		fileRead.open("Productos.txt", ios::in);
//
//		if (fileRead.fail()) {
//			fileRead.close();
//
//			fileWrite.open("Productos.txt", ios::out);
//			fileWrite << "Pulidora Smart - SAMSUNG" << endl; //nombre
//			fileWrite << "342134" << endl; //ID
//			fileWrite << "1534.76" << endl;  //Precio
//			fileWrite << "Nuevo" << endl; //estado
//			fileWrite << "Acero" << endl;//material
//			fileWrite << "6" << endl; //tiempo de vida
//                        
//			fileWrite << "Microondas - TOSHIBA" << endl;
//			fileWrite << "2428841" << endl;
//			fileWrite << "677.99" << endl;
//			fileWrite << "Usado" << endl;
//			fileWrite << "Metal Pulido" << endl;
//			fileWrite << "3" << endl; //tiempo de vida
//
//			fileWrite << "Lavadora CLEANITALL - LG " << endl;
//			fileWrite << "3424234" << endl;
//			fileWrite << "789.99" << endl;
//			fileWrite << "Usado" << endl;
//			fileWrite << "Metal Ferroso" << endl;
//			fileWrite << "10" << endl; //tiempo de vida
//
//			fileWrite << "CAMA SIZEKING" << endl; //nombre
//			fileWrite << "324453" << endl; //ID
//			fileWrite << "984.5" << endl;  //Precio
//			fileWrite << "Nuevo" << endl; //estado
//			fileWrite << "Tela de Punto" << endl; //material
//			fileWrite << "5 años" << endl; //tiempo de vida
//
//			fileWrite << "SOFA PARA CUATRO" << endl;
//			fileWrite << "54365653" << endl;
//			fileWrite << "654.99" << endl;
//			fileWrite << "Nuevo" << endl;
//			fileWrite << "Tela" << endl; //material
//			fileWrite << "20 años" << endl; //tiempo de vida
//
//			fileWrite << "MESA GAMER 80 x 41 x 48cm " << endl;
//			fileWrite << "424342" << endl;
//			fileWrite << "123.89" << endl;
//			fileWrite << "Usado" << endl;
//			fileWrite << "Madera Pulida" << endl; //material
//			fileWrite << "10 años" << endl; //tiempo de vida
//
//			fileWrite.close();
//
//			fileRead.open("Productos.txt", ios::in);
//		}
//	   //pasar lineas txt a data types 
//		for (int i = 0; i < n; i++) {
//
//			getline(fileRead, texto);
//			Nombres[i] = (texto.c_str());
//			getline(fileRead, texto);
//			IDs[i] = atoi(texto.c_str());
//			getline(fileRead, texto);
//			Precios[i] = atoi(texto.c_str());
//			getline(fileRead, texto);
//			estado[i] = (texto.c_str());
//			getline(fileRead, texto);
//			material[i] = (texto.c_str());
//			getline(fileRead, texto);
//			t_vidas[i] = atoi(texto.c_str());
//
//		};
//		fileRead.close();
//	}
//
//
//	//TODA ESTA SECCION PARA ELECTRODOM
//	//Gets
//	string getNombre(int n) { return Nombres[n]; }
//	double getPrecios(int n) { return Precios[n]; }
//	int getIDs(int n) { return IDs[n]; }
//	string getEstado(int n) { return estado[n]; }
//	string getMaterial(int n) { return material[n]; }
//	int getN() { return n; }
//	int getTVIDAS(int n) { return t_vidas[n]; }
//	//agregar elemento al txt
//	void aumentaCantidad() { n++; }
//	//AÑADIR PRODUCTO ELECTRODOMESTICOS
//	void AgregarProducto(string nombre, int ID, int precio, string Estado, string material, int t_vida) {
//		aumentaCantidad();
//		Nombres[n - 1] = nombre;  IDs[n - 1] = ID; Precios[n - 1] = precio; this->estado[n - 1] = Estado;
//		this->material[n-1] = material; this->t_vidas[n - 1] = t_vida;
//		fileWrite.open("Productos.txt", ios::out);
//		if (fileWrite.is_open()) {
//			fileWrite << nombre << endl;
//			fileWrite << ID << endl;
//			fileWrite << precio << endl;
//			fileWrite << Estado << endl;
//			fileWrite << material << endl;
//			fileWrite << t_vida << endl;
//			fileWrite.close();
//		}
//	}
};
