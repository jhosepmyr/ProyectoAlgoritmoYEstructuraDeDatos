#include "pch.h"
#include <iostream>
#include <string>
//#include <locale.h>
#include "InterfazInicio.h"

using namespace System;
using namespace std;

int main()
{
    //setlocale(LC_ALL, "");
    Console::SetWindowSize(60, 40);
    Console::CursorVisible = false;

    InterfazInicio* sistema = new InterfazInicio();
    sistema->ventanaInicio();
    sistema->iniciarLogin();

    system("pause>0");
    return 0;
}