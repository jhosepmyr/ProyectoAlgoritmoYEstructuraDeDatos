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

	cout << dato;
}

template<class T>
void Cola<T>::mostrardatos() {
	while (inicio != fin) {
		dequeue();
	}
}


#endif
