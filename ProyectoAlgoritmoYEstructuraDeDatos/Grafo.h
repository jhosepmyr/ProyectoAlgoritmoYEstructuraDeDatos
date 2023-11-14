#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Grafo {
private:
    unordered_map<int, vector<int>> lista_adyacencia;
    vector<string>sucursal;
    vector<int> pesos;

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
        pesos.push_back(1 + rand() % (10 - 1));
    }

    void imprimir_grafo() {
        int i = 0;
        for (const auto& par : lista_adyacencia) {
            cout <<"La sucursal " << sucursal.at(par.first) << " puede llevar paqueteria hasta la sucursal.";
            for (const auto& vecino : par.second) {
                cout << sucursal.at(vecino) <<endl<< " (Tienen una distancia de " << pesos.at(i) << "KM entre ellos)";
                break;
            }
            i++;
            cout << endl;
        }
    }
};
