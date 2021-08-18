//Implementación de librería
#include "adivinum.h"
//Prototipo de función
void ConfigurarColor(int valor);
using namespace std;

void InstruccionesAdivinum() {
	//Nombre del juego
	cout << "ADIVINUM" << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	//Instrucciones para el jugador
	cout << "Para poder jugar este juego, debes ingresar un n" << char (163) 
		<< "mero entre 1000 y" << endl << "9999." << endl << endl;
	cout << "Si ese n" << char (163) << "mero es el mismo que el que ha sido" 
		<< " escogido aleatoriamente " << endl << "para esta partida, eres " 
		<< "victorioso." << endl << endl;
	cout << "Si no lograste descifrarlo, tienes nueve intentos m" << char (160) 
		<< "s para hacerlo." << endl << endl;
	cout << "Si en todos los diez intentos, no logras descifrarlo, podr" 
		<< char (160) << "s " << endl << "verlo finalmente y la partida acabar" 
		<< char (160) << "." << endl << endl;
	cout << "Con cada intento, dependiendo de si el n" << char (163) 
		<< "mero ingresado contiene uno " << endl << "o m" << char (160) 
		<< "s d" << (char) 161 << "gitos del secreto, podr" << char (160) 
		<< "s ver la cantidad de d" << (char) 161 << "gitos que se " << endl
		<< "encuentran " << "en el mismo lugar que en el n" << char (163) 
		<< "mero oculto y " << "los que se " << endl << "encuentran en un " 
		<< "lugar distinto." << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	}
int JugarAdivinum() {
	int intentos = 1;
	cout << "Intento " << intentos << ": ";
	int digitosigualpos = 0, digitosdispos = 0;
	//Generación de número secreto
	srand (time(NULL));
	int numsecreto = rand() % 9999 + 1000;
	int cifra1n1 = numsecreto / 1000, cifra2n1 = (numsecreto / 100) % 10, 
		cifra3n1 = (numsecreto % 100) / 10, cifra4n1 = numsecreto % 10;
	while (numsecreto > 9999 || numsecreto < 1000 
		   || cifra1n1 == cifra2n1 || cifra1n1 == cifra3n1 
		   || cifra1n1 == cifra4n1
		   || cifra2n1 == cifra1n1 || cifra2n1 == cifra3n1 
		   || cifra2n1 == cifra4n1
		   || cifra3n1 == cifra1n1 || cifra3n1 == cifra2n1 
		   || cifra3n1 == cifra4n1   
		   || cifra4n1 == cifra1n1 || cifra4n1 == cifra2n1 
		   || cifra4n1 == cifra3n1) {
		numsecreto = rand() % 9999 + 1000;
		cifra1n1 = numsecreto / 1000, cifra2n1 = (numsecreto / 100) % 10, 
			cifra3n1 = (numsecreto % 100) / 10, cifra4n1 = numsecreto % 10;
	}
	int adivinanza;
	cin >> adivinanza;
	while (adivinanza != numsecreto && intentos < 10) {
		while (adivinanza > 9999 || adivinanza < 1000) {
			cout << "Se debe ingresar un n" << (char) 163 
				<< "mero entre 1000 y 9999. Intente de nuevo: ";
			cin >> adivinanza;
		}
		int cifra1n2 = adivinanza / 1000, cifra2n2 = (adivinanza / 100) % 10, 
			   cifra3n2 = (adivinanza % 100) / 10, cifra4n2 = adivinanza % 10;
		if(cifra1n1 == cifra1n2) digitosigualpos++;
		if(cifra2n1 == cifra2n2) digitosigualpos++;
		if(cifra3n1 == cifra3n2) digitosigualpos++;
		if(cifra4n1 == cifra4n2) digitosigualpos++;
		if(cifra1n1 == cifra2n2 || cifra1n1 == cifra3n2 || cifra1n1 == cifra4n2)
			digitosdispos++;
		if(cifra2n1 == cifra1n2 || cifra2n1 == cifra3n2 || cifra2n1 == cifra4n2)
			digitosdispos++;
		if(cifra3n1 == cifra1n2 || cifra3n1 == cifra2n2 || cifra3n1 == cifra4n2) 
			digitosdispos++;
		if(cifra4n1 == cifra1n2 || cifra4n1 == cifra2n2 || cifra4n1 == cifra3n2)
			digitosdispos++;
		ConfigurarColor(11);
		cout << "Cant. de dig. repetidos en la misma posici" << (char) 162 << 
			"n: ";
		ConfigurarColor(15);
		cout << digitosigualpos << "." << endl; 
		ConfigurarColor(11);
		cout << "Cant. de dig. repetidos en otra posici" << (char) 162 << "n: "; 
		ConfigurarColor(15);
		cout << digitosdispos << "." << endl;
		digitosigualpos = 0, digitosdispos = 0;
		intentos++;
		cout << "Intento " << intentos << ": ";
		cin >> adivinanza;
	}
	cout << endl;
	int puntaje = 0;
	if (adivinanza == numsecreto) {
		//Cálculo de puntaje
		puntaje = 11 - intentos;
		//Mensaje de victoria
		cout << "HAS GANADO. Puntaje obtenido: " << puntaje
			<< " " << (char) 173 << "Felicitaciones!" << endl;
	}
	else if (intentos == 10)
		//Mensaje de derrota
		cout << "HAS FALLADO. El n" << (char) 163 << "mero era " << numsecreto 
			<< "." << endl;
	return puntaje;
}
 
