#pragma once
#include "Interfaz.h"
#include "Cliente.h"

using namespace std;

class InterfazCliente : public Interfaz {
private:
	Cliente* clienteAux;
public:
	InterfazCliente(string _nombre, string _contra) {
		this->clienteAux = new Cliente(_nombre, _contra);
	}
	void mostrarInterfaz() {
		cout << "prueba" << endl;
		system("pause>0");
		system("cls");
		return;
	}
};