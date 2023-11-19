#pragma once
#include "Fecha.h"
#include <fstream>
#include <sstream>
#include <vector>

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
	Comentario() {}

	void mostrarDatos() {
		cout << "---------------------------------------------------------------" << endl;
		cout << "Fecha de publicacion: " << to_string(this->fecha.dia) << "/" << to_string(this->fecha.mes) << "/" << to_string(this->fecha.anio) << endl;
		cout << this->texto << endl;
		cout << "---------------------------------------------------------------" << endl;
	}

	static vector<Comentario> extraerComentariosTXT() {
		// Operaciones constantes: 1
		vector<Comentario> comentarios;
		// Operaciones constantes: 1
		ifstream archivo("Comentarios.txt");
		if (!archivo.is_open()) {
			// Operaciones constantes: 1
			cerr << "Error al abrir el archivo: Comentarios.txt" << endl;
			return comentarios;  // Operaciones constantes: 1
		}
		string linea;
		// Bucle que se ejecuta n veces, donde n es el número de líneas en el archivo
		while (getline(archivo, linea)) {  // n veces
			// Operaciones constantes: 1
			istringstream ss(linea);
			string token;
			int dia, mes, anio, hora, min;
			string texto;
			getline(ss, token, ',');
			dia = stoi(token); // Operaciones constantes: 1

			getline(ss, texto); // Operaciones constantes: 1
			comentarios.emplace_back(texto, dia, mes, anio, hora, min); //1
		}
		archivo.close(); // Operaciones constantes: 1
		return comentarios; // Operaciones constantes: 1
	}


	// Obtener el comentario formateado para guardar en el archivo
	string obtenerComentarioFormateado() {
		ostringstream ss;
		ss << this->fecha.dia << "," << this->fecha.mes << "," << this->fecha.anio << "," << this->fecha.hora << "," << this->fecha.min << "," << this->texto;
		return ss.str();
	}

	Fecha getFecha() {
		return this->fecha;
	}

	static bool esMenor(Fecha& fecha1, Fecha& fecha2) {
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

	static bool sonIguales(Fecha& fecha1, Fecha& fecha2) {
		return fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes &&
			fecha1.dia == fecha2.dia && fecha1.hora == fecha2.hora &&
			fecha1.min == fecha2.min;
	}
};