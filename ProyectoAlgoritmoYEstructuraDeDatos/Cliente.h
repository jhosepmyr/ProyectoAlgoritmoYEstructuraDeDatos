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
            this->productos.MostrarDatosPROD();
            cout << endl << "Desea agregar algun elemento al carrito(1:SI, 2: NO):";
            cin >> opc;
            if (opc == '1') {
                string identificadorAux = "";
                cout << "Elija el producto que desea agregar al carrito(INGRESE EL ID):";
                cin >> identificadorAux;
                //se busca de la lista de productos por identificar y lo retorna
                Producto productoAux = this->productos.buscarporID(identificadorAux);
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
            this->pedido.setNombreArchivoPedido(nombrePedido);
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
        this->pedido.setNombreArchivoPedido("");
        this->pedido.eliminarProductos();
    }

    void reactualizarProductosAlmacen() {
        for (int i = 0; i < this->pedido.getCantidadProductosCarrito(); i++)
        {
            Producto auxProduc = this->pedido.getProductoPorPosicion(i);
            this->productos.agregaFinal(auxProduc);
        }
    }

        // Función para agregar un Pedido al archivo (creando el archivo si no existe)
    void agregarPedido(Pedido pedido) {
        string rutaClientepedido = this->personal.getNombreArchivoPropio();
        // Abre el archivo en modo append
        ofstream archivoSalida(rutaClientepedido, ios_base::app); 
        if (archivoSalida.is_open()) {
            archivoSalida << pedido.getNombreArchivo() <<endl;
            for (int i = 0; i < pedido.getCantidadProductosCarrito(); i++)
            {
                archivoSalida << pedido.getProductoPorPosicion(i).getNombre() << ' ' << pedido.getProductoPorPosicion(i).getPrecio()<<' '<< pedido.getProductoPorPosicion(i).getTipo()<<' '<< pedido.getProductoPorPosicion(i).getIdentificador() << endl;
            }
            archivoSalida.close();
            //cout << "Pedido agregado al archivo." << endl;
        }
    }

    Pila<Pedido> cargarPedidos() {
        string rutaClientepedidos = this->personal.getNombreArchivoPropio();
        ifstream archivoEntrada(rutaClientepedidos);
        string nombreCliente;
        Pila<Pedido> pedidos;
        if (archivoEntrada.is_open())
        {
            string linea;
            while (getline(archivoEntrada, linea)) {
                Pedido pedido;
                pedido.setNombreArchivoPedido(linea);// El primer dato de la línea es el nombre del cliente
                while (getline(archivoEntrada, linea) && !linea.empty()) {
                    istringstream iss(linea);
                    string nombreProducto;
                    float precio;
                    string tipo;
                    string id;
                    iss >> nombreProducto >> precio>>tipo>>id;
                    Producto auxProduct(nombreProducto, precio, tipo, id);
                    pedido.agregaraCarrito(auxProduct);
                }
                pedidos.push(pedido);
                pedido.eliminarProductos();
            }
        }
        return pedidos;
    }

    void mostrarPedidos() {
        Pila<Pedido> auxPedidos = this->pedidos;
        auxPedidos.pop().mostrarListaProductos();
    }
};