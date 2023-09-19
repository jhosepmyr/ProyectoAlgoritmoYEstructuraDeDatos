#pragma once
#include "Files.h"
#include"Lista.h"
#include "Pila.h"
#include "Producto.h"

using namespace std;
class Controller {
private:
	Files* fls;
	Lista<Producto>*lst;
	Pila<Producto> *carrito;

public:
	Controller() {
		fls = new Files();
		fls->DatosProductos();
		lst = new Lista<Producto>();		
		agregaDatosIniciales(0);
	};
	int agregaDatosIniciales(int n) {// aqui solo se agregaran los datos por default del txt
		lst->agregaInicial(Producto(fls->getIDs(n), fls->getNombre(n), fls->getPrecios(n),fls->getMaterial(n), fls->getEstado(n), fls->getTVIDAS(n)));
		n++;
		if (n < fls->getN()) { return agregaDatosIniciales(n); }
		else return 0;
	}

	void mostrarLSTPRDCTS() {
		lst->MostrarDatosPROD();
	}


	void agregarProducto(int ID, string Nombre, int Precios, string estado, string material, int t_vida) {
		fls->AgregarProducto(Nombre, ID, Precios, estado,material, t_vida);
		lst->agregaInicial(Producto(ID, Nombre, Precios, material ,estado, t_vida));
	}

	void agregar_a_Carrito(int ID) {
		carrito->push(lst->buscarporID(ID));
	}

	void Proceder_Compra() {

	}


};
