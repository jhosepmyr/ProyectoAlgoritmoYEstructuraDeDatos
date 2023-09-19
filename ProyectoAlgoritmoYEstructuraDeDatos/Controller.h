#pragma once
#include "Files.h"
#include "Electrodomesticos.h"
#include"Lista.h"
#include "Muebles.h"
using namespace std;
class Controller {
private:
	Files* fls;
	Lista<Electrodomesticos>* lst;
	Lista<Muebles>* lst2;
public:
	Controller() {
		fls = new Files();
		fls->DatosELEC();
		fls->DatosMUEBLES();
		lst = new Lista<Electrodomesticos>();
		lst2 = new Lista<Muebles>();
		agregaDatosIniciales(0);
	};
	int agregaDatosIniciales(int n) {// aqui solo se agregaran los datos por default del txt
		lst->agregaInicial(Electrodomesticos(fls->getIDs(n), fls->getNombre(n), fls->getPrecios(n), fls->getEstado(n), fls->getTVIDAS(n)));
		lst2->agregaInicial(Muebles(fls->getIDs2(n), fls->getNombre2(n), fls->getPrecios2(n), fls->getArmado(n), fls->geTextura(n)));
		n++;
		if (n < fls->getN()) { return agregaDatosIniciales(n); }
		else return 0;
	}

	int MostrarDatosELECTRO(int n) {
		Electrodomesticos elec;
		elec = lst->obtenerPos(n);
		elec.MostrarED();
		n++;
		if (n < lst->longitud()) { return MostrarDatosELECTRO(n); }
		else return 0;
	}

	int MostrarDatosMUEBLE(int n) {
		Muebles mueb;
		mueb = lst2->obtenerPos(n);
		mueb.MostrarMueble();
		n++;
		if (n < lst2->longitud()) { return MostrarDatosMUEBLE(n); }
		else return 0;
	}

	void agregarELEC(int ID, string Nombre, int Precios, string estado, int t_vida) {
		fls->AgregarProducto(Nombre, ID, Precios, estado, t_vida);
		lst->agregaInicial(Electrodomesticos(ID, Nombre, Precios, estado, t_vida));
	}

	void agregarMUEBLES(int ID, string Nombre, int Precios, string armado, string textura) {
		fls->AgregarProducto2(Nombre, ID, Precios, armado, textura);
		lst2->agregaInicial(Muebles(ID, Nombre, Precios, armado, textura));
	}


};