#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <iomanip> // Para setw
#include <queue>
#include <climits>  // Para INT_MAX

using namespace std;

class Grafo {
private:
    unordered_map<int, vector<int>> lista_adyacencia;
    vector<string>sucursal;
    vector<int> pesos;

public:

    Grafo() {
        // Inicializar la semilla del generador de n�meros aleatorios con el tiempo actual
        srand(static_cast<unsigned>(time(nullptr)));
    };

    void agregar_vertice(int vertice, string sucursal) {
        // Si el v�rtice no est� en el mapa, lo agregamos con un vector vac�o como valor
        if (lista_adyacencia.find(vertice) == lista_adyacencia.end()) {
            lista_adyacencia[vertice] = vector<int>();
            this->sucursal.push_back(sucursal);
        }
    }

    void agregar_arista(int vertice_origen, int vertice_destino) {
        // A�adimos la arista a ambos v�rtices (grafo no dirigido)
        lista_adyacencia[vertice_origen].push_back(vertice_destino);
        lista_adyacencia[vertice_destino].push_back(vertice_origen);
        pesos.push_back(1 + rand() % (10 - 1));
    }

    // Funci�n para obtener el �ndice correspondiente a la arista entre dos v�rtices
    int obtener_indice(int vertice_origen, int vertice_destino) {
        auto it = find(lista_adyacencia[vertice_origen].begin(), lista_adyacencia[vertice_origen].end(), vertice_destino);
        int indice = distance(lista_adyacencia[vertice_origen].begin(), it);
        return indice;
    }

    void imprimir_grafo() {
        cout << "==============================================" << endl;
        cout << setw(25) << "Informacion del Grafo" << endl;
        cout << "==============================================" << endl;

        for (const auto& par : lista_adyacencia) {
            for (const auto& vecino : par.second) {
                // Evitar repeticiones mostrando solo si el vecino es mayor que el v�rtice actual
                if (vecino > par.first) {
                    cout << left << setw(30) << "Desde la sucursal '" + sucursal.at(par.first) + "' hasta la sucursal '" + sucursal.at(vecino) + "' : " <<
                        "Distancia = " << pesos.at(obtener_indice(par.first, vecino)) << " KM" << endl;
                }
            }
        }
        cout << "==============================================" << endl;
    }

    // Funci�n para calcular la distancia m�s corta entre dos puntos usando Dijkstra
    int calcular_distancia_corta(int sucursal_inicio, int sucursal_destino) {
        // Verificar si las sucursales son válidas
        if (sucursal_inicio < 0 || sucursal_inicio >= sucursal.size() ||
            sucursal_destino < 0 || sucursal_destino >= sucursal.size()) {
            cerr << "Error: Sucursales no válidas." << endl;
            return -1; // O cualquier otro valor que indique un error // 1
        }
        // Estructuras para Dijkstra
        vector<int> distancias(sucursal.size(), INT_MAX); // O(V)
        distancias[sucursal_inicio] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // O(1)
        pq.push({ 0, sucursal_inicio });

        // Implementación del algoritmo de Dijkstra
        while (!pq.empty()) {  // Se ejecuta n veces en el peor caso // n veces
            int u = pq.top().second;
            pq.pop();
            for (int v : lista_adyacencia[u]) {  // Se ejecuta n veces en el peor caso // n veces
                int peso = pesos[obtener_indice(u, v)];
                if (distancias[v] > distancias[u] + peso) {
                    distancias[v] = distancias[u] + peso;
                    pq.push({ distancias[v], v });
                }
            }
        }
        // Mostrar la distancia más corta entre las sucursales
        cout << "La distancia más corta entre '" << sucursal.at(sucursal_inicio) << "' y '"
            << sucursal.at(sucursal_destino) << "' es: " << distancias[sucursal_destino] << " KM" << endl;
        return distancias[sucursal_destino];
    }


    void ingresar_datos_y_mostrar_camino_mas_corto() {
        cout << "Sucursales disponibles:" << endl;
        for (size_t i = 0; i < sucursal.size(); ++i) {
            cout << i << ". " << sucursal[i] << endl;
        }

        int indice_origen, indice_destino;
        cout << "Ingrese el �ndice de la sucursal de origen: ";
        cin >> indice_origen;

        if (indice_origen < 0 || indice_origen >= sucursal.size()) {
            cerr << "�ndice de sucursal de origen no v�lido." << endl;
            return;
        }

        cout << "Ingrese el �ndice de la sucursal de destino: ";
        cin >> indice_destino;

        if (indice_destino < 0 || indice_destino >= sucursal.size()) {
            cerr << "�ndice de sucursal de destino no v�lido." << endl;
            return;
        }

        calcular_distancia_corta(indice_origen, indice_destino);
    }
};
