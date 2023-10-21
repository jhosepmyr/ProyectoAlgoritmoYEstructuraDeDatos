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
	string codigoVendedor;
public:
	Producto() {};
	Producto(string _nombre, int _precio, string _tipo, string _identificador, string _codigoVendedor) {
		this->Nombre = _nombre;
		this->precio = _precio;
		this->tipo = _tipo;
		this->identificador = _identificador;
		this->codigoVendedor = _codigoVendedor;

	}
	void mostrarDatos() {
		cout << "\n---------------------------";
		cout << "\nCodigo Vendedor: " << this->codigoVendedor;
		cout << "\nID: " << this->identificador;
		cout << "\nNombre: " << this->Nombre;
		cout << "\nPrecio: " << this->precio;
		cout << "\nTipo: " << this->tipo;
	}
	void mostrarDatosLinea() {
		// Utilizar una función lambda para formatear la salida
		auto formatLine = [this]() {
			cout << "Nombre: " << this->Nombre << ", Precio: " << this->precio << ", Tipo: " << this->tipo << ", ID: " << this->identificador << ", Codigo Vendedor: " << this->codigoVendedor << endl;
		};
		formatLine();
	}
	void setNombre(string nombre) {
		this->Nombre = nombre;
	}
	string getNombre() {
		return this->Nombre;
	}
	void setPrecio(int precio) {
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
	string getCodigoVendedor() {
		return this->codigoVendedor;
	}

};
