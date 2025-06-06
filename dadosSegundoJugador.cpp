#include<iostream>
#include<ctime>
#include"funciones.h"

using namespace std ;


void tiradaDado6caras(){

    int continuar, sorteo ;

    do{

        int dados[12] ;

        int stock, cant ;

        srand(time(0)) ;

        cout << "Ingrese cuantos dados tiene en su poder: " ;

        cin >> cant ;

        for(int i=0 ; i < cant ; i++){

            dados[i] = rand() % 6 + 1 ;

            cout << dados[i] << endl ; }

        cout << endl ;

        cout << "presione 1 si desea continuar: " ;

        cin >> continuar ; }

        while(continuar==1);

        int resultado_volver = volver_atras() ;

    if (resultado_volver == 1) {

        system("cls") ;
    }

}








