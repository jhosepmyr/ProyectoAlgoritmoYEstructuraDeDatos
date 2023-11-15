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
class Nodo {
public:
	T elemento;
	Nodo* izq;
	Nodo* der;
	int altura;

	Nodo() {
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};

template<class T>
class ArbolAVL {
private:
	Nodo<T>* raiz;
	void(*procesar)(T); //puntero a función

	//Operaciones privadas
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		//Actualizamos la altura

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		//Actualizamos la altura

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<T>*& nodo, T e) {

		if (nodo == nullptr) {
			//Nuevo elemento
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento)
			return false;
		else if (e < nodo->elemento) {
			_insertar(nodo->izq, e);
		}
		else if (e > nodo->elemento) {
			_insertar(nodo->der, e);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(nodo->altura);
		_inOrdenH(nodo->der);
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
