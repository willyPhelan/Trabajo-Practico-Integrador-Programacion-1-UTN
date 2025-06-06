#include<iostream>
#include"Dado6caras.h"
#include "funciones.h"

using namespace std ;

void menuPrincipal(){

    int numero ;
    string jugador1, jugador2, primero_en_jugar ;

    cout << "BIENVENIDO A ENFRENDADOS!" << endl ;

    cout << endl <<"Ingrese una opcion: "  << endl ;

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

            cout << "--- A jugar! ---------" << endl << endl ;


            cout << "Ingrese el nombre del Jugador 1: " ;

            cin >> jugador1 ;

            cout << "Ingrese el nombre del Jugador 2: " ;

            cin >> jugador2 ;

            cout << endl ;

            int dado1, dado2 ;

            cout << jugador1 << ", tira tu dado para ver quien comienza..." << endl ;

            system("pause") ; // Pausa para tirar dado

            dado1 = tiradaInicial() ; // Asumiendo que dado6caras() devuelve el valor del dado

            cout << "Salio el dado numero: "<< dado1 << endl ;

            cout << endl ;

            cout << jugador2 << ", tira tu dado para ver quien comienza..." << endl;

            system("pause") ; // Pausa para tirar dado

            dado2 = tiradaInicial() ; // Asumiendo que dado6caras() devuelve el valor del dado

            cout << "Salio el dado numero: "<< dado2 << endl ;

            cout << endl ;

             while (jugador1 == jugador2) {

                cout << "¡Empate! Deben repetir la tirada inicial." << endl ;

                cout << jugador1 << ", te toca tirar de lanzar de nuevo." << endl ;

                system("pause") ; // Pausa para tirar dado

                dado1 = tiradaInicial() ;

                cout << jugador1 << "te salio el numero: " << dado1 << endl << endl ;

                cout << jugador2 << ", ahora te toca a vos tirar de lanzar de nuevo." << endl ;

                system("pause") ; // Pausa para tirar dado

                dado2 = tiradaInicial() ;

                cout << jugador2 << "te salio el numero: " << dado2 << endl << endl ; }

            cout << "----------------------------" << endl ;


            if (dado1 > dado2) {

                primero_en_jugar = jugador1 ;

                cout << jugador1 << " sacaste el dado mas alto, vas primero!" << endl << endl ;

            } else {

                primero_en_jugar = jugador2 ;

                cout << jugador2 << " sacaste el dado mas alto, vas primero!" << endl << endl;
            }

            volver_atras() ;





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


