#pragma once
#include <ctime>
#include <vector>
using namespace std;
class Fecha {
public:
	int dia, mes, anio, hora, min;
public:
	//crear fechas desde txt
	Fecha(int dia, int mes, int anio, int hora, int min) :dia(dia), mes(mes), anio(anio), hora(hora), min(min) {}
	
	//crear fechas del momento del usuario
	Fecha() {
		// Obtiene la fecha y hora actual
		time_t t = std::time(0);
		tm* now = std::localtime(&t);

		// Extrae los componentes de la fecha y hora
		this->dia = now->tm_mday;
		this->mes = now->tm_mon + 1; // tm_mon comienza desde 0
		this->anio = now->tm_year + 1900; // tm_year es el año actual desde 1900
		this->hora = now->tm_hour;
		this->min = now->tm_min;
	}

	//establecer datos de fecha
	void setFecha(int dia, int mes, int anio, int hora, int min) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
		this->hora = hora;
		this->min = min;
	}
};
class Comentario {
private:
	string texto;
	Fecha fecha;
public:
	Comentario(string texto, int dia, int mes, int anio, int hora, int min) {
		this->texto = texto;
		this->fecha.setFecha(dia, mes, anio, hora, min);
	}

	Comentario(string texto) {
		this->texto = texto;
	}

	static vector<Comentario> extraerComentariosTXT() {
		vector<Comentario> comentarios;

		istringstream iss("Comentarios.txt");
		string linea;

		while (std::getline(iss, linea)) {
			// Suponemos que cada línea contiene un comentario en el formato deseado
			string comentarioTexto = linea;

			// Suponemos que también hay información de fecha en el formato deseado en la misma línea
			int dia, mes, anio, hora, min;
			// Aquí deberías implementar la lógica para extraer los valores de fecha

			// Crear un objeto Comentario y agregarlo al vector
			comentarios.push_back(Comentario(comentarioTexto, dia, mes, anio, hora, min));
		}

		return comentarios;
	}

	Fecha getFecha() {
		return this->fecha;
	}

	static bool esMenor(Fecha& fecha1,Fecha& fecha2) {
		if (fecha1.anio < fecha2.anio) {
			return true;
		}
		else if (fecha1.anio > fecha2.anio) {
			return false;
		}

		if (fecha1.mes < fecha2.mes) {
			return true;
		}
		else if (fecha1.mes > fecha2.mes) {
			return false;
		}

		if (fecha1.dia < fecha2.dia) {
			return true;
		}
		else if (fecha1.dia > fecha2.dia) {
			return false;
		}

		if (fecha1.hora < fecha2.hora) {
			return true;
		}
		else if (fecha1.hora > fecha2.hora) {
			return false;
		}

		return fecha1.min < fecha2.min;
	}

	static bool esMayor(Fecha& fecha1, Fecha& fecha2) {
		return !esMenor(fecha1, fecha2) && !(fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes &&
			fecha1.dia == fecha2.dia && fecha1.hora == fecha2.hora &&
			fecha1.min == fecha2.min);
	}

	bool sonIguales(Fecha& fecha1,Fecha& fecha2) {
		return fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes &&
			fecha1.dia == fecha2.dia && fecha1.hora == fecha2.hora &&
			fecha1.min == fecha2.min;
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
		else if (Comentario::sonIguales(e.getFecha(), NodoAVL->elemento.getFecha())) {
			return false;
		}
		else if (Comentario::esMayor(e.getFecha(), NodoAVL->elemento.getFecha())) {
			_insertar(NodoAVL->izq, e);
		}
		else if (Comentario::esMenor(e.getFecha(), NodoAVL->elemento.getFecha())) {
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
