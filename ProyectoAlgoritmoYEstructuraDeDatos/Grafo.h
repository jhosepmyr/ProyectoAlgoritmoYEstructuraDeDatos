#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Grafo {
private:
    unordered_map<int, vector<int>> lista_adyacencia;
    vector<string>sucursal;

public:

    Grafo() {};

    void agregar_vertice(int vertice, string sucursal) {
        // Si el vértice no está en el mapa, lo agregamos con un vector vacío como valor
        if (lista_adyacencia.find(vertice) == lista_adyacencia.end()) {
            lista_adyacencia[vertice] = vector<int>();
            this->sucursal.push_back(sucursal);
        }
    }

    void agregar_arista(int vertice_origen, int vertice_destino) {
        // Añadimos la arista a ambos vértices (grafo no dirigido)
        lista_adyacencia[vertice_origen].push_back(vertice_destino);
        lista_adyacencia[vertice_destino].push_back(vertice_origen);
    }

    void imprimir_grafo() {
        for (const auto& par : lista_adyacencia) {
            cout <<"La sucursal " << sucursal.at(par.first) << " puede llevar paqueteria hasta la sucursal";
            for (const auto& vecino : par.second) {
                cout << sucursal.at(vecino) << ".";
                break;
            }
            cout << endl;
        }
    }
};
