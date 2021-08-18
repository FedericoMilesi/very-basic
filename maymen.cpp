//Implementación de librería
#include "maymen.h"
//Prototipo de función
void ConfigurarColor(int valor);
using namespace std;

void InstruccionesMaymen() {
	//Nombre del juego
	cout << "MAYMEN" << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	//Instrucciones para el jugador
	cout << "Para poder jugar este juego, debes ingresar un n" << char (163) 
		<< "mero entre 1 y 999." << endl << endl;
	cout << "Si ese n" << char (163) << "mero es el mismo que el que ha sido" 
		<< " escogido aleatoriamente " << endl << "para esta partida, eres " 
		<< "victorioso." << endl << endl;
	cout << "Si no lograste descifrarlo, tienes nueve intentos m" << char (160) 
		<< "s para hacerlo." << endl << endl;
	cout << "Si en todos los diez intentos, no logras descifrarlo, podr" 
		<< char (160) << "s " << endl << "verlo finalmente y la partida acabar" 
		<< char (160) << "." << endl << endl;
	cout << "Con cada intento, dependiendo de si el n" << char (163) 
		<< "mero ingresado es mayor " << char (162) << endl << 
		"menor que el secreto, podr" << char (160) << "s ver un intervalo " 
		<< "reducido de los " << endl << "n" << char (163) 
		<< "meros que entre los cuales se encuentra el n" << char (163) 
		<< "mero oculto." << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
}
int JugarMaymen() {
	int intentos = 1;
	cout << "Intento " << intentos << ": ";
	int numintervalomenor = 1, numintervalomayor = 999;
	//Generación de número secreto
	srand (time(NULL));
	int numsecreto = rand() % 999 + 1;
	while (numsecreto > 999 || numsecreto < 1) {
		numsecreto = rand() % 999 + 1;
	}
	int adivinanza;
	cin >> adivinanza;
	while (adivinanza != numsecreto && intentos < 10) {
		while (adivinanza > 999 || adivinanza < 1) {
			cout << "Se debe ingresar un n" << (char) 163 
				<< "mero entre 1 y 999. Intente de nuevo: ";
			cin >> adivinanza;
		}
		if(numsecreto < adivinanza) { 
			if (adivinanza < numintervalomayor) numintervalomayor = adivinanza 
				- 1;
			ConfigurarColor(11);
			cout << "El n" << (char) 163 << "mero secreto es menor y se " 
				<< "encuentra entre " << numintervalomenor << " y " 
				<< numintervalomayor << "." << endl;
			ConfigurarColor(15);
		}
		if(numsecreto > adivinanza) {
			if (adivinanza > numintervalomenor) numintervalomenor = adivinanza 
				+ 1;
			ConfigurarColor(11);
			cout << "El n" << (char) 163 << "mero secreto es mayor y se " 
				<< "encuentra entre " << numintervalomenor << " y " 
				<< numintervalomayor << "." << endl;
			ConfigurarColor(15);
		}
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
 
