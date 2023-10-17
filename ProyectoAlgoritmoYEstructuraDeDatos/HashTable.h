#pragma once
#include <iostream>
#include "HashEntidad.h"

class HashTabla {
private:
	HashEntidad** tabla;
	int numElementos;
	int TABLE_SIZE;

public:
	HashTabla(int TABLE_SIZE = 128) {
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new HashEntidad * [TABLE_SIZE];
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

	void insertar(int key, int value) {
		int base, step, hash;
		//validar si la tabla esta llena 
		if (numElementos == TABLE_SIZE)return;
		//Funcion Hash
		base = key % TABLE_SIZE; //base es el indice 
		hash = base; //igualas hash a base 
		step = 0; //para recorrer la tabla
		while (tabla[hash] != nullptr) {
			//funcion hash
			hash = (base + step) % TABLE_SIZE;
			step++;
			//se recorre la tabla hasta encontrar un espacio
		}
		//almacenarlo en la tabla
		tabla[hash] = new HashEntidad(key, value);
		numElementos++;
	}

	int size() { return TABLE_SIZE; }
	int sizeactual() { return numElementos; }
	int buscar(int key) {
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE;
		while (true) {
			if (tabla[i] == nullptr)return -1;
			else if (tabla[i]->getKey() == key)return i;
			else step++;
			i = (base + step) % TABLE_SIZE;
		}
	}

	int buscarElem(int key) {
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE;
		while (true) {
			if (tabla[i] == nullptr)return -1;
			else if (tabla[i]->getKey() == key)return tabla[i]->getValue();
			else step++;
			i = (base + step) % TABLE_SIZE;
		}
	}
};