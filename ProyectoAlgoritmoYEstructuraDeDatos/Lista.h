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

    T obtenerEliminarPorPosicion(uint pos);
    T eliminarPrimero();
    T eliminarUltimo();

    T       obtenerInicial();
    T       obtenerPos(uint pos);
    T       obtenerFinal();

    void eliminarTodos();
    void eliminarTodosRecursivo(Nodo* nodo);

    void    MostrarDatosPROD();
    void    MostrarDatosPRODLinea();

    void     eliminarporID(string ID);
    bool  existeID(string ID, int tipo);
    T     buscarporID(string ID, int tipo);
    T     buscarRecursivo(Nodo* aux, string ID, int tipo);

    void MergeSort(int ini, int fin);
    void Merge(int ini, int mitad, int fin);
    void ordenarPorPrecioDescendente();

    T QuickSelect(int p, int r, int k);
    int Particion(int p, int r);
    void ordenarPorPrecioAscendente();
    void intercambiar(int i, int j);

    void QuickSort(int p, int r);
    void ordenarPorPrecioAscendente2();
    
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

//ELIMINAR Y RETORNAR ELEMENTO
template <class T>
T Lista<T>::obtenerEliminarPorPosicion(uint pos) {
    if (pos >= lon || pos < 0) {
        throw out_of_range("Posición fuera de rango");
    }

    if (pos == 0) {
        // Si la posición es la primera, eliminamos el primer elemento y lo retornamos
        T elemento = ini->elem;
        Nodo* temp = ini;
        ini = ini->sig;
        delete temp;
        lon--;
        return elemento;
    }

    Nodo* aux = ini;
    for (uint i = 0; i < pos - 1; i++) {
        aux = aux->sig;
    }

    // Guardamos el elemento en la posición especificada
    T elemento = aux->sig->elem;

    // Eliminamos el elemento de la posición
    Nodo* temp = aux->sig;
    aux->sig = temp->sig;
    delete temp;
    lon--;

    return elemento;
}

template <class T>
T Lista<T>::eliminarPrimero() {
    if (lon == 0) {
        throw std::runtime_error("La lista está vacía, no se puede eliminar el primer elemento.");
    }

    return obtenerEliminarPorPosicion(0);
}

template <class T>
T Lista<T>::eliminarUltimo() {
    if (lon == 0) {
        throw std::runtime_error("La lista está vacía, no se puede eliminar el último elemento.");
    }

    return obtenerEliminarPorPosicion(lon - 1);
}

//ELIMINAR TODO ELEMENTO RECURSIVA
template <class T>
void Lista<T>::eliminarTodos() {
    eliminarTodosRecursivo(ini);
    ini = nullptr;  // Establecemos el puntero inicial a nullptr para indicar que la lista está vacía.
    lon = 0;        // Restablecemos la longitud de la lista a 0.
}

template <class T>
void Lista<T>::eliminarTodosRecursivo(Nodo* nodo) {
    if (nodo) {
        eliminarTodosRecursivo(nodo->sig);  // Llamada recursiva con el siguiente nodo.
        delete nodo;                        // Elimina el nodo actual.
    }
}

//MOSTRADO DE PRODUCTOS

template<class T>
void Lista<T>::MostrarDatosPROD() {
    if (this->lon!=0)
    {
        Nodo* aux = ini;
        cout << "\n---------------------------\n";
        cout << "Numero de productos: " << this->longitud();
        cout << "\n---------------------------\n\n";
        for (int i = 0; i < lon; i++) {
            aux->elem.mostrarDatos();
            aux = aux->sig;
        }
        cout << "\n\n";
    }
    else
    {
        cout << "\nNo hay productos disponibles\n";
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
bool Lista<T>::existeID(string ID, int tipo) {
    Nodo* aux = ini;
    while (aux != nullptr) {
        if ((tipo == 1 && aux->elem.getIdentificador() == ID) || (tipo == 2 && aux->elem.getCodigoVendedor() == ID)) {
            return true;  // Si se encuentra el ID, devuelve true.
        }
        aux = aux->sig;
    }
    return false;  // Si no se encuentra el ID, devuelve false.
}

template <class T>
T Lista<T>::buscarporID(string ID, int tipo) {
    return buscarRecursivo(ini, ID, tipo);
}

template <class T>
T Lista<T>::buscarRecursivo(Nodo* aux, string ID, int tipo) {
    if (aux == nullptr) {
        throw std::runtime_error("Elemento no encontrado");
    }

    bool encontrado = (tipo == 1) ? (aux->elem.getIdentificador() == ID) : (aux->elem.getCodigoVendedor() == ID);
    if (encontrado) {
        return aux->elem;
    }

    return buscarRecursivo(aux->sig, ID, tipo);
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
            //cout << "\nSe ha eliminado el producto correctamente" << endl;
            lon--;
            return;
        }

        anterior = actual;
        actual = actual->sig;
    }

    cout << "\nNo se ha encontrado el producto con el identificador brindado" << endl;
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


template <typename T>
void Lista<T>::QuickSort(int p, int r) {
    if (p < r) {
        int q = Particion(p, r);
        QuickSort(p, q - 1);
        QuickSort(q + 1, r);
    }
}

template <typename T>
void Lista<T>::ordenarPorPrecioAscendente2() {
    if (longitud() <= 1) {
        return;  // No es necesario ordenar
    }
    QuickSort(0, longitud() - 1);
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