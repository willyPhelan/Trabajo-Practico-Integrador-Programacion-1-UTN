#include <ctime>
#include "funciones.h"
#include <iostream>

using namespace std ;

int dado6caras(){

    int random ;

    random = rand() % 6 + 1 ; // esto birndara numeros aleatoreos entre el 0 y el 6, si quiero que incluya el 6 le sumo 1.

    return random ; }


void tirarDados6Caras(int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        dados[i] = dado6caras(); // Llama a la función dado6caras() para obtener el valor
    }
}

// Función para mostrar los valores de un array de dados

void mostrarDados(const int dados[], int cantidadDados) {
    bool primerDadoMostrado = false;
    for (int i = 0; i < cantidadDados; i++) {
        if (dados[i] != 0) { // Solo muestra si el dado no es 0
            if (primerDadoMostrado) {
                cout << " "; // Agrega un espacio si ya se mostró un dado
            }
            cout << dados[i];
            primerDadoMostrado = true;
        }
    }
    // Si no se mostró ningún dado (todos eran 0), puedes imprimir un mensaje o dejarlo vacío
    if (!primerDadoMostrado && cantidadDados > 0) { // Muestra si hay dados pero todos son 0
         cout << "(Sin dados visibles)"; // Opcional: mensaje si todos son 0
    }
}


// Función de selección de dados


