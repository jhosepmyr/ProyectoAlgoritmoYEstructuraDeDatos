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
};

template <class T>
void Pila<T>::push(T v) {
	if (estaVacia()) tope = new Nodo<T>(v);
	else tope = new Nodo<T>(v, tope);
	lon++;
}

template <class T>
T Pila<T>::pop() {
	if (estaVacia()) return nullptr; //ERROR PILA VACIA
	else {
		T elemento = tope->dato;
		tope = tope->siguiente;
		return elemento;
	}
	lon--;
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
			topeaux->dato.mostrarDatos();
			topeaux = topeaux->siguiente;
			i++;
		}
	}

}

