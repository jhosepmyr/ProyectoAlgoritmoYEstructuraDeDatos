#pragma once
#include "InterfazLogin.h"
using namespace System;
using namespace std;

class InterfazInicio : public Interfaz {
private:
    InterfazLogin* interfazLogin;
public:
    InterfazInicio() {
        interfazLogin = new InterfazLogin();
    }
    void ventanaInicio() {
        Console::SetCursorPosition(0, 8);
        Console::ForegroundColor = ConsoleColor::White;
 
        cout << R"(
         _______  __    __  .______       __    __    
        /  _____||  |  |  | |   _  \     |  |  |  |   
       |  |  __  |  |  |  | |  |_)  |    |  |  |  |   
       |  | |_ | |  |  |  | |      /     |  |  |  |   
       |  |__| | |  `--'  | |  |\  \----.|  `--'  |   
        \______|  \______/  | _| `._____| \______/    
            _______. __    __    ______   .______  
           /       ||  |  |  |  /  __  \  |   _  \ 
          |   (----`|  |__|  | |  |  |  | |  |_)  |
           \   \    |   __   | |  |  |  | |   ___/ 
       .----)   |   |  |  |  | |  `--'  | |  |     
       |_______/    |__|  |__|  \______/  | _|                               
)";
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(14, 22);
        cout << "Presiona ENTER para continuar";
        cin.get();
        system("cls");
    }
    void iniciarLogin() {
        this->interfazLogin->mostrarInterfaz();
    }
};

