//Interfaz -> validarOpcion()
/*auto opcionValida = 
[](char op)->bool {return op == '1' || op == '2' || op == '3'; };*/

//Producto -> mostrarDatosLinea()
/*auto formatLine = [this]() {
			cout << "Nombre: " << this->Nombre << ", Precio: " << this->precio << ", Tipo: " << this->tipo << ", ID: " << this->identificador << endl;
};*/

//Vendedor -> opcionesMisProductos()
/*auto MENU = []() {
            cout << "MODIFICACION DE MIS PRODUCTOS " << endl;
            cout << "1. Agrega un nuevo producto\n";
            cout << "2. Modificar un producto\n";
            cout << "3. Elimina un producto\n";
            cout << "4. Salir\n";
            cout << "Selecciona una opcion ingresando el numero\n\n";
            cout << "Opcion: ";
            };*/

//Usuario -> setTodaInformacion()
/*auto updateMember = [](string& member, const string& value) {
            if (value != "ninguno") {
                member = value;
            }
        };*/

//Usuario -> mostrarDatosPersonales()
/*        auto mostrarDato = [this](const string& label, const string& dato) {
            if (dato != "ninguno") {
                cout << label << ": " << dato << endl;
            }
        };*/

//Usuario -> actualizarDatosPersonales()
/*auto actualizarDato = [this](string& dato, const string& label) {
                cout << "Actualizar " << label << ": " << endl;
                cin >> dato;
                this->opcionUsuario = '0';
            };*/

//Files -> actualizarProductosTxt()
/*auto createLine = [](Producto producto) {
			return producto.getNombre() + " " +
				to_string(producto.getPrecio()) + " " +
				producto.getTipo() + " " +
				producto.getIdentificador();
		};*/

//Producto -> mostrarDatos()
/*auto Datos = [this]() {
    cout << "\n---------------------------";
    cout << "\nCodigo Vendedor: " << this->codigoVendedor;
    cout << "\nID: " << this->identificador;
    cout << "\nNombre: " << this->Nombre;
    cout << "\nPrecio: " << this->precio;
    cout << "\nTipo: " << this->tipo;
    };
Datos();*/

//Pedido ->mostrarListaProductos
/*auto Productos = [this]() {
    cout << "*********************************\n";
    cout << this->nombrePedido << endl;
    this->carritoCompras.MostrarDatosPRODLinea();
    cout << "*********************************\n";
    };
Productos();*/