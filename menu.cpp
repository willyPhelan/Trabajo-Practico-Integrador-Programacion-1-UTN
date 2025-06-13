#include<iostream>
#include "funciones.h"

using namespace std ;

void menuPrincipal(){

    int numero ;

    cout << "BIENVENIDO A ENFRENDADOS!" << endl ;

    cout << endl << "Ingrese una opcion: "  << endl ;

    cout << endl << "1 - Para Jugar" << endl ;

    cout << "------------------" << endl ;

    cout << "2 - Para Estadisticas" << endl ;

    cout << "------------------" << endl ;

    cout << "3 - Para Creditos" << endl ;

    cout << "------------------" << endl ;

    cout << "0 - Para Salir" << endl << endl ;

    cin >> numero ;

    cout << endl ;


    if(numero > 3 || numero < 0){

        cout << "El numero ingresado no es correcto " << endl << endl ;

        cout << "Ingrese otra opcion entre 1 y 3: "  << endl << endl  ;

        cin >> numero ; }

    switch(numero){

        case 1:

            system("cls") ;

            jugar() ;

        break ;

        case 2:

            cout << endl << "Aca va la funcion para las estadisticas" << endl ;

        break ;

        case 3:

            cout << endl << "Aca va la funcion para los creditos" << endl ;

        break ;

        case 0:

            system("cls") ;

            cout << "El juego ha finalizado. Hasta la proxima!" << endl ;

            return ; } } // porque aca en caso de salir puse return y no break? cono en dado6caras?


