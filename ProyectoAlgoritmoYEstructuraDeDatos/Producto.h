#pragma once
#include <iostream>
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







	//protected:
	//	int id;
	//	string material;
	//	string estado;
	//	int t_vida;//tiempo de vida 
	//
	//public:
	//	//Producto() :id(0), Nombre(" "), precio(0), material(" "), estado(" "), t_vida(0) {};
	//	Producto() :id(1243), Nombre("Leche"), precio(5), material("comestible"), estado("liquido"), t_vida(2) {};
	//	Producto(int id, string Nombre, int precio, string material, string estado, int t_vida) :
	//		id(id), Nombre(Nombre), precio(precio), material(material), estado(estado), t_vida(t_vida) {};
	//	~Producto() {};
	//	void ModificarID(int n) { id = n; }
	//	void ModificarNombre(string nm) { Nombre = nm; }
	//	void ModificarPrecio(int pr) { precio = pr; }
	//	
	//	int getID() { return id; }
};
