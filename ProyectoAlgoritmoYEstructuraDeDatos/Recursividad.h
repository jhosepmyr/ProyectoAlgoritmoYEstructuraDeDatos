#pragma once

//En la clase Lista
/*template <class T>
T Lista<T>::loopdeBusquedaDATO(Nodo* aux, string ID) {
    if (aux->elem.getNombre() == ID) {
        return aux->elem;
    }
    else  if (aux != nullptr) return loopdeBusquedaDATO(aux = aux->sig, ID);
}*/

//En la clase Pila
/*template<class T>
void Pila<T>::mostrarDatosPila() {
	T aux = pop();
	if (estaVacia()) return;
	aux.mostrarListaProductos();
	mostrarDatosPila();
}*/

//En la clase Cola
/*
template<class T>
void Cola<T>::mostrardatos() {
	if (inicio == fin) return;
	dequeue();
	mostrardatos();
}*/

/*int MenuCliente() {
  system("cls");
   this->opcion = '0';
    for (int x = 2; x <= 57; x++) {//dibuja linea 
        Console::SetCursorPosition(x, 2); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
    }
    for (int x = 2; x <= 57; x++) { //dibuja linea 
        Console::SetCursorPosition(x, 36); Console::ForegroundColor = ConsoleColor::Cyan; ; cout << (char)219;
    }
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(20, 8);
    cout << "BIENVENIDO " + this->clienteAux->getNombre() << endl;
    Console::SetCursorPosition(20, 12);
    cout << "MENU DE OPCIONES";
    Console::SetCursorPosition(18, 15);
    cout << "1. Informacion personal";
    Console::SetCursorPosition(18, 17);
    cout << "2. Modificar informacion\n";
    Console::SetCursorPosition(18, 19);
    cout << "3. Mostrar Productos\n";
    Console::SetCursorPosition(18, 21);
    cout << "4. Mi carrito de compras\n";
    Console::SetCursorPosition(18, 23);
    cout << "5. Historial de pedidos\n";
    Console::SetCursorPosition(18, 25);
    cout << "6. Cerrar sesion\n";
    Console::SetCursorPosition(10, 27);
    cout << "Selecciona una opcion ingresando el numero\n\n";
    Console::SetCursorPosition(10, 28);
    cout << "Opcion: ";
    cin >> this->opcion;
    //validarOpcion();
    resultadosOpcionSeleccionada();
    system("pause>0");
    if (this->opcion != '6') { return MenuCliente(); }
    else return 0;
}*/


