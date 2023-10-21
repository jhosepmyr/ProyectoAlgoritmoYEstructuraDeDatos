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
    // función con template para iniciar sesión

    template <typename T, class tipoInterfaz>
    void iniciarSesion() {
        string nombre, contra;
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(21, 28);
        cout << "INICIO DE SESION";
        Console::SetCursorPosition(20, 30);
        cout << "Nombre: ";
        cin >> nombre;
        Console::SetCursorPosition(20, 32);
        cout << "Contrasenia: ";
        cin >> contra;

        //uso de template,
        T* auxUsuario = new T(nombre, contra);

        ifstream archivoLectura(auxUsuario->getDatosInicioSesion());
        
        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << auxUsuario->getDatosInicioSesion() << endl;
            return;
        }

        string linea;
        bool credencialesCorrectas = false;

        while (getline(archivoLectura, linea)) {
            // Separar la línea en nombre de usuario y contraseña
            istringstream iss(linea);
            string storedNombre, storedContra;
            if (iss >> storedNombre >> storedContra) {
                if (nombre == storedNombre && contra == storedContra) {
                    credencialesCorrectas = true;
                    break;
                }
            }
        }

        archivoLectura.close();

        if (credencialesCorrectas) {
            cout << "Inicio de sesion exitoso." << endl;
            tipoInterfaz* auxInterfazUsuario = new tipoInterfaz(nombre, contra);
            auxInterfazUsuario->mostrarInterfaz();
            delete auxInterfazUsuario;
        }
        else {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(1, 34);
            cout << "Inicio de sesion fallido. Nombre o contrasenia incorrectos." << endl;
        }
        Console::SetCursorPosition(14, 35);
        Console::ForegroundColor = ConsoleColor::Blue;
        cout << "Presiona ENTER para volver";
        system("pause>0");
    }

    bool existeIDEnArchivo(const string& id, const string& rutaTxt) {
        ifstream archivo(rutaTxt);
        string linea;
        while (getline(archivo, linea)) {
            // Parsear la línea para obtener el ID (asumiendo el formato "nombre contrasena ID")
            string token;
            istringstream ss(linea);
            ss >> token >> token >> token;  // Saltar nombre y contraseña
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
        string nombre, contra;
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(16, 28);
        cout << "REGISTRO DE NUEVO USUARIO";
        Console::SetCursorPosition(20, 30);
        cout << "Nombre: ";
        cin >> nombre;
        Console::SetCursorPosition(20, 32);
        cout << "Contrasenia: ";
        cin >> contra;

        T* auxUsuario = new T(nombre, contra);

        // Generar un nuevo ID único
        string nuevoID = generarIDUnico(auxUsuario->getNombre(), auxUsuario->getDatosInicioSesion());
        auxUsuario->setID(nuevoID);

        if (verificarUsuarioExistente(nombre, contra, auxUsuario->getDatosInicioSesion())) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(1, 34);
            cout << "Registro fallido: Nombre de usuario ocupado en el sistema" << endl;
        }
        else {
            agregarNuevoUsuario(nombre, contra,auxUsuario->getID(), auxUsuario->getDatosInicioSesion());
        }
        Console::SetCursorPosition(14, 35);
        Console::ForegroundColor = ConsoleColor::Blue;
        cout << "Presiona ENTER para volver";
    }

    bool verificarUsuarioExistente(string nombreUsuario, string contraUsuario,string archivo) {
        ifstream archivoLectura(archivo);

        if (!archivoLectura.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            return false;
        }

        string linea;

        while (getline(archivoLectura, linea)) {
            // Separar la línea en nombre de usuario y contraseña
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
