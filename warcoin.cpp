//Implementación de librería
#include "warcoin.h"
//Prototipo de función
void ConfigurarColor(int valor);
using namespace std;

void InstruccionesWarcoin() {
	//Nombre del juego
	cout << "WARCOIN" << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	//Instrucciones para el jugador
	cout << "Para poder empezar a jugar este juego, debes ingresar la cantidad "
		<< endl << "m" << (char) 161 << "nima y m" << (char) 160 << "xima de "
		<< "monedas que puedan ser retiradas de una " << "pila de " << endl 
		<< "monedas en una s" << (char) 162 << "la instancia. " << endl << endl;
	cout << "Dicha pila tendr" << (char) 160 << " una cantidad inicial de "
		<< "monedas que ser" << (char) 160 << " un " << "valor " << endl 
		<< "al azar. De esa pila tendr" << (char) 160 
		<< "s que sacar monedas estrat" << char (130) << "gicamente " << endl 
		<< "hasta vaciarla, teniendo en cuenta que tienes un oponente " << 
		"controlado " << endl << "por computadora que tambi" << char (130) 
		<< "n saca monedas." << endl << endl;
	cout << "Para ganar debes vaciar la pila antes que la computadora. Se "
		<< endl << "decidir" << (char) 160 << " al azar quien comienzar" 
		<< char (160) << " la partida." << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
}
int JugarWarcoin() {
	cout << "Cantidad ";
	ConfigurarColor(10);
	cout << "m" << char (161) << "nima";
	ConfigurarColor(15);
	cout << " de monedas retirables (1-8): ";
	char caracter;
	cin >> caracter;
	while (caracter < '1' || caracter > '8') {
		Sleep( 500 );
		cout << "La cantidad de monedas ingresada debe ser un n" << (char) 163
			<< "mero entre 1 y 8." << endl << "Intente de nuevo: ";
		cin >> caracter;
	}
	int minmonedas = (int) caracter - 48;
	Sleep( 500 );
	cout << "Cantidad ";
	ConfigurarColor(12);
	cout << "m" << char (160) << "xima"; 
	ConfigurarColor(15);
	cout << " de monedas retirables (2-9): ";
	cin >> caracter;
	while (caracter < '2' || caracter > '9') {
		Sleep( 500 );
		cout << "La cantidad de monedas ingresada debe ser un n" << (char) 163
			<< "mero entre 2 y 9." << endl << "Intente de nuevo: ";
		cin >> caracter;
	}
	int maxmonedas = caracter - 48;
	while (maxmonedas < minmonedas || maxmonedas == minmonedas 
		   || caracter < '2' || caracter > '9') {
		Sleep( 500 );
		cout << "La cantidad de monedas ingresada debe ser mayor que la " << 
			"anterior. Intente de nuevo: ";
		cin >> caracter;
		maxmonedas = caracter - 48;
	}
	//Generación de pila de monedas
	srand (time(NULL));
	int monenpila = rand() % 50 + 10;
	while (monenpila < 10 || monenpila > 50) {
		monenpila = rand() % 50 + 10;
	}
	Sleep( 500 );
	ConfigurarColor(14);
	cout << "Monedas en pila: ";
	ConfigurarColor(15);
	cout << monenpila << endl;
	//Elección aleatoria del jugador del primer turno
	int primjugador = rand() % 2 + 1;
	int monaretirar, ganador;
	bool detener = false;
	if (primjugador == 1) { 
		Sleep( 500 );
		cout << "Es t" << (char) 163 << " turno. " << (char) 168 
			<< "Cu" << (char) 160 << "ntas monedas retirar" 
			<< (char) 160 << "s? ";
		cin >> caracter;
		monaretirar = caracter - 48;
		while (monaretirar < minmonedas || monaretirar > maxmonedas) {
			Sleep( 500 );
			cout << "La cantidad de monedas ingresada debe ser entre "
				<< minmonedas << " y " << maxmonedas << "." << endl 
				<< "Intente de nuevo: ";
			cin >> caracter;
			monaretirar = caracter - 48;
		}
		monenpila -= monaretirar;
		Sleep( 500 );
		ConfigurarColor(14);
		cout << "Monedas restantes en la pila: ";
		ConfigurarColor(15);
		cout << monenpila << endl;
		while (monenpila > 0 && detener == false) {
			monaretirar = rand() % maxmonedas + minmonedas;
			while (monaretirar < minmonedas || monaretirar > maxmonedas) {
				monaretirar = rand() % maxmonedas + minmonedas;
			}
			Sleep( 500 );
			cout << "Es turno de la computadora. Retira " << monaretirar 
				<< " monedas." << endl;
			monenpila -= monaretirar;
			if(monenpila <= 0) { 
				ganador = 1;
				detener = true;
			}
			Sleep( 500 );
			if (detener == false) {
				ConfigurarColor(14);
				cout << "Monedas restantes en la pila: ";
				ConfigurarColor(15);
				cout << monenpila << endl;
				Sleep( 500 );
				cout << "Es t" << (char) 163 << " turno. " << (char) 168 
					<< "Cu" << (char) 160 << "ntas monedas retirar" 
					<< (char) 160 << "s? ";
				cin >> caracter;
				monaretirar = caracter - 48;
				while (monaretirar < minmonedas || monaretirar > maxmonedas) {
					Sleep( 500 );
					cout << "La cantidad de monedas ingresada debe ser entre ";
					ConfigurarColor(10);
					cout << minmonedas;
					ConfigurarColor(15);
					cout << " y ";
					ConfigurarColor(12);
					cout << maxmonedas;
					ConfigurarColor(15);
					cout << "." << endl << "Intente de nuevo: ";
					cin >> caracter;
					monaretirar = caracter - 48;
				}
				monenpila -= monaretirar;
				if(monenpila <= 0) { 
					ganador = 0;
					detener = true;
				}
			}
			Sleep( 500 );
			if (detener == false) { 
				ConfigurarColor(14);
				cout << "Monedas restantes en la pila: ";
				ConfigurarColor(15);
				cout << monenpila << endl;
			}
		}
	}
	else if (primjugador == 2) { 
		monaretirar = rand() % maxmonedas + minmonedas;
		while (monaretirar < minmonedas || monaretirar > maxmonedas) {
			monaretirar = rand() % maxmonedas + minmonedas;
		}
		Sleep( 500 );
		cout << "Es turno de la computadora. Retira " << monaretirar 
			<< " monedas." << endl;
		monenpila -= monaretirar;
		Sleep( 500 );
		ConfigurarColor(14);
		cout << "Monedas restantes en la pila: ";
		ConfigurarColor(15);
		cout << monenpila << endl;
		while (monenpila > 0 && detener == false) {
			Sleep( 500 );
			cout << "Es t" << (char) 163 << " turno. " << (char) 168 
				<< "Cu" << (char) 160 << "ntas monedas retirar" 
				<< (char) 160 << "s? ";
			cin >> caracter;
			monaretirar = caracter - 48;
			while (monaretirar < minmonedas || monaretirar > maxmonedas) {
				Sleep( 500 );
				cout << "La cantidad de monedas ingresada debe ser entre ";
				ConfigurarColor(10);
				cout << minmonedas;
				ConfigurarColor(15);
				cout << " y ";
				ConfigurarColor(12);
				cout << maxmonedas;
				ConfigurarColor(15);
				cout << "." << endl << "Intente de nuevo: ";
				cin >> caracter;
				monaretirar = caracter - 48;
			}
			monenpila -= monaretirar;
			if(monenpila <= 0) { 
				ganador = 0;
				detener = true;
			}
			Sleep( 500 );
			if (detener == false) {
				ConfigurarColor(14);
				cout << "Monedas restantes en la pila: ";
				ConfigurarColor(15);
				cout << monenpila << endl;
				monaretirar = rand() % maxmonedas + minmonedas;
				while (monaretirar < minmonedas || monaretirar > maxmonedas) {
					monaretirar = rand() % maxmonedas + minmonedas;
				}
				Sleep( 500 );
				cout << "Es turno de la computadora. Retira " << monaretirar 
					<< " monedas." << endl;
				monenpila -= monaretirar;
				if(monenpila <= 0) {
					ganador = 1;
					detener = true;
				}
			}
			Sleep( 500 );
			if (detener == false) { 
				ConfigurarColor(14);
				cout << "Monedas restantes en la pila: ";
				ConfigurarColor(15);
				cout << monenpila << endl;
			}
		}
	}
	Sleep( 500 );
	cout << endl;
	int puntaje = 0;
	if (ganador == 0) {
		//Cálculo de puntaje
		puntaje = 5;
		//Mensaje de victoria
		cout << "VACIASTE LA PILA, HAS GANADO. Puntaje obtenido: " << puntaje
			<< " ";
		cout << (char) 173 << "Felicitaciones!" << endl;
	}
	if (ganador == 1)
		//Mensaje de derrota
		cout << "LA COMPUTADORA HA VACIADO LA PILA, HAS FALLADO." << endl;
	return puntaje;
}
