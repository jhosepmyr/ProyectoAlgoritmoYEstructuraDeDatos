#pragma once
#include <iostream>
#include "HashEntidad.h"
using namespace std;
template<typename T>
class HashTabla {
private:
	HashEntidad<T>** tabla;
	int numElementos;
	int TABLE_SIZE;
public:
	HashTabla(int TABLE_SIZE = 128) {
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new HashEntidad<T> * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
			tabla[i] = nullptr;
		numElementos = 0;
	}

	~HashTabla() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (tabla[i] != nullptr)delete tabla[i];
		}
		delete[]tabla;
	}

	int _hash(string key) {
		int hash = 0;

		for (char ch : key) {
			hash += int(ch);
		}
		hash = hash * 3 / 10;
		return hash % TABLE_SIZE;
	}

	void insertar(string key, T value) {
		int base, step, hash;
		//validar si la tabla esta llena 
		if (numElementos == TABLE_SIZE)return;
		//Funcion Hash
		base = _hash(key); //base es el indice 
		hash = base; //igualas hash a base 
		step = 0; //para recorrer la tabla
		while (tabla[hash] != nullptr) {
			//funcion hash
			hash = (base + step) % TABLE_SIZE;
			step++;
			//se recorre la tabla hasta encontrar un espacio
		}
		//almacenarlo en la tabla
		tabla[hash] = new HashEntidad<T>(key, value);
		numElementos++;
	}

	int size() { return TABLE_SIZE; }
	int sizeactual() { return numElementos; }
	int buscar(string key) {
		int step = 0;
		int i, base;
		i = base = _hash(key);
		while (true) {
			if (tabla[i] == nullptr)return -1;
			else if (tabla[i]->getKey() == key)return i;
			else step++;
			i = (base + step) % TABLE_SIZE;
		}
	}

	T buscarElem(string key) {
		int step = 0;
		int i, base;
		i = base = _hash(key);
		while (true) {
			if (tabla[i] == nullptr)break;
			else if (tabla[i]->getKey() == key)return tabla[i]->getValue();
			else step++;
			i = (base + step) % TABLE_SIZE;
		}
	}

	void imprimir_grafos(string keys) {
		buscarElem(keys).imprimir_grafo();
	}
};