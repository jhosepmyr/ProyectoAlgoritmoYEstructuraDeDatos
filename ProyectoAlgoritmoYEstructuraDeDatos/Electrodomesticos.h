#pragma once
#include "Producto.h"
#include "Files.h"
using namespace std;
class Electrodomesticos : public Producto {
private:
	string estado;
	int t_vida;//tiempo de vida 
public:
	Electrodomesticos() : Producto() {
		estado = " ";
		t_vida = 0;
	};
	Electrodomesticos(int id, string Nombre, int precio, string estado, int t_vida) :Producto(id, Nombre, precio)
	{
		this->estado = estado;
		this->t_vida = t_vida;
	};
	~Electrodomesticos() {};
	void MostrarED() {
		mostrarDatos();
		cout << "\nEstado: " << estado;
		cout << "\nTiempo estimado de vida: " << t_vida << " años";
	}
	void modificarEstado(string estado) { this->estado = estado; }
	string getEstado() { return estado; }
};