#pragma once
#include "Comentarios.h"

//Funcion a puntero para mostrar datos
void mostrarComentarios(Comentario comentario) {
	comentario.mostrarDatos();
}

template<class T>
class NodoAVL {
public:
	T elemento;
	NodoAVL* izq;
	NodoAVL* der;
	int altura;
	
	NodoAVL(): izq(nullptr), der(nullptr), altura(0) {
	}
};

template<class T>
class ArbolAVL {
private:
	NodoAVL<T>* raiz;
	void(*procesar)(T); //puntero a función

	//Operaciones privadas
	int _altura(NodoAVL<T>* nodoAVL) {
		if (nodoAVL == nullptr) return 0;
		return nodoAVL->altura;
	}

	void _rotarDerecha(NodoAVL<T>*& nodoAVL) {
		NodoAVL<T>* p = nodoAVL->izq;
		nodoAVL->izq = p->der;
		p->der = nodoAVL;
		//Actualizamos la altura

		nodoAVL = p;
	}

	void _rotarIzquierda(NodoAVL<T>*& nodoAVL) {
		NodoAVL<T>* p = nodoAVL->der;
		nodoAVL->der = p->izq;
		p->izq = nodoAVL;
		//Actualizamos la altura

		nodoAVL = p;
	}
	void _balanceo(NodoAVL<T>*& nodoAVL) {
		int hizq = _altura(nodoAVL->izq);
		int hder = _altura(nodoAVL->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(nodoAVL->der->izq);
			int hhder = _altura(nodoAVL->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(nodoAVL->der);
			}
			_rotarIzquierda(nodoAVL);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(nodoAVL->izq->izq);
			int hhder = _altura(nodoAVL->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodoAVL->izq);
			}
			_rotarDerecha(nodoAVL);
		}
		//Actualizar la altura del NodoAVL raiz
		hizq = _altura(nodoAVL->izq);
		hder = _altura(nodoAVL->der);
		nodoAVL->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(NodoAVL<T>*& nodoAV, T e) {

		if (nodoAV == nullptr) {
			//Nuevo elemento
			nodoAV = new NodoAVL<T>();
			nodoAV->elemento = e;
			return true;
		}
		else if (Comentario::sonIguales(e.getFecha(), nodoAV->elemento.getFecha())) {
			return false;
		}
		else if (Comentario::esMenor(e.getFecha(), nodoAV->elemento.getFecha())) {
			_insertar(nodoAV->izq, e);
		}
		else if (Comentario::esMayor(e.getFecha(), nodoAV->elemento.getFecha())) {
			_insertar(nodoAV->der, e);
		}
		_balanceo(nodoAV);
		return true;
	}

	void _inOrden(NodoAVL<T>* nodoAVL) {
		if (nodoAVL == nullptr) return;
		_inOrden(nodoAVL->izq);
		procesar(nodoAVL->elemento);
		_inOrden(nodoAVL->der);
	}

	void _inOrdenH(NodoAVL<T>* nodoAVL) {
		if (nodoAVL == nullptr) return;
		_inOrdenH(nodoAVL->izq);
		procesar(nodoAVL->altura);
		_inOrdenH(nodoAVL->der);
	}

public:
	ArbolAVL() {
		//void(*nuevaFuncion)(T)
		this->procesar = mostrarComentarios;
		this->raiz = nullptr;
	}

	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}
};
