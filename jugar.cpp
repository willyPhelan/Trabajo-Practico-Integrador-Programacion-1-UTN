#include <iostream>
#include <ctime>
#include <string> // Necesario para std::string
#include "funciones.h" // Incluye tus prototipos de funciones

using namespace std;

// PROTOTIPOS DE FUNCIONES AUXILIARES
// Estas funciones se definen al final de este archivo para mantenerlo "completo".
// Idealmente, sus prototipos irian en funciones.h y sus definiciones en un .cpp aparte.
int posicionNumeroEnVector(int v[],int tam, int numero);
bool _eliminarPrimerOcurrencia(int arr[], int &cant, int valor);
void copiarVector(const int v[], int v2[], int tam); // Anadida para la logica de copia de stock


int jugar (){

    string jugador1, jugador2, primero_en_jugar, jugadorActual, oponente ;
    int suma_objetivo = 0, primer_tiro, segundo_tiro ;
    int puntosJ1=0, puntosJ2= 0 ;

    const int stock_maximo = 12 ; // Maximo de dados por jugador (todos los dados del juego)
    int stockJ1[stock_maximo] ;
    int stockJ2[stock_maximo] ;

    int cantDadosJ1 = 6; // Cantidad inicial de dados para el Jugador 1
    int cantDadosJ2 = 6; // Cantidad inicial de dados para el Jugador 2

    // === INICIALIZACION DE DADOS AL INICIO DEL JUEGO ===
    // Asignar valores aleatorios a los dados iniciales de cada jugador.
    // srand(time(0)); // NOTA: srand(time(0)) debe ir solo una vez en main.cpp
    for (int i = 0; i < cantDadosJ1; ++i) {
        stockJ1[i] = dado6caras();
    }
    for (int i = 0; i < cantDadosJ2; ++i) {
        stockJ2[i] = dado6caras();
    }
    // ===================================================

    cout << "--- A JUGAR ---------" << endl << endl ; // Consistente con mayusculas, sin exclamacion

    cout << "Ingrese el nombre del jugador 1: " ; // Minusculas
    cin >> jugador1 ;

    cout << "Ingrese el nombre del jugador 2: " ; // Minusculas
    cin >> jugador2 ;

    cout << endl ;

    int dado1_inicio, dado2_inicio ; // Renombradas para evitar conflicto con dado1/dado2 de la ronda

    cout << jugador1 << ", tira tu dado para ver quien comienza..." << endl ;
    system("pause") ;

    dado1_inicio = dado6caras() ;
    cout << endl << "Salio el dado numero: "<< dado1_inicio << endl ;
    cout << endl ;

    cout << jugador2 << ", tira tu dado para ver quien comienza..." << endl;
    system("pause") ;

    dado2_inicio = dado6caras() ;
    cout << endl << "Salio el dado numero: "<< dado2_inicio << endl ;
    cout << endl ;

    while (dado1_inicio == dado2_inicio) {
        cout << "Empate. Deben repetir la tirada inicial."<< endl << endl ; // Sin exclamacion
        system("pause") ;
        system("cls") ;

        cout << jugador1 << ", te toca lanzar de nuevo." << endl ;
        system("pause") ;
        dado1_inicio = dado6caras() ;
        cout << jugador1 << " te salio el numero: " << dado1_inicio << endl << endl ;

        cout << jugador2 << ", ahora te toca a vos lanzar de nuevo." << endl ;
        system("pause") ;
        dado2_inicio = dado6caras() ;
        cout << jugador2 << " te salio el numero: " << dado2_inicio << endl << endl ;
    }

    cout << "----------------------------" << endl ;

    if (dado1_inicio > dado2_inicio) {
        primero_en_jugar = jugador1 ;
        cout << jugador1 << " sacaste el dado mas alto, vas primero" << endl << endl ; // Sin exclamacion
    } else {
        primero_en_jugar = jugador2 ;
        cout << jugador2 << ", sacaste el dado mas alto, vas primero" << endl << endl ; // Sin exclamacion
    }

    system("pause") ;
    system("cls") ;

    int ronda = 1 ;
    string jugadorTurno1, jugadorTurno2; // Para gestionar quien juega en cada parte de la ronda


    while (true) { // Bucle principal del juego (cada iteracion es una RONDA completa)

        cout << "--- RONDA " << ronda << " ---" << endl ; // Mayusculas

        // Establecer el orden de los turnos para esta ronda
        jugadorTurno1 = primero_en_jugar;
        jugadorTurno2 = (primero_en_jugar == jugador1) ? jugador2 : jugador1;

        // =======================================================================
        // === TURNO DEL PRIMER JUGADOR DE LA RONDA (jugadorTurno1) ===
        // =======================================================================
        jugadorActual = jugadorTurno1;
        oponente = jugadorTurno2;

        cout << "Turno de: " << jugadorActual << endl; // Minusculas
        // Mostrar el puntaje del jugador actual
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << jugadorActual << ", momento de tirar los dados objetivo" << endl << endl ; // Sin exclamacion
        system("pause") ;

        primer_tiro = dado12caras() ;
        cout << "Te salio el numero: " << primer_tiro << endl << endl;

        system("pause") ;

        segundo_tiro = dado12caras() ;
        cout << "Te salio el numero: " << segundo_tiro << endl ;

        suma_objetivo = primer_tiro + segundo_tiro ;

        cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;

        cout << endl ;
        system("pause") ;
        system("cls") ;

        cout << "--- RONDA " << ronda << " ---" << endl;
        cout << "Hora de alcanzar el objetivo " << endl << endl ; // Sin exclamacion

        cout << "Jugador: " << jugadorActual << endl ;
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << "Numero objetivo: " << suma_objetivo << endl ;

        cout << endl << jugadorActual << ", tira tus dados de 6 caras:" << endl << endl ;
        system("pause") ;

        // Tirar los dados del stock del jugador actual
        if (jugadorActual == jugador1) {
            tirarDados6Caras(stockJ1, cantDadosJ1) ;
            cout << endl << "Salieron los dados:" << endl ;
            mostrarDados(stockJ1, cantDadosJ1) ;
        } else {
            tirarDados6Caras(stockJ2, cantDadosJ2);
            cout << endl << "Salieron los dados:" << endl;
            mostrarDados(stockJ2, cantDadosJ2);
        }

        cout << endl << endl;
        system("pause");
        system("cls");

        cout << "--- RONDA " << ronda << " ---" << endl;
        cout << "Jugador: " << jugadorActual << endl ;
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << "Numero objetivo: " << suma_objetivo << endl ;
        cout << endl << "Ahora debes elegir que dados utilizas para llegar al numero objetivo" << endl;

        cout << endl << "Tus dados en stock: " ;
        if (jugadorActual == jugador1) {
            mostrarDados(stockJ1, cantDadosJ1);
        } else {
            mostrarDados(stockJ2, cantDadosJ2);
        }
        cout << endl << endl ;

        // === LOGICA DE SELECCION DE DADOS Y VERIFICACION DEL OBJETIVO PARA jugadorTurno1 ===
        int dadosElegidos_T1[stock_maximo];
        int cantElegidos_T1 = 0;
        int suma_seleccionada_T1 = 0;

        int tempStock_T1[stock_maximo];
        int tempCant_T1;
        if (jugadorActual == jugador1) {
            copiarVector(stockJ1, tempStock_T1, cantDadosJ1);
            tempCant_T1 = cantDadosJ1;
        } else {
            copiarVector(stockJ2, tempStock_T1, cantDadosJ2);
            tempCant_T1 = cantDadosJ2;
        }

        cout << "Ingresa los valores de los dados que deseas usar (0 para terminar):" << endl;
        cout << "Tienes " << ((jugadorActual == jugador1) ? cantDadosJ1 : cantDadosJ2) << " dados disponibles." << endl;

        cout << endl ;

        while (true) {
            if (cantElegidos_T1 >= ((jugadorActual == jugador1) ? cantDadosJ1 : cantDadosJ2) || tempCant_T1 <= 0) {
                cout << "No quedan mas dados para seleccionar." << endl;
                break;
            }

            int valorSeleccionado;
            cout << "Dado a seleccionar (0 para terminar): ";
            cin >> valorSeleccionado;

            if (valorSeleccionado == 0) { break; }
            if (valorSeleccionado < 1 || valorSeleccionado > 6) {
                cout << "Valor de dado no valido. Debe ser entre 1 y 6." << endl;
                continue;
            }

            int posEnTemp = posicionNumeroEnVector(tempStock_T1, tempCant_T1, valorSeleccionado);
            if (posEnTemp != -1) {
                dadosElegidos_T1[cantElegidos_T1] = valorSeleccionado;
                suma_seleccionada_T1 += valorSeleccionado;
                cantElegidos_T1++;
                _eliminarPrimerOcurrencia(tempStock_T1, tempCant_T1, valorSeleccionado);
                cout << "Dado " << valorSeleccionado << " seleccionado." << endl << "Suma actual: " << suma_seleccionada_T1 << endl << endl;
            } else {
                cout << "No tienes un dado con el valor " << valorSeleccionado << " disponible en tu stock para seleccionar." << endl;
            }
        }

        cout << "\n--- RESUMEN DE LA SELECCION DE " << jugadorActual << " ---" << endl; // Mayusculas
        cout << "Dados elegidos: ";
        if (cantElegidos_T1 > 0) {
            for (int i = 0; i < cantElegidos_T1; ++i) { cout << dadosElegidos_T1[i] << " "; }
        } else { cout << "Ninguno"; }
        cout << endl;
        cout << "Suma de dados elegidos: " << suma_seleccionada_T1 << endl;
        cout << "Numero objetivo: " << suma_objetivo << endl;
        cout << "------------------------------" << endl;

        system("pause");
        system("cls");

        // === VERIFICACION DEL OBJETIVO Y TRANSFERENCIA DE DADOS PARA jugadorTurno1 ===
        bool logroObjetivo_T1 = (suma_seleccionada_T1 == suma_objetivo);

        if (logroObjetivo_T1) {
            cout << jugadorActual << ", HAS LOGRADO EL OBJETIVO! (" << suma_seleccionada_T1 << " == " << suma_objetivo << ")" << endl; // Mayusculas, sin exclamacion
            cout << endl  << "Transfiriendo los " << cantElegidos_T1 << " dados elegidos al oponente (" << oponente << ")..." << endl;

            if (cantElegidos_T1 > 0) {
                for (int i = 0; i < cantElegidos_T1; ++i) {
                    int dadoAtransferir = dadosElegidos_T1[i];
                    if (jugadorActual == jugador1) { // J1 transfiere dado a J2
                        if (_eliminarPrimerOcurrencia(stockJ1, cantDadosJ1, dadoAtransferir)) {
                            if (cantDadosJ2 < stock_maximo) {
                                stockJ2[cantDadosJ2] = dadoAtransferir;
                                cantDadosJ2++;
                                cout << "  -> Dado " << dadoAtransferir << " transferido a " << oponente << "." << endl;
                            } else {
                                cout << "  -> ADVERTENCIA STOCK DE " << oponente << " LLENO. DADO " << dadoAtransferir << " NO TRANSFERIDO." << endl; // Mayusculas, sin exclamacion
                            }
                        } else { cout << "  -> ERROR: DADO " << dadoAtransferir << " NO ENCONTRADO EN STOCK DE " << jugadorActual << "." << endl; } // Mayusculas
                    } else { // J2 transfiere dado a J1
                        if (_eliminarPrimerOcurrencia(stockJ2, cantDadosJ2, dadoAtransferir)) {
                            if (cantDadosJ1 < stock_maximo) {
                                stockJ1[cantDadosJ1] = dadoAtransferir;
                                cantDadosJ1++;
                                cout << endl << "  -> Dado " << dadoAtransferir << " transferido a " << oponente << "." << endl;
                            } else {
                                cout << "  -> ADVERTENCIA STOCK DE " << oponente << " LLENO. DADO " << dadoAtransferir << " NO TRANSFERIDO." << endl; // Mayusculas, sin exclamacion
                            }
                        } else { cout << "  -> ERROR: DADO " << dadoAtransferir << " NO ENCONTRADO EN STOCK DE " << jugadorActual << "." << endl; } // Mayusculas
                    }
                }
                cout << endl << "Transferencia de dados completada para " << jugadorActual << "." << endl; // Mayusculas, sin exclamacion
            } else {
                cout << jugadorActual << " no selecciono ningun dado para transferir." << endl; // Minusculas
            }
        } else {
            cout << jugadorActual << ", no has llegado al objetivo :( (" << suma_seleccionada_T1 << " != " << suma_objetivo << ")" << endl;
            cout << "Los dados seleccionados permanecen en tu stock." << endl;
        }
        cout << endl;

        // --- Mostrar estado de los arrays despues del turno del primer jugador ---
        cout << "\n-- Estado de los dados despues del turno de " << jugadorActual << " ---" << endl << endl; // Mayusculas
        cout << "Dados de " << jugador1 << " (" << cantDadosJ1 << "): " ;
        mostrarDados(stockJ1, cantDadosJ1);
        cout << endl;
        cout << "Dados de " << jugador2 << " (" << cantDadosJ2 << "): " ;
        mostrarDados(stockJ2, cantDadosJ2);
        cout << endl << endl;
        system("pause");
        system("cls");


        // =======================================================================
        // === TURNO DEL SEGUNDO JUGADOR DE LA RONDA (jugadorTurno2) ===
        // =======================================================================
        jugadorActual = jugadorTurno2; // Swap roles
        oponente = jugadorTurno1;

        cout << "--- RONDA " << ronda << " ---" << endl;
        cout << "Turno de: " << jugadorActual << endl; // Minusculas
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << jugadorActual << ", momento de tirar los dados objetivo" << endl << endl ; // Sin exclamacion
        system("pause") ;

        primer_tiro = dado12caras() ;
        cout << "Te salio el numero: " << primer_tiro << endl << endl;

        system("pause") ;

        segundo_tiro = dado12caras() ;
        cout << "Te salio el numero: " << segundo_tiro << endl ;

        suma_objetivo = primer_tiro + segundo_tiro ;

        cout << endl << jugadorActual << ", tu numero objetivo es: " << suma_objetivo << endl ;

        cout << endl ;
        system("pause") ;
        system("cls") ;

        cout << "--- RONDA " << ronda << " ---" << endl;
        cout  << "Hora de alcanzar el objetivo " << endl << endl ; // Sin exclamacion

        cout << "Jugador: " << jugadorActual << endl ;
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << "Numero objetivo: " << suma_objetivo << endl ;

        cout << endl << jugadorActual << ", tira tus dados de 6 caras:" << endl << endl ;
        system("pause") ;

        // Tirar los dados del stock del jugador actual
        if (jugadorActual == jugador1) {
            tirarDados6Caras(stockJ1, cantDadosJ1) ;
            cout << endl << "Salieron los dados:" << endl ;
            mostrarDados(stockJ1, cantDadosJ1) ;
        } else {
            tirarDados6Caras(stockJ2, cantDadosJ2);
            cout << endl << "Salieron los dados:" << endl;
            mostrarDados(stockJ2, cantDadosJ2);
        }

        cout << endl << endl;
        system("pause");
        system("cls");

        cout << "--- RONDA " << ronda << " ---" << endl;
        cout << "Jugador: " << jugadorActual << endl ;
        if (jugadorActual == jugador1) {
            cout << "Puntaje: " << puntosJ1 << endl;
        } else {
            cout << "Puntaje: " << puntosJ2 << endl;
        }

        cout << endl << "Numero objetivo: " << suma_objetivo << endl ;
        cout << endl << "Ahora debes elegir que dados utilizas para llegar al numero objetivo" << endl;

        cout << endl << "Tus dados en stock: " ;
        if (jugadorActual == jugador1) {
            mostrarDados(stockJ1, cantDadosJ1);
        } else {
            mostrarDados(stockJ2, cantDadosJ2);
        }
        cout << endl << endl;

        // === LOGICA DE SELECCION DE DADOS Y VERIFICACION DEL OBJETIVO PARA jugadorTurno2 ===
        int dadosElegidos_T2[stock_maximo];
        int cantElegidos_T2 = 0;
        int suma_seleccionada_T2 = 0;

        int tempStock_T2[stock_maximo];
        int tempCant_T2;
        if (jugadorActual == jugador1) {
            copiarVector(stockJ1, tempStock_T2, cantDadosJ1);
            tempCant_T2 = cantDadosJ1;
        } else {
            copiarVector(stockJ2, tempStock_T2, cantDadosJ2);
            tempCant_T2 = cantDadosJ2;
        }

        cout << "Ingresa los valores de los dados que deseas usar (0 para terminar):" << endl;
        cout << "Tienes " << ((jugadorActual == jugador1) ? cantDadosJ1 : cantDadosJ2) << " dados disponibles." << endl << endl;

        while (true) {
            if (cantElegidos_T2 >= ((jugadorActual == jugador1) ? cantDadosJ1 : cantDadosJ2) || tempCant_T2 <= 0) {
                cout << "No quedan mas dados para seleccionar." << endl;
                break;
            }

            int valorSeleccionado;
            cout << "Dado a seleccionar (0 para terminar): ";
            cin >> valorSeleccionado;

            if (valorSeleccionado == 0) { break; }
            if (valorSeleccionado < 1 || valorSeleccionado > 6) {
                cout << "Valor de dado no valido. Debe ser entre 1 y 6." << endl;
                continue;
            }

            int posEnTemp = posicionNumeroEnVector(tempStock_T2, tempCant_T2, valorSeleccionado);
            if (posEnTemp != -1) {
                dadosElegidos_T2[cantElegidos_T2] = valorSeleccionado;
                suma_seleccionada_T2 += valorSeleccionado;
                cantElegidos_T2++;
                _eliminarPrimerOcurrencia(tempStock_T2, tempCant_T2, valorSeleccionado);
                cout << "Dado " << valorSeleccionado << " seleccionado." << endl << "Suma actual: " << suma_seleccionada_T2 << endl << endl;
            } else {
                cout << "No tienes un dado con el valor " << valorSeleccionado << " disponible en tu stock para seleccionar." << endl;
            }
        }

        cout << "\n--- RESUMEN DE LA SELECCION DE " << jugadorActual << " ---" << endl; // Mayusculas
        cout << "Dados elegidos: ";
        if (cantElegidos_T2 > 0) {
            for (int i = 0; i < cantElegidos_T2; ++i) { cout << dadosElegidos_T2[i] << " "; }
        } else { cout << "Ninguno"; }
        cout << endl;
        cout << "Suma de dados elegidos: " << suma_seleccionada_T2 << endl;
        cout << "Numero objetivo: " << suma_objetivo << endl;
        cout << "------------------------------" << endl;

        system("pause");
        system("cls");

        // === VERIFICACION DEL OBJETIVO Y TRANSFERENCIA DE DADOS PARA jugadorTurno2 ===
        bool logroObjetivo_T2 = (suma_seleccionada_T2 == suma_objetivo);

        if (logroObjetivo_T2) {
            cout << jugadorActual << ", HAS LOGRADO EL OBJETIVO! (" << suma_seleccionada_T2 << " == " << suma_objetivo << ")" << endl; // Mayusculas, sin exclamacion
            cout << endl << "Transfiriendo los " << cantElegidos_T2 << " dados elegidos al oponente (" << oponente << ")..." << endl;

            if (cantElegidos_T2 > 0) {
                for (int i = 0; i < cantElegidos_T2; ++i) {
                    int dadoAtransferir = dadosElegidos_T2[i];
                    if (jugadorActual == jugador1) { // J1 transfiere dado a J2
                        if (_eliminarPrimerOcurrencia(stockJ1, cantDadosJ1, dadoAtransferir)) {
                            if (cantDadosJ2 < stock_maximo) {
                                stockJ2[cantDadosJ2] = dadoAtransferir;
                                cantDadosJ2++;
                                cout << "  -> Dado " << dadoAtransferir << " transferido a " << oponente << "." << endl;
                            } else {
                                cout << "  -> ADVERTENCIA STOCK DE " << oponente << " LLENO. DADO " << dadoAtransferir << " NO TRANSFERIDO." << endl; // Mayusculas, sin exclamacion
                            }
                        } else { cout << "  -> ERROR: DADO " << dadoAtransferir << " NO ENCONTRADO EN STOCK DE " << jugadorActual << "." << endl; } // Mayusculas
                    } else { // J2 transfiere dado a J1
                        if (_eliminarPrimerOcurrencia(stockJ2, cantDadosJ2, dadoAtransferir)) {
                            if (cantDadosJ1 < stock_maximo) {
                                stockJ1[cantDadosJ1] = dadoAtransferir;
                                cantDadosJ1++;
                                cout << "  -> Dado " << dadoAtransferir << " transferido a " << oponente << "." << endl;
                            } else {
                                cout << "  -> ADVERTENCIA STOCK DE " << oponente << " LLENO. DADO " << dadoAtransferir << " NO TRANSFERIDO." << endl; // Mayusculas, sin exclamacion
                            }
                        } else { cout << "  -> ERROR: DADO " << dadoAtransferir << " NO ENCONTRADO EN STOCK DE " << jugadorActual << "." << endl; } // Mayusculas
                    }
                }
                cout << endl << "Transferencia de dados completada para " << jugadorActual << "." << endl; // Mayusculas, sin exclamacion
            } else {
                cout << jugadorActual << " no selecciono ningun dado para transferir." << endl; // Minusculas
            }
        } else {
            cout << jugadorActual << ", no has llegado al objetivo :( (" << suma_seleccionada_T2 << " != " << suma_objetivo << ")" << endl;
            cout << "Los dados seleccionados permanecen en tu stock." << endl;
        }
        cout << endl;

        // --- Mostrar estado de los arrays despues del turno del segundo jugador ---
        cout << "\n-- Estado de los dados despues del turno de " << jugadorActual << " ---" << endl << endl; // Mayusculas
        cout << "Dados de " << jugador1 << " (" << cantDadosJ1 << "): ";
        mostrarDados(stockJ1, cantDadosJ1);
        cout << endl;
        cout << "Dados de " << jugador2 << " (" << cantDadosJ2 << "): ";
        mostrarDados(stockJ2, cantDadosJ2);
        cout << endl << endl;
        system("pause");
        system("cls");


        // =======================================================================
        // === FIN DE RONDA: Logica para la proxima ronda y condiciones de victoria ===
        // =======================================================================

        // Alternar el nombre del jugador que comienza la PROXIMA ronda
        if (primero_en_jugar == jugador1) {
            primero_en_jugar = jugador2;
        } else {
            primero_en_jugar = jugador1;
        }
        ronda++; // Incrementar la ronda

        // === Criterios de Fin de Juego ===
        if (cantDadosJ1 <= 0) {
            cout << jugador2 << " ha ganado la partida. " << jugador1 << " se quedo sin dados." << endl; // Sin exclamacion
            break;
        }
        if (cantDadosJ2 <= 0) {
            cout << jugador1 << " ha ganado la partida. " << jugador2 << " se quedo sin dados." << endl; // Sin exclamacion
            break;
        }
        if (cantDadosJ1 >= stock_maximo) {
            cout << jugador1 << " ha ganado la partida al acumular todos los dados (" << cantDadosJ1 << ")." << endl; // Sin exclamacion
            break;
        }
        if (cantDadosJ2 >= stock_maximo) {
            cout << jugador2 << " ha ganado la partida al acumular todos los dados (" << cantDadosJ2 << ")." << endl; // Sin exclamacion
            break;
        }
        // Si no hay condicion de victoria, el bucle continuara para la siguiente ronda
    } // Fin del bucle principal del juego (while(true))

    volver_atras() ;
    return 0;
}

