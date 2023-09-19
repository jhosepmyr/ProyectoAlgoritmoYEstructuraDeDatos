#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

class Files {
	//Se pasara los datos de txt a sus clases respectivas
private:
	//Atributos
	ofstream fileWrite;
	ifstream fileRead;
	int n, n2;
	int* IDs; int* IDs2;
	string texto;
	string* Nombres; string* Nombres2;
	double* Precios; double* Precios2;
	string* estado;  string* armado; string* textura;
	int* t_vidas;
	bool pase;
public:

	Files() {
		n2 = n = 3; IDs = new int[n]; Nombres = new string[n]; Precios = new double[n];
		estado = new string[n]; t_vidas = new int[n]; IDs2 = new int[n]; Nombres2 = new string[n];
		Precios2 = new double[n]; armado = new string[n]; textura = new string[n]; pase = false;
	}

	~Files() {}

	void DatosELEC() {

		fileRead.open("ELECTRODOM.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();


			fileWrite.open("ELECTRODOM.txt", ios::out);
			fileWrite << "Pulidora Smart - SAMSUNG" << endl; //nombre
			fileWrite << "342134" << endl; //ID
			fileWrite << "1534.76" << endl;  //Precio
			fileWrite << "Nuevo" << endl; //estado
			fileWrite << "6" << endl; //tiempo de vida

			fileWrite << "Microondas - TOSHIBA" << endl;
			fileWrite << "2428841" << endl;
			fileWrite << "677.99" << endl;
			fileWrite << "Usado" << endl;
			fileWrite << "3" << endl; //tiempo de vida

			fileWrite << "Lavadora CLEANITALL - LG " << endl;
			fileWrite << "3424234" << endl;
			fileWrite << "789.99" << endl;
			fileWrite << "Usado" << endl;
			fileWrite << "10" << endl; //tiempo de vida

			fileWrite.close();

			fileRead.open("ELECTRODOM.txt", ios::in);
		}
		//pasar lineas txt a data types 
		for (int i = 0; i < n; i++) {
			getline(fileRead, texto);
			Nombres[i] = (texto.c_str());
			getline(fileRead, texto);
			IDs[i] = atoi(texto.c_str());
			getline(fileRead, texto);
			Precios[i] = atoi(texto.c_str());
			getline(fileRead, texto);
			estado[i] = (texto.c_str());
			getline(fileRead, texto);
			t_vidas[i] = atoi(texto.c_str());
		}
		fileRead.close();
	}

	void DatosMUEBLES() {

		fileRead.open("MUEBLES.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();


			fileWrite.open("MUEBLES.txt", ios::out);
			fileWrite << "CAMA SIZEKING" << endl; //nombre
			fileWrite << "324453" << endl; //ID
			fileWrite << "984.5" << endl;  //Precio
			fileWrite << "SI" << endl; //ARMADO
			fileWrite << "Suave" << endl; //textura

			fileWrite << "SOFA PARA CUATRO" << endl;
			fileWrite << "54365653" << endl;
			fileWrite << "654.99" << endl;
			fileWrite << "SI" << endl;
			fileWrite << "Sedoza" << endl;

			fileWrite << "MESA GAMER 80 x 41 x 48cm " << endl;
			fileWrite << "424342" << endl;
			fileWrite << "123.89" << endl;
			fileWrite << "NO" << endl;
			fileWrite << "Rugoso" << endl;

			fileWrite.close();

			fileRead.open("MUEBLES.txt", ios::in);
		}
		//pasar lineas txt a data types 
		for (int i = 0; i < n; i++) {
			getline(fileRead, texto);
			Nombres2[i] = (texto.c_str());
			getline(fileRead, texto);
			IDs2[i] = atoi(texto.c_str());
			getline(fileRead, texto);
			Precios2[i] = atoi(texto.c_str());
			getline(fileRead, texto);
			armado[i] = (texto.c_str());
			getline(fileRead, texto);
			textura[i] = (texto.c_str());

		}
		fileRead.close();
	}

	//TODA ESTA SECCION PARA ELECTRODOM
	//Gets
	string getNombre(int n) { return Nombres[n]; }
	double getPrecios(int n) { return Precios[n]; }
	int getIDs(int n) { return IDs[n]; }
	string getEstado(int n) { return estado[n]; }
	int getN() { return n; }
	int getTVIDAS(int n) { return t_vidas[n]; }
	//agregar elemento al txt
	void aumentaCantidad() { n++; }
	//AÑADIR PRODUCTO ELECTRODOMESTICOS
	void AgregarProducto(string nombre, int ID, int precio, string Estado, int t_vida) {
		aumentaCantidad();
		Nombres[n - 1] = nombre;  IDs[n - 1] = ID; Precios[n - 1] = precio; this->estado[n - 1] = Estado; this->t_vidas[n - 1] = t_vida;
		fileWrite.open("ELECTRODOM.txt", ios::out);
		if (fileWrite.is_open()) {
			fileWrite << nombre << endl;
			fileWrite << ID << endl;
			fileWrite << precio << endl;
			fileWrite << Estado << endl;
			fileWrite << t_vida << endl;
			fileWrite.close();
		}
	}

	//TODA ESTA SECCION PARA MUEBLES 
	//Gets
	string getNombre2(int n) { return Nombres2[n]; }
	double getPrecios2(int n) { return Precios2[n]; }
	int getIDs2(int n) { return IDs2[n]; }
	string getArmado(int n) { return armado[n]; }
	string geTextura(int n) { return textura[n]; }
	int getN2() { return n2; }
	//agregar elemento al txt
	void aumentaCantidad2() { n2++; }
	//AÑADIR PRODUCTO ELECTRODOMESTICOS
	void AgregarProducto2(string nombre, int ID, int precio, string textura, string armado) {
		aumentaCantidad2();
		Nombres2[n - 1] = nombre;  IDs2[n - 1] = ID; Precios2[n - 1] = precio;  this->textura[n - 1] = textura;
		this->armado[n - 1] = armado;
		fileWrite.open("MUEBLES.txt", ios::out);
		if (fileWrite.is_open()) {
			fileWrite << nombre << endl;
			fileWrite << ID << endl;
			fileWrite << precio << endl;
			fileWrite << armado << endl;
			fileWrite << textura << endl;
			fileWrite.close();
		}
	}


};