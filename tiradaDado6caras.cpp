#include <iostream>
#include "funciones.h"

using namespace std ;

void tirarDados6Caras(int dados[], int cantidadDados) {

    for (int i = 0; i < cantidadDados; i++) {
        dados[i] = dado6caras(); // Llama a la función dado6caras() para obtener el valor
    }
}

// Función para mostrar los valores de un array de dados
void mostrarDados(const int dados[], int cantidadDados) {
    for (int i = 0; i < cantidadDados; i++) {
        cout << dados[i] << " ";
    }}
