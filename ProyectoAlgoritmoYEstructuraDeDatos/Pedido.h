#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;

class Pedido {
private:
	string nombrePedido;
	Lista<Producto> carritoCompras;
	int precioTotal;
public:
	Pedido() {

	}
	string getNombrePedido() {
		return this->nombrePedido;
	}

	void setNombrePedido(string _nombre) {
		this->nombrePedido = _nombre;
	}

	void agregaraCarrito(Producto aux){
		this->carritoCompras.agregaFinal(aux);
	}

	bool isVacio() {
		return this->carritoCompras.esVacia();
	}

	void mostrarListaProductos() {
		if (!this->carritoCompras.esVacia())
		{
			cout << endl << "----------------------------------------------------------------------------------------";
			cout << endl << "Codigo de pedido: " << this->nombrePedido << endl;
			cout << endl << "Numero de productos: " << getCantidadProductosCarrito() << endl;
			cout << endl;
			this->carritoCompras.MostrarDatosPRODLinea();
			cout << endl;
			cout << "Costo total: S/." << to_string(getPrecioTotal()) << endl;
			cout << endl << "----------------------------------------------------------------------------------------";
			cout << endl;
		}
		else
		{
			cout << "No tienes ningun producto\n";
		}
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
		if (!this->carritoCompras.esVacia())
		{
			this->carritoCompras.eliminarTodos();
		}
	}

	string getIdPorProducto(int posi) {
		return this->carritoCompras.obtenerPos(posi).getIdentificador();
	}

	Producto getProductoPorPosicion(int pos) {
		return this->carritoCompras.obtenerPos(pos);
	}

	Producto eliminarUltimoProducto() {
		Producto auxProducto = this->carritoCompras.eliminarUltimo();
		return auxProducto;
	}
};