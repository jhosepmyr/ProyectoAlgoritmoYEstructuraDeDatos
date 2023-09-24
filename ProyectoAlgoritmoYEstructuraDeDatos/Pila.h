#pragma once
#include "Nodo.h"
using namespace std;

template <class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { 
		tope = nullptr; 
	}
	void push(T v);
	T pop();
	bool estaVacia();
	Nodo<T>* getTope();
	void mostrarTodosLosPedidos();
	
};

template <class T>
void Pila<T>::push(T v) {
	if (estaVacia()) tope = new Nodo<T>(v);
	else tope = new Nodo<T>(v, tope);
}

template <class T>
T Pila<T>::pop() {
	if (!estaVacia())
	{
		T elemento = tope->dato;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool Pila <T>::estaVacia() {
	return (tope == NULL);
}

template<class T>
Nodo<T>* Pila<T>::getTope() {
	return tope;
}

template<class T>
void Pila<T>::mostrarTodosLosPedidos() {
	while (!estaVacia()) {
		Pedido aux = this->pop();
		aux.mostrarListaProductos();
	}
}



