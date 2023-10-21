#pragma once
#include <functional>
#include "Cola.h"
#include <random>

using namespace std;

typedef unsigned int uint;

template <class T>
class Lista {
    struct Nodo;
    typedef function<int(T, T)> Comp;
    Nodo* ini;
    uint    lon;

public:
    Lista() : ini(nullptr), lon(0) { };
    Lista(Comp comparar) : ini(nullptr), lon(0){ };
    ~Lista();

    uint    longitud();
    bool    esVacia();
    void    agregaInicial(T elem);
    void    agregaPos(T elem, uint pos);
    void    agregaFinal(T elem);

    void    modificarInicial(T elem);
    void    modificarPos(T elem, uint pos);
    void    modificarFinal(T elem);

    void    eliminaInicial();
    void    eliminaPos(uint pos);
    void    eliminaFinal();

    T       obtenerInicial();
    T       obtenerPos(uint pos);
    T       obtenerFinal();

    void    MostrarDatosPROD();
    void    MostrarDatosPRODLinea();

    T     buscarporID(string ID, int tipo);
    void     eliminarporID(string ID);
    T loopdeBusquedaDATO(Nodo* aux, string ID, int tipo);

    void MergeSort(int ini, int fin);
    void Merge(int ini, int mitad, int fin);
    void ordenarPorPrecioDescendente();

    T QuickSelect(int p, int r, int k);
    int Particion(int p, int r);
    void ordenarPorPrecioAscendente();
    void intercambiar(int i, int j);
    
    void desordenamientoShuffle();

};

template <class T>
struct Lista<T>::Nodo {
    T elem;
    Nodo* sig; // puntero apunta al siguiente nodo
    Nodo(T elem, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};

template <class T>
Lista<T>::~Lista() {
}

template <class T>
uint Lista<T>::longitud() {
    return lon;
}

template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}

template <class T>
void Lista<T>::agregaInicial(T elem) {
    Nodo* nuevo = new Nodo(elem, ini);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {

    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* nuevo = new Nodo(elem, aux->sig);
        if (nuevo != nullptr) {
            aux->sig = nuevo;
            lon++;
        }
    }
}

template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon); // ;)
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        aux->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo* aux = ini;
        ini = ini->sig;
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        eliminaInicial();
    }
    else {
        Nodo* eliminar = this->ini;
        Nodo* anterior = nullptr;
        uint contador = 0;
        while (contador < pos) {
            anterior = eliminar;
            eliminar = eliminar->sig;
            contador++;
        }
        anterior->sig = eliminar->sig;
        delete eliminar;
        this->lon--;
    }
}

template <class T>
void Lista<T>::eliminaFinal() {
    eliminaPos(lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}

template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        return aux->elem;
    }
}

template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}


//MOSTRADO DE PRODUCTOS

template<class T>
void Lista<T>::MostrarDatosPROD() {
    Nodo* aux = ini;
    for (int i = 0; i < lon; i++) {
        aux->elem.mostrarDatos();
        aux = aux->sig;
    }
}

template<class T>
void Lista<T>::MostrarDatosPRODLinea() {
    Nodo* aux = ini;
    for (int i = 0; i < lon; i++) {
        aux->elem.mostrarDatosLinea();
        aux = aux->sig;
    }
}

//BUSQUEDA DE PRODUCTOS

template <class T>
T Lista<T>::buscarporID(string ID, int tipo) {
    Nodo *aux = ini;
    /*while (aux != nullptr) {
        if (aux->elem.getIdentificador()==ID) {
            return aux->elem;
        }
        aux = aux->sig;
    }*/
    return loopdeBusquedaDATO(aux, ID, tipo);
}

template <class T>
void Lista<T>::eliminarporID(string ID) {
    Nodo* actual = ini;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {

        if (actual->elem.getIdentificador() == ID) {
            if (anterior == nullptr) {
                ini = actual->sig;
            }
            else {
                anterior->sig = actual->sig;
            }
            delete actual;
            cout << "\nSe ha eliminado el producto correctamente" << endl;
            lon--;
            return;
        }

        anterior = actual;
        actual = actual->sig;
    }

    cout << "\nNo se ha encontrado el producto con el identificador brindado" << endl;
}

