#pragma once
#include "Interfaz.h"
#include "InterfazLogin.h"

using namespace System;
using namespace std;

class InterfazInicio : public Interfaz {
private:
    InterfazLogin* interfazLogin;
public:
    InterfazInicio() {}
    void ventanaInicio() {
        Console::SetCursorPosition(0, 8);
        cout << endl;
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
        cout << endl;
        cout << "Presiona ENTER para continuar";
        cout << endl;
        system("pause>0");
        system("cls");
    }
    void iniciarLogin() {
        this->interfazLogin->mostrarInterfaz();
    }
};

