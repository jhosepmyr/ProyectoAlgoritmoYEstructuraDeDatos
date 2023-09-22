#pragma once
#include "Interfaz.h"
#include "Vendedor.h"

using namespace std;

class InterfazVendedor : public Interfaz {
private: 
    Vendedor* vendedorAux;
public:
    InterfazVendedor(string _nombre, string _contra) {

        this->vendedorAux = new Vendedor(_nombre, _contra);
        this->vendedorAux->setProductosPropios();
        this->tipoUsuario = '2';
        extraerInformacionUsuario("DatosSesionVendedores.txt");
    }

    void mostrarInterfaz() {
        do {
            system("cls");
            this->opcion = '0';
            cout << "BIENVENIDO " + this->vendedorAux->getNombre() << endl;
            cout << "1. Informacion personal\n";
            cout << "2. Modificar informacion\n";
            cout << "3. Mis Productos\n";
            cout << "4. Modificar productos\n";
            cout << "5. Salir\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            cin >> this->opcion;
            validarOpcion();
            system("cls");
            resultadosOpcionSeleccionada();
            if (this->opcion == '5') actualizarDatosSesion("DatosSesionVendedores.txt");
            system("pause");
        } while (this->opcion != '5');
        this->vendedorAux = nullptr;
        cout << "\nSESION CERRADA\n";
        system("pause>0");
        return;
    }

    void resultadosOpcionSeleccionada() {
        switch (this->opcion) {
        case '1': {
            this->vendedorAux->mostrarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '2': {
            this->vendedorAux->actualizarDatosPersonales();
            this->opcion = '0';
            break;
        }
        case '3': {
            this->vendedorAux->mostrarMisProductos();
            this->opcion = '0';
            break;
        }
        case '4': {
            this->vendedorAux->aniadirProducto();
            this->opcion = '0';
            break;
        }
        }
    }

    void extraerInformacionUsuario(string rutaArchivoDatos) {
        ifstream archivoLectura(rutaArchivoDatos);
        string contenidoArchivo;

        if (!archivoLectura.is_open())
        {
            cout << "Error al abrir el archivo " << this->vendedorAux->getDatosInicioSesion() << endl;
            return;
        }
        string linea;
        while (getline(archivoLectura, linea))
        {
            bool verificarNombre = linea.find(this->vendedorAux->getNombre()) != string::npos;
            bool verificarContra = linea.find(this->vendedorAux->getContra()) != string::npos;
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
                this->vendedorAux->setTodaInformacion(nombre, contra, apellido, correoElectronico, numeroCelular, direccion, genero, DNI);
                return;
            }
        }
        archivoLectura.close();
        ofstream archivoEscritura(rutaArchivoDatos);
        archivoEscritura << contenidoArchivo;
        archivoEscritura.close();
    }

    void actualizarDatosSesion(string rutaArchivoDatos) {
        ifstream archivoLectura(rutaArchivoDatos);
        string contenidoArchivo;
        if (archivoLectura.is_open())
        {
            string linea;
            while (getline(archivoLectura, linea))
            {v
                bool verificarNombre = linea.find(this->vendedorAux->getNombre()) != string::npos;
                bool verificarContra = linea.find(this->vendedorAux->getContra()) != string::npos;
                if (verificarContra && verificarNombre)
                {
                    string nuevaLinea = this->vendedorAux->getNombre() + " " +
                        this->vendedorAux->getContra() + " " +
                        this->vendedorAux->getApellido() + " " +
                        this->vendedorAux->getCorreoElectronico() + " " +
                        to_string(this->vendedorAux->getNumeroCelular()) + " " +
                        this->vendedorAux->getDireccion() + " " +
                        to_string(this->vendedorAux->getGenero()) + " " +
                        to_string(this->vendedorAux->getDNI());
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