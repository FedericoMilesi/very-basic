//Implementación de librería
#include "ahorcado.h"
//Prototipos de funciones
void ConfigurarColor(int valor);
void LimpiarPantallaAhorcado();
void PartesPerdidas(int b);
void LetrasYaIngresadas(char letrasincorrectas[100]);
using namespace std;
string ElegirPalabra(int a);

void InstruccionesAhorcado() {
	//Nombre del juego
	cout << "AHORCADO" << endl << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
	//Instrucciones para el jugador
	cout << "Para poder jugar este juego, debes intentar descifrar letra por " 
		<< endl << "letra la palabra que ha sido escogida al azar." << endl;
	cout << endl;
	cout << "Esta palabra est" << (char) 160 << " relacionada con el lenguaje " 
		<< "de programaci" << (char) 162 << "n C++ y " << endl << 
		"la codificaci" << (char) 162 << "n de algoritmos en general. Tienes" 
		<< " una pista." << endl;
	cout << endl;
	cout << "Por cada intento fall" << (char) 161 << "do perder" << (char) 160 
		<< "s una parte del cuerpo. En total " << endl 
		<< "tienes diez intentos, en caso de que falles todos ser" 
		<< (char) 160 << "s ahorcado." << endl;
	cout << endl;
	cout << "===============================================================" 
		<< "=====" << endl << endl;
}
void LimpiarPantallaAhorcado() {
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
string ElegirPalabra(int a) {
	//Lectura de archivo (palabrasAhorcado.txt)
	ifstream f;
	f.open("palabrasAhorcado.txt");
	char palabra[12];
	int palabraleida = 0;
	while (palabraleida < a) {
		f >> palabra;
		palabraleida++;
	}
	return string(palabra);
}
void PartesPerdidas(int b) {
	if(b == 1) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
	}
	if(b == 2) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
	}
	if(b == 3) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
	}
	if(b == 4) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
	}
	if(b == 5) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
	}
	if(b == 6) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pierna derecha";
		ConfigurarColor(15);
	}
	if(b == 7) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pierna derecha";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano izquierda";
		ConfigurarColor(15);
	}
	if(b == 8) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pierna derecha";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano derecha";
		ConfigurarColor(15);
	}
	if(b == 9) { 
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pierna derecha";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano derecha";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pie izquierdo";
		ConfigurarColor(15);
	}
	if(b == 10) {
		ConfigurarColor(12);
		cout << "cabeza";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "tronco";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "brazo derecho";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pierna izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pierna derecha";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano izquierda";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "mano derecha";
		ConfigurarColor(15);
		cout << endl;
		ConfigurarColor(12);
		cout << "pie izquierdo";
		ConfigurarColor(15);
		cout << " - ";
		ConfigurarColor(12);
		cout << "pie derecho";
		ConfigurarColor(15);
	}
}
void LetrasYaIngresadas(char letrasincorrectas[10]) {
	int iterador = 0;
	while(letrasincorrectas[iterador] != '\0') {
		ConfigurarColor(14);
		if(letrasincorrectas[iterador] != letrasincorrectas[iterador-1]) 
			cout << letrasincorrectas[iterador] << " ";
		ConfigurarColor(15);
		iterador++;
	}
}

