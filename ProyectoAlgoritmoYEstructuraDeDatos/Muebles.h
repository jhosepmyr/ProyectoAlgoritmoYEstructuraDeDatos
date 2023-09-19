#pragma once
#include "Producto.h"
class Muebles : public Producto {
private:
	string armado;
	string textura;
public:
	Muebles() { armado = " "; };
	Muebles(int id, string Nombre, int precio, string armado, string textura) :Producto(id, Nombre, precio)
	{
		this->armado = armado;
		this->textura = textura;
	};
	~Muebles() {};
	void MostrarMueble() {
		mostrarDatos();
		cout << "\nTextrura:" << textura; //Rugoso, suave, etc.
		cout << "\nRequiere Armado: " << armado;//si el producto ya viene armado o no
	}
	void modificarArmado(string armado) { this->armado = armado; }
	string getArmado() { return armado; }
	void modificarTextura(string textura) { this->textura = textura; }
	string getTextura() { return textura; }
};