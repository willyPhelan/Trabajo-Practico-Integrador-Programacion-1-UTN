
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

        dados[i] = dado6caras(); // Llama a la funci�n dado6caras() para obtener el valor
    }
}

// Funci�n para mostrar los valores de un array de dados

void mostrarDados(const int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {

        cout << dados[i] << " ";
    }}


// Funci�n de selecci�n de dados


