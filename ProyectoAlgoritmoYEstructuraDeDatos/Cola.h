#ifndef __COLA_H__
#define __COLA_H__
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	void enqueue(T v);
	void dequeue();
	bool esVacia();
	void mostrardatos();

	void ordenarPorPrecio(function<bool(const T&, const T&)> comparador);

};

template<class T>
bool Cola<T>::esVacia() {
	return (inicio == NULL);
}

template<class T>
void Cola<T>::enqueue(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {

		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}

template<class T>
void Cola<T>::dequeue() {
	T dato = inicio->dato;

	if (inicio == fin) {
		inicio = NULL;
		fin = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}

	dato.mostrarDatos();
}

template<class T>
void Cola<T>::mostrardatos() {
	while (inicio != fin) {
		dequeue();
	}
}

template<class T>
void Cola<T>::ordenarPorPrecio(function<bool(const T&, const T&)> comparador) { //usando metodo de ordenamiento por selección
	if (inicio == nullptr || inicio == fin) { //vacía o tiene un solo elemento
		return;
	}

	Nodo<T>* actual = inicio;
	while (actual != nullptr) {
		Nodo<T>* minimo = actual;
		Nodo<T>* siguiente = actual->siguiente;

		while (siguiente != nullptr) {
			if (comparador(siguiente->dato, minimo->dato)) {
				minimo = siguiente;
			}
			siguiente = siguiente->siguiente;
		}

		// Intercambia los datos de actual y minimo.
		T temp = actual->dato;
		actual->dato = minimo->dato;
		minimo->dato = temp;

		actual = actual->siguiente;
	}
}


#endif
