#pragma once
#include "Interfaz.h"
#include "Vendedor.h"

using namespace std;

class InterfazVendedor : public Interfaz {
private: 
    Vendedor* vendedorAux;
public:
    InterfazVendedor(string _nombre, string _contra, int numUsuario) {
        this->vendedorAux = new Vendedor(_nombre, _contra);
    }
    void mostrarInterfaz() {
        cout << "prueba" << endl;
        system("pause>0");
        system("cls");
        return;
    }
};


/*void ventanaInventario() {
    Console::Clear();
    cout << "NUESTROS PRODUCTOS";
    objInventario.listarProductos();
}*/