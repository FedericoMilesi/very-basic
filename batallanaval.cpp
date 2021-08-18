//Implementación de librería
#include "batallanaval.h"
//Prototipos de funciones
void ConfigurarColor(int valor);
void cargarTablero(char tablero[10][10]);
void LimpiarPantallaBN();
using namespace std;

void InstruccionesBatallaNaval() {
	//Nombre del juego
	cout << "BATALLA NAVAL" << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	//Instrucciones para el jugador
	cout << "Para poder jugar este juego, debes realizar disparos a barcos" 
		<< endl << "enemigos con tu ca" << (char) 164 << (char) 162 << "n. " 
		<< "Para realizar cada disparo, debes ingresar" << endl 
		<< "una letra y un n" << (char) 163 << "mero, ambos correspondientes a "
		<< "las coordenadas de" << endl << "la casilla a la cual quieres " << 
		"disparar. S" << (char) 162 << "lo sabr" << (char) 160 << "s lo que has" 
		<< endl << "disparado luego de realizar el disparo, porque los barcos "
		<< "est" << (char) 160 << "n" << endl << "ocultos." << endl << endl;
	cout << "Si realizas un disparo y terminas disparando al agua, perder" 
		<< (char) 160 << "s un" << endl 
		<< "punto de vida. Si en lugar de disparar a un barco disparas a una" 
		<< endl << "mina, perder" << (char) 160 << "s cinco puntos de vida.";
	cout << endl << endl;
	cout << "Empiezas el juego con 100 puntos de vida. Si te quedas sin puntos" 
		<< endl << "de vida, pierdes. Y si ganas, tu puntuaci" << (char) 162 
		<< "n ser" << (char) 160 << " la misma que la" << endl
		<< "cantidad de puntos de vida que tengas restantes." << endl << endl;
	cout << "Para poder ganar el juego, debes hundir los siete barcos evitando"
		<< endl << "las diez minas y el agua." << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
}
void cargarTablero(char tablero[10][10]) {
	srand(time(NULL));
	int barcos [7] = {5, 4, 4, 3, 3, 2, 2};
	char barco = 'a';
	int x, y, longitud, l, r;
	bool listo, horizontal;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
		tablero[i][j] = '.';
		for(int i = 0; i < 7; i++) {
			listo = false;
			do {
				longitud = barcos[i];
				x = rand() % 10;
				y = rand() % 10;
				horizontal = rand() % 2;
				l = r = (horizontal)? x : y;
				if(tablero[x][y] == '.') {
					longitud--;
					for(int j = ((horizontal)? x : y) + 1; j < 10 && !listo 
						&& tablero[x + horizontal * (j - x)][y + (!horizontal) 
							* (j - y)] == '.'; j++) {
						longitud--;
						r = j;
						if(longitud == 0) listo = true;
					}
							for(int j = ((horizontal) ? x : y) -1; j >= 0 && !listo 
								&& tablero[x + horizontal * (j - x)][y + (!horizontal) 
									* (j - y)] == '.'; j--) {
								longitud--;
								l = j;
								if(longitud == 0) listo = true;
							}
				}
			}
			while (!listo);
			for(int j = l; j <= r; j++) tablero[x + horizontal * (j - x)]
				[y + (!horizontal) * (j - y)] = barco;
			barco++;
		}
		for(int i = 0; i < 10; i++) {
			do {
				x = rand() % 10;
				y = rand() % 10;
			} 
			while (tablero[x][y] != '.');
			tablero[x][y] = 'm';
		}
		return;
}
void LimpiarPantallaBN() {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };
	
	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;
	
	if (!FillConsoleOutputCharacter(
									hStdOut,
									(TCHAR) ' ',
									cellCount,
									homeCoords,
									&count
									)) return;
	
	if (!FillConsoleOutputAttribute(
									hStdOut,
									csbi.wAttributes,
									cellCount,
									homeCoords,
									&count
									)) return;
	
	SetConsoleCursorPosition( hStdOut, homeCoords );
}
int JugarBatallaNaval() {
	LimpiarPantallaBN();
	ConfigurarColor(10);
	char tableropartida[10][10], tablerooculto[10][10], letras;
	string numeros = "     1 2 3 4 5 6 7 8 9 10";
	//Generación de tablero
	cargarTablero(tableropartida);
	for(int columnas = 0; columnas < 10; columnas++) {
		for(int filas = 0; filas < 10; filas++) {
			tablerooculto[columnas][filas] = '?';
		}
	}
	cout << endl << endl << endl << numeros;
	for(int columnas = 0; columnas < 10; columnas++) {
		cout << endl;
		letras = columnas + 65;
		cout << letras << "    ";
		for(int filas = 0; filas < 10; filas++) {
			ConfigurarColor(2);
			cout << tablerooculto[columnas][filas] << " ";
			ConfigurarColor(10);
		}
	}
	char lectura[100], letra;
	int barcos = 7, numero, puntos = 100, jugadas = 1, a = 0, b = 0, c = 0, 
		d = 0, e = 0, f = 0, g = 0;
	while (puntos > 0 && barcos > 0) {
		cout << endl << endl;
		cout << "Jugada N" << (char) 167 << " " << jugadas << endl;
		cout << "Ingrese coordenadas a disparar: ";
		cin >> lectura;
		letra = lectura[0];
		numero = lectura[1] - 48;
		if(lectura [1] == 49 && lectura[2] == 48) numero = 10;
		if(letra >= 97 && letra <= 106) {
			letra -= 32;
		} 
		LimpiarPantallaBN();
		cout << "Puntos de vida restantes: ";
		//Informaciones para el jugador sobre el resultado de su ataque.
		if(((letra >= 65 && letra <= 74)) && (numero >= 1 && numero <= 10)) {
			int coordenadax = ((int) letra) - 65, coordenaday = numero - 1;
			if(tableropartida[coordenadax][coordenaday] == '.'){
				tablerooculto[coordenadax][coordenaday] = 'a';
				puntos -= 1;
				cout << puntos << endl;
				cout << "Resultado de la jugada anterior: ";
				cout << "Le has disparado al";
				ConfigurarColor(11);
				cout << " AGUA";
				ConfigurarColor(10);
				cout << ". Pierdes un punto." << endl;
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'm') {
				tablerooculto[coordenadax][coordenaday] = 'm';
				tableropartida[coordenadax][coordenaday] = 'M';
				puntos -= 5;
				cout << puntos << endl;
				cout << "Resultado de la jugada anterior: ";
				cout << "Le has disparado a una ";
				ConfigurarColor(8);
				cout << "MINA MARINA";
				ConfigurarColor(10);
				cout << ". Pierdes cinco puntos." << endl;
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'a') {
				a++;
				if(a == 5) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'b') {
				b++;
				if(b == 4) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'c') {
				c++;
				if(c == 4) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'd') {
				d++;
				if(d == 3) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'e') {
				e++;
				if(e == 3) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'f') {
				f++;
				if(f == 2) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'g') {
				g++;
				if(g == 2) {
					tablerooculto[coordenadax][coordenaday] = 'H';
					tableropartida[coordenadax][coordenaday] = 'H';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					ConfigurarColor(20);
					cout << "HAS HUNDIDO UN BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Excelente." << endl;
					barcos--;
				}
				else {
					tablerooculto[coordenadax][coordenaday] = 'F';
					tableropartida[coordenadax][coordenaday] = 'F';
					cout << puntos << endl;
					cout << "Resultado de la jugada anterior: ";
					cout << "Le has disparado a un ";
					ConfigurarColor(12);
					cout << "BARCO ENEMIGO";
					ConfigurarColor(10);
					cout << ". Muy bien." << endl;
				}
				jugadas++;
			}
			else if(tableropartida[coordenadax][coordenaday] == 'H' 
				|| tableropartida[coordenadax][coordenaday] == 'F' 
					|| tableropartida[coordenadax][coordenaday] == 'M') {
				cout << puntos << endl;
				cout << "Resultado de la jugada anterior: ";
				cout << "Ya has disparado en esa posici" << (char) 162 
					<< "n. Intente de nuevo." << endl;
			}
		}
		else {
			cout << puntos << endl;
			cout << "Resultado de la jugada anterior: ";
			cout << "Se deben ingresar coordenadas validas. Intente de nuevo." 
				<< endl; 
		}
		cout << endl << numeros;
		for(int columnas = 0; columnas < 10; columnas++) {
			cout << endl;
			letras = columnas + 65;
			cout << letras << "    ";
			for(int filas = 0; filas < 10; filas++) {
				if (tablerooculto[columnas][filas] == 'a') 
					ConfigurarColor(11);
				else if (tablerooculto[columnas][filas] == 'F') 
					ConfigurarColor(12);
				else if(tablerooculto[columnas][filas] == 'H') 
					ConfigurarColor(20);
				else if(tablerooculto[columnas][filas] == 'm') 
					ConfigurarColor(8);
				else if(tablerooculto[columnas][filas] == '?') 
					ConfigurarColor(2);
				cout << tablerooculto[columnas][filas] << " ";
				ConfigurarColor(10);
			}
		}		
	}
	int puntaje = 0;
	if (puntos > 0) {
		//Cálculo de puntaje
		puntaje = puntos;
		//Mensaje de victoria
		cout << endl << endl << "HAS GANADO. Puntaje obtenido: " << puntaje 
			<< " " << (char) 173 << "Felicitaciones!" << endl;
	}
	else
		//Mensaje de derrota
		cout << endl << endl << "HAS PERDIDO. No llegaste a destruir los barcos" 
			<< " a tiempo." << endl;
	ConfigurarColor(15);
	return puntaje;
}
 
