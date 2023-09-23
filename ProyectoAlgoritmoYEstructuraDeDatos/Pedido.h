#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;

class Pedido {
private:
	string nombreArchivoPedido;
	Lista<Producto> carritoCompras;
	int precioTotal;
public:
	string getNombreArchivo() {
		return this->nombreArchivoPedido;
	}

	void setNombreArchivoPedido(string _nombre) {
		this->nombreArchivoPedido = _nombre;
	}

	void agregaraCarrito(Producto aux){
		this->carritoCompras.agregaFinal(aux);
	}

	void mostrarListaProductos() {
		cout << "\n---------------------------------\n";
		cout << this->nombreArchivoPedido<<endl;
		this->carritoCompras.MostrarDatosPROD();
		cout << "\n---------------------------------\n";
	}

	int getCantidadProductosCarrito() {
		return this->carritoCompras.longitud();
	}

	int getPrecioTotal() {
		this->precioTotal = 0;
		for (int i = 0; i < this->carritoCompras.longitud(); i++)
		{
			precioTotal += this->carritoCompras.obtenerPos(i).getPrecio();
		}
		return this->precioTotal;
	}

	void eliminarProductos() {
		for (int i = 0; i < this->carritoCompras.longitud(); i++)
		{
			this->carritoCompras.eliminaInicial();
		}
	}

	string getIdPorProducto(int posi) {
		return this->carritoCompras.obtenerPos(posi).getIdentificador();
	}

	Producto getProductoPorPosicion(int pos) {
		return this->carritoCompras.obtenerPos(pos);
	}
};