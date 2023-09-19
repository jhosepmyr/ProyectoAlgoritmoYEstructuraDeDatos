#pragma once
#include <iostream>
using namespace std;

class Producto {
protected:
	int id;
	string Nombre;
	int precio;
public:
	Producto() :id(0), Nombre(" "), precio(0) {};
	Producto(int id, string Nombre, int precio) :id(id), Nombre(Nombre), precio(precio) {};
	~Producto() {};

	void mostrarDatos() {
		cout << "\n---------------------------";
		cout << "\nID: " << id;
		cout << "\nNombre: " << Nombre;
		cout << "\nPrecio: " << precio;
	}
	void ModificarID(int n) { id = n; }
	void ModificarNombre(string nm) { Nombre = nm; }
	void ModificarPrecio(int pr) { precio = pr; }

	int getID() { return id; }
	string getNombre() { return Nombre; }
	int getPrecio() { return precio; }
};
//template <class T, >
//T cambiardatos(T objeto,) {
//	objeto->
//}