#include <iostream>
#include <string> // Necesario para std::string
#include "funciones.h" //

using namespace std ;

// Función auxiliar para eliminar un valor específico de un array y retornar la nueva cantidad


int eliminarDadoDeArray(int arr[], int cantidad, int valor) {

    int indice = -1 ;

    for (int i = 0; i < cantidad; ++i) {
        if (arr[i] == valor) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {

    // Mover los elementos restantes para llenar el hueco

    for (int i = indice ; i < cantidad - 1; ++i) {

            arr[i] = arr[i + 1] ;
        }
        return cantidad - 1; // Retorna la nueva cantidad
    }
    return cantidad; // No se encontró el valor, la cantidad no cambia
}

// Función auxiliar para agregar un valor a un array y retornar la nueva cantidad

int agregarDadoAlArray(int arr[], int cantidad, int valor) {

    if (cantidad < 12) { // Asumiendo MAX_DICE_STOCK de 12

        arr[cantidad] = valor;

        return cantidad + 1; // Retorna la nueva cantidad

    } else {
        // cout << "Advertencia: Stock de dados lleno, no se puede agregar mas." << endl;
        return cantidad ; // La cantidad no cambia si no se pudo agregar
    }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}

bool transferirDadoSeleccionado(int stockOrigen[], int &cantOrigen,
                                 int stockDestino[], int &cantDestino,
                                 int maxStock) {


    if (cantOrigen <= 0) {
        cout << "No tienes dados para transferir. Stock vacio." << endl;
        return false;
    }
    if (cantDestino >= maxStock) {
        cout << "El stock del oponente esta lleno (" << maxStock << " dados). No puede recibir mas." << endl;
        return false;
    }

    cout << "Tus dados actuales: ";
    mostrarVector(stockOrigen, cantOrigen); // Usamos mostrarVector de tu funciones.h
    cout << endl;

    int valorADar;
    cout << "Ingresa el valor del dado (1-6) que deseas transferir: ";
    cin >> valorADar;

    // Validar que el valor sea un dado de 6 caras
    if (valorADar < 1 || valorADar > 6) {
        cout << "Valor de dado no valido. Debe ser entre 1 y 6." << endl;
        return false;
    }

    // Buscar la posición del dado seleccionado en el array de origen
    int posicion = posicionNumeroEnVector(stockOrigen, cantOrigen, valorADar); // Usamos posicionNumeroEnVector de tu funciones.h

    if (posicion == -1) {
        cout << "No tienes un dado con el valor " << valorADar << " en tu stock." << endl;
        return false;
    }

    // --- Lógica para eliminar el dado del stock de origen ---
    // Mover los elementos a la izquierda para "eliminar" el dado lógicamente
    for (int i = posicion; i < cantOrigen - 1; ++i) {
        stockOrigen[i] = stockOrigen[i + 1];
    }
    cantOrigen--; // Decrementar la cantidad de dados en el origen

    // --- Lógica para agregar el dado al stock de destino ---
    // Agregamos el dado al final del array de destino (siempre hay espacio si pasamos la comprobación inicial)
    stockDestino[cantDestino] = valorADar;
    cantDestino++; // Incrementar la cantidad de dados en el destino

    cout << "Dado " << valorADar << " transferido exitosamente." << endl;
    return true;
}

// NOTA: Para que el código compile, las funciones auxiliares 'mostrarVector' y 'posicionNumeroEnVector'
// deben estar definidas en un archivo .cpp que se compile y enlace con este.
// Las definiciones que incluiste en tu pregunta (después de "Desarrollo de funciones / Definiciones")
// deberían ser las que están en ese otro .cpp (o en el mismo si decides unificar).


void copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}


bool _eliminarPrimerOcurrencia(int arr[], int &cant, int valor) {
    int pos = posicionNumeroEnVector(arr, cant, valor);
    if (pos != -1) {
        for (int i = pos; i < cant - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        cant--;
        return true;
    }
    return false;
}
