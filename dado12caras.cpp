#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

int dado12caras(){

    int random ;

    random = rand() % 12 + 1 ; // esto birndara numeros aleatoreos entre el 0 y el 6, si quiero que incluya el 6 le sumo 1.

    return random ; }


