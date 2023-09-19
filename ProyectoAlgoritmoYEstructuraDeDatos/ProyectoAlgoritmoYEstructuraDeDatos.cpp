#include "pch.h"
#include <iostream>
#include <string>
#include <locale.h>

#include "InterfazInicio.h"

using namespace System;
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int opcion = 1;

    Console::SetWindowSize(100, 100);
    Console::CursorVisible = false;

    InterfazInicio sistema;
    sistema.ventanaInicio();
    sistema.iniciarLogin();

    system("pause>0");
    return 0;
}