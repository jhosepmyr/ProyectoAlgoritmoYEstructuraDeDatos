#pragma once
#include "Usuario.h"
#include "Pedido.h"

using namespace std;

class Cliente : public Usuario {
private:
    string nombreArchivoClienteEspecifico; //implementar con el ID Ejem: cliente10.txt
    Pedido pedido;
    Pila<Pedido> pedidos;
public:
    Cliente(string _nombre, string _contra) : Usuario(_nombre, _contra) {
        this->datosInicioSesion = "DatosSesionClientes.txt";
        getInformacionPersonalTxt();
        this->pedidos = cargarPedidos();
    }

    void mostrarProductos() {
        char opc = '0';
        do
        {
            system("cls");
            //muestra producto actualizados
            cout << endl << "Filtrado para los productos:";
            cout << endl << "1.Menor a mayor precio";
            cout << endl << "2.Mayor a menor precio";
            cout << endl << "3.Ninguno de los anteriores";
            cout << endl;
            cin >> opc;
            system("cls");
            switch (opc)
            {
            case '1': {
                this->productos.ordenarPorPrecioDescendente();
                this->productos.MostrarDatosPROD();
                break;
            }
            case '2': {
                this->productos.ordenarPorPrecioAscendente();
                this->productos.MostrarDatosPROD();
                break;
            }
            default:
                this->productos.desordenamientoShuffle();
                this->productos.MostrarDatosPROD();
                break;
            }
            cout << endl << endl << "Desea agregar algun elemento al carrito(1:SI, 2: NO):";
            cin >> opc;
            if (opc == '1') {
                string identificadorAux = "";
                cout << "Elija el producto que desea agregar al carrito:" << endl;
                cout << "(INGRESE EL ID): " << endl;
                cin >> identificadorAux;
                if (this->productos.existeID(identificadorAux,1))
                {
                    //se busca de la lista de productos por identificar y lo retorna
                    Producto productoAux = this->productos.buscarporID(identificadorAux, 1);
                    //el producto retornado se agrega al unico pedido
                    this->pedido.agregaraCarrito(productoAux);
                    //el pedido se agrega a la pila pedidos
                    this->productos.eliminarporID(identificadorAux);
                }
                else
                {
                    cout << "Codigo ingresado invalido" << endl;
                    system("pause");
                }
            }
        } while (opc!='2');
    }

    void mostrarPedido() {
        this->pedido.mostrarListaProductos();
        system("pause>0");
        if (!this->pedido.isVacio())
        {
            confirmarPedido();
        }  
    }

    string generarNumeroAleatorio() {
        // Inicializa el generador de números aleatorios con una semilla basada en el tiempo
        srand(static_cast<unsigned>(time(nullptr)));

        // Lista de cifras disponibles (1 al 9)
        vector<int> cifrasDisponibles{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // Mezcla aleatoriamente las cifras
        random_shuffle(cifrasDisponibles.begin(), cifrasDisponibles.end());

        // Asegura que la primera cifra no sea 0
        if (cifrasDisponibles[0] == 0) {
            swap(cifrasDisponibles[0], cifrasDisponibles[1]);
        }

        // Construye el número aleatorio como una cadena
        ostringstream numeroAleatorio;
        for (int i = 0; i < 7; ++i) {
            numeroAleatorio << cifrasDisponibles[i];
        }

        return numeroAleatorio.str();
    }

    void confirmarPedido() {
        system("cls");
        if (!this->pedido.isVacio())
        {
            char desicion = '0';
            cout << endl << "El pago total por el pedido es: " << to_string(this->pedido.getPrecioTotal());
            cout << endl << "Confirmar pago(1:SI, 2: NO):" << endl;
            cin >> desicion;
            if (desicion == '1')
            {
                string nombrePedido = generarNumeroAleatorio();
                this->pedido.setNombrePedido(nombrePedido);
                agregarPedido(this->pedido);
                restaurarPedido();
                cout << endl << "GRACIAS POR SU COMPRA" << endl;
            }
            else
            {
                reactualizarProductosAlmacen();
                cout << endl << "ES UNA LASTIMA QUE NO PUDO COMPLETAR SU COMPRA" << endl;

            }
        }
        else
        {
            cout << endl << "Su pedido esta vacio" << endl;
        }

    }

    void restaurarPedido() {
        if (!this->pedido.isVacio()) {
             this->pedido.setNombrePedido("");
             this->pedido.eliminarProductos();
        }
    }

    void reactualizarProductosAlmacen() {
        if (!this->pedido.isVacio())
        {
            for (int i = 0; i < this->pedido.getCantidadProductosCarrito(); i++)
            {
                Producto auxProduc = this->pedido.eliminarUltimoProducto();
                this->productos.agregaFinal(auxProduc);
            }
        }
    }

    string formatoProducto(Producto product) {
        ostringstream ss;
        ss << "{" << product.getNombre() << ";" << product.getPrecio() << ";" << product.getTipo() << ";" << product.getIdentificador()<<";" << product.getCodigoVendedor() << "}";
        return ss.str();
    }

        // Función para agregar un Pedido al archivo (creando el archivo si no existe)
    void agregarPedido(Pedido pedido) {
        string rutaClientepedido = this->personal.getNombreArchivoPropio();
        // Abre el archivo en modo append
        ofstream archivoSalida(rutaClientepedido, ios_base::app); 
        if (archivoSalida.is_open()) {
            archivoSalida << endl << pedido.getNombrePedido() << "|";
            for (int i = 0; i < pedido.getCantidadProductosCarrito(); i++)
            {
                archivoSalida << formatoProducto(pedido.getProductoPorPosicion(i));
            }
            archivoSalida << "|";

            archivoSalida.close();
        }
    }

    Pila<Pedido> cargarPedidos() {
        Pila<Pedido> pedidos;
        string rutaClientepedidos = this->personal.getNombreArchivoPropio();
        ifstream archivoEntrada(rutaClientepedidos);

        if (!archivoEntrada.is_open())
        {
            cerr << "Error al abrir el archivo: " << rutaClientepedidos << endl;
            return pedidos;
        }

        string linea;
        while (getline(archivoEntrada, linea)) {
            istringstream ss(linea);
            string nombrePedido;
            getline(ss, nombrePedido, '|');

            Pedido pedido;
            pedido.setNombrePedido(nombrePedido);

            string productosData;
            getline(ss, productosData, '|');

            istringstream productosStream(productosData);
            string productoInfo;
            while (getline(productosStream, productoInfo, '}')) {
                if (!productoInfo.empty()) {
                    // Eliminamos el carácter '{' inicial
                    productoInfo.erase(productoInfo.begin());

                    // Dividimos los datos del producto utilizando ';'
                    istringstream productoInfoStream(productoInfo);
                    string nombre;
                    string precio;
                    string tipo;
                    string identificador;
                    string codigoVendedor;

                    getline(productoInfoStream, nombre, ';');
                    getline(productoInfoStream, precio, ';');
                    getline(productoInfoStream, tipo, ';');
                    getline(productoInfoStream, identificador, ';');
                    getline(productoInfoStream, codigoVendedor, ';');

                    Producto producto(nombre, stof(precio), tipo, identificador, codigoVendedor);
                    pedido.agregaraCarrito(producto);
                }
            }
            pedidos.push(pedido);
        }
        archivoEntrada.close();
        return pedidos;
    }

    void mostrarPedidos() {
        if (this->pedidos.estaVacia()) {
            cout << "No hay pedidos registrados."<<endl;
        }
        else {
            cout << "Pedidos registrados:" << endl;
            cout << "Numero de pedidos realizados: " << this->pedidos.cantidadElementos() << endl;

            this->pedidos = cargarPedidos();
            this->pedidos.mostrarTodosLosPedidos();

            //trae de nuevo los pedidos eliminados
            this->pedidos = cargarPedidos();
        }  
    }
};