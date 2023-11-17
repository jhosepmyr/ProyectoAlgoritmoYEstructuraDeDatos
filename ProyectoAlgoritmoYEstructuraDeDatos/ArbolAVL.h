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
		time_t t = time(0);
		tm* now = localtime(&t);

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
	Comentario(){}

	void mostrarDatos() {
		cout << "---------------------------------------------------------------" << endl;
		cout << "Fecha de publicacion: "<<to_string(this->fecha.dia)<<"/"<< to_string(this->fecha.mes)<<"/"<<to_string(this->fecha.anio)<<endl;
		cout << this->texto << endl;
		cout << "---------------------------------------------------------------" << endl;
	}

	static vector<Comentario> extraerComentariosTXT() {
		vector<Comentario> comentarios;

		ifstream archivo("Comentarios.txt");
		if (!archivo.is_open()) {
			cerr << "Error al abrir el archivo: Comentarios.txt" << endl;
			return comentarios;
		}

		string linea;
		while (getline(archivo, linea)) {
			istringstream ss(linea);
			string token;
			int dia, mes, anio, hora, min;
			string texto;

			// Leer los datos separados por comas
			getline(ss, token, ',');
			dia = stoi(token);

			getline(ss, token, ',');
			mes = stoi(token);

			getline(ss, token, ',');
			anio = stoi(token);

			getline(ss, token, ',');
			hora = stoi(token);

			getline(ss, token, ',');
			min = stoi(token);

			getline(ss, texto);

			// Crear un objeto Comentario y agregarlo al vector
			comentarios.emplace_back(texto, dia, mes, anio, hora, min);
		}

		archivo.close();

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

	static bool sonIguales(Fecha& fecha1,Fecha& fecha2) {
		return fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes &&
			fecha1.dia == fecha2.dia && fecha1.hora == fecha2.hora &&
			fecha1.min == fecha2.min;
	}
};

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
		else if (Comentario::esMayor(e.getFecha(), nodoAV->elemento.getFecha())) {
			_insertar(nodoAV->izq, e);
		}
		else if (Comentario::esMenor(e.getFecha(), nodoAV->elemento.getFecha())) {
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
