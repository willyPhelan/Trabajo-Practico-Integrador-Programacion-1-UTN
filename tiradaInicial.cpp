#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;


// primer tirada para cada jugador

int tiradaInicial(){

    int random ;

    srand(time(0)) ;

    random = rand() % 6 + 1 ; // esto birndara numeros aleatoreos entre el 0 y el 6, si quiero que incluya el 6 le sumo 1.

    return random ; }
