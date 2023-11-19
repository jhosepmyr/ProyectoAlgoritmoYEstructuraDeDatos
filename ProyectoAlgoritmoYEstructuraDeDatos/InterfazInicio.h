#pragma once
#include "InterfazLogin.h"
#include <thread>
#include <chrono>
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
        Console::SetCursorPosition(6, 16);
        int duracion = 5000;
        int porcentajeTotal = 40;
        int intervaloActualizacion = 100;
        int transcurrido = 0;

        while (transcurrido < duracion) {
            int porcentaje = (transcurrido * 100) / duracion;
            int bloquesLlenos = (porcentaje * porcentajeTotal) / 100;

            cout << "\r\t[";
            for (int i = 0; i < bloquesLlenos; ++i) {
                cout << char(219);
            }
            for (int i = bloquesLlenos; i < porcentajeTotal; ++i) {
                cout << char(176);
            }
            cout << "] " << porcentaje << "%";
            cout.flush();

            this_thread::sleep_for(chrono::milliseconds(intervaloActualizacion));
            transcurrido += intervaloActualizacion;
        }
        system("cls");
    }
    void iniciarLogin() {
        this->interfazLogin->mostrarInterfaz();
    }
};

