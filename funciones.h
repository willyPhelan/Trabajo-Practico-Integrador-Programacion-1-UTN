#pragma once

void menuPrincipal() ;
int dado6caras() ;
int dado12caras();
int volver_atras() ;
int jugar() ;


 // el objetivo a alcanzar) ;

void tirarDados6Caras(int dados[], int cantidadDados); // Rellena el array con dados de 6 caras
void mostrarDados(const int dados[], int cantidadDados);

// fn array

int agregarDadoAlArray() ;
int eliminarDadoDeArray() ;

// laburo array
void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector
int posicionNumeroEnVector(int v[],int tam, int numero);/// devuelve la posici�n que ocupa un n�mero que se //env�a como par�metro. Devuelve la primera posici�n que encuentra el n�mero. Si no lo encuentra devuelve -1

void copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool _eliminarPrimerOcurrencia(int arr[], int &cant, int valor);

int posicionNumeroEnVector(int v[],int tam, int numero);
bool _eliminarPrimerOcurrencia(int arr[], int &cant, int valor);
void copiarVector(const int v[], int v2[], int tam);



void mostrarDadosNoCero(const int dados[], int cantidadDados); // Nueva función