template <class T>
T Lista<T>::loopdeBusquedaDATO(Nodo* aux, string ID, int tipo) {
    bool encontrado = (tipo == 1) ? (aux->elem.getIdentificador() == ID) : (aux->elem.getCodigoVendedor() == ID);
    if (encontrado) {
        return aux->elem;
    }
    else  if (aux != nullptr) return loopdeBusquedaDATO(aux = aux->sig, ID, tipo);
}

//ORDENAMIENTOS O FILTRADOS

template<class T>
void Lista<T>::Merge(int ini, int mitad, int fin) {
    int n1 = mitad - ini + 1;
    int n2 = fin - mitad;

    Lista<T> L;
    Lista<T> R;

    // Copia datos a listas temporales L y R
    for (int i = 0; i < n1; i++) {
        L.agregaFinal(obtenerPos(ini + i));
    }
    for (int j = 0; j < n2; j++) {
        R.agregaFinal(obtenerPos(mitad + 1 + j));
    }

    int i = 0, j = 0, k = ini;

    // Combina las dos listas temporales en la lista original
    while (i < n1 && j < n2) {
        if (L.obtenerPos(i).getPrecio() >= R.obtenerPos(j).getPrecio()) {
            modificarPos(L.obtenerPos(i), k);
            i++;
        }
        else {
            modificarPos(R.obtenerPos(j), k);
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L y R, si los hay
    while (i < n1) {
        modificarPos(L.obtenerPos(i), k);
        i++;
        k++;
    }
    while (j < n2) {
        modificarPos(R.obtenerPos(j), k);
        j++;
        k++;
    }
}

template<class T>
void Lista<T>::MergeSort(int ini, int fin) {
    if (ini < fin) {
        int mitad = ini + (fin - ini) / 2;

        MergeSort(ini, mitad);
        MergeSort(mitad + 1, fin);

        Merge(ini, mitad, fin);
    }
}

template<class T>
void Lista<T>::ordenarPorPrecioDescendente() {
    int n = longitud();
    if (n > 1) {
        MergeSort(0, n - 1);
    }
}



template <typename T>
int Lista<T>::Particion(int p, int r) {
    T x = obtenerPos(r); // El pivote
    int i = p - 1; // Índice de los menores
    for (int j = p; j < r; j++) {
        if (obtenerPos(j).getPrecio() <= x.getPrecio()) {
            i++;
            intercambiar(i, j); // Utiliza una función para intercambiar elementos
        }
    }
    intercambiar(i + 1, r); // Utiliza una función para intercambiar elementos
    return i + 1;
}

template <typename T>
T Lista<T>::QuickSelect(int p, int r, int k) {
    if (p == r) {
        return obtenerPos(p);
    }
    // Índice del pivote con A ordenado Izq(Menores) Der(Mayores) al pivote
    int q = Particion(p, r);
    int l = q - p + 1; // Número de elementos del subarreglo donde se encuentra el k-ésimo elemento
    if (k == l) {
        return obtenerPos(q);
    }
    else if (k < l) {
        return QuickSelect(p, q - 1, k);
    }
    else {
        return QuickSelect(q + 1, r, k - l);
    }
}

template <typename T>
void Lista<T>::ordenarPorPrecioAscendente() {
    int n = longitud();
    if (n <= 1) {
        return;
    }
    QuickSelect(0, n - 1, n - 1);
}

template <typename T>
void Lista<T>::intercambiar(int i, int j) {
    T temp = obtenerPos(i);
    modificarPos(obtenerPos(j), i);
    modificarPos(temp, j);
}


template <class T>
void Lista<T>::desordenamientoShuffle() {
    random_device rd;
    mt19937 generator(rd());

    for (int i = longitud() - 1; i > 0; --i) {
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(generator);
        intercambiar(i, j);
    }
}