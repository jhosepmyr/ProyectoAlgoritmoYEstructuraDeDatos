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
            cout << endl << "Desea agregar algun elemento al carrito(1:SI, 2: NO):";
            cin >> opc;
            if (opc == '1') {
                string identificadorAux = "";
                cout << "Elija el producto que desea agregar al carrito:\n";
                cout << "(INGRESE EL ID): ";
                cin >> identificadorAux;
                //se busca de la lista de productos por identificar y lo retorna
                Producto productoAux = this->productos.buscarporID(identificadorAux,1);
                //el producto retornado se agrega al unico pedido
                this->pedido.agregaraCarrito(productoAux);
                //el pedido se agrega a la pila pedidos
                this->productos.eliminarporID(identificadorAux);
            }
        } while (opc!='2');

        this->pedidos.push(pedido);
    }

    void mostrarPedido() {
        this->pedido.mostrarListaProductos();
        cout << "---------------------------" << endl;
        system("pause");
        confirmarPedido();
    }

    void confirmarPedido() {
        system("cls");
        char desicion = '0';
        cout << endl << "El pago total por el pedido es: "<< to_string(this->pedido.getPrecioTotal());
        cout << endl << "Confirmar pago(1:SI, 2: NO):"<<endl;
        cin >> desicion;
        if (desicion=='1')
        {
            static int numPedido = 1;
            string nombrePedido = this->nombre+this->contra+to_string(numPedido);
            this->pedido.setNombrePedido(nombrePedido);
            agregarPedido(this->pedido);
            numPedido++;
            restaurarPedido();
            cout << endl << "GRACIAS POR SU COMPRA" << endl;
        }
        else
        {
            reactualizarProductosAlmacen();
            this->pedido.eliminarProductos();
            cout << endl << "ES UNA LASTIMA QUE NO PUDO COMPLETAR SU COMPRA" << endl;

        }
    }

    void restaurarPedido() {
        this->pedido.setNombrePedido("");
        this->pedido.eliminarProductos();
    }

    void reactualizarProductosAlmacen() {
        for (int i = 0; i < this->pedido.getCantidadProductosCarrito(); i++)
        {
            Producto auxProduc = this->pedido.getProductoPorPosicion(i);
            this->productos.agregaFinal(auxProduc);
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
            archivoSalida << "\n" << pedido.getNombrePedido() << "|";
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
        Pila<Pedido> auxPedidos = this->pedidos;

        if (auxPedidos.estaVacia()) {
            cout << "No hay pedidos registrados." << endl;
        }
        else {
            cout << "Pedidos registrados:" << endl;
            auxPedidos.mostrarDatosPila();
        }
    }
};