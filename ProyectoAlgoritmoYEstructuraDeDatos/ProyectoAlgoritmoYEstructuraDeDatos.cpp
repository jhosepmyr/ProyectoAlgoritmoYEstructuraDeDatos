#include "pch.h"
#include <iostream>
#include <string>
//#include <locale.h>
#include "InterfazInicio.h"
#include "InterfazLogin.h"
//using namespace System;
using namespace std;

int main()
{
    //setlocale(LC_ALL, "");
    //Console::SetWindowSize(100, 100);
    //Console::CursorVisible = false;

    InterfazLogin* sistema;
    sistema->ventanaIngreso();

    system("pause>0");
    return 0;
}