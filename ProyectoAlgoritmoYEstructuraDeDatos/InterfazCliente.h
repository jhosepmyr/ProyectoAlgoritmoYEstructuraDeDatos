#pragma once
#include "Interfaz.h"
#include "Cliente.h"
#include <sstream>

using namespace std;

class InterfazCliente : public Interfaz {
private:
	Cliente* clienteAux;
    Files datosActualizados;

public:
	InterfazCliente(string _nombre, string _contra) {
		this->clienteAux = new Cliente(_nombre, _contra);
        this->tipoUsuario = '1';
        extraerInformacionUsuario("DatosSesionClientes.txt");
	}

	void mostrarInterfaz() {
        do {
            system("cls");
            this->opcion = '0';
            cout << "BIENVENIDO "+ this->clienteAux->getNombre() << endl;
            cout << "1. Informacion personal\n";
            cout << "2. Modificar informacion\n";
            cout << "3. Mostrar Productos\n";
            cout << "4. Mi carrito de compras\n";
            cout << "5. Cerrar sesion\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            cin >> this->opcion;
            validarOpcion();
            system("cls");
            resultadosOpcionSeleccionada();
            if (this->opcion == '5') actualizarDatosSesion("DatosSesionClientes.txt");
            system("pause");
        } while (this->opcion != '5');
        this->clienteAux = nullptr;
        cout << "\nSESION CERRADA\n";
		system("pause>0");
		return;
	}

    void resultadosOpcionSeleccionada() {
        switch (this->opcion) {
        case '1': {
            this->clienteAux->mostrarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '2': {
            this->clienteAux->actualizarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '3': {
            this->clienteAux->mostrarProductos();
            this->opcion = '0';
            break;
        }
        case '4': {
            this->clienteAux->mostrarPedido();
            this->opcion = '0';
            break;
        }
        }
    }

    //extraer la informacion personal del txt
    void extraerInformacionUsuario(string rutaArchivoDatos) {
        ifstream archivoLectura(rutaArchivoDatos);
        string contenidoArchivo;

        if (!archivoLectura.is_open())
        {
            cout << "Error al abrir el archivo " << this->clienteAux->getDatosInicioSesion() << endl;
            return;
        }
        string linea;
        while (getline(archivoLectura, linea))
        {
            bool verificarNombre = linea.find(this->clienteAux->getNombre()) != string::npos;
            bool verificarContra = linea.find(this->clienteAux->getContra()) != string::npos;
            if (verificarContra && verificarNombre)
            {
                string nombre;
                string apellido;
                string contra;
                string correoElectronico;
                int numeroCelular;
                string direccion;
                char genero;
                int DNI;
                istringstream iss(linea);
                iss >> nombre >> contra >> apellido >> correoElectronico >> numeroCelular >> direccion >> genero >> DNI;
                this->clienteAux->setTodaInformacion(nombre, contra, apellido, correoElectronico, numeroCelular, direccion, genero, DNI);
                return;
            }
        }
        archivoLectura.close();
        ofstream archivoEscritura(rutaArchivoDatos);
        archivoEscritura << contenidoArchivo;
        archivoEscritura.close();
    }

    //actualiza el archivo txt
    void actualizarDatosSesion(string rutaArchivoDatos) {
        ifstream archivoLectura(rutaArchivoDatos);
        string contenidoArchivo;
        if (archivoLectura.is_open())
        {
            string linea;
            while (getline(archivoLectura, linea))
            {
                bool verificarNombre = linea.find(this->clienteAux->getNombre()) != string::npos;
                bool verificarContra = linea.find(this->clienteAux->getContra()) != string::npos;
                if (verificarContra && verificarNombre)
                {
                    string nuevaLinea = this->clienteAux->getNombre() + " " +
                        this->clienteAux->getContra() + " " +
                        this->clienteAux->getApellido() + " " +
                        this->clienteAux->getCorreoElectronico() + " " +
                        to_string(this->clienteAux->getNumeroCelular()) + " " +
                        this->clienteAux->getDireccion() + " " +
                        to_string(this->clienteAux->getGenero()) + " " +
                        to_string(this->clienteAux->getDNI());
                    contenidoArchivo += nuevaLinea + "\n";
                }
                else
                {
                    contenidoArchivo += linea + "\n";
                }
            }
            archivoLectura.close();
            ofstream archivoEscritura(rutaArchivoDatos);
            archivoEscritura << contenidoArchivo;
            archivoEscritura.close();

            //cout << "Datos actualizados en el archivo exitosamente." <<endl;
        }
        else {
            //cerr << "Error al abrir el archivo para lectura." <<endl;
        }
    }

};