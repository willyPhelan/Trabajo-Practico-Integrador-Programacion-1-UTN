#include <iostream>
#include "funciones.h"

using namespace std ;

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
