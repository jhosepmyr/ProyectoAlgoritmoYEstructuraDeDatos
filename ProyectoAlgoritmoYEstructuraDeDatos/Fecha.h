#pragma once
#include <ctime>
#include <iostream>
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