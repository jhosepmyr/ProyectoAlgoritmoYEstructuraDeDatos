#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <set>
#include "Lista.h"
#include "Producto.h"
using namespace std;

class Files {
	//Se pasara los datos de txt a sus clases respectivas
private:
	string nombreUsuario;
	string apellidoUsuario;
public:
	Files() {};
	Files(string nombre, string apellido) {
		this->nombreUsuario = nombre;
		this->apellidoUsuario = apellido;
	}

	//getNombreArchivoPropio-> no se utiliza en nada por ahora
	string getNombreArchivoPropio() {
		// Ruta relativa desde la ubicación del archivo Files.h hasta la carpeta de Archivos
		string nombreArchivoPropio = "InformacionUsuarios/" + this->nombreUsuario + this->apellidoUsuario + ".txt";
		// Intentar abrir el archivo en modo lectura
		ifstream archivoEntrada(nombreArchivoPropio);

		if (archivoEntrada.is_open()) {
			archivoEntrada.close();
			//cout << "El archivo existe." << endl;
		}
		else {
			// El archivo no existe, crearlo
			ofstream archivoSalida(nombreArchivoPropio, std::ios::out);

			if (archivoSalida.is_open()) {
				archivoSalida.close();
				//cout << "El archivo no existía y ha sido creado." << endl;
			}
			else {
				cout << "Error al crear el archivo." << endl;
			}
		}
		return nombreArchivoPropio;
	}
	string generarIDUnico() {
		string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(0, caracteres.size() - 1);
		set<string> IDsExistentes;

		while (true) {
			string nuevoID;
			for (int i = 0; i < 7; i++) {
				nuevoID += caracteres[distribution(generator)];
			}

			// Verificar que el nuevo ID no se repita en el archivo TXT
			if (!existeIDEnArchivo(nuevoID, "DatosProductos.txt")) {
				return nuevoID;
			}
		}
	}
	bool existeIDEnArchivo(const string& id, const string& rutaTxt) {
		ifstream archivo(rutaTxt);
		string linea;
		while (getline(archivo, linea)) {
			// Parsear la línea para obtener el ID (asumiendo el formato "nombre precio tipo idUnico codigoVendedor")
			string token;
			istringstream ss(linea);
			ss >> token >> token >> token >> token;  // Saltar nombre, precio y tipo
			if (token == id) {
				archivo.close();
				return true;
			}
		}
		archivo.close();
		return false;
	}

	Lista<Producto> Dataset(Lista<Producto> lista, int numDatos) {
		string nombres[100] = { "Cepillo", "Televisor", "Papa", "Yuca", "Manzana", "Naranja", "Platano", "Fresa", "Piña", "Mango",
					  "Kiwi", "Uva", "Melon", "Sandia", "Smartphone", "Laptop", "Smartwatch", "Auriculares", "Camara",
					  "PS5", "Mouse", "Teclado", "Silla", "Mesa", "Monitor", "Libro", "Pelota", "Cuchillo", "Lámpara",
					  "Reloj", "Zapatos", "Gafas", "Sombrero", "Bicicleta", "DiscoDuro", "Impresora", "TecladoInalámbrico",
					  "Altavoces", "Microondas", "Refrigeradora", "Aspiradora", "MáquinaCafé", "Ventilador", "RobotCocina",
					  "Secadora", "Plancha", "Estufa", "Licuadora", "BateríaPortátil", "MonitorGaming", "Guitarra", "CámaraDeportiva",
					  "Pantalones", "Camisa", "ZapatosDeportivos", "Mochila", "Gorra", "LentesSol", "Collar", "Anillo", "Pulsera",
					  "Perfume", "JuegoMesa", "Peluche", "Bolso", "Corbata", "Calcetines", "Billetera", "Maleta", "FundaMóvil",
					  "Lápiz", "Cuaderno", "BolsaBasura", "Escoba", "PapelHigiénico", "CajaPañuelos", "BotellaAgua", "CepilloDientes",
					  "CremaDental", "CepilloPelo", "Revista", "CajaHerramientas", "CintaAdhesiva", "Báscula", "BicicletaEstática",
					  "CañaPescar", "TiendaCampaña", "Sartén", "Taza", "Candelabro", "Perchero", "Escritorio", "MáquinaCoser", "Ratón",
					  "Almohada", "BolsoDeporte", "MáscaraFacial", "CargadorPortátil", "Paraguas", "JuegoToallas" };

		string tipo[2] = { "Comestible", "NoComestible" };
		string codigoVendedor[6] = { "987653","543663","756323","523412","123456","272064" };

		for (int i = 0; i < numDatos; ++i) {
			string nombre = nombres[rand() % 100];
			double precio = (rand() % 500 + 50) / 10.0; // Rango de precios de 5.0 a 50.0 con incrementos de 0.1
			precio = round(precio * 10.0) / 10.0; // Redondear el precio a un solo decimal
			string tipoProducto = tipo[rand() % 2];
			string idUnico = generarIDUnico();
			string codigoVend = codigoVendedor[rand() % 6];

			Producto nuevoProducto(nombre, precio, tipoProducto, idUnico, codigoVend);
			lista.agregaFinal(nuevoProducto);
		}

		return lista;
	}

	Lista<Producto> getProductos(string datosProductos = "DatosProductos.txt") {
		Lista<Producto> auxList;
		ifstream archivo(datosProductos);
		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				auto parseLine = [&]() {
					istringstream iss(linea);
					string nombre, tipo, identificador, codigoVendedor;
					int precio;
					iss >> nombre >> precio >> tipo >> identificador >> codigoVendedor;
					return Producto(nombre, precio, tipo, identificador, codigoVendedor);
				};
				Producto product = parseLine();
				auxList.agregaFinal(product);
			}
			archivo.close();
		}
		else {
			cerr << "Error al abrir el archivo." <<endl;
		}

		// Agregar datos generados aleatoriamente con la función Dataset

		auxList = Dataset(auxList, 500);

		return auxList;
	}

	void actualizarProductosTxt(Lista<Producto> productos, string datosProductos = "DatosProductos.txt") {
		ofstream archivoEscritura(datosProductos);
		if (!archivoEscritura.is_open()) {
			cout << "Error al abrir el archivo " << endl;
			return;
		}

		auto createLine = [](Producto producto) {
			return producto.getNombre() + " " +
				to_string(static_cast<int>(producto.getPrecio())) + " " +
				producto.getTipo() + " " +
				producto.getIdentificador() + " " +
				producto.getCodigoVendedor();
		};

		for (int n = 0; n < productos.longitud(); ++n) {
			// Escribir la línea en el nuevo formato
			archivoEscritura << createLine(productos.obtenerPos(n)) << endl;
		}

		archivoEscritura.close();
	}
};
