#pragma once
#include "Usuario.h"
#include "Pedido.h"
#include "ArbolAVL.h"
#include "conio.h"
#define ABAJO 80
#define ARRIBA 72

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
            for (int x = 2; x <= 57; x++) {//dibuja linea 
                Console::SetCursorPosition(x, 10); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            for (int x = 2; x <= 57; x++) { //dibuja linea 
                Console::SetCursorPosition(x, 25); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            //muestra producto actualizados
            Console::SetCursorPosition(17, 10); Console::ForegroundColor = ConsoleColor::White;
            cout << "Filtrado para los productos";
            Console::SetCursorPosition(19, 15);
            cout << "Mayor a menor precio";
            Console::SetCursorPosition(19, 17);
            cout << "Menor a mayor precio";
            Console::SetCursorPosition(16, 19);
            cout << "Ninguno de los anteriores";
            //animacion de seleccion
            int y = 15;
            while (true) {
                //borrar
                Console::BackgroundColor = ConsoleColor::Black;
                if (y == 15) { Console::SetCursorPosition(19, y); cout << "Mayor a menor precio"; }
                if (y == 17) { Console::SetCursorPosition(19, y); cout << "Menor a mayor precio"; }
                if (y == 19) { Console::SetCursorPosition(16, y); cout << "Ninguno de los anteriores"; }

                //mover
                if (_kbhit()) {
                    char tecla = getch();
                    if (tecla == ABAJO && y < 19) y += 2;
                    if (tecla == ARRIBA && y > 15) y -= 2;
                    if (tecla == 13) {
                        if (y == 15) opc = '1';
                        if (y == 17) opc = '2';
                        if (y == 19) opc = '3';
                        break;
                    }
                }
                Console::BackgroundColor = ConsoleColor::DarkMagenta;
                if (y == 15) { Console::SetCursorPosition(19, y); cout << "Mayor a menor precio"; }
                if (y == 17) { Console::SetCursorPosition(19, y); cout << "Menor a mayor precio"; }
                if (y == 19) { Console::SetCursorPosition(16, y); cout << "Ninguno de los anteriores"; }
                _sleep(100);
            }
            system("cls");
            for (int x = 2; x <= 57; x++) {//dibuja linea 
                Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
            }
            Console::SetCursorPosition(26, 2);  Console::ForegroundColor = ConsoleColor::White; cout << "PRODUCTOS";
            cout << endl;
            
            switch (opc)
            {
            case '1': {
                this->productos.ordenarPorPrecioDescendente();
                this->productos.MostrarDatosPROD();
                break;
            }
            case '2': {
                // Inicializa la semilla para números aleatorios
                srand(time(0));

                // Genera un número aleatorio entre 0 y RAND_MAX
                int numAleatorio = rand();

                // Comprueba si el número está en la mitad superior del rango
                if (numAleatorio > RAND_MAX / 2) {
                    this->productos.ordenarPorPrecioAscendente();
                }
                else {
                    this->productos.ordenarPorPrecioAscendente2();
                }
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

                }
            }
        } while (opc!='2');
    }

    void mostrarPedido() {
        for (int x = 2; x <= 57; x++) {//dibuja linea 
            Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
        }
        Console::SetCursorPosition(27, 2);  Console::ForegroundColor = ConsoleColor::White; cout << "PEDIDO";
        cout << endl;
        string nombrePedido = generarNumeroAleatorio();
        this->pedido.setNombrePedido(nombrePedido);
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
            cout << "Presione ENTER para volver";
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
        for (int x = 2; x <= 87; x++) {//dibuja linea 
            Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
        }
        Console::SetCursorPosition(35, 2);  Console::ForegroundColor = ConsoleColor::White; cout << "HISTORIAL DE PEDIDOS";
        cout << endl;
        if (this->pedidos.estaVacia()) {
            Console::SetCursorPosition(33, 10); cout << "No hay pedidos registrados";
            Console::SetCursorPosition(33, 12); cout << "PRESIONA ENTER PARA VOLVER" << endl;
        }
        else {
            this->pedidos = cargarPedidos();
            cout << "Pedidos registrados:" << endl;
            cout << "Numero de pedidos realizados: " << this->pedidos.cantidadElementos() << endl;
            this->pedidos.mostrarTodosLosPedidos();

            //trae de nuevo los pedidos eliminados
            this->pedidos = cargarPedidos();
        }  
    }

    void generarArbolAVL() {
        ArbolAVL<Comentario> arbol;
        vector<Comentario> comentariosGenerados = Comentario::extraerComentariosTXT();

        for (int i = 0; i < comentariosGenerados.size(); i++)
        {
            arbol.Insertar(comentariosGenerados[i]);
        }
        arbol.inOrden();
        
    }

    void agregarComentarioAlArchivo(const string& nombreArchivo, Comentario& comentario) {
        ofstream archivo(nombreArchivo, ios::app);  // Modo de apertura: adjuntar al final del archivo

        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo: " << nombreArchivo << " para escritura." << endl;
            return;
        }

        archivo << comentario.obtenerComentarioFormateado() << "\n";

        archivo.close();
    }

    void realizarComentario() {
        cout << "------------------------------------------------------------" << endl;
        cout << "                  COMENTARIOS Y RESENIAS" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Ingresa tu comentario (presiona Enter para finalizar):\n";

        // Pedir al usuario que ingrese un nuevo comentario
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer de entrada
        cin.clear();
        string textoComentario;
        getline(cin, textoComentario);

        // Verificar si el campo del comentario está vacío
        if (textoComentario.empty()) {
            cout << "No se ha ingresado ningún comentario. Operación cancelada.\n";
            return; // Salir de la función sin agregar nada al archivo
        }

        // Crear un objeto Comentario con la fecha y hora actual y el comentario del usuario
        Comentario nuevoComentario(textoComentario);

        // Agregar el nuevo comentario al archivo
        agregarComentarioAlArchivo("Comentarios.txt", nuevoComentario);

        cout << "Comentario agregado con éxito.\n";
    }
};