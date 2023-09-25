#include "pch.h"
#include <iostream>
#include <string>
#include "InterfazInicio.h"
#include "InterfazLogin.h"
using namespace std;
using namespace System;
int main()
{
    Console::SetWindowSize(60,40);
    InterfazInicio* sistema = new InterfazInicio();
    sistema->ventanaInicio();
    sistema->iniciarLogin();

    system("pause>0");
    return 0;
}