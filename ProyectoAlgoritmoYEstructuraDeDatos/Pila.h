#pragma once
#include "Nodo.h"
using namespace std;

template <class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() : tope(nullptr) {}
	void push(T v);
	T pop();
	bool estaVacia();
	Nodo<T>* getTope();
	void mostrarTodosLosPedidos();
	void mostrarDatosPila();
	int cantidadElementos();
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
		Nodo<T>* nodoAEliminar = tope;
		tope = tope->siguiente;
		delete nodoAEliminar;  // Liberar memoria del nodo retirado
		return elemento;
	}
	return T();
}

template<class T>
bool Pila <T>::estaVacia() {
	return (tope == nullptr);
}

template<class T>
Nodo<T>* Pila<T>::getTope() {
	return tope;
}

template<class T>
void Pila<T>::mostrarTodosLosPedidos() {
	while (!estaVacia()) {
		T aux = this->pop();
		aux.mostrarListaProductos();
	}
}

template<class T>
void Pila<T>::mostrarDatosPila() {
	if (estaVacia()) { 
		return; 
	}
	else
	{
		T aux = pop();
		aux.mostrarListaProductos();
		mostrarDatosPila();
	}
	
}

template <class T>
int Pila<T>::cantidadElementos() {
	int count = 0;
	Nodo<T>* temp = tope;
	while (temp != nullptr) {
		count++;
		temp = temp->siguiente;
	}
	return count;
}



