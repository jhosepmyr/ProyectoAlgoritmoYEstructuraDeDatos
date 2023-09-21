#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;

class Pedido {
	private:
	string nombreArchivoPedido;
	Lista<Producto> carritoCompras;
public:

void agregaraCarrito(Producto aux){
	this->carritoCompras.agregaFinal(aux);
}
void mostrarPila() {
	this->carritoCompras.MostrarDatosPROD();
}
};