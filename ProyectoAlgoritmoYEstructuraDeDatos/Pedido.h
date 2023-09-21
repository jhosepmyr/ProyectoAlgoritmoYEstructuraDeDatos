#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;

class Pedido {
	private:
	string nombreArchivoPedido;
	Lista<Producto> carrito;
public:

void agregaraCarrito(Producto aux){
	carrito.agregaFinal(aux);
}
void mostrarPila() {
}

};