#pragma once
#include "Nodo.h"
using namespace std;

template <class T>
class Pila {
private:
	Nodo<T>* tope;
	int lon;
public:
	Pila() { 
		tope = nullptr; 
		lon = 0; 
	}
	void push(T v);
	T pop();
	bool estaVacia();
	void mostrarDATOS();
	Nodo<T>* getTope();
	void mostrarTodosLosPedidos();
	
};

template <class T>
void Pila<T>::push(T v) {
	if (estaVacia()) tope = new Nodo<T>(v);
	else tope = new Nodo<T>(v, tope);
	lon++;
}

template <class T>
T Pila<T>::pop() {
	if (!estaVacia())
	{
		T elemento = tope->dato;
		tope = tope->siguiente;
		return elemento;
		lon--;
	}
}

template<class T>
bool Pila <T>::estaVacia() {
	return (tope == NULL);
}

template<class T>
void Pila<T>::mostrarDATOS() {
	if (estaVacia()) cout<<"VACIO"; //ERROR PILA VACIA
	else {
		Nodo<T>* topeaux=tope;
		int i = 0;
		while (i<lon ) {
			T elemento = topeaux->dato;
			topeaux->dato.mostrarListaProductos();
			topeaux = topeaux->siguiente;
			i++;
		}
	}
}

template<class T>
Nodo<T>* Pila<T>::getTope() {
	return tope;
}

template<class T>
void Pila<T>::mostrarTodosLosPedidos() { //uso de recursividad
	while (!estaVacia()) {
		Pedido aux = this->pop();
		aux.mostrarListaProductos();
	}
}



