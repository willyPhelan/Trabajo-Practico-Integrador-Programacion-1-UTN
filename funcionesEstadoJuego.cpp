#include <iostream>
#include <string> // Necesario para std::string
#include "funciones.h" // Incluye funciones.h para acceder a dado6caras, mostrarDados, _eliminarUnDadoDeArray

using namespace std;

void mostrarEstadoJuego(std::string nombreJugador, int scoreJugador, int cantidadDadosStock, int numeroObjetivo) {
    cout << "Jugador: " << nombreJugador << endl;
    cout << "Puntaje: " << scoreJugador << endl;
    cout << "Dados en stock: " << cantidadDadosStock << endl;
    cout << "Numero objetivo: " << numeroObjetivo << endl << endl;
}




