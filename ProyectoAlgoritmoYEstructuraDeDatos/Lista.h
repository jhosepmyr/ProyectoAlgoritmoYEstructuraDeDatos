#pragma once
#include <functional>
#include "Cola.h"
using namespace std;

typedef unsigned int uint;

template <class T>
class Lista {
    struct Nodo;
    typedef function<int(T, T)> Comp;
    Nodo* ini;
    uint    lon; // número de elementos en la lista
    //Comp    comparar; // lambda de criterio de comparación

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
    void    MostrarDatosPROD();
    void    buscarPRODMAYVALOR();

    T       obtenerInicial();
    T       obtenerPos(uint pos);
    T       obtenerFinal();
    T     buscarporID(string ID);
    void     eliminarporID(string ID);
    T rECURSIV(Nodo* aux, string ID);
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


//METODOS EXTRA

template<class T>
void Lista<T>::MostrarDatosPROD() {
    Nodo* aux = ini;
    for (int i = 0; i < lon; i++) {
        aux->elem.mostrarDatos();
        aux = aux->sig;
    }
}

template<class T>
void Lista<T>::buscarPRODMAYVALOR() {
    Nodo* aux = ini;
    Cola<T>colaaux;
    Producto *arr=new Producto[lon];
    for (int i = 0; i < lon; i++) {
        arr[i] = aux->elem;
        aux = aux->sig;
    }

    auto ordIntercambio = [](Producto a[], int n)
        {
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (a[i].getPrecio() > a[k].getPrecio()) {
                        swap(a[i], a[k]);
                    }
                }
            }
        };
    ordIntercambio(arr, lon);
    
    for (int i = lon - 1; i >= 0; i--) {
        colaaux.enqueue(arr[i]);
    }

    colaaux.mostrardatos();

}



template <class T>
T Lista<T>::buscarporID(string ID) {
    Nodo *aux = ini;
    /*while (aux != nullptr) {
        if (aux->elem.getIdentificador()==ID) {
            return aux->elem;
        }
        aux = aux->sig;
    }*/
    return rECURSIV(aux, ID);
}


template <class T>
void Lista<T>::eliminarporID(string ID) {
    Nodo* aux = ini;
    int pos = 0;
    bool encontrado = false;
    while (aux != nullptr && !encontrado) {
        if (aux->elem.getIdentificador() == ID) {
            eliminaPos(pos);
            cout << "\nSe ha eliminado el producto correctamente" << endl;
            encontrado = true;
            break;
        }
        else
        {
            pos++;
            aux = aux->sig;
        }
    }
    cout << "\nSe no se ha encontrado el producto con el identificador brindado" << endl;
}

template <class T>
T Lista<T>::rECURSIV(Nodo* aux, string ID) {
    if (aux->elem.getIdentificador() == ID) {
        return aux->elem;
    }
    else  if (aux != nullptr) return rECURSIV(aux = aux->sig, ID);
}
