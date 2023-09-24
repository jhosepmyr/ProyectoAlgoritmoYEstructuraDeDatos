#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Producto {
protected:
	string Nombre;
	double precio;
	string tipo;
	string identificador;//"nombrevendedor+sucontrasena" UNICO NO SE CAMBIA
public:
	Producto() {};
	Producto(string _nombre, double _precio, string _tipo, string _identificador) {
		this->Nombre = _nombre;
		this->precio = _precio;
		this->tipo = _tipo;
		this->identificador = _identificador;
	}
	void mostrarDatos() {
		cout << "\n---------------------------";
		cout << "\nID: " << this->identificador;
		cout << "\nNombre: " << this->Nombre;
		cout << "\nPrecio: " << this->precio;
		cout << "\nTipo: " << this->tipo;
	}
	void mostrarDatosLinea() {

		cout << "Nombre: " << this->Nombre << ", Precio: " << this->precio << ", Tipo: " << this->tipo << ", ID: " << this->identificador<<endl;
	}
	void setNombre(string nombre) {
		this->Nombre = nombre;
	}
	string getNombre() {
		return this->Nombre;
	}
	void setPrecio(float precio) {
		this->precio = precio;
	}
	double getPrecio() {
		return this->precio;
	}
	void setTipo(string tipo) {
		this->tipo = tipo;
	}
	string getTipo() {
		return this->tipo;
	}
	string getIdentificador() {
		return this->identificador;
	}

};
