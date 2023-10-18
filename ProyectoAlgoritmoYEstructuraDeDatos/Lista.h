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

    T     buscarporID(string ID);
    void     eliminarporID(string ID);
    T loopdeBusquedaDATO(Nodo* aux, string ID);

    void ordenarPorPrecioAscendente();
    void ordenarPorPrecioDescendente();
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
T Lista<T>::buscarporID(string ID) {
    Nodo *aux = ini;
    /*while (aux != nullptr) {
        if (aux->elem.getIdentificador()==ID) {
            return aux->elem;
        }
        aux = aux->sig;
    }*/
    return loopdeBusquedaDATO(aux, ID);
}

template <class T>
void Lista<T>::eliminarporID(string ID) {
    Nodo* aux = ini;
    int pos = 0;
    bool encontrado = false;
    while (aux != nullptr && !encontrado) {
        if (aux->elem.getNombre() == ID) {
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
T Lista<T>::loopdeBusquedaDATO(Nodo* aux, string ID) {
    if (aux->elem.getNombre() == ID) {
        return aux->elem;
    }
    else  if (aux != nullptr) return loopdeBusquedaDATO(aux = aux->sig, ID);
}

//ORDENAMIENTOS O FILTRADOS

template <class T>
void Lista<T>::ordenarPorPrecioAscendente() {
    Nodo* aux = ini;
    Cola<T>colaaux;
    Producto* arr = new Producto[lon];
    for (int i = 0; i < lon; i++) {
        arr[i] = aux->elem;
        aux = aux->sig;
    }

    auto partition = [](Producto* arr, int start, int end) {

        int pivot = arr[start].getPrecio();

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i].getPrecio() <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);

        // Sorting left and right parts of the pivot element
        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i].getPrecio() <= pivot) {
                i++;
            }

            while (arr[j].getPrecio() > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
    };

    auto quickSort = [&](Producto* arr, int start, int end, auto&& quickSort)
        {

            // base case
            if (start >= end)
                return;

            // partitioning the array
            int p = partition(arr, start, end);

            // Sorting the left part
            quickSort(arr, start, p - 1, quickSort);

            // Sorting the right part
            quickSort(arr, p + 1, end, quickSort);
        };




    //auto ordIntercambio = [](Producto a[], int n)
    //    {
    //        for (int i = 0; i < n - 1; i++) {
    //            for (int k = i + 1; k < n; k++) {
    //                if (a[i].getPrecio() > a[k].getPrecio()) {
    //                    swap(a[i], a[k]);
    //                }
    //            }
    //        }
    //    };

    //ordIntercambio(arr, lon);
    quickSort(arr, 0, lon-1, quickSort);

    for (int i = lon - 1; i >= 0; i--) {
        colaaux.enqueue(arr[i]);
    }

    colaaux.mostrardatos();
}

template <class T>
void Lista<T>::ordenarPorPrecioDescendente() {
    Nodo* aux = ini;
    Cola<T>colaaux;
    Producto* arr = new Producto[lon];
    for (int i = 0; i < lon; i++) {
        arr[i] = aux->elem;
        aux = aux->sig;
    }

    auto Merge = [&](Producto* A1, Producto* A2, Producto* A, int n) {
        int i = 0, j = 0, k = 0;
        int mitad = n / 2;
        while (i < mitad && j < n - mitad) {
            if (A1[i].getPrecio() < A2[j].getPrecio()) {
                A[k] = A1[i];
                i++; k++;
            }
            else {
                A[k] = A2[j];
                j++; k++;
            }
        }
        while (i < mitad) {
            A[k] = A1[i];
            i++; k++;
        }
        while (j < n - mitad) {
            A[k] = A2[j];
            j++; k++;
        }
        };


    auto mergeSort = [&](Producto* A, int n, auto mergeSort)->void{
        if (n > 1) {
            int mitad = n / 2;
            Producto* A1 = new Producto[mitad];
            Producto* A2 = new Producto[n - mitad];

            for (int i = 0; i < mitad; i++) {
                A1[i] = A[i];
            }
            for (int i = mitad; i < n; i++) {
                A2[i - mitad] = A[i];
            }
            mergeSort(A1, mitad, mergeSort);
            mergeSort(A2, n - mitad, mergeSort);
            Merge(A1, A2, A, n);
        };
        };



    /*auto ordBurbujaModificado = [](Producto a[], int n) {
        bool ordenado;
        for (int i = 0; i < n - 1; i++) {
            ordenado = true;
            for (int j = 0; j < n - (i + 1); j++) {
                if (a[j].getPrecio() > a[j + 1].getPrecio()) {
                    swap(a[j], a[j + 1]);
                    ordenado = false;
                }
            }
            if (ordenado)break;
        }
    };*/

    //ordBurbujaModificado(arr, lon);
    mergeSort(arr, lon, mergeSort);
    for (int i = 0; i < lon; i++) {
        colaaux.enqueue(arr[i]);
    };

    colaaux.mostrardatos();
}

template <class T>
void Lista<T>::desordenamientoShuffle() {
    Nodo* aux = ini;
    Cola<T>colaAux;
    T* arr = new T[lon];
    for (int i = 0; i < lon; i++) {
        arr[i] = aux->elem;
        aux = aux->sig;
    }
    delete aux;
    for (int i = lon - 1; i > 0; i--)
    {
        int j = (rand() % (i + 1));
        swap(arr[j], arr[i]);
        colaAux.enqueue(arr[i]);
    }
    colaAux.mostrardatos();
}