#pragma once

class Comentario {
private:
	string texto;
	int fecha;
public:
	Comentario() {

	}
	void comentarioToString() {

	}
};

template<class T>
class NodoAVL {
public:
	T elemento;
	NodoAVL* izq;
	NodoAVL* der;
	int altura;

	NodoAVL() {
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};

template<class T>
class ArbolAVL {
private:
	NodoAVL<T>* raiz;
	void(*procesar)(T); //puntero a función

	//Operaciones privadas
	int _altura(NodoAVL<T>* NodoAVL) {
		if (NodoAVL == nullptr) return 0;
		return NodoAVL->altura;
	}

	void _rotarDerecha(NodoAVL<T>*& NodoAVL) {
		NodoAVL<T>* p = NodoAVL->izq;
		NodoAVL->izq = p->der;
		p->der = NodoAVL;
		//Actualizamos la altura

		NodoAVL = p;
	}

	void _rotarIzquierda(NodoAVL<T>*& NodoAVL) {
		NodoAVL<T>* p = NodoAVL->der;
		NodoAVL->der = p->izq;
		p->izq = NodoAVL;
		//Actualizamos la altura

		NodoAVL = p;
	}
	void _balanceo(NodoAVL<T>*& NodoAVL) {
		int hizq = _altura(NodoAVL->izq);
		int hder = _altura(NodoAVL->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(NodoAVL->der->izq);
			int hhder = _altura(NodoAVL->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(NodoAVL->der);
			}
			_rotarIzquierda(NodoAVL);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(NodoAVL->izq->izq);
			int hhder = _altura(NodoAVL->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(NodoAVL->izq);
			}
			_rotarDerecha(NodoAVL);
		}
		//Actualizar la altura del NodoAVL raiz
		hizq = _altura(NodoAVL->izq);
		hder = _altura(NodoAVL->der);
		NodoAVL->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(NodoAVL<T>*& NodoAVL, T e) {

		if (NodoAVL == nullptr) {
			//Nuevo elemento
			NodoAVL = new NodoAVL<T>();
			NodoAVL->elemento = e;
			return true;
		}
		else if (e == NodoAVL->elemento)
			return false;
		else if (e < NodoAVL->elemento) {
			_insertar(NodoAVL->izq, e);
		}
		else if (e > NodoAVL->elemento) {
			_insertar(NodoAVL->der, e);
		}
		_balanceo(NodoAVL);
		return true;
	}

	void _inOrden(NodoAVL<T>* NodoAVL) {
		if (NodoAVL == nullptr) return;
		_inOrden(NodoAVL->izq);
		procesar(NodoAVL->elemento);
		_inOrden(NodoAVL->der);
	}

	void _inOrdenH(NodoAVL<T>* NodoAVL) {
		if (NodoAVL == nullptr) return;
		_inOrdenH(NodoAVL->izq);
		procesar(NodoAVL->altura);
		_inOrdenH(NodoAVL->der);
	}

public:
	ArbolAVL(void(*nuevaFuncion)(T)) {
		this->procesar = nuevaFuncion;
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
