#pragma once
using namespace std;
template<typename T>
class HashEntidad {
private:
	string key;
	T value;
public:
	HashEntidad(string key, T value) {
		this->key = key;
		this->value = value;
	}
    string getKey() { return key; }
	T getValue() { return value; }
};