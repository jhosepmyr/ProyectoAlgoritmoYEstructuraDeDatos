#pragma once
#include <iostream>
using namespace std;

class Producto {
protected:
	int id;
	string Nombre;
	double precio;
	string material;
	string estado;
	int t_vida;//tiempo de vida 
public:
	Producto() :id(0), Nombre(" "), precio(0), material(" "), estado(" "), t_vida(0) {};
	Producto(int id, string Nombre, int precio, string material, string estado, int t_vida) :
		id(id), Nombre(Nombre), precio(precio), material(material), estado(estado), t_vida(t_vida) {};
	~Producto() {};

	void mostrarDatos() {
		cout << "\n---------------------------";
		cout << "\nID: " << id;
		cout << "\nNombre: " << Nombre;
		cout << "\nPrecio: " << precio;
		cout << "\nMaterial: " << material;
		cout << "\nEstado: " << estado;
		cout << "\nTiempo estimado de vida: " << t_vida;

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
