#pragma once
#include "Interfaz.h"
#include "Cliente.h"
#include "Controller.h"
#include <fstream>
#include<sstream>

using namespace std;

class InterfazCliente : public Interfaz {
private:
	Cliente* clienteAux;
	Controller* objController;
	string archivoCliente;
public:
	InterfazCliente(string _nombre, string _contra, int numUsuario) {
		this->clienteAux = new Cliente(_nombre, _contra);
		this->objController = new Controller();
		ostringstream ss;
		ss << "Cliente" << numUsuario << ".txt";
		this->archivoCliente = ss.str();
	}
	void mostrarInterfaz() {
		Console::ForegroundColor = ConsoleColor::Blue;
		objController->agregaDatosIniciales(4);
		objController->mostrarLSTPRDCTS();
		system("pause>0");
		system("cls");
	}
};