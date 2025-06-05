#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

int random, volver=-99999 ;

void dado6caras(){

    srand(time(0)) ;

    random = rand() % 6 + 1 ; // esto birndara numeros aleatoreos entre el 0 y el 6, si quiero que incluya el 6 le sumo 1.

    switch(random){

        case 1:

            cout << "Salio el numero 1" << endl << endl ;

            volver_atras() ;

        break ;

        case 2:

            cout << "Salio el numero 2" << endl << endl ;

            volver_atras() ;

        break ;

        case 3:

            cout << "Salio el numero 3 " << endl <<endl ;

            volver_atras() ;

        break ;

        case 4:

            cout << "Salio el numero 4 " << endl << endl ;

            volver_atras() ;

        break ;

        case 5:

            cout << "Salio el numero 5 " << endl << endl ;

            volver_atras() ;

        break ;

        case 6:
            cout << "Salio el numero 6 " << endl << endl ;

            volver_atras() ;

        break ; }}

    int volver_atras(){

    cout << "Ingrese 1 para volver al Menu o 0 para salir" << endl;

    cin >> volver ;

    if(volver < 0 || volver > 1){

    cout << "EL numero Ingresado no es valido. Vuelva a intentarlo (1 para volver al Menu o 0 para salir)" ;

    cin >> volver ; }


    switch (volver){

        case 1:

            system("cls") ; // borro pantalla y muestro el menu

            menuPrincipal();

            break ;

        case 0:

            system("cls") ;

            cout << "Gracias por jugar!" << endl << endl ;

            break ; }}