int JugarAhorcado() {
	//Generación de palabra oculta
	srand (time(NULL));
	int aleatoria = rand() % 30 + 0, caracteres;
	string palabra; 
	char palabraoculta[21], pistaelegida[99];
	if(aleatoria == 0) {
		//Palabra = "COMPILADOR"
		palabra = ElegirPalabra(1);
		char guiones[11] = "__________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Traduce el código fuente a código ejecutable.";
		pista[12] = (char) 162;
		pista[28] = (char) 162;
		strcpy(pistaelegida, pista);
		caracteres = 10;
	}
	if(aleatoria == 1) {
		//Palabra = "ENTORNO"
		palabra = ElegirPalabra(2);
		char guiones[8] = "_______";
		strcpy(palabraoculta, guiones);
		char pista[] =
	 "En él disponemos de un conjunto de ventanas y de botones para programar.";
		pista[3] = (char) 130;
		strcpy(pistaelegida, pista);
		caracteres = 7;
	}
	if(aleatoria == 2) {
		//Palabra = "COMPUTADORA"
		palabra = ElegirPalabra(3);
		char guiones[12] = "___________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Debe realizar un conjunto mínimo de funciones.";
		pista[27] = (char) 161;
		strcpy(pistaelegida, pista);
		caracteres = 11;
	}
	if(aleatoria == 3) {
		//Palabra = "ESTRUCTURA"
		palabra = ElegirPalabra(4);
		char guiones[11] = "__________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Es lo que da forma y orden a un programa.";
		strcpy(pistaelegida, pista);
		caracteres = 10;
	}
	if(aleatoria == 4) {
		//Palabra = "SELECCION"
		palabra = ElegirPalabra(5);
		char guiones[10] = "_________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Estructura de control básica.";
		pista[23] = (char) 160;
		strcpy(pistaelegida, pista);
		caracteres = 9;
	}
	if(aleatoria == 5) {
		//Palabra = "REPETICION"
		palabra = ElegirPalabra(6);
		char guiones[11] = "__________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Estructura de control básica.";
		pista[23] = (char) 160;
		strcpy(pistaelegida, pista);
		caracteres = 10;
	}
	if(aleatoria == 6) {
		//Palabra = "DIRECTIVA"
		palabra = ElegirPalabra(7);
		char guiones[10] = "_________";
		strcpy(palabraoculta, guiones);
		char pista[] =
		"Indica al preprocesador que realice acciones específicas.";
		pista[50] = (char) 161;
		strcpy(pistaelegida, pista);
		caracteres = 9;
	}
	if(aleatoria == 7) {
		//Palabra = "ALGORITMO"
		palabra = ElegirPalabra(8);
		char guiones[10] = "_________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Conjunto finito de instrucciones o pasos.";
		strcpy(pistaelegida, pista);
		caracteres = 9;
	}
	if(aleatoria == 8) {
		//Palabra = "PROGRAMA"
		palabra = ElegirPalabra(9);
		char guiones[9] = "________";
		strcpy(palabraoculta, guiones);
		char pista[] = "Conjunto de instrucciones o sentencias.";
		strcpy(pistaelegida, pista);
		caracteres = 8;
	}
	if(aleatoria == 9) {
		//Palabra = "EJECUCION"
		palabra = ElegirPalabra(10);
		char guiones[10] = "_________";
		strcpy(palabraoculta, guiones);
		char pista[] =
		"Proceso que lleva a cabo las instrucciones de un programa.";
		strcpy(pistaelegida, pista);
		caracteres = 9;
	}
	if(aleatoria == 10) {
		//Palabra = "INT"
		palabra = ElegirPalabra(11);
		char guiones[4] = "___";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite almacenar números enteros.";
		pista[19] = (char) 163;
		strcpy(pistaelegida, pista);
		caracteres = 3;
	}
	if(aleatoria == 11) {
		//Palabra = "FLOAT"
		palabra = ElegirPalabra(12);
		char guiones[6] = "_____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite almacenar números con decimales.";
		pista[19] = (char) 163;
		strcpy(pistaelegida, pista);
		caracteres = 5;
	}
	if(aleatoria == 12) {
		//Palabra = "CHAR"
		palabra = ElegirPalabra(13);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite almacenar símbolos.";
		pista[19] = (char) 161;
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 13) {
		//Palabra = "DOUBLE"
		palabra = ElegirPalabra(14);
		char guiones[7] = "______";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite almacenar números con decimales.";
		pista[19] = (char) 163;
		strcpy(pistaelegida, pista);
		caracteres = 6;
	}
	if(aleatoria == 14) {
		//Palabra = "LONG"
		palabra = ElegirPalabra(15);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] =
		"Permite extender la capacidad de almacenamiento de ciertas variables.";
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 15) {
		//Palabra = "IF"
		palabra = ElegirPalabra(16);
		char guiones[3] = "__";
		strcpy(palabraoculta, guiones);
		char pista[] = "Opuesto de ELSE.";
		strcpy(pistaelegida, pista);
		caracteres = 2;
	}
	if(aleatoria == 16) {
		//Palabra = "ELSE"
		palabra = ElegirPalabra(17);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Opuesto de IF.";
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 17) {
		//Palabra = "FOR"
		palabra = ElegirPalabra(18);
		char guiones[4] = "___";
		strcpy(palabraoculta, guiones);
		char pista[] = "Estructura de repetición.";
		pista[22] = (char) 162;
		strcpy(pistaelegida, pista);
		caracteres = 3;
	}
	if(aleatoria == 18) {
		//Palabra = "WHILE"
		palabra = ElegirPalabra(19);
		char guiones[6] = "_____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Estructura de repetición.";
		pista[22] = (char) 162;
		strcpy(pistaelegida, pista);
		caracteres = 5;
	}
	if(aleatoria == 19) {
		//Palabra = "RETURN"
		palabra = ElegirPalabra(20);
		char guiones[7] = "______";
		strcpy(palabraoculta, guiones);
		char pista[] =
		"Indica al compilador que debe regresar un valor de r...";
		strcpy(pistaelegida, pista);
		caracteres = 6;
	}
	if(aleatoria == 20) {
		//Palabra = "BREAK"
		palabra = ElegirPalabra(21);
		char guiones[6] = "_____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Interrumpe un ciclo de repetición.";
		pista[31] = (char) 162;
		strcpy(pistaelegida, pista);
		caracteres = 5;
	}
	if(aleatoria == 21) {
		//Palabra = "SWITCH"
		palabra = ElegirPalabra(22);
		char guiones[7] = "______";
		strcpy(palabraoculta, guiones);
		char pista[] = "Estructura condicional.";
		strcpy(pistaelegida, pista);
		caracteres = 6;
	}
	if(aleatoria == 22) {
		//Palabra = "CASE"
		palabra = ElegirPalabra(23);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] = 
		"Permite evaluar una variable en cierta estructura de control.";
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 23) {
		//Palabra = "MAIN"
		palabra = ElegirPalabra(24);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Esencial en cualquier programa.";
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 24) {
		//Palabra = "INCLUDE"
		palabra = ElegirPalabra(25);
		char guiones[8] = "_______";
		strcpy(palabraoculta, guiones);
		char pista[] = "Directiva del preprocesador.";
		strcpy(pistaelegida, pista);
		caracteres = 7;
	}
	if(aleatoria == 25) {
		//Palabra = "DEFINE"
		palabra = ElegirPalabra(26);
		char guiones[7] = "______";
		strcpy(palabraoculta, guiones);
		char pista[] = "Macro del preprocesador.";
		strcpy(pistaelegida, pista);
		caracteres = 6;
	}
	if(aleatoria == 26) {
		//Palabra = "STRUCT"
		palabra = ElegirPalabra(27);
		char guiones[7] = "______";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite indicar elementos para componer una es...";
		strcpy(pistaelegida, pista);
		caracteres = 6;
	}
	if(aleatoria == 27) {
		//Palabra = "CIN"
		palabra = ElegirPalabra(28);
		char guiones[4] = "___";
		strcpy(palabraoculta, guiones);
		char pista[] = "Permite la entrada formateada.";
		strcpy(pistaelegida, pista);
		caracteres = 3;
	}
	if(aleatoria == 28) {
		//Palabra = "COUT"
		palabra = ElegirPalabra(29);
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] =
		"Transforma a ASCII los datos en binario y los deriva a pantalla.";
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	if(aleatoria == 29) {
		//Palabra = "ENDL"
		palabra = ElegirPalabra(30);		
		char guiones[5] = "____";
		strcpy(palabraoculta, guiones);
		char pista[] = "Salto de línea.";
		pista[10] = (char) 161;
		strcpy(pistaelegida, pista);
		caracteres = 4;
	}
	bool acierto = false, descifrada = false, detener = false, repetida = false;
	int iterador = 0, letrasadivinadas = 0, letrasrepetidas = 0, partes = 0;
	char adivinanza, lectura[100], repeticion[10];
	repeticion[0] = '\0', repeticion[1] = '\0', repeticion[2] = '\0', 
		repeticion[3] = '\0', repeticion[4] = '\0', repeticion[5] = '\0', 
		repeticion[6] = '\0', repeticion[7] = '\0', repeticion[8] = '\0', 
		repeticion[9] = '\0', repeticion[10] = '\0';
	while (letrasadivinadas < caracteres && detener == false) {
		acierto = false;
		descifrada = false;
		repetida = false;
		cout << "La palabra a ser adivinada tiene " << caracteres << " letras." 
			<< endl;
		cout << "Pista: " << pistaelegida << endl;
		cout << "Palabra: ";
		iterador = 0;
		while (palabraoculta[iterador] != '\0') {
			if(palabraoculta[iterador] != '_') {
				ConfigurarColor(10);
				cout << palabraoculta[iterador] << " ";
				ConfigurarColor(15);
			}
			else cout << palabraoculta[iterador] << " ";
			iterador++;
		}
		cout << endl;
		cout << "Letras incorrectas: ";
		LetrasYaIngresadas(repeticion);
		cout << endl;
		cout << "Partes perdidas: ";
		PartesPerdidas(partes);
		if(partes == 10) detener = true;
		if(detener == false) {
			cout << endl;
			if(letrasadivinadas == 0 && partes == 0) cout 
				<< "Ingrese una letra para adivinar: ";
			else if(letrasadivinadas > 0 || partes > 0) {
				cout << "Ingrese otra letra para adivinar: ";
			}
			cin >> lectura;
			adivinanza = lectura[0];
			while((adivinanza < 65 || adivinanza > 90) 
				&& (adivinanza < 97 || adivinanza > 122)) {
				cout << "No has ingresado ninguna letra. Intente de nuevo: ";
				cin >> lectura;
				adivinanza = lectura[0];
				}
				if(adivinanza >= 97 && adivinanza <= 122) {
					adivinanza -= 32;
				}
				iterador = 0;
				while (palabra[iterador] != '\0' && descifrada != true) {
					if(palabra[iterador] == adivinanza && 
					   palabraoculta[iterador] != adivinanza) { 
						palabraoculta[iterador] = adivinanza;
						letrasadivinadas++;
						acierto = true;
					}
					else if(palabraoculta[iterador] == adivinanza) {
						descifrada = true;
					}
					iterador++;
				}
				iterador = 0;
				while (repeticion[iterador] != '\0' && acierto == false && 
					   descifrada == false) {
					if(repeticion[iterador] == adivinanza) { 
						repetida = true;
					}
					iterador++;
				}
				if (acierto == true) cout << "Acertaste una letra.";
				else if (acierto == false && descifrada == true)
					cout << "La letra que has ingresado ya ha sido descifrada.";
				else if (acierto == false && repetida == true) cout 
					<< "La letra que has ingresado ya ha sido ingresada err" 
					<< (char) 162 << "neamente.";
				else if (acierto == false && repetida == false) {
					cout << "Esa letra no se encuentra en la palabra. ";
					repeticion[letrasrepetidas] = adivinanza;
					letrasrepetidas++;
					partes++;
				}
		}
		Sleep( 1200 );
		LimpiarPantallaAhorcado();
	}
	cout << "La palabra a ser adivinada tiene " << caracteres << " letras." 
		   << endl;
	cout << "Pista: " << pistaelegida << endl;
	cout << "Palabra: ";
	iterador = 0;
	while (palabraoculta[iterador] != '\0') {
		if(palabraoculta[iterador] != '_') {
			ConfigurarColor(10);
			cout << palabraoculta[iterador] << " ";
			ConfigurarColor(15);
		}
		else cout << palabraoculta[iterador] << " ";
		iterador++;
	}
	cout << endl;
	int puntaje = 0;
	if (partes != 10) {
		cout << "Letras incorrectas: ";
		LetrasYaIngresadas(repeticion);
		cout << endl;
		cout << "Partes perdidas: ";
		PartesPerdidas(partes);
		cout << endl << endl;
		//Cálculo de puntaje
		puntaje = 50 - 2*partes;
		//Mensaje de victoria
		cout << "HAS GANADO. Puntaje obtenido: " << puntaje
			<< ". " << (char) 173 << "Felicitaciones!" << endl;
	}
	else {
		cout << "Letras incorrectas: ";
		LetrasYaIngresadas(repeticion);
		cout << endl;
		cout << "Partes perdidas: ";
		PartesPerdidas(partes);
		cout << endl << endl;
		//Mensaje de derrota
		cout << "HAS SIDO AHORCADO. La palabra era " << palabra 
			<< "." << endl;
	}
	return puntaje;
}
