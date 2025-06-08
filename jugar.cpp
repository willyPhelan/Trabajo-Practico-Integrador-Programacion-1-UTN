#include <iostream>
#include <ctime>
#include "funciones.h"

using namespace std ;

 int jugar (){

 string jugador1, jugador2, primero_en_jugar ;
 int suma=0, primer_tiro, segundo_tiro, tirada6 ;
 int mostrar_dado() ;

 cout << "--- A jugar! ---------" << endl << endl ;


            cout << "Ingrese el nombre del Jugador 1: " ;

            cin >> jugador1 ;

            cout << "Ingrese el nombre del Jugador 2: " ;

            cin >> jugador2 ;

            cout << endl ;

            int dado1, dado2 ;

            cout << jugador1 << ", tira tu dado para ver quien comienza..." << endl ;

            system("pause") ; // Pausa para tirar dado

            dado1 = dado6caras() ; // Asumiendo que dado6caras() devuelve el valor del dado

            cout << endl << "Salio el dado numero: "<< dado1 << endl ;

            cout << endl ;

            cout << jugador2 << ", tira tu dado para ver quien comienza..." << endl;

            system("pause") ; // Pausa para tirar dado

            dado2 = dado6caras() ; // Asumiendo que dado6caras() devuelve el valor del dado

            cout << endl << "Salio el dado numero: "<< dado2 << endl ;

            cout << endl ;

             while (dado1 == dado2) {

                cout << "¡Empate! Deben repetir la tirada inicial." << endl ;

                cout << jugador1 << ", te toca tirar de lanzar de nuevo." << endl ;

                system("pause") ; // Pausa para tirar dado

                dado1 = dado6caras() ;

                cout << jugador1 << "te salio el numero: " << dado1 << endl << endl ;

                cout << jugador2 << ", ahora te toca a vos tirar de lanzar de nuevo." << endl ;

                system("pause") ; // Pausa para tirar dado

                dado2 = dado6caras() ;

                cout << jugador2 << "te salio el numero: " << dado2 << endl << endl ; }

            cout << "----------------------------" << endl ;


            if (dado1 > dado2) {

                primero_en_jugar = jugador1 ;

                cout << jugador1 << " sacaste el dado mas alto, vas primero!" << endl << endl ;

            } else {

                primero_en_jugar = jugador2 ;

                cout << jugador2 << ", sacaste el dado mas alto, vas primero!" << endl << endl ;
            }

            system("pause") ;

            system("cls") ;

            cout << primero_en_jugar << ", momento de tirar los dados objetivo!" << endl << endl ;

            system("pause") ; // Pausa para tirar dado

            primer_tiro = dado12caras() ;

            cout <<  "te salio el numero: " << primer_tiro << endl << endl;

            system("pause") ; // Pausa para tirar dado

            segundo_tiro = dado12caras() ;

            cout << "te salio el numero: " << segundo_tiro << endl  ;

            suma = primer_tiro + segundo_tiro ;

            cout << endl << primero_en_jugar << ", tu numero objetivo es: " << suma << endl  ;

            cout << endl << "Hora de alcanzarlo! " << endl << endl  ;

            system("pause") ;
            system("cls") ;

            cout << endl << "Numero objetivo: " << suma << endl  ;

            cout << endl << primero_en_jugar << ", tira tus dados de 6 caras:" << endl  << endl ;

            system("pause") ;

            cout << endl << "Salieron los dados:" << endl ;


            int dadosJugador1[6] ;

            tirarDados6Caras(dadosJugador1, 6) ;

            mostrarDados(dadosJugador1, 6) ; // nombre del array + cantidad de elementos

            cout << endl << endl ;

            system("pause") ;
            system("cls") ;

            cout << "Jugador: " << primero_en_jugar << endl << endl ;

            cout << "Ahora debes elegir que dados utilizas para llegar al numero objetivo" << endl ;

            cout << endl << "Numero objetivo: " << suma << endl  ;

            cout << endl  << "Tus dados: " ;

            mostrarDados(dadosJugador1, 6) ;

            cout << endl  ;

            cout << endl ;

            volver_atras() ;
 }



