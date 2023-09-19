#pragma once
#include <iostream>

using namespace std;


//Interfaz 
auto opcionValida = [](char op)->bool{return op == '1' || op == '2' || op == '3'; };
