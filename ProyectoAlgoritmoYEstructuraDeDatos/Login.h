#pragma once
#include <iostream>
#include "InterfazCliente.h"
#include "InterfazVendedor.h"
#include <random>
#include <set>
using namespace std;

class Login {
private:
public:
	Login(){}
    // funci�n con template para iniciar sesi�n

template <typename T, class tipoInterfaz>
void iniciarSesion() {
    string nombre, contra;   // 1
    Console::ForegroundColor = ConsoleColor::Blue;   // 1
    Console::SetCursorPosition(21, 28);   // 1
    cout << "INICIO DE SESION";   // 1
    Console::SetCursorPosition(20, 30);   // 1
    cout << "Nombre: ";   // 1
    cin >> nombre;   // 1
    Console::SetCursorPosition(20, 32);   // 1
    cout << "Contrasenia: ";   // 1
    cin >> contra;   // 1

    T* auxUsuario = new T(nombre, contra);   // 1

    ifstream archivoLectura(auxUsuario->getDatosInicioSesion());   // 1

    if (!archivoLectura.is_open()) {   // 1
        cout << "Error al abrir el archivo " << auxUsuario->getDatosInicioSesion() << endl;   // 1
        return;   // 1
    }

    string linea;   // 1
    bool credencialesCorrectas = false;   // 1

    while (getline(archivoLectura, linea)) {   // n
        istringstream iss(linea);   // 1
        string storedNombre, storedContra;   // 1
        if (iss >> storedNombre >> storedContra) {   // 1
            if (nombre == storedNombre && contra == storedContra) {   // 1
                credencialesCorrectas = true;   // 1
                break;   // 1
            }
        }
    }

    archivoLectura.close();   // 1

    if (credencialesCorrectas) {   // 1
        cout << "Inicio de sesion exitoso." << endl;   // 1
        tipoInterfaz* auxInterfazUsuario = new tipoInterfaz(nombre, contra);   // 1
        auxInterfazUsuario->mostrarInterfaz();   // 1
        delete auxInterfazUsuario;   // 1
    }
    else {
        Console::ForegroundColor = ConsoleColor::Red;   // 1
        Console::SetCursorPosition(1, 34);   // 1
        cout << "Inicio de sesion fallido. Nombre o contrasenia incorrectos." << endl;   // 1
    }
    Console::SetCursorPosition(14, 35);   // 1
    Console::ForegroundColor = ConsoleColor::Blue;   // 1
    system("pause>0");   // 1
}
    bool existeIDEnArchivo(const string& id, const string& rutaTxt) {
        ifstream archivo(rutaTxt);
        string linea;
        while (getline(archivo, linea)) {
            // Parsear la l�nea para obtener el ID (asumiendo el formato "nombre contrasena ID")
            string token;
            istringstream ss(linea);
            ss >> token >> token >> token;  // Saltar nombre y contrase�a
            if (token == id) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

    string generarIDUnico(const string& nombreUsuario, const string& rutaTxt) {
        set<string> IDsExistentes;
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(100000, 999999);

        while (true) {
            int num = distribution(generator);
            string nuevoID = to_string(num);

            // Verificar que el nuevo ID no se repita en el archivo TXT
            if (!existeIDEnArchivo(nuevoID, rutaTxt)) {
                return nuevoID;
            }
        }
    }


    // template para registrarse, admite todos los tipos de usuario
    template <typename T>
    void registrarse() {
        string nombre, contra;   // 1
        Console::ForegroundColor = ConsoleColor::Blue;   // 1
        Console::SetCursorPosition(16, 28);   // 1
        cout << "REGISTRO DE NUEVO USUARIO";   // 1
        Console::SetCursorPosition(20, 30);   // 1
        cout << "Nombre: ";   // 1
        cin >> nombre;   // 1
        Console::SetCursorPosition(20, 32);   // 1
        cout << "Contrasenia: ";   // 1
        cin >> contra;   // 1

        T* auxUsuario = new T(nombre, contra);   // 1

        string nuevoID = generarIDUnico(auxUsuario->getNombre(), auxUsuario->getDatosInicioSesion());   // n
        auxUsuario->setID(nuevoID);   // 1

        if (verificarUsuarioExistente(nombre, contra, auxUsuario->getDatosInicioSesion())) {   // n
            Console::ForegroundColor = ConsoleColor::Red;   // 1
            Console::SetCursorPosition(1, 34);   // 1
            cout << "Registro fallido: Nombre de usuario ocupado en el sistema" << endl;   // 1
        }
        else {
            agregarNuevoUsuario(nombre, contra, auxUsuario->getID(), auxUsuario->getDatosInicioSesion());   // 1
        }
        Console::SetCursorPosition(14, 35);   // 1
        Console::ForegroundColor = ConsoleColor::Blue;   // 1
        cout << "Presiona ENTER para volver";   // 1
    }

    bool verificarUsuarioExistente(string nombreUsuario, string contraUsuario,string archivo) {
        ifstream archivoLectura(archivo);

        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            return false;
        }

        string linea;

        while (getline(archivoLectura, linea)) {
            // Separar la l�nea en nombre de usuario y contrase�a
            istringstream iss(linea);
            string storedNombre, storedContra;
            if (iss >> storedNombre >> storedContra) {
                if (nombreUsuario == storedNombre && contraUsuario == storedContra) {
                    archivoLectura.close();
                    return true; // El usuario ya existe en el sistema
                }
            }
        }

        archivoLectura.close();
        return false; // El usuario no existe
    }
    
    void agregarNuevoUsuario(string nombre, string contra, string Id,string archivo) {
        // Abre el archivo en modo de escritura sin agregar
        ofstream archivoEscritura(archivo, ios_base::app);

        if (!archivoEscritura.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            return;
        }
        // Escribe los datos del nuevo usuario al final del archivo
        archivoEscritura << nombre << " " << contra << " " << Id << endl;
        archivoEscritura.close();

        Console::SetCursorPosition(18, 34);
        Console::ForegroundColor = ConsoleColor::Green;
        cout << "Registro exitoso." << endl;
    }

 };
