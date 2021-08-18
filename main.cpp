//Implementación de librerías
#include "adivinum.h"
#include "ahorcado.h"
#include "batallanaval.h"
#include "maymen.h"
#include "warcoin.h"
#include <conio.h>
#include <iomanip>
//Estructuras de datos
struct Fecha {
	int dia;
	int mes;
	int anyo;
};
struct Partida {
	char nombre_usuario[11];
	int id_juego;
	int puntaje;
};
struct Usuario {
	char nombre_usuario[11];
	char clave[37];
	Fecha ultimo_acceso;
	Partida partidas[1000];
};
//Prototipos de funciones
void ConfigurarColor(int valor);
void LimpiarPantalla();
char MostrarMenu();
Usuario CrearUsuario();
int IniciarSesion(Usuario actual);
char MostrarMenu2();
Usuario PantallaDeBienvenida(Usuario actual, int id);
char MenuMaymen();
char MenuAdivinum();
char MenuWarCoin();
char MenuAhorcado();
char MenuBatallaNaval();
char MenuEstadisticasJuegos(int vecesjugadasMM, int vecesjugadasAD, 
							int vecesjugadasWC, int vecesjugadasAH,
							int vecesjugadasBN, int diplomasMM, int monedasMM, 
							int medallasMM, int trofeosMM, int copasMM, 
							int diplomasAD, int monedasAD, int medallasAD, 
							int trofeosAD, int copasAD, int copasWC, 
							int medallasAH, int trofeosAH, int copasAH, 
							int diplomasBN, int monedasBN, int medallasBN, 
							int trofeosBN, int copasBN);
char MenuEstadisticasUsuarios(int puntosMM, int puntosAD, int puntosWC, 
							  int puntosAH, int puntosBN, 
							  char mejorjugadorMM[11],
							  char mejorjugadorAD[11],
							  char mejorjugadorWC[11],
							  char mejorjugadorAH[11],
							  char mejorjugadorBN[11]);
using namespace std;

int main() {
	//Declaración estructura Usuario
	struct Usuario actual[100];
	//Declaración estructura Partida
	struct Partida partidas[1000];
	char opcion, opcion2, opcion3, opcion4, caracter[99];
	int id, npart, vecesjugadasMM, puntajemaximoMM, 
		vecesjugadasAD, puntajemaximoAD, vecesjugadasWC,
		puntajemaximoWC, vecesjugadasAH, puntajemaximoAH,
		vecesjugadasBN, puntajemaximoBN;
	while(opcion != '9') {
		LimpiarPantalla();
		//Definición color de texto (blanco brillante)
		ConfigurarColor(15);
		npart = 0, vecesjugadasMM = 0, puntajemaximoMM = 0, 
		vecesjugadasAD = 0, puntajemaximoAD = 0, vecesjugadasWC = 0,
		puntajemaximoWC = 0, vecesjugadasAH = 0, puntajemaximoAH = 0,
		vecesjugadasBN = 0, puntajemaximoBN = 0;
		opcion = '0', opcion2 = '0', opcion3 = '0', opcion4 = '0';
		strcpy(actual[id].nombre_usuario, "\0");
		strcpy(actual[id].clave, "\0");
		opcion = MostrarMenu();
		id = 0;
		if(opcion == '1') {
			actual[id] = CrearUsuario();
			id = -2;
		}
		else if(opcion == '2') { 
			id = IniciarSesion(actual[id]);
		}
		else if(opcion == '3') {
			while(opcion2 != '9') {
				LimpiarPantalla();
				cout << "Estad" << (char) 161 << "sticas" << endl;
				cout << "==========================" << endl << endl;
				//Opciones para el jugador
				cout << "1. De Juegos" << endl;
				cout << "2. De Usuarios" << endl << endl;
				cout << "9. Volver al men" << (char) 163 << " anterior" 
					<< endl << endl;
				cout << "==========================" << endl << endl;
				cout << "Ingrese una opci" << (char) 162 << "n: ";
				cin >> opcion2;
				while(opcion2 <= 47 || opcion2 >= 58) {
					LimpiarPantalla();
					cout << "Estad" << (char) 161 << "sticas" << endl;
					cout << "==========================" << endl << endl;
					cout << "1. De Juegos" << endl;
					cout << "2. De Usuarios" << endl << endl;
					cout << "9. Volver al men" << (char) 163 << " anterior" 
						<< endl << endl;
					cout << "==========================" << endl << endl;
					cout << "Ingrese una opci" << (char) 162 << "n: ";
					cout << endl << endl;
					cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
						<< "intentarlo: ";
					cin >> opcion2;
				}
				if(opcion2 == '1') {
					while(opcion3 != '9') {
						LimpiarPantalla();
						int vecesjugadasMM = 0, vecesjugadasAD = 0, 
							vecesjugadasWC = 0,vecesjugadasAH = 0, 
							vecesjugadasBN = 0, diplomasMM = 0, monedasMM = 0, 
							medallasMM = 0, trofeosMM = 0, copasMM = 0, 
							diplomasAD = 0, monedasAD = 0, medallasAD = 0, 
							trofeosAD = 0, copasAD = 0, copasWC = 0, 
							medallasAH = 0, trofeosAH = 0, copasAH = 0, 
							diplomasBN = 0, monedasBN = 0, medallasBN = 0, 
							trofeosBN = 0, copasBN = 0, puntos;
						char nombre_usuario[11], id_juego, puntaje[3];
						//Lectura de archivo (Partidas.txt)
						ifstream f;
						f.open("Partidas.txt");
						if(f.fail()) {
							f.close();
							ofstream f;
							f.open("Partidas.txt");
							f.close();
						}
						else while(!f.eof()) {
							f >> nombre_usuario;
							f >> id_juego;
							if(id_juego == '0') {
								vecesjugadasMM++;
								if(f.eof()) vecesjugadasMM--;
							}
							else if(id_juego == '1') {
								vecesjugadasAD++;
								if(f.eof()) vecesjugadasAD--;
							}
							else if(id_juego == '2') {
								vecesjugadasWC++;
								if(f.eof()) vecesjugadasWC--;
							}
							else if(id_juego == '3') {
								vecesjugadasAH++;
								if(f.eof()) vecesjugadasAH--;
							}
							else if(id_juego == '4') {
								vecesjugadasBN++;
								if(f.eof()) vecesjugadasBN--;
							}
							f >> puntaje;
							if(puntaje[1] != '\0') 
								puntos = ((puntaje[0] - 48) * 10) +
								(puntaje[1] - 48);
							else puntos = puntaje[0] - 48;
							if(id_juego == '0' 
							   && puntos >= 2 && puntos < 4) {
								diplomasMM++;
								if(f.eof()) diplomasMM--;
							}
							else if(id_juego == '0' 
									&& puntos >= 4 && puntos < 6) {
								monedasMM++;
								if(f.eof()) monedasMM--;
							}
							else if(id_juego == '0' 
									&& puntos >= 6 && puntos < 8) {
								medallasMM++;
								if(f.eof()) medallasMM--;
							}
							else if(id_juego == '0' 
									&& puntos >= 8 && puntos < 10) {
								trofeosMM++;
								if(f.eof()) trofeosMM--;
							}
							else if(id_juego == '0' 
									&& puntos == 10) {
								copasMM++;
								if(f.eof()) copasMM--;
							}
							else if(id_juego == '1' 
									&& puntos >= 2 && puntos < 4) {
								diplomasAD++;
								if(f.eof()) diplomasAD--;
							}
							else if(id_juego == '1' 
									&& puntos >= 4 && puntos < 6) {
								monedasAD++;
								if(f.eof()) monedasAD--;
							}
							else if(id_juego == '1' 
									&& puntos >= 6 && puntos < 8) {
								medallasAD++;
								if(f.eof()) medallasAD--;
							}
							else if(id_juego == '1' 
									&& puntos >= 8 && puntos < 10) {
								trofeosAD++;
								if(f.eof()) trofeosAD--;
							}
							else if(id_juego == '1' 
									&& puntos == 10) {
								copasAD++;
								if(f.eof()) copasAD--;
							}
							else if(id_juego == '2' 
									&& puntos == 5) {
								copasWC++;
								if(f.eof()) copasWC--;
							}
							else if(id_juego == '3' 
									&& puntos >= 30 && puntos < 40) {
								medallasAH++;
								if(f.eof()) medallasAH--;
							}
							else if(id_juego == '3' 
									&& puntos >= 40 && puntos < 50) {
								trofeosAH++;
								if(f.eof()) trofeosAH--;
							}
							else if(id_juego == '3' 
									&& puntos == 50) {
								copasAH++;
								if(f.eof()) copasAH--;
							}
							else if(id_juego == '4' 
									&& puntos >= 20 && puntos < 40) {
								diplomasBN++;
								if(f.eof()) diplomasBN--;
							}
							else if(id_juego == '4' 
									&& puntos >= 40 && puntos < 60) {
								monedasBN++;
								if(f.eof()) monedasBN--;
							}
							else if(id_juego == '4' 
									&& puntos >= 60 && puntos < 80) {
								medallasBN++;
								if(f.eof()) medallasBN--;
							}
							else if(id_juego == '4' 
									&& puntos >= 80 && puntos < 90) {
								trofeosBN++;
								if(f.eof()) trofeosBN--;
							}
							else if(id_juego == '4' 
									&& puntos >= 90) {
								copasBN++;
								if(f.eof()) copasBN--;
							}
						}
						f.close();
						opcion3 = MenuEstadisticasJuegos(vecesjugadasMM, vecesjugadasAD, 
														vecesjugadasWC, vecesjugadasAH, vecesjugadasBN, 
														diplomasMM, monedasMM, medallasMM, trofeosMM, copasMM, 
														diplomasAD, monedasAD, medallasAD, trofeosAD, copasAD, 
														copasWC, medallasAH, trofeosAH, copasAH, diplomasBN, 
														monedasBN, medallasBN, trofeosBN, copasBN);
					}
				opcion3 = '0';
				}
				else if(opcion2 == '2') {
					while(opcion3 != '9') {
						LimpiarPantalla();
						int puntosMM = 0, puntosAD = 0, puntosWC = 0, puntosAH = 0,
						puntosBN = 0, puntos;
						char nombre_usuario[11], id_juego, puntaje[3], 
						mejorjugadorMM[11], mejorjugadorAD[11], mejorjugadorWC[11],
						mejorjugadorAH[11], mejorjugadorBN[11];
						//Lectura de archivo (Partidas.txt)
						ifstream f;
						f.open("Partidas.txt");
						if(f.fail()) {
							f.close();
							ofstream f;
							f.open("Partidas.txt");
							f.close();
						}
						else while(!f.eof()) {
							f >> nombre_usuario;
							f >> id_juego;
							f >> puntaje;
							if(puntaje[1] != '\0') 
								puntos = ((puntaje[0] - 48) * 10) +
								(puntaje[1] - 48);
							else puntos = puntaje[0] - 48;
								if(id_juego == '0' && puntos > puntosMM) {
								puntosMM = puntos;
								strcpy(mejorjugadorMM, nombre_usuario);
							}
							else if(id_juego == '1' && puntos > puntosAD) {
								puntosAD = puntos;
								strcpy(mejorjugadorAD, nombre_usuario);
							}
							else if(id_juego == '2' && puntos > puntosWC) {
								puntosWC = puntos;
								strcpy(mejorjugadorWC, nombre_usuario);
							}
							else if(id_juego == '3' && puntos > puntosAH) {
								puntosAH = puntos;
								strcpy(mejorjugadorAH, nombre_usuario);
							}
							else if(id_juego == '4' && puntos > puntosBN) {
								puntosBN = puntos;
								strcpy(mejorjugadorBN, nombre_usuario);
							}
						}
						f.close();
						opcion3 = MenuEstadisticasUsuarios(puntosMM, puntosAD, 
								puntosWC, puntosAH, puntosBN, mejorjugadorMM,
								mejorjugadorAD, mejorjugadorWC, mejorjugadorAH,
								mejorjugadorBN);
						}
					opcion3 = '0';
					}
				}
			opcion2 = '0';
			id = -2;
		}
		else if(opcion == '9') return 0;
		LimpiarPantalla();
		if (id > -2) {
			actual[id] = PantallaDeBienvenida(actual[id], id);
			while(opcion4 != '9' && id > -2) { 
				LimpiarPantalla();
				opcion4 = MostrarMenu2();
				if(opcion4 == '1') { 
					while(opcion4 != '6') {
						LimpiarPantalla();
						opcion4 = MenuMaymen();
						if(opcion4 == '1') {
							LimpiarPantalla();
							InstruccionesMaymen();
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '2') {
							LimpiarPantalla();
							if(npart <= 999) {
								strcpy(partidas[npart].nombre_usuario, 
									   actual[id].nombre_usuario);
								partidas[npart].id_juego = 0;
								partidas[npart].puntaje = JugarMaymen();
								//Escritura de archivo (Partidas.txt)
								ofstream f;
								f.open("Partidas.txt", fstream::app);
								f << actual[id].nombre_usuario << endl;
								f << partidas[npart].id_juego << endl;
								f << partidas[npart].puntaje << endl;
								f.close();
								npart++;
							}
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " del juego.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '3') {
							LimpiarPantalla();
							cout << "El jugador " << actual[id].nombre_usuario << ": " 
								<< endl << endl;
							bool mismousuario;
							int contador = 0, caracteresrepetidos, caracterestotales, 
								iterador, puntos;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								if(mismousuario == true && id_juego == '0') {
									contador++;
									if(f.eof()) contador--;
								}
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '0' 
								   && puntos > puntajemaximoMM) 
									puntajemaximoMM = puntos;
							}
							f.close();
							vecesjugadasMM = contador;
							cout << (char) 254 << " Jug" << (char) 162 << " MayMen " 
								<< vecesjugadasMM << " veces." << endl;
							cout << (char) 254 << " El m" << (char) 160 << "ximo " 
								<< "puntaje que obtuvo fue " 
								<< puntajemaximoMM << " puntos." << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '4') {
							LimpiarPantalla();
							cout << "Premios obtenidos en MayMen" 
								<< endl;
							cout << "===========================" << endl << endl;
							bool mismousuario;
							int caracteresrepetidos, caracterestotales, 
								iterador, puntos, diplomas = 0, monedas = 0, 
								medallas = 0, trofeos = 0, copas = 0;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '0' 
								   && puntos >= 2 && puntos < 4) {
									diplomas++;
									if(f.eof()) diplomas--;
								}
								else if(mismousuario == true && id_juego == '0' 
										&& puntos >= 4 && puntos < 6) {
									monedas++;
									if(f.eof()) monedas--;
								}
								else if(mismousuario == true && id_juego == '0' 
										&& puntos >= 6 && puntos < 8) {
									medallas++;
									if(f.eof()) medallas--;
								}
								else if(mismousuario == true && id_juego == '0' 
										&& puntos >= 8 && puntos < 10) {
									trofeos++;
									if(f.eof()) trofeos--;
								}
								else if(mismousuario == true && id_juego == '0' 
										&& puntos == 10) {
									copas++;
									if(f.eof()) copas--;
								}
							}
							f.close();
							cout << "Diplomas: " << diplomas << endl;
							cout << "Monedas: " << monedas << endl;
							cout << "Medallas: " << medallas << endl;
							cout << "Trofeos: " << trofeos << endl;
							cout << "Copas: " << copas << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
					}
				}
				else if(opcion4 == '2') { 
					while(opcion4 != '6') {
						LimpiarPantalla();
						opcion4 = MenuAdivinum();
						if(opcion4 == '1') {
							LimpiarPantalla();
							InstruccionesAdivinum();
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '2') {
							LimpiarPantalla();
							if(npart <= 999) {
								strcpy(partidas[npart].nombre_usuario, 
									   actual[id].nombre_usuario);
								partidas[npart].id_juego = 1;
								partidas[npart].puntaje = JugarAdivinum();
								//Escritura de archivo (Partidas.txt)
								ofstream f;
								f.open("Partidas.txt", fstream::app);
								f << actual[id].nombre_usuario << endl;
								f << partidas[npart].id_juego << endl;
								f << partidas[npart].puntaje << endl;
								f.close();
								npart++;
							}
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " del juego.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '3') {
							LimpiarPantalla();
							cout << "El jugador " << actual[id].nombre_usuario << ": " 
								<< endl << endl;
							bool mismousuario;
							int contador = 0, caracteresrepetidos, caracterestotales, 
								iterador, puntos;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								if(mismousuario == true && id_juego == '1') {
									contador++;
									if(f.eof()) contador--;
								}
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '1' 
								   && puntos > puntajemaximoAD) 
									puntajemaximoAD = puntos;
							}
							f.close();
							vecesjugadasAD = contador;
							cout << (char) 254 << " Jug" << (char) 162 << " Adivinum " 
								<< vecesjugadasAD << " veces." << endl;
							cout << (char) 254 << " El m" << (char) 160 << "ximo " 
								<< "puntaje que obtuvo fue " 
								<< puntajemaximoAD << " puntos." << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '4') {
							LimpiarPantalla();
							cout << "Premios obtenidos en Adivinum" 
								<< endl;
							cout << "=============================" << endl << endl;
							bool mismousuario;
							int caracteresrepetidos, caracterestotales, 
								iterador, puntos, diplomas = 0, monedas = 0, 
								medallas = 0, trofeos = 0, copas = 0;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '1' 
								   && puntos >= 2 && puntos < 4) {
									diplomas++;
									if(f.eof()) diplomas--;
								}
								else if(mismousuario == true && id_juego == '1' 
										&& puntos >= 4 && puntos < 6) {
									monedas++;
									if(f.eof()) monedas--;
								}
								else if(mismousuario == true && id_juego == '1' 
										&& puntos >= 6 && puntos < 8) {
									medallas++;
									if(f.eof()) medallas--;
								}
								else if(mismousuario == true && id_juego == '1' 
										&& puntos >= 8 && puntos < 10) {
									trofeos++;
									if(f.eof()) trofeos--;
								}
								else if(mismousuario == true && id_juego == '1' 
										&& puntos == 10) {
									copas++;
									if(f.eof()) copas--;
								}
							}
							f.close();
							cout << "Diplomas: " << diplomas << endl;
							cout << "Monedas: " << monedas << endl;
							cout << "Medallas: " << medallas << endl;
							cout << "Trofeos: " << trofeos << endl;
							cout << "Copas: " << copas << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
					}
				}
				else if(opcion4 == '3') { 
					while(opcion4 != '6') {
						LimpiarPantalla();
						opcion4 = MenuWarCoin();
						if(opcion4 == '1') {
							LimpiarPantalla();
							InstruccionesWarcoin();
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '2') {
							LimpiarPantalla();
							if(npart <= 999) {
								strcpy(partidas[npart].nombre_usuario, 
									   actual[id].nombre_usuario);
								partidas[npart].id_juego = 2;
								partidas[npart].puntaje = JugarWarcoin();
								//Escritura de archivo (Partidas.txt)
								ofstream f;
								f.open("Partidas.txt", fstream::app);
								f << actual[id].nombre_usuario << endl;
								f << partidas[npart].id_juego << endl;
								f << partidas[npart].puntaje << endl;
								f.close();
								npart++;
							}					
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " del juego.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '3') {
							LimpiarPantalla();
							cout << "El jugador " << actual[id].nombre_usuario << ": " 
								<< endl << endl;
							bool mismousuario;
							int contador = 0, caracteresrepetidos, caracterestotales, 
								iterador, puntos;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								if(mismousuario == true && id_juego == '2') {
									contador++;
									if(f.eof()) contador--;
								}
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '2' 
								   && puntos > puntajemaximoWC) 
									puntajemaximoWC = puntos;
							}
							f.close();
							vecesjugadasWC = contador;
							cout << (char) 254 << " Jug" << (char) 162 << " WarCoin " 
								<< vecesjugadasWC << " veces." << endl;
							cout << (char) 254 << " El m" << (char) 160 << "ximo " 
								<< "puntaje que obtuvo fue " 
								<< puntajemaximoWC << " puntos." << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '4') {
							LimpiarPantalla();
							cout << "Premios obtenidos en WarCoin" 
								<< endl;
							cout << "============================" << endl << endl;
							bool mismousuario;
							int caracteresrepetidos, caracterestotales, 
								iterador, puntos, copas = 0;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '2' 
								   && puntos == 5) {
									copas++;
									if(f.eof()) copas--;
								}
							}
							f.close();
							cout << "Copas: " << copas << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
					}
				}
				else if(opcion4 == '4') { 
					while(opcion4 != '6') {
						LimpiarPantalla();
						opcion4 = MenuAhorcado();
						if(opcion4 == '1') {
							LimpiarPantalla();
							InstruccionesAhorcado();
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '2') {
							LimpiarPantalla();
							if(npart <= 999) {
								strcpy(partidas[npart].nombre_usuario, 
									   actual[id].nombre_usuario);
								partidas[npart].id_juego = 3;
								partidas[npart].puntaje = JugarAhorcado();
								//Escritura de archivo (Partidas.txt)
								ofstream f;
								f.open("Partidas.txt", fstream::app);
								f << actual[id].nombre_usuario << endl;
								f << partidas[npart].id_juego << endl;
								f << partidas[npart].puntaje << endl;
								f.close();
								npart++;
							}
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " del juego.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '3') {
							LimpiarPantalla();
							cout << "El jugador " << actual[id].nombre_usuario << ": " 
								<< endl << endl;
							bool mismousuario;
							int contador = 0, caracteresrepetidos, caracterestotales, 
								iterador, puntos;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								if(mismousuario == true && id_juego == '3') {
									contador++;
									if(f.eof()) contador--;
								}
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '3' 
								   && puntos > puntajemaximoAH) 
									puntajemaximoAH = puntos;
							}
							f.close();
							vecesjugadasAH = contador;
							cout << (char) 254 << " Jug" << (char) 162 << " Ahorcado " 
								<< vecesjugadasAH << " veces." << endl;
							cout << (char) 254 << " El m" << (char) 160 << "ximo " 
								<< "puntaje que obtuvo fue " 
								<< puntajemaximoAH << " puntos." << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '4') {
							LimpiarPantalla();
							cout << "Premios obtenidos en Ahorcado" 
								<< endl;
							cout << "=============================" << endl << endl;
							bool mismousuario;
							int caracteresrepetidos, caracterestotales, 
								iterador, puntos, medallas = 0, trofeos = 0, copas = 0;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '3' 
								   && puntos >= 30 && puntos < 40) {
									medallas++;
									if(f.eof()) medallas--;
								}
								else if(mismousuario == true && id_juego == '3' 
										&& puntos >= 40 && puntos < 50) {
									trofeos++;
									if(f.eof()) trofeos--;
								}
								else if(mismousuario == true && id_juego == '3' 
										&& puntos == 50) {
									copas++;
									if(f.eof()) copas--;
								}
							}
							f.close();
							cout << "Medallas: " << medallas << endl;
							cout << "Trofeos: " << trofeos << endl;
							cout << "Copas: " << copas << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
					}
				}
				else if(opcion4 == '5') {
					while(opcion4 != '6') {
						LimpiarPantalla();
						opcion4 = MenuBatallaNaval();
						if(opcion4 == '1') {
							LimpiarPantalla();
							InstruccionesBatallaNaval();
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '2') {
							LimpiarPantalla();
							if(npart <= 999) {
								strcpy(partidas[npart].nombre_usuario, 
									   actual[id].nombre_usuario);
								partidas[npart].id_juego = 4;
								partidas[npart].puntaje = JugarBatallaNaval();
								//Escritura de archivo (Partidas.txt)
								ofstream f;
								f.open("Partidas.txt", fstream::app);
								f << actual[id].nombre_usuario << endl;
								f << partidas[npart].id_juego << endl;
								f << partidas[npart].puntaje << endl;
								f.close();
								npart++;
							}
							cout << endl;
							ConfigurarColor(10);
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " del juego.";
							ConfigurarColor(15);
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '3') {
							LimpiarPantalla();
							cout << "El jugador " << actual[id].nombre_usuario << ": " 
								<< endl << endl;
							bool mismousuario;
							int contador = 0, caracteresrepetidos, caracterestotales, 
								iterador, puntos;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								if(mismousuario == true && id_juego == '4') {
									contador++;
									if(f.eof()) contador--;
								}
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '4' 
								   && puntos > puntajemaximoBN) 
									puntajemaximoBN = puntos;
							}
							f.close();
							vecesjugadasBN = contador;
							cout << (char) 254 << " Jug" << (char) 162 << " Batalla " 
								<< "Naval " << vecesjugadasBN << " veces." 
								<< endl;
							cout << (char) 254 << " El m" << (char) 160 << "ximo " 
								<< "puntaje que obtuvo fue " 
								<< puntajemaximoBN << " puntos." << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
						else if(opcion4 == '4') {
							LimpiarPantalla();
							cout << "Premios obtenidos en Batalla Naval" 
								<< endl;
							cout << "==================================" << endl 
								<< endl;
							bool mismousuario;
							int caracteresrepetidos, caracterestotales, 
								iterador, puntos, diplomas = 0, monedas = 0, 
								medallas = 0, trofeos = 0, copas = 0;
							char nombre_usuario[11], id_juego, puntaje[3];
							//Lectura de archivo (Partidas.txt)
							ifstream f;
							f.open("Partidas.txt");
							if(f.fail()) {
								f.close();
								ofstream f;
								f.open("Partidas.txt");
								f.close();
							}
							else while(!f.eof()) {
								caracteresrepetidos = 0;
								caracterestotales = 
									string(actual[id].nombre_usuario).length();
								iterador = 0;
								mismousuario = false;
								f >> nombre_usuario;
								while(iterador < caracterestotales) {
									if(actual[id].nombre_usuario[iterador] == 
									   nombre_usuario[iterador]) caracteresrepetidos++;
									iterador++;
								}
								if(caracteresrepetidos == caracterestotales) 
									  mismousuario = true;
								f >> id_juego;
								f >> puntaje;
								if(puntaje[1] != '\0') 
									puntos = ((puntaje[0] - 48) * 10) +
									(puntaje[1] - 48);
								else puntos = puntaje[0] - 48;
								if(mismousuario == true && id_juego == '4' 
								   && puntos >= 20 && puntos < 40) {
									diplomas++;
									if(f.eof()) diplomas--;
								}
								else if(mismousuario == true && id_juego == '4' 
										&& puntos >= 40 && puntos < 60) {
									monedas++;
									if(f.eof()) monedas--;
								}
								else if(mismousuario == true && id_juego == '4' 
										&& puntos >= 60 && puntos < 80) {
									medallas++;
									if(f.eof()) medallas--;
								}
								else if(mismousuario == true && id_juego == '4' 
										&& puntos >= 80 && puntos < 90) {
									trofeos++;
									if(f.eof()) trofeos--;
								}
								else if(mismousuario == true && id_juego == '4' 
										&& puntos >= 90) {
									copas++;
									if(f.eof()) copas--;
								}
							}
							f.close();
							cout << "Diplomas: " << diplomas << endl;
							cout << "Monedas: " << monedas << endl;
							cout << "Medallas: " << medallas << endl;
							cout << "Trofeos: " << trofeos << endl;
							cout << "Copas: " << copas << endl;
							cout << endl;
							cout << "Presione cualquier tecla para volver al men" 
								<< (char) 163 << " anterior.";
							char tecla;
							tecla = getch();
						}
					}
				}
				else if(opcion4 == '9') {
					LimpiarPantalla();
				}
			}
		}
	}
}

void ConfigurarColor(int valor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), valor);
}
void LimpiarPantalla() {
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
char MostrarMenu() {
	cout << "Men" << (char) 163 << " Principal" << endl;
	cout << "========================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Registro" << endl;
	cout << "2. Iniciar sesi" << (char) 162 << "n" << endl;
	cout << "3. Estad" << (char) 161 << "sticas" << endl << endl;
	cout << "9. Cerrar la aplicaci" << (char) 162 << "n" << endl << endl;
	cout << "========================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Men" << (char) 163 << " Principal" << endl;
		cout << "========================" << endl << endl;
		cout << "1. Registro" << endl;
		cout << "2. Iniciar sesi" << (char) 162 << "n" << endl;
		cout << "3. Estad" << (char) 161 << "sticas" << endl << endl;
		cout << "9. Cerrar la aplicaci" << (char) 162 << "n" << endl << endl;
		cout << "========================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
Usuario CrearUsuario() {
	bool detener = false;
	struct Usuario actual;
	while(detener != true) {
		LimpiarPantalla();
		//Información para el jugador
		cout << "A continuaci" << (char) 162 << "n, debe ingresar un nombre"
			<< " de usuario para su nueva" << endl << "cuenta. " << endl 
			<< endl << "El nombre debe tener por lo menos seis caracteres y "
			<< "como m" << (char) 160 << "ximo" << endl << "diez. Debe comenzar"
			<< " con una letra min" << (char) 163 << "scula, debe tener por " 
			<< "lo" << endl << "menos dos letras may" << (char) 163 
			<< "sculas y si contiene d" << (char) 161 << "gitos estos no pueden" 
			<< endl << "ser m" << (char) 160 << "s que tres." << endl;
		cout << endl;
		cout << "Nombre de usuario: ";
		char nomusuario[99];
		cin >> nomusuario;
		bool condiciona = true, condicionb = true, condicionc = true, 
			condiciond = true, condicione = true, longitud = true;
		int iterador = 0, letrasmayus = 0, digitos = 0, id = -2, 
			caracteresrepetidos, caracterestotales;
		while(nomusuario[iterador] != '\0') {
			if(nomusuario[iterador] >= 'A' && nomusuario[iterador] <= 'Z') 
				letrasmayus++;
			if(nomusuario[iterador] >= '0' && nomusuario[iterador] <= '9')
				digitos++;
			iterador++;
		}
		if(nomusuario[0] >= 'A' && nomusuario[0] <= 'Z') condicionb = false;
		if(letrasmayus < 2) condicionc = false;
		if(digitos > 3) condiciond = false;
		char nombre_usuario[11], clave[37], dia[2], mes[2], anio[5];
		//Lectura de archivo (Usuarios.txt)
		ifstream f;
		f.open("Usuarios.txt");
		if(f.fail()) {
			f.close();
			ofstream f;
			f.open("Usuarios.txt");
			f.close();
			id = 0;
		}
		else while(!f.eof()) {
			caracteresrepetidos = 0;
			f >> nombre_usuario;
			caracterestotales = string(nombre_usuario).length();
			if(iterador == caracterestotales) { 
				iterador = 0;
				while(iterador < caracterestotales) {
					if(nomusuario[iterador] == nombre_usuario[iterador])
						caracteresrepetidos++;
					iterador++;
				}
				if(caracteresrepetidos == caracterestotales) condicione = false;
			}
			f >> clave;
			f >> dia;
			f >> mes;
			f >> anio;
			id++;
		}
		f.close();
		if(iterador > 10) longitud = false;
		if(condiciona == true && condicionb == true && condicionc == true 
		   && condiciond == true && condicione == true && longitud == true) {
			cout << endl;
			cout << "Nombre de usuario ";
			//Definición color de texto (verde claro)
			ConfigurarColor(10);
			cout << "v" << (char) 160 << "lido";
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << ".";
			detener = true;
			strcpy(actual.nombre_usuario, nomusuario);
		}
		else {
			cout << endl;
			cout << "Nombre de usuario ";
			//Definición color de texto (rojo claro)
			ConfigurarColor(12);
			cout << "inv" << (char) 160 << "lido";
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << "." << endl << endl;
			//Opciones para el jugador
			cout << "Ingrese la letra X para volver al men" << (char) 163 
				<< " o cualquier otro caracter " << endl << "para reintentar: ";
			char opcion[99];
			cin >> opcion;
			if(opcion[0] == 'x' || opcion[0] == 'X') {
				strcpy(actual.nombre_usuario, "\0");
				strcpy(actual.clave, "\0");
				return actual;
			}
		}
	}
	Sleep(2500);
	detener = false;
	while(detener != true) {
		LimpiarPantalla();
		//Información para el jugador
		cout << "A continuaci" << (char) 162 << "n, debe ingresar una contrase"
			<< (char) 164 << "a para su nueva cuenta." << endl << endl;
		cout << "La contrase" << (char) 164 << "a debe tener por lo menos seis "
			<< "caracteres alfanum" << (char) 130 << "ricos" << endl 
			<< "y como m" << (char) 160 << "ximo treintaid" << (char) 162 
			<< "s. Debe tener al menos una letra may" << (char) 163 
			<< "scula," << endl << "una letra min" << (char) 163 << "scula y " 
			<< "un d" << (char) 161 << "gito. No debe tener m" << (char) 160 
			<< "s de tres d" << (char) 161 << "gitos" << endl << "consecutivos."
			<< " No debe tener dos letras consecutivas que tambi" << (char) 130 
			<< "n sean" << endl << "alfab" << (char) 130 
			<< "ticamente consecutivas (por ejemplo: 'AB')." << endl;
		cout << endl;
		cout << "Contrase" << (char) 164 << "a: ";
		char contra[99];
		cin >> contra;
		bool condiciona = true, condicionb = true, condicionc = true, 
			condiciond = true, condicione = true, longitud = true;
		int iterador = 0, letrasmayus = 0, letrasminus = 0, digitos = 0, 
			numconsecutivos = 0, caracterestotales = 
			string(actual.nombre_usuario).length(), caracteresrepetidos = 0;
		while(contra[iterador] != '\0') {
			if((contra[iterador] < '0') || 
				(contra[iterador] >= '[' && contra[iterador] <= '`') ||
				(contra[iterador] >= '{')) condicionb = false;
			if(contra[iterador] >= 'A' && contra[iterador] <= 'Z') {
				letrasmayus++;
				switch(contra[iterador]) {
				case 'B': if(contra[iterador-1] == 'A' || contra[iterador-1] == 
						  'a') condicione = false;
						  break;
				case 'C': if(contra[iterador-1] == 'B' || contra[iterador-1] == 
						  'b') condicione = false;
						  break;
				case 'D': if(contra[iterador-1] == 'C' || contra[iterador-1] == 
						  'c') condicione = false;
						  break;
				case 'E': if(contra[iterador-1] == 'D' || contra[iterador-1] == 
						  'd') condicione = false;
						  break;
				case 'F': if(contra[iterador-1] == 'E' || contra[iterador-1] == 
						  'e') condicione = false;
						  break;
				case 'G': if(contra[iterador-1] == 'F' || contra[iterador-1] == 
						  'f') condicione = false;
						  break;
				case 'H': if(contra[iterador-1] == 'G' || contra[iterador-1] == 
						  'g') condicione = false;
						  break;
				case 'I': if(contra[iterador-1] == 'H' || contra[iterador-1] == 
						  'h') condicione = false;
						  break;
				case 'J': if(contra[iterador-1] == 'I' || contra[iterador-1] == 
						  'i') condicione = false;
						  break;
				case 'K': if(contra[iterador-1] == 'J' || contra[iterador-1] == 
						  'j') condicione = false;
						  break;
				case 'L': if(contra[iterador-1] == 'K' || contra[iterador-1] == 
						  'k') condicione = false;
						  break;
				case 'M': if(contra[iterador-1] == 'L' || contra[iterador-1] == 
						  'l') condicione = false;
						  break;
				case 'N': if(contra[iterador-1] == 'M' || contra[iterador-1] == 
						  'm') condicione = false;
						  break;
				case 'O': if(contra[iterador-1] == 'N' || contra[iterador-1] == 
						  'n') condicione = false;
						  break;
				case 'P': if(contra[iterador-1] == 'O' || contra[iterador-1] == 
						  'o') condicione = false;
						  break;
				case 'Q': if(contra[iterador-1] == 'P' || contra[iterador-1] == 
						  'p') condicione = false;
						  break;
				case 'R': if(contra[iterador-1] == 'Q' || contra[iterador-1] == 
						  'q') condicione = false;
						  break;
				case 'S': if(contra[iterador-1] == 'R' || contra[iterador-1] == 
						  'r') condicione = false;
						  break;
				case 'T': if(contra[iterador-1] == 'S' || contra[iterador-1] == 
						  's') condicione = false;
						  break;
				case 'U': if(contra[iterador-1] == 'T' || contra[iterador-1] == 
						  't') condicione = false;
						  break;
				case 'V': if(contra[iterador-1] == 'U' || contra[iterador-1] == 
						  'u') condicione = false;
						  break;
				case 'W': if(contra[iterador-1] == 'V' || contra[iterador-1] == 
						  'v') condicione = false;
						  break;
				case 'X': if(contra[iterador-1] == 'W' || contra[iterador-1] == 
						  'w') condicione = false;
						  break;
				case 'Y': if(contra[iterador-1] == 'X' || contra[iterador-1] == 
						  'x') condicione = false;
						  break;
				case 'Z': if(contra[iterador-1] == 'Y' || contra[iterador-1] == 
						  'y') condicione = false;
						  break;
				default: break;
				}
			}
			if(contra[iterador] >= 'a' && contra[iterador] <= 'z') { 
				letrasminus++;
				switch(contra[iterador]) {
				case 'b': if(contra[iterador-1] == 'A' || contra[iterador-1] == 
						  'a') condicione = false;
						  break;
				case 'c': if(contra[iterador-1] == 'B' || contra[iterador-1] == 
						  'b') condicione = false;
						  break;
				case 'd': if(contra[iterador-1] == 'C' || contra[iterador-1] == 
						  'c') condicione = false;
						  break;
				case 'e': if(contra[iterador-1] == 'D' || contra[iterador-1] == 
						  'd') condicione = false;
						  break;
				case 'f': if(contra[iterador-1] == 'E' || contra[iterador-1] == 
						  'e') condicione = false;
						  break;
				case 'g': if(contra[iterador-1] == 'F' || contra[iterador-1] == 
						  'f') condicione = false;
						  break;
				case 'h': if(contra[iterador-1] == 'G' || contra[iterador-1] == 
						  'g') condicione = false;
						  break;
				case 'i': if(contra[iterador-1] == 'H' || contra[iterador-1] == 
						  'h') condicione = false;
						  break;
				case 'j': if(contra[iterador-1] == 'I' || contra[iterador-1] == 
						  'i') condicione = false;
						  break;
				case 'k': if(contra[iterador-1] == 'J' || contra[iterador-1] == 
						  'j') condicione = false;
						  break;
				case 'l': if(contra[iterador-1] == 'K' || contra[iterador-1] == 
						  'k') condicione = false;
						  break;
				case 'm': if(contra[iterador-1] == 'L' || contra[iterador-1] == 
						  'l') condicione = false;
						  break;
				case 'n': if(contra[iterador-1] == 'M' || contra[iterador-1] == 
						  'm') condicione = false;
						  break;
				case 'o': if(contra[iterador-1] == 'N' || contra[iterador-1] == 
						  'n') condicione = false;
						  break;
				case 'p': if(contra[iterador-1] == 'O' || contra[iterador-1] == 
						  'o') condicione = false;
						  break;
				case 'q': if(contra[iterador-1] == 'P' || contra[iterador-1] == 
						  'p') condicione = false;
						  break;
				case 'r': if(contra[iterador-1] == 'Q' || contra[iterador-1] == 
						  'q') condicione = false;
						  break;
				case 's': if(contra[iterador-1] == 'R' || contra[iterador-1] == 
						  'r') condicione = false;
						  break;
				case 't': if(contra[iterador-1] == 'S' || contra[iterador-1] == 
						  's') condicione = false;
						  break;
				case 'u': if(contra[iterador-1] == 'T' || contra[iterador-1] == 
						  't') condicione = false;
						  break;
				case 'v': if(contra[iterador-1] == 'U' || contra[iterador-1] == 
						  'u') condicione = false;
						  break;
				case 'w': if(contra[iterador-1] == 'V' || contra[iterador-1] == 
						  'v') condicione = false;
						  break;
				case 'x': if(contra[iterador-1] == 'W' || contra[iterador-1] == 
						  'w') condicione = false;
						  break;
				case 'y': if(contra[iterador-1] == 'X' || contra[iterador-1] == 
						  'x') condicione = false;
						  break;
				case 'z': if(contra[iterador-1] == 'Y' || contra[iterador-1] == 
						  'y') condicione = false;
						  break;
				default: break;
				}
			}
			if(contra[iterador] >= '0' && contra[iterador] <= '9')
			   digitos++;
			if((contra[iterador] >= '0' && contra[iterador] <= '9') && 
				(contra[iterador-1] == contra[iterador])) numconsecutivos++;
			iterador++;
		}
		if(letrasmayus < 1) condiciona = false;
		if(letrasminus < 1) condiciona = false;
		if(digitos < 1) condiciona = false;
		if(numconsecutivos > 1) condiciond = false;
		if(iterador == caracterestotales) { 
			iterador = 0;
			while(iterador < caracterestotales) {
				if(contra[iterador] == actual.clave[iterador])
					caracteresrepetidos++;
				iterador++;
			}
			if(caracteresrepetidos == caracterestotales) condicione = false;
		}
		if(iterador < 6 || iterador > 32) longitud = false;
		if(condiciona == true && condicionb == true && condicionc == true 
		   && condiciond == true && condicione == true && longitud == true) {
			cout << endl;
			cout << "Contrase" << (char) 164 << "a ";
			//Definición color de texto (verde claro)
			ConfigurarColor(10);
			cout << "v" << (char) 160 << "lida";
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << ".";
			Sleep(2500);
			char opcion[99];
			opcion[0] = '0';
			while(opcion[0] != 'x' && opcion[0] != 'X' && detener != true) {
				LimpiarPantalla();
				//Información para el jugador
				cout << "A continuaci" << (char) 162 << "n, debe ingresar la " 
					<< "contrase" << (char) 164 
					<< "a nuevamente para " << endl << "completar el registro: ";
				char contra2[99];
				cin >> contra2;
				int caracteresvalidos = 0;
				caracterestotales = 0;
				iterador = 0;
				while(contra[iterador] != '\0') {
					caracterestotales++;
					iterador++;
				}
				iterador = 0;
				while(contra2[iterador] != '\0') {
					if(contra2[iterador] == contra[iterador]) 
						caracteresvalidos++;
					iterador++;
				}
				if((caracteresvalidos == caracterestotales) 
					&& (string(contra2).length() == caracterestotales)) { 
					cout << endl;
					cout << "Contrase" << (char) 164 << "a ";
					//Definición color de texto (verde claro)
					ConfigurarColor(10);
					cout << "v" << (char) 160 << "lida";
					//Definición color de texto (blanco brillante)
					ConfigurarColor(15);
					cout << ".";
					strcpy(actual.clave, contra);
					detener = true;
				}
				else { 
						cout << endl;
						cout << "Contrase" << (char) 164 << "a ";
						ConfigurarColor(12);
						cout << "inv" << (char) 160 << "lida"; 
						ConfigurarColor(15);
						cout << "." << endl << endl;
						//Opciones para el jugador
						cout << "Ingrese la letra X para volver a la pantalla" 
							<< " anterior o cualquier" << endl 
							<< "otro caracter para reintentar: ";
						cin >> opcion;
					}
				}
			}
		else {
			cout << endl;
			cout << "Contrase" << (char) 164 << "a ";
			//Definición color de texto (rojo claro)
			ConfigurarColor(12);
			cout << "inv" << (char) 160 << "lida"; 
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << "." << endl << endl;
			//Opciones para el jugador
			cout << "Ingrese la letra X para volver al men" << (char) 163 
				<< " o cualquier otro caracter "
				<< endl << "para reintentar: ";
			char opcion[99];
			cin >> opcion;
			if(opcion[0] == 'x' || opcion[0] == 'X') { 
				strcpy(actual.nombre_usuario, "\0");
				strcpy(actual.clave, "\0");
				return actual;
			}
		}
	}
	//Cálculo de fecha
	time_t t = time(0);
	struct tm * now = localtime( & t );
	actual.ultimo_acceso = {now -> tm_mday, now -> tm_mon + 1, 
		now -> tm_year + 1900};
	//Escritura de archivo (Usuarios.txt)
	ofstream f;
	f.open("Usuarios.txt", fstream::app);
	f << actual.nombre_usuario << endl;
	f << actual.clave << endl;
	f << actual.ultimo_acceso.dia << endl;
	f << actual.ultimo_acceso.mes << endl;
	f << actual.ultimo_acceso.anyo << endl;
	f.close();
	Sleep(2500);
	LimpiarPantalla();
	cout << (char) 173 << "Felicitaciones! La cuenta ha sido creada " 
		<< "exitosamente." << endl << endl;
	cout << "Nombre de usuario: " << actual.nombre_usuario << endl;
	cout << "Contrase" << (char) 164 << "a: " << actual.clave << endl << endl;
	cout << "Presione cualquier tecla para volver al men" << (char) 163 
		<< " principal.";
	char tecla;
	tecla = getch();
	return actual;
}
int IniciarSesion(Usuario actual) {
	bool detener = false;
	char opcion[99], nombre_usuario[11], dia[2], mes[2], anio[5], clave[37];
	int id = -2;
	while(detener != true) {
		LimpiarPantalla();
		//Información para el jugador
		cout << "A continuaci" << (char) 162 << "n, debe ingresar su nombre de "
			"usuario y contrase" << (char) 164 << "a" << endl << "para poder "
			<< "jugar y/o ver las estad" << (char) 161 << "sticas." << endl 
			<< endl;
		int iterador, caracteresrepetidos, caracterestotales;
		cout << "Nombre de usuario: ";
		char nomusuario[99];
		cin >> nomusuario;
		int caracteresingresados = string(nomusuario).length();
		bool existeusuario = false;
		//Lectura de archivo (Usuarios.txt)
		ifstream f;
		f.open("Usuarios.txt");
		if(f.fail()) {
			f.close();
			ofstream f;
			f.open("Usuarios.txt");
			f.close();
			id = -2;
		}
		else while(!f.eof() && existeusuario != true) {
			caracteresrepetidos = 0;
			f >> nombre_usuario;
			caracterestotales = string(nombre_usuario).length();
			if(caracteresingresados == caracterestotales) { 
				iterador = 0;
				while(iterador < caracterestotales) {
					if(nomusuario[iterador] == nombre_usuario[iterador])
						caracteresrepetidos++;
					iterador++;
				}
				if(caracteresrepetidos == caracterestotales) 
					  existeusuario = true;
			}
			f >> clave;
			f >> dia;
			f >> mes;
			f >> anio;
			id++;
		}
		f.close();
		if(existeusuario == true) { 
			cout << endl;
			cout << "Nombre de usuario ";
			//Definición color de texto (verde claro)
			ConfigurarColor(10);
			cout << "v" << (char) 160 << "lido";
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << ".";
			Sleep(2500);
			detener = true;
		}
		else { 
				cout << endl;
				cout << "Nombre de usuario ";
				//Definición color de texto (rojo claro)
				ConfigurarColor(12);
				cout << "inv" << (char) 160 << "lido";
				//Definición color de texto (blanco brillante)
				ConfigurarColor(15);
				cout << "." << endl << endl;
				//Opciones para el jugador
				cout << "Ingrese la letra X para volver al men" << (char) 163 
					<< " o cualquier otro caracter " << endl 
					<< "para reintentar: ";
				cin >> opcion;
				if(opcion[0] == 'x' || opcion[0] == 'X') {
					id = -2;
					detener = true;
				}
			}
	}
	if(opcion[0] == 'x' || opcion[0] == 'X') {
		detener = true;
		id = -2;
	}
	else detener = false;
	while(detener != true) {
		LimpiarPantalla();
		//Información para el jugador
		cout << "A continuaci" << (char) 162 << "n, debe ingresar su nombre de "
			"usuario y contrase" << (char) 164 << "a" << endl << "para poder "
			<< "jugar y/o ver las estad" << (char) 161 << "sticas." << endl 
			<< endl;
		int iterador = 0, caracteresvalidos = 0, caracterestotales = 
			string(clave).length();
		cout << "Contrase" << (char) 164 << "a: ";
		char contra[99];
		cin >> contra;
		while(clave[iterador] != '\0') {
			if(contra[iterador] == clave[iterador]) 
				caracteresvalidos++;
			iterador++;
		}
		if((caracteresvalidos == caracterestotales) 
			&& (string(contra).length() == caracterestotales)) { 
			cout << endl;
			cout << "Contrase" << (char) 164 << "a ";
			//Definición color de texto (verde claro)
			ConfigurarColor(10);
			cout << "v" << (char) 160 << "lida";
			//Definición color de texto (blanco brillante)
			ConfigurarColor(15);
			cout << ".";
			Sleep(2500);
			detener = true;
		}
		else { 
				cout << endl;
				cout << "Contrase" << (char) 164 << "a ";
				//Definición color de texto (rojo claro)
				ConfigurarColor(12);
				cout << "inv" << (char) 160 << "lida"; 
				//Definición color de texto (blanco brillante)
				ConfigurarColor(15);
				cout << "." << endl << endl;
				//Opciones para el jugador
				cout << "Ingrese la letra X para volver al men" << (char) 163 
					<< " o cualquier otro caracter " << endl 
					<< "para reintentar: ";
				cin >> opcion;
				if(opcion[0] == 'x' || opcion[0] == 'X') {
					detener = true;
					id = -2;
				}
			}
	}
	return id;
}
char MostrarMenu2() {
	cout << "Men" << (char) 163 << " de Juegos" << endl;
	cout << "========================" << endl << endl;
	cout << "Juegos Num" << (char) 130 << "ricos" << endl;
	//Opciones para el jugador
	cout << "1. MayMen" << endl;
	cout << "2. Adivinum" << endl;
	cout << "3. WarCoin" << endl << endl;
	cout << "Juegos de Letras" << endl;
	cout << "4. Ahorcado" << endl << endl;
	cout << "Juegos con Tablas" << endl;
	cout << "5. Batalla Naval" << endl << endl;
	cout << "9. Salir" << endl << endl;
	cout << "========================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Men" << (char) 163 << " de Juegos" << endl;
		cout << "========================" << endl << endl;
		cout << "Juegos Num" << (char) 130 << "ricos" << endl;
		cout << "1. MayMen" << endl;
		cout << "2. Adivinum" << endl;
		cout << "3. WarCoin" << endl << endl;
		cout << "Juegos de Letras" << endl;
		cout << "4. Ahorcado" << endl << endl;
		cout << "Juegos con Tablas" << endl;
		cout << "5. Batalla Naval" << endl << endl;
		cout << "9. Salir" << endl << endl;
		cout << "========================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
Usuario PantallaDeBienvenida(Usuario actual, int id) {
	char nombre_usuario[11], dia[3], mes[2], anio[4], clave[37];
	int iterador = -2, auxiliar = 0, multiplo = 0, dialong, meslong, aniolong, 
		restar = 8;
	//Lectura de archivo (Usuarios.txt)
	ifstream f;
	f.open("Usuarios.txt");
	while(!f.eof() && iterador < id) {
		f >> nombre_usuario;
		strcpy(actual.nombre_usuario, nombre_usuario);
		f >> clave;
		f >> dia;
		dialong = string(dia).length();
		if(dia[1] != '\0') 
			actual.ultimo_acceso.dia = (((int) dia[0] - 48) * 10) + 
			((int) dia[1] - 48);
		else actual.ultimo_acceso.dia = ((int) dia[0] - 48);
		f >> mes;
		if(mes[1] != '\0') 
			actual.ultimo_acceso.mes = (((int) mes[0] - 48) * 10) + 
			((int) mes[1] - 48);
		else actual.ultimo_acceso.mes = ((int) mes[0] - 48);
		f >> anio;
		actual.ultimo_acceso.anyo = (((int) anio[0] - 48) * 1000) + 
			(((int) anio[1] - 48) * 100) + (((int) anio[2] - 48) * 10)
			+ ((int) anio[3] - 48);
		iterador++;
	}
	f.close();
	bool mismousuario;
	int caracteresrepetidos, caracterestotales, puntos, diplomas = 0, 
		monedas = 0, medallas = 0, trofeos = 0, copas = 0, 
		puntajemaximo = 0, numericos = 0, letras = 0, tablas = 0;
	char id_juego, puntaje[3];
	string juegomayorpuntaje;
	//Lectura de archivo (Partidas.txt)
	f.open("Partidas.txt");
	if(f.fail()) {
		f.close();
		ofstream f;
		f.open("Partidas.txt");
		f.close();
	}
	else while(!f.eof()) {
		caracteresrepetidos = 0;
		caracterestotales = 
			string(actual.nombre_usuario).length();
		iterador = 0;
		mismousuario = false;
		f >> nombre_usuario;
		while(iterador < caracterestotales) {
			if(actual.nombre_usuario[iterador] == 
			   nombre_usuario[iterador]) caracteresrepetidos++;
			iterador++;
		}
		if(caracteresrepetidos == caracterestotales) 
			  mismousuario = true;
		f >> id_juego;
		f >> puntaje;
		if(puntaje[1] != '\0') 
			puntos = ((puntaje[0] - 48) * 10) +
			(puntaje[1] - 48);
		else puntos = puntaje[0] - 48;
		if(mismousuario == true && id_juego == '0' 
		   && puntos >= 2 && puntos < 4) {
			diplomas++;
			if(f.eof()) diplomas--;
		}
		else if(mismousuario == true && id_juego == '0' 
				&& puntos >= 4 && puntos < 6) {
			monedas++;
			if(f.eof()) monedas--;
		}
		else if(mismousuario == true && id_juego == '0' 
				&& puntos >= 6 && puntos < 8) {
			medallas++;
			if(f.eof()) medallas--;
		}
		else if(mismousuario == true && id_juego == '0' 
				&& puntos >= 8 && puntos < 10) {
			trofeos++;
			if(f.eof()) trofeos--;
		}
		else if(mismousuario == true && id_juego == '0' 
				&& puntos == 10) {
			copas++;
			if(f.eof()) copas--;
		}
		else if(mismousuario == true && id_juego == '1' 
				&& puntos >= 2 && puntos < 4) {
			diplomas++;
			if(f.eof()) diplomas--;
		}
		else if(mismousuario == true && id_juego == '1' 
				&& puntos >= 4 && puntos < 6) {
			monedas++;
			if(f.eof()) monedas--;
		}
		else if(mismousuario == true && id_juego == '1' 
				&& puntos >= 6 && puntos < 8) {
			medallas++;
			if(f.eof()) medallas--;
		}
		else if(mismousuario == true && id_juego == '1' 
				&& puntos >= 8 && puntos < 10) {
			trofeos++;
			if(f.eof()) trofeos--;
		}
		else if(mismousuario == true && id_juego == '1' 
				&& puntos == 10) {
			copas++;
			if(f.eof()) copas--;
		}
		else if(mismousuario == true && id_juego == '2' 
		   && puntos == 5) {
			copas++;
			if(f.eof()) copas--;
		}
		else if(mismousuario == true && id_juego == '3' 
		   && puntos >= 30 && puntos < 40) {
			medallas++;
			if(f.eof()) medallas--;
		}
		else if(mismousuario == true && id_juego == '3' 
				&& puntos >= 40 && puntos < 50) {
			trofeos++;
			if(f.eof()) trofeos--;
		}
		else if(mismousuario == true && id_juego == '3' 
				&& puntos == 50) {
			copas++;
			if(f.eof()) copas--;
		}
		else if(mismousuario == true && id_juego == '4' 
				&& puntos >= 20 && puntos < 40) {
			diplomas++;
			if(f.eof()) diplomas--;
		}
		else if(mismousuario == true && id_juego == '4' 
				&& puntos >= 40 && puntos < 60) {
			monedas++;
			if(f.eof()) monedas--;
		}
		else if(mismousuario == true && id_juego == '4' 
				&& puntos >= 60 && puntos < 80) {
			medallas++;
			if(f.eof()) medallas--;
		}
		else if(mismousuario == true && id_juego == '4' 
				&& puntos >= 80 && puntos < 90) {
			trofeos++;
			if(f.eof()) trofeos--;
		}
		else if(mismousuario == true && id_juego == '4' 
				&& puntos >= 90) {
			copas++;
			if(f.eof()) copas--;
		}
		if(mismousuario == true && puntos >= puntajemaximo) {
			puntajemaximo = puntos;
			if(id_juego == '0') juegomayorpuntaje = "MayMen";
			else if(id_juego == '1') juegomayorpuntaje = "Adivinum";
			else if(id_juego == '2') juegomayorpuntaje = "WarCoin";
			else if(id_juego == '3') juegomayorpuntaje = "Ahorcado";
			else if(id_juego == '4') juegomayorpuntaje = "Batalla Naval";
		}
		if(mismousuario == true && (id_juego == '0' || id_juego == '1' 
		   || id_juego == '2')) numericos++;
		else if(mismousuario == true && id_juego == '3') letras++;
		else if(mismousuario == true && id_juego == '4') tablas++;
	}
	f.close();
	cout << "Bienvenido " << actual.nombre_usuario << endl;
	cout << "=====================" << endl << endl;
	if(actual.ultimo_acceso.dia >= 10) cout << (char) 233 
		<< "ltimo acceso a la aplicaci" << (char) 162 << "n: " 
		<< actual.ultimo_acceso.dia << '/';
	else cout << (char) 233 << "ltimo acceso a la aplicaci" << (char) 162 
		<< "n: 0" << actual.ultimo_acceso.dia << '/';
	if(actual.ultimo_acceso.mes >= 10) cout << actual.ultimo_acceso.mes << '/' 
		<< actual.ultimo_acceso.anyo << "." << endl;
	else cout << '0' << actual.ultimo_acceso.mes << '/' 
		<< actual.ultimo_acceso.anyo << "." << endl;
	cout << "Categor" << (char) 161 << "a favorita de juegos: "; 
	if(numericos == 0 && letras == 0 && tablas == 0) cout << "Ninguna." << endl;
	else {
		if(numericos >= letras && numericos >= tablas) cout << "N" 
			<< (char) 163 << "mericos." 
			<< endl;
		else if(letras >= numericos && letras >= tablas) cout << "Letras." 
			<< endl;
		else if(tablas >= numericos && tablas >= letras) cout << "Tablas." 
			<< endl;
	}
	cout << "Juego con mayor puntaje: ";
	if(puntajemaximo == 0) cout << "Ninguno." << endl;
	else cout << juegomayorpuntaje << "." << endl;
	cout << "Premios obtenidos: ";
	if(diplomas == 0 && monedas == 0 && medallas == 0 && trofeos == 0 && 
	   copas == 0) cout << "Ninguno." << endl << endl;
	else {
		cout << "DIPLOMAS (" << diplomas << ") - ";
		cout << "MONEDAS (" << monedas << ") - ";
		cout << "MEDALLAS (" << medallas << ")" << endl;
		cout << "TROFEOS (" << trofeos << ") - ";
		cout << "COPAS (" << copas << ")" << endl << endl;
	}
	cout << "Presione cualquier tecla para acceder al men" << (char) 163 
		<< " de juegos.";
	char tecla;
	tecla = getch();
	return actual;
} 
char MenuMaymen() {
	cout << "Juego MAYMEN - Categor" << (char) 161 << "a Num" << (char) 130 
		<< "ricos" << endl;
	cout << "==================================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Ver instrucciones" << endl;
	cout << "2. Jugar" << endl;
	cout << "3. Ver Puntaje" << endl;
	cout << "4. Ver Premios" << endl << endl;
	cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
	cout << "==================================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Juego MAYMEN - Categor" << (char) 161 << "a Num" << (char) 130 
			<< "ricos" << endl;
		cout << "==================================" << endl << endl;
		cout << "1. Ver instrucciones" << endl;
		cout << "2. Jugar" << endl;
		cout << "3. Ver Puntaje" << endl;
		cout << "4. Ver Premios" << endl << endl;
		cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
		cout << "==================================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
char MenuAdivinum() {
	cout << "Juego ADIVINUM - Categor" << (char) 161 << "a Num" << (char) 130 
		<< "ricos" << endl;
	cout << "====================================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Ver instrucciones" << endl;
	cout << "2. Jugar" << endl;
	cout << "3. Ver Puntaje" << endl;
	cout << "4. Ver Premios" << endl << endl;
	cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
	cout << "====================================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Juego ADIVINUM - Categor" << (char) 161 << "a Num" 
			<< (char) 130 << "ricos" << endl;
		cout << "====================================" << endl << endl;
		cout << "1. Ver instrucciones" << endl;
		cout << "2. Jugar" << endl;
		cout << "3. Ver Puntaje" << endl;
		cout << "4. Ver Premios" << endl << endl;
		cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
		cout << "====================================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
char MenuWarCoin() {
	cout << "Juego WARCOIN - Categor" << (char) 161 << "a Num" << (char) 130 
		<< "ricos" << endl;
	cout << "===================================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Ver instrucciones" << endl;
	cout << "2. Jugar" << endl;
	cout << "3. Ver Puntaje" << endl;
	cout << "4. Ver Premios" << endl << endl;
	cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
	cout << "===================================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Juego WARCOIN - Categor" << (char) 161 << "a Num" << (char) 130 
			<< "ricos" << endl;
		cout << "===================================" << endl << endl;
		cout << "1. Ver instrucciones" << endl;
		cout << "2. Jugar" << endl;
		cout << "3. Ver Puntaje" << endl;
		cout << "4. Ver Premios" << endl << endl;
		cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
		cout << "===================================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
char MenuAhorcado() {
	cout << "Juego AHORCADO - Categor" << (char) 161 << "a Letras" << endl;
	cout << "=================================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Ver instrucciones" << endl;
	cout << "2. Jugar" << endl;
	cout << "3. Ver Puntaje" << endl;
	cout << "4. Ver Premios" << endl << endl;
	cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
	cout << "=================================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Juego AHORCADO - Categor" << (char) 161 << "a Letras" << endl;
		cout << "=================================" << endl << endl;
		cout << "1. Ver instrucciones" << endl;
		cout << "2. Jugar" << endl;
		cout << "3. Ver Puntaje" << endl;
		cout << "4. Ver Premios" << endl << endl;
		cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
		cout << "=================================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
char MenuBatallaNaval() {
	cout << "Juego BATALLA NAVAL - Categor" << (char) 161 << "a Tablas" << endl;
	cout << "======================================" << endl << endl;
	//Opciones para el jugador
	cout << "1. Ver instrucciones" << endl;
	cout << "2. Jugar" << endl;
	cout << "3. Ver Puntaje" << endl;
	cout << "4. Ver Premios" << endl << endl;
	cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
	cout << "======================================" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Juego BATALLA NAVAL - Categor" << (char) 161 << "a Tablas" << endl;
		cout << "======================================" << endl << endl;
		cout << "1. Ver instrucciones" << endl;
		cout << "2. Jugar" << endl;
		cout << "3. Ver Puntaje" << endl;
		cout << "4. Ver Premios" << endl << endl;
		cout << "6. Volver a men" << (char) 163 << " anterior" << endl;
		cout << "======================================" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
char MenuEstadisticasJuegos(int vecesjugadasMM, int vecesjugadasAD, 
							int vecesjugadasWC, int vecesjugadasAH,
							int vecesjugadasBN, int diplomasMM, int monedasMM, 
							int medallasMM, int trofeosMM, int copasMM, 
							int diplomasAD, int monedasAD, int medallasAD, 
							int trofeosAD, int copasAD, int copasWC, 
							int medallasAH, int trofeosAH, int copasAH, 
							int diplomasBN, int monedasBN, int medallasBN, 
							int trofeosBN, int copasBN) {
	string juegomenosjugado, juegomasjugado1, juegomasjugado2, juegomasjugado3, 
		juegomasjugado4;
	int mayorpremioMM = 0, mayorpremioAD = 0, mayorpremioWC = 0, 
		mayorpremioAH = 0, mayorpremioBN = 0, mayordiploma = 0, mayormoneda = 0, 
		mayormedalla = 0, mayortrofeo = 0, mayorcopa = 0, masjugado1 = 0, 
		masjugado2 = 0, masjugado3 = 0, masjugado4 = 0, juegomasjugado5 = 0;
	if(diplomasMM >= mayorpremioMM) mayorpremioMM = diplomasMM;
	if(monedasMM >= mayorpremioMM) mayorpremioMM = monedasMM;
	if(medallasMM >= mayorpremioMM) mayorpremioMM = medallasMM;
	if(trofeosMM >= mayorpremioMM) mayorpremioMM = trofeosMM;
	if(copasMM >= mayorpremioMM) mayorpremioMM = copasMM;
	if(diplomasAD >= mayorpremioAD) mayorpremioAD = diplomasAD;
	if(monedasAD >= mayorpremioAD) mayorpremioAD = monedasAD;
	if(medallasAD >= mayorpremioAD) mayorpremioAD = medallasAD;
	if(trofeosAD >= mayorpremioAD) mayorpremioAD = trofeosAD;
	if(copasAD >= mayorpremioAD) mayorpremioAD = copasAD;
	if(copasWC >= mayorpremioWC) mayorpremioWC = copasWC;
	if(medallasAH >= mayorpremioAH) mayorpremioAH = medallasAH;
	if(trofeosAH >= mayorpremioAH) mayorpremioAH = trofeosAH;
	if(copasAH >= mayorpremioAH) mayorpremioAH = copasAH;
	if(diplomasBN >= mayorpremioBN) mayorpremioBN = diplomasBN;
	if(monedasBN >= mayorpremioBN) mayorpremioBN = monedasBN;
	if(medallasBN >= mayorpremioBN) mayorpremioBN = medallasBN;
	if(trofeosBN >= mayorpremioBN) mayorpremioBN = trofeosBN;
	if(copasBN >= mayorpremioBN) mayorpremioBN = copasBN;
	if(diplomasMM >= mayordiploma) mayordiploma = diplomasMM;
	if(diplomasAD >= mayordiploma) mayordiploma = diplomasAD;
	if(diplomasBN >= mayordiploma) mayordiploma = diplomasBN;
	if(monedasMM >= mayormoneda) mayormoneda = monedasMM;
	if(monedasAD >= mayormoneda) mayormoneda = monedasAD;
	if(monedasBN >= mayormoneda) mayormoneda = monedasBN;
	if(medallasMM >= mayormedalla) mayormedalla = medallasMM;
	if(medallasAD >= mayormedalla) mayormedalla = medallasAD;
	if(medallasAH >= mayormedalla) mayormedalla = medallasAH;
	if(medallasBN >= mayormedalla) mayormedalla = medallasBN;
	if(trofeosMM >= mayortrofeo) mayortrofeo = trofeosMM;
	if(trofeosAD >= mayortrofeo) mayortrofeo = trofeosAD;
	if(trofeosAH >= mayortrofeo) mayortrofeo = trofeosAH;
	if(trofeosBN >= mayortrofeo) mayortrofeo = trofeosBN;
	if(copasMM >= mayorcopa) mayorcopa = copasMM;
	if(copasAD >= mayorcopa) mayorcopa = copasAD;
	if(copasWC >= mayorcopa) mayorcopa = copasWC;
	if(copasAH >= mayorcopa) mayorcopa = copasAH;
	if(copasBN >= mayorcopa) mayorcopa = copasBN;
	if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC == 0 
	   && vecesjugadasAH == 0 && vecesjugadasBN == 0) {
			juegomasjugado1 = "Ninguno ha sido jugado";
			juegomasjugado2 = "-";
			juegomasjugado3 = "-";
			juegomasjugado4 = "-";
			juegomenosjugado = "-";
		}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		juegomasjugado1 = "MayMen";
		juegomasjugado2 = "-";
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		juegomasjugado1 = "Adivinum";
		juegomasjugado2 = "-";
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		juegomasjugado1 = "WarCoin";
		juegomasjugado2 = "-";
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		juegomasjugado1 = "Ahorcado";
		juegomasjugado2 = "-";
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		juegomasjugado1 = "Batalla Naval";
		juegomasjugado2 = "-";
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasMM >= vecesjugadasAD) { 
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Adivinum";
		}
		else {
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "MayMen";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasMM >= vecesjugadasWC) { 
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "WarCoin";
		}
		else {
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "MayMen";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasMM >= vecesjugadasAH) { 
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Ahorcado";
		}
		else {
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "MayMen";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasBN) { 
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Batalla Naval";
		}
		else {
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "MayMen";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasAD >= vecesjugadasMM) { 
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "MayMen";
		}
		else {
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Adivinum";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasAD >= vecesjugadasWC) { 
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "WarCoin";
		}
		else {
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Adivinum";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasAD >= vecesjugadasAH) { 
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "Ahorcado";
		}
		else {
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "Adivinum";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasAD >= vecesjugadasBN) { 
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "Batalla Naval";
		}
		else {
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "Adivinum";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasWC >= vecesjugadasMM) { 
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "MayMen";
		}
		else {
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "WarCoin";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
		if(vecesjugadasWC >= vecesjugadasAD) { 
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Adivinum";
		}
		else {
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "WarCoin";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasWC >= vecesjugadasAH) { 
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Ahorcado";
		}
		else {
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "WarCoin";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasWC >= vecesjugadasBN) { 
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Batalla Naval";
		}
		else {
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Batalla Naval";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasAH >= vecesjugadasMM) { 
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "MayMen";
		}
		else {
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Ahorcado";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasAH >= vecesjugadasAD) { 
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "Adivinum";
		}
		else {
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "Ahorcado";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasAH >= vecesjugadasWC) { 
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "WarCoin";
		}
		else {
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Ahorcado";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasAH >= vecesjugadasBN) { 
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "Batalla Naval";
		}
		else {
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "Ahorcado";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasBN >= vecesjugadasMM) { 
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "MayMen";
		}
		else {
			juegomasjugado1 = "MayMen";
			juegomasjugado2 = "Batalla Naval";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasBN >= vecesjugadasAD) { 
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "Adivinum";
		}
		else {
			juegomasjugado1 = "Adivinum";
			juegomasjugado2 = "Batalla Naval";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasBN >= vecesjugadasWC) { 
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "WarCoin";
		}
		else {
			juegomasjugado1 = "WarCoin";
			juegomasjugado2 = "Batalla Naval";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC == 0
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasBN >= vecesjugadasAH) { 
			juegomasjugado1 = "Batalla Naval";
			juegomasjugado2 = "Ahorcado";
		}
		else {
			juegomasjugado1 = "Ahorcado";
			juegomasjugado2 = "Batalla Naval";
		}
		juegomasjugado3 = "-";
		juegomasjugado4 = "-";
		juegomenosjugado = "-";
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1
			&& vecesjugadasAH == 0 && vecesjugadasBN == 0) {
			if(vecesjugadasMM >= vecesjugadasAD 
				&& vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado1 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasWC) {
						juegomasjugado2 = "Adivinum";
						juegomasjugado3 = "WarCoin";
				}
				else {
					juegomasjugado2 = "WarCoin";
					juegomasjugado3 = "Adivinum";
				}
			}
		else if(vecesjugadasAD >= vecesjugadasMM 
				&& vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado1 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "WarCoin";
				}
				else {
					juegomasjugado2 = "WarCoin";
					juegomasjugado3 = "MayMen";
				}
			}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado1 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "Adivinum";
				}
				else {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "MayMen";
				}
			}
		}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC == 0 
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
			if(vecesjugadasMM >= vecesjugadasAD 
			   && vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado1 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "Ahorcado";
				}
				else {
					juegomasjugado2 = "Ahorcado";
					juegomasjugado3 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM 
					&& vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado1 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "Ahorcado";
				}
				else {
					juegomasjugado2 = "Ahorcado";
					juegomasjugado3 = "MayMen";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM 
					&& vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado1 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "Adivinum";
				}
				else {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "MayMen";
				}
			}
		}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC == 0 
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
			if(vecesjugadasMM >= vecesjugadasAD 
				&& vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado1 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "Batalla Naval";
				}
				else {
					juegomasjugado2 = "Batalla Naval";
					juegomasjugado3 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM 
					&& vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado1 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "Batalla Naval";
				}
				else {
					juegomasjugado2 = "Batalla Naval";
					juegomasjugado3 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM 
					&& vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado1 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado2 = "MayMen";
					juegomasjugado3 = "Adivinum";
				}	
				else {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "MayMen";
				}
			}
		}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
			if(vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado1 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado2 = "Adivinum";
					juegomasjugado3 = "WarCoin";
				}
				else {
					juegomasjugado2 = "WarCoin";
					juegomasjugado3 = "Adivinum";
				}
			}
		else if(vecesjugadasAD >= vecesjugadasAH 
				&& vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado1 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasWC) {
					juegomasjugado2 = "Ahorcado";
					juegomasjugado3 = "WarCoin";
				}
				else {
					juegomasjugado2 = "WarCoin";
					juegomasjugado3 = "Ahorcado";
				}
			}
		else if(vecesjugadasWC >= vecesjugadasAH 
				&& vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado1 = "WarCoin";
			if(vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "Adivinum";
			}
			else {
				juegomasjugado2 = "Adivinum";
				juegomasjugado3 = "Ahorcado";
			}
		}
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasWC >= vecesjugadasAD 
			&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "Adivinum";
			}
		}
		else if(vecesjugadasAD >= vecesjugadasWC 
			&& vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "WarCoin";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasWC 
			&& vecesjugadasBN >= vecesjugadasAD) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Adivinum";
			}
			else {
				juegomasjugado2 = "Adivinum";
				juegomasjugado3 = "WarCoin";
			}
		}
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD == 0 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasWC >= vecesjugadasAH 
		   && vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "Ahorcado";
			}
		}
		else if(vecesjugadasAH >= vecesjugadasWC 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "WarCoin";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Ahorcado";
			}
			else {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "WarCoin";
			}
		}
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC == 0 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasAD >= vecesjugadasAH 
		   && vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "Ahorcado";
			}
		}
		else if(vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "Adivinum";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado2 = "Adivinum";
				juegomasjugado3 = "Ahorcado";
			}
			else {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "Adivinum";
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC == 0 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasAH 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "Ahorcado";
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "MayMen";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "Ahorcado";
			}
			else {
				juegomasjugado2 = "Ahorcado";
				juegomasjugado3 = "MayMen";
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC >= 1 
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasWC 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "WarCoin";
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "MayMen";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasMM) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "MayMen";
			}
			else {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "WarCoin";
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC >= 1 
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasWC 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "WarCoin";
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "Batalla Naval";
			}
			else {
				juegomasjugado2 = "Batalla Naval";
				juegomasjugado3 = "MayMen";
			}
		}
		else if(vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasMM) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado2 = "WarCoin";
				juegomasjugado3 = "MayMen";
			}
			else {
				juegomasjugado2 = "MayMen";
				juegomasjugado3 = "WarCoin";
			}
		}
	}
	else if(vecesjugadasMM == 0 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasAD >= vecesjugadasWC 
		   && vecesjugadasAD >= vecesjugadasAH 
		   && vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasWC >= vecesjugadasAH && 
			   vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasWC && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasWC && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasAD 
				   && vecesjugadasWC >= vecesjugadasAH 
				   && vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasAD >= vecesjugadasAH && 
			   vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasAD && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasAD && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasWC 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasAD >= vecesjugadasWC && 
			   vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAD && 
					vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasAD && 
					vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasAD >= vecesjugadasWC && 
			   vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAD && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasAD && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD == 0 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasWC 
		   && vecesjugadasMM >= vecesjugadasAH 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasWC >= vecesjugadasAH && 
			   vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasWC && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasWC && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAH 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasMM >= vecesjugadasAH && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasWC 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasMM >= vecesjugadasWC && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasMM >= vecesjugadasWC && 
			   vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC == 0 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasAD 
		   && vecesjugadasMM >= vecesjugadasAH 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasAD >= vecesjugadasAH && 
			   vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasAD && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasAD && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM 
				&& vecesjugadasAD >= vecesjugadasAH 
				&& vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasMM >= vecesjugadasAH && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasBN) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH == 0 && vecesjugadasBN >= 1) {
		if(vecesjugadasMM >= vecesjugadasAD 
		   && vecesjugadasMM >= vecesjugadasWC 
		   && vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasAD >= vecesjugadasWC && 
			   vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAD && 
					vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasAD && 
					vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM 
				&& vecesjugadasAD >= vecesjugadasWC 
				&& vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasMM >= vecesjugadasWC && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasBN) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasBN) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAD 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasBN) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasBN) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasBN) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Batalla Naval";
				}
				else {
					juegomasjugado3 = "Batalla Naval";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasMM && 
					vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado2 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasWC) {
			juegomasjugado1 = "Batalla Naval";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN == 0) {
		if(vecesjugadasMM >= vecesjugadasAD 
		   && vecesjugadasMM >= vecesjugadasWC 
		   && vecesjugadasMM >= vecesjugadasAH) {
			juegomasjugado1 = "MayMen";
			if(vecesjugadasAD >= vecesjugadasWC && 
			   vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAD && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasAD && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM 
				&& vecesjugadasAD >= vecesjugadasWC 
				&& vecesjugadasAD >= vecesjugadasAH) {
			juegomasjugado1 = "Adivinum";
			if(vecesjugadasMM >= vecesjugadasWC && 
			   vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAD 
				&& vecesjugadasWC >= vecesjugadasAH) {
			juegomasjugado1 = "WarCoin";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Ahorcado";
				}
				else {
					juegomasjugado3 = "Ahorcado";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasMM && 
					vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado2 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasWC) {
			juegomasjugado1 = "Ahorcado";
			if(vecesjugadasMM >= vecesjugadasAD && 
			   vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado2 = "MayMen";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasMM && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado2 = "Adivinum";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "WarCoin";
				}
				else {
					juegomasjugado3 = "WarCoin";
					juegomasjugado4 = "MayMen";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasMM && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado2 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado3 = "MayMen";
					juegomasjugado4 = "Adivinum";
				}
				else {
					juegomasjugado3 = "Adivinum";
					juegomasjugado4 = "MayMen";
				}
			}
		}
	}
	else if(vecesjugadasMM >= 1 && vecesjugadasAD >= 1 && vecesjugadasWC >= 1 
			&& vecesjugadasAH >= 1 && vecesjugadasBN >= 1) {
	if(vecesjugadasMM >= vecesjugadasAD && vecesjugadasMM >= vecesjugadasWC &&
		vecesjugadasMM >= vecesjugadasAH && vecesjugadasMM >= vecesjugadasBN) {
		juegomasjugado1 = "MayMen";
		if(vecesjugadasAD >= vecesjugadasWC 
		   && vecesjugadasAD >= vecesjugadasAH 
		   && vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado2 = "Adivinum";
			if(vecesjugadasBN >= vecesjugadasWC && 
			   vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasBN 
				&& vecesjugadasWC >= vecesjugadasAD 
				&& vecesjugadasWC >= vecesjugadasAH) {
			juegomasjugado2 = "WarCoin";
			if(vecesjugadasAH >= vecesjugadasBN && 
			   vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasAD) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasBN >= vecesjugadasAH && 
					vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasAH >= vecesjugadasAD) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasAH && 
					vecesjugadasAD >= vecesjugadasBN) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasBN) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
				else {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasWC 
		   && vecesjugadasAH >= vecesjugadasAD 
		   && vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado2 = "Ahorcado";
			if(vecesjugadasBN >= vecesjugadasWC && 
			   vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasWC >= vecesjugadasAD) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasAD) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasBN && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasWC 
				&& vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado2 = "Batalla Naval";
			if(vecesjugadasAH >= vecesjugadasWC && 
			   vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasWC >= vecesjugadasAD) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAH && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasAD) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasAH && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasWC) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
	}
	else if(vecesjugadasAD >= vecesjugadasMM && vecesjugadasAD >= vecesjugadasWC &&
			vecesjugadasAD >= vecesjugadasAH && vecesjugadasAD >= vecesjugadasBN) {
		juegomasjugado1 = "Adivinum";
		if(vecesjugadasMM >= vecesjugadasWC 
			&& vecesjugadasMM >= vecesjugadasAH 
			&& vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado2 = "MayMen";
			if(vecesjugadasBN >= vecesjugadasWC && 
				vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasWC >= vecesjugadasAH) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasAH) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAH 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado2 = "WarCoin";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasMM) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasWC
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado2 = "Ahorcado";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasWC
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado2 = "Batalla Naval";
			if(vecesjugadasAH >= vecesjugadasMM && 
			   vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasAH && 
					vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasWC) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAH && 
					vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasMM) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
	}
	else if(vecesjugadasWC >= vecesjugadasMM && vecesjugadasWC >= vecesjugadasAD &&
			vecesjugadasWC >= vecesjugadasAH && vecesjugadasWC >= vecesjugadasBN) {
		juegomasjugado1 = "WarCoin";
		if(vecesjugadasMM >= vecesjugadasAD 
			&& vecesjugadasMM >= vecesjugadasAH 
			&& vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado2 = "MayMen";
			if(vecesjugadasBN >= vecesjugadasAD && 
				vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasAH) {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasBN && 
					vecesjugadasAD >= vecesjugadasAH) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasAD) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM 
		   && vecesjugadasAD >= vecesjugadasAH 
		   && vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado2 = "Adivinum";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Ahorcado";
				}
				else {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasMM) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM 
				&& vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasBN) {
			juegomasjugado2 = "Ahorcado";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasAH) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasAH) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasBN && 
					vecesjugadasAH >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasAH) {
			juegomasjugado2 = "Batalla Naval";
			if(vecesjugadasAH >= vecesjugadasMM && 
			   vecesjugadasAH >= vecesjugadasAH) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasAH) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasAH && 
					vecesjugadasMM >= vecesjugadasAH) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasAH) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasAH >= vecesjugadasAH && 
					vecesjugadasAH >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasMM) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
	}
	else if(vecesjugadasAH >= vecesjugadasMM && vecesjugadasAH >= vecesjugadasAD &&
			vecesjugadasAH >= vecesjugadasWC && vecesjugadasAH >= vecesjugadasBN) {
		juegomasjugado1 = "Ahorcado";
		if(vecesjugadasMM >= vecesjugadasAD 
			&& vecesjugadasMM >= vecesjugadasWC 
			&& vecesjugadasMM >= vecesjugadasBN) {
			juegomasjugado2 = "MayMen";
			if(vecesjugadasBN >= vecesjugadasAD && 
				vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasBN && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasAD) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM 
				&& vecesjugadasAD >= vecesjugadasWC 
				&& vecesjugadasAD >= vecesjugadasBN) {
			juegomasjugado2 = "Adivinum";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasWC) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasWC) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasBN && 
					vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM 
				&& vecesjugadasWC >= vecesjugadasAD 
				&& vecesjugadasWC >= vecesjugadasBN) {
			juegomasjugado2 = "WarCoin";
			if(vecesjugadasBN >= vecesjugadasMM && 
			   vecesjugadasBN >= vecesjugadasAD) {
				juegomasjugado3 = "Batalla Naval";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasBN && 
					vecesjugadasMM >= vecesjugadasAD) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasBN >= vecesjugadasAD) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Batalla Naval";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasBN && 
					vecesjugadasAD >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasBN >= vecesjugadasMM) {
					juegomasjugado4 = "Batalla Naval";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Batalla Naval";
				}
			}
		}
		else if(vecesjugadasBN >= vecesjugadasMM 
				&& vecesjugadasBN >= vecesjugadasAD 
				&& vecesjugadasBN >= vecesjugadasWC) {
			juegomasjugado2 = "Batalla Naval";
			if(vecesjugadasWC >= vecesjugadasMM && 
			   vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasWC && 
					vecesjugadasMM >= vecesjugadasAD) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasAD) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasWC && 
					vecesjugadasAD >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasMM) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
			}
		}
	}
	else if(vecesjugadasBN >= vecesjugadasMM && vecesjugadasBN >= vecesjugadasAD &&
			vecesjugadasBN >= vecesjugadasWC && vecesjugadasBN >= vecesjugadasAH) {
		juegomasjugado1 = "Batalla Naval";
		if(vecesjugadasMM >= vecesjugadasAD 
			&& vecesjugadasMM >= vecesjugadasWC 
			&& vecesjugadasMM >= vecesjugadasAH) {
			juegomasjugado2 = "MayMen";
			if(vecesjugadasAH >= vecesjugadasAD && 
				vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasAD >= vecesjugadasWC) {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasAH && 
					vecesjugadasAD >= vecesjugadasWC) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasWC) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAH && 
					vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasAD) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
		else if(vecesjugadasAD >= vecesjugadasMM
				&& vecesjugadasAD >= vecesjugadasWC 
				&& vecesjugadasAD >= vecesjugadasAH) {
			juegomasjugado2 = "Adivinum";
			if(vecesjugadasAH >= vecesjugadasMM && 
			   vecesjugadasAH >= vecesjugadasWC) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasWC) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasAH && 
					vecesjugadasMM >= vecesjugadasWC) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasWC) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "WarCoin";
				}
				else {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasWC >= vecesjugadasAH && 
					vecesjugadasWC >= vecesjugadasMM) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasAH >= vecesjugadasMM) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
		else if(vecesjugadasWC >= vecesjugadasMM
				&& vecesjugadasWC >= vecesjugadasAD 
				&& vecesjugadasWC >= vecesjugadasAH) {
			juegomasjugado2 = "WarCoin";
			if(vecesjugadasAH >= vecesjugadasMM && 
			   vecesjugadasAH >= vecesjugadasAD) {
				juegomasjugado3 = "Ahorcado";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasAH && 
					vecesjugadasMM >= vecesjugadasAD) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasAH >= vecesjugadasAD) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "Ahorcado";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasAH && 
					vecesjugadasAD >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasAH >= vecesjugadasMM) {
					juegomasjugado4 = "Ahorcado";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Ahorcado";
				}
			}
		}
		else if(vecesjugadasAH >= vecesjugadasMM
				&& vecesjugadasAH >= vecesjugadasAD 
				&& vecesjugadasAH >= vecesjugadasWC) {
			juegomasjugado2 = "Ahorcado";
			if(vecesjugadasWC >= vecesjugadasMM && 
			   vecesjugadasWC >= vecesjugadasAD) {
				juegomasjugado3 = "WarCoin";
				if(vecesjugadasMM >= vecesjugadasAD) {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "MayMen";
				}
			}
			else if(vecesjugadasMM >= vecesjugadasWC && 
					vecesjugadasMM >= vecesjugadasAD) {
				juegomasjugado3 = "MayMen";
				if(vecesjugadasWC >= vecesjugadasAD) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "Adivinum";
				}
				else {
					juegomasjugado4 = "Adivinum";
					juegomenosjugado = "WarCoin";
				}
			}
			else if(vecesjugadasAD >= vecesjugadasWC && 
					vecesjugadasAD >= vecesjugadasMM) {
				juegomasjugado3 = "Adivinum";
				if(vecesjugadasWC >= vecesjugadasMM) {
					juegomasjugado4 = "WarCoin";
					juegomenosjugado = "MayMen";
				}
				else {
					juegomasjugado4 = "MayMen";
					juegomenosjugado = "WarCoin";
				}
			}
		}
	}
	}
	cout << "Estad" << (char) 161 << "sticas de Juegos" << endl;
	cout << "==================================================================" 
		<< "==" << endl << endl;
	//Información para el jugador (juegos más jugados)
	cout << "Primer juego m" << (char) 160 << "s jugado: " << juegomasjugado1 
		<< "." << endl; 
	cout << "Segundo juego m" << (char) 160 << "s jugado: " << juegomasjugado2 
		<< "." << endl;
	cout << "Tercer juego m" << (char) 160 << "s jugado: " << juegomasjugado3 
		<< "." << endl;
	cout << "Cuarto juego m" << (char) 160 << "s jugado: " << juegomasjugado4 
		<< "." << endl;
	cout << "Juego menos jugado: " << juegomenosjugado << "." << endl << endl;
	//Información para el jugador (ranking de premios por juego)
	cout << setw(35) << "Ranking de premios por juego" << endl << endl;
	cout << setw(24) << "Maymen" << setw(10) << "Adivinum" << setw(9) 
		<< "Warcoin" << setw(10) << "Ahorcado" << setw(15) << "Batalla Naval" 
		<< endl;
	cout << setw(8) << "0" << setw(8) << "Diploma" << setw(6);
	if(mayorpremioMM == diplomasMM) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << diplomasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasMM; 
	cout << setw(9); 
	if(mayorpremioAD == diplomasAD) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << diplomasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasAD; 
	cout << setw(9) << "0" << setw(10) << "0" << setw(12);
	if(mayorpremioBN == diplomasBN) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << diplomasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasBN; 
	cout << endl;
	cout << setw(8) << "1" << setw(8) << "Moneda" << setw(6);
	if(mayorpremioMM == monedasMM && monedasMM != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << monedasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasMM;
	cout << setw(9); 
	if(mayorpremioAD == monedasAD && monedasAD != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << monedasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasAD; 
	cout << setw(9) << "0" << setw(10) << "0" << setw(12);
	if(mayorpremioBN == monedasBN && monedasBN != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << monedasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasBN;
	cout << endl;
	cout << setw(8) << "2" << setw(8) << "Medalla" << setw(6); 
	if(mayorpremioMM == medallasMM && medallasMM != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << medallasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasMM;
	cout << setw(9);
	if(mayorpremioAD == medallasAD && medallasAD != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << medallasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasAD;
	cout << setw(9) << "0" << setw(10);
	if(mayorpremioAH == medallasAH) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << medallasAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasAH;
	cout << setw(12);
	if(mayorpremioBN == medallasBN && medallasBN != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << medallasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasBN;
	cout << endl;
	cout << setw(8) << "3" << setw(8) << "Trofeo" << setw(6);
	if(mayorpremioMM == trofeosMM && trofeosMM != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << trofeosMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosMM;
	cout << setw(9);
	if(mayorpremioAD == trofeosAD && trofeosAD != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << trofeosAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosAD;
	cout << setw(9) << "0" << setw(10);
	if(mayorpremioAH == trofeosAH && trofeosAH != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << trofeosAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosAH;
	cout << setw(12);
	if(mayorpremioBN == trofeosBN && trofeosBN != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << trofeosBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosBN;
	cout << endl;
	cout << setw(8) << "4" << setw(8) << "Copa" << setw(6);
	if(mayorpremioMM == copasMM && copasMM != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << copasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasMM;
	cout << setw(9);
	if(mayorpremioAD == copasAD && copasAD != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << copasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasAD;
	cout << setw(9);
	if(mayorpremioWC == copasWC) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << copasWC;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasWC;
	cout << setw(10);
	if(mayorpremioAH == copasAH && copasAH != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << copasAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasAH;
	cout << setw(12);
	if(mayorpremioBN == copasBN && copasBN != 0) {
		//Definición de color de texto (rojo claro)
		ConfigurarColor(12);
		cout << copasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasBN;
	cout << endl << endl;
	//Información para el jugador (ranking de juegos por premios)
	cout << setw(36) << "Ranking de juegos por premios" << endl << endl;
	cout << setw(24) << "Maymen" << setw(10) << "Adivinum" << setw(9) 
		<< "Warcoin" << setw(10) << "Ahorcado" << setw(15) << "Batalla Naval" 
		<< endl;
	cout << setw(8) << "0" << setw(8) << "Diploma" << setw(6);
	if(mayordiploma == diplomasMM || mayordiploma == 0) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << diplomasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasMM; 
	cout << setw(9); 
	if(mayordiploma == diplomasAD && mayordiploma >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << diplomasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasAD; 
	cout << setw(9) << "0" << setw(10) << "0" << setw(12);
	if(mayordiploma == diplomasBN && mayordiploma >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << diplomasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << diplomasBN; 
	cout << endl;
	cout << setw(8) << "1" << setw(8) << "Moneda" << setw(6);
	if(mayormoneda == monedasMM || mayormoneda == 0) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << monedasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasMM;
	cout << setw(9); 
	if(mayormoneda == monedasAD && mayormoneda >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << monedasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasAD; 
	cout << setw(9) << "0" << setw(10) << "0" << setw(12);
	if(mayormoneda == monedasBN && mayormoneda >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << monedasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << monedasBN;
	cout << endl;
	cout << setw(8) << "2" << setw(8) << "Medalla" << setw(6); 
	if(mayormedalla == medallasMM && mayormedalla == 0) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << medallasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasMM;
	cout << setw(9);
	if(mayormedalla == medallasAD && mayormedalla >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << medallasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasAD;
	cout << setw(9) << "0" << setw(10);
	if(mayormedalla == medallasAH && mayormedalla >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << medallasAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasAH;
	cout << setw(12);
	if(mayormedalla == medallasBN && mayormedalla >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << medallasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << medallasBN;
	cout << endl;
	cout << setw(8) << "3" << setw(8) << "Trofeo" << setw(6);
	if(mayortrofeo == trofeosMM || mayortrofeo == 0) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << trofeosMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosMM;
	cout << setw(9);
	if(mayortrofeo == trofeosAD && mayortrofeo >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << trofeosAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosAD;
	cout << setw(9) << "0" << setw(10);
	if(mayortrofeo == trofeosAH && mayortrofeo >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << trofeosAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosAH;
	cout << setw(12);
	if(mayortrofeo == trofeosBN && mayortrofeo >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << trofeosBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << trofeosBN;
	cout << endl;
	cout << setw(8) << "4" << setw(8) << "Copa" << setw(6);
	if(mayorcopa == copasMM || mayorcopa == 0) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << copasMM;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasMM;
	cout << setw(9);
	if(mayorcopa == copasAD && mayorcopa >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << copasAD;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasAD;
	cout << setw(9);
	if(mayorcopa == copasWC && mayorcopa >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << copasWC;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasWC;
	cout << setw(10);
	if(mayorcopa == copasAH && mayorcopa >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << copasAH;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasAH;
	cout << setw(12);
	if(mayorcopa == copasBN && mayorcopa >= 1) {
		//Definición de color de texto (azul claro)
		ConfigurarColor(9);
		cout << copasBN;
		//Definición de color de texto (blanco brillante)
		ConfigurarColor(15);
	}
	else cout << copasBN;
	cout << endl << endl;
	//Opción para el jugador
	cout << "9. Volver a men" << (char) 163 << " anterior" << endl << endl;
	cout << "==================================================================" 
		<< "==" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Estad" << (char) 161 << "sticas de Juegos" << endl;
		cout << "==================================================================" 
			<< "==" << endl << endl;
		cout << "Primer juego m" << (char) 160 << "s jugado: " << juegomasjugado1 
			<< "." << endl; 
		cout << "Segundo juego m" << (char) 160 << "s jugado: " << juegomasjugado2 
			<< "." << endl;
		cout << "Tercer juego m" << (char) 160 << "s jugado: " << juegomasjugado3 
			<< "." << endl;
		cout << "Cuarto juego m" << (char) 160 << "s jugado: " << juegomasjugado4 
			<< "." << endl;
		cout << "Juego menos jugado: " << juegomenosjugado << "." << endl << endl;
		cout << setw(35) << "Ranking de premios por juego" << endl << endl;
		cout << setw(24) << "Maymen" << setw(10) << "Adivinum" << setw(9) 
			<< "Warcoin" << setw(10) << "Ahorcado" << setw(15) << "Batalla Naval" 
			<< endl;
		cout << setw(8) << "0" << setw(8) << "Diploma" << setw(6);
		if(mayorpremioMM == diplomasMM) {
			ConfigurarColor(12);
			cout << diplomasMM;
			ConfigurarColor(15);
		}
		else cout << diplomasMM; 
		cout << setw(9); 
		if(mayorpremioAD == diplomasAD) {
			ConfigurarColor(12);
			cout << diplomasAD;
			ConfigurarColor(15);
		}
		else cout << diplomasAD; 
		cout << setw(9) << "0" << setw(10) << "0" << setw(12);
		if(mayorpremioBN == diplomasBN) {
			ConfigurarColor(12);
			cout << diplomasBN;
			ConfigurarColor(15);
		}
		else cout << diplomasBN; 
		cout << endl;
		cout << setw(8) << "1" << setw(8) << "Moneda" << setw(6);
		if(mayorpremioMM == monedasMM && monedasMM != 0) {
			ConfigurarColor(12);
			cout << monedasMM;
			ConfigurarColor(15);
		}
		else cout << monedasMM;
		cout << setw(9); 
		if(mayorpremioAD == monedasAD && monedasAD != 0) {
			ConfigurarColor(12);
			cout << monedasAD;
			ConfigurarColor(15);
		}
		else cout << monedasAD; 
		cout << setw(9) << "0" << setw(10) << "0" << setw(12);
		if(mayorpremioBN == monedasBN && monedasBN != 0) {
			ConfigurarColor(12);
			cout << monedasBN;
			ConfigurarColor(15);
		}
		else cout << monedasBN;
		cout << endl;
		cout << setw(8) << "2" << setw(8) << "Medalla" << setw(6); 
		if(mayorpremioMM == medallasMM && medallasMM != 0) {
			ConfigurarColor(12);
			cout << medallasMM;
			ConfigurarColor(15);
		}
		else cout << medallasMM;
		cout << setw(9);
		if(mayorpremioAD == medallasAD && medallasAD != 0) {
			ConfigurarColor(12);
			cout << medallasAD;
			ConfigurarColor(15);
		}
		else cout << medallasAD;
		cout << setw(9) << "0" << setw(10);
		if(mayorpremioAH == medallasAH) {
			ConfigurarColor(12);
			cout << medallasAH;
			ConfigurarColor(15);
		}
		else cout << medallasAH;
		cout << setw(12);
		if(mayorpremioBN == medallasBN && medallasBN != 0) {
			ConfigurarColor(12);
			cout << medallasBN;
			ConfigurarColor(15);
		}
		else cout << medallasBN;
		cout << endl;
		cout << setw(8) << "3" << setw(8) << "Trofeo" << setw(6);
		if(mayorpremioMM == trofeosMM && trofeosMM != 0) {
			ConfigurarColor(12);
			cout << trofeosMM;
			ConfigurarColor(15);
		}
		else cout << trofeosMM;
		cout << setw(9);
		if(mayorpremioAD == trofeosAD && trofeosAD != 0) {
			ConfigurarColor(12);
			cout << trofeosAD;
			ConfigurarColor(15);
		}
		else cout << trofeosAD;
		cout << setw(9) << "0" << setw(10);
		if(mayorpremioAH == trofeosAH && trofeosAH != 0) {
			ConfigurarColor(12);
			cout << trofeosAH;
			ConfigurarColor(15);
		}
		else cout << trofeosAH;
		cout << setw(12);
		if(mayorpremioBN == trofeosBN && trofeosBN != 0) {
			ConfigurarColor(12);
			cout << trofeosBN;
			ConfigurarColor(15);
		}
		else cout << trofeosBN;
		cout << endl;
		cout << setw(8) << "4" << setw(8) << "Copa" << setw(6);
		if(mayorpremioMM == copasMM && copasMM != 0) {
			ConfigurarColor(12);
			cout << copasMM;
			ConfigurarColor(15);
		}
		else cout << copasMM;
		cout << setw(9);
		if(mayorpremioAD == copasAD && copasAD != 0) {
			ConfigurarColor(12);
			cout << copasAD;
			ConfigurarColor(15);
		}
		else cout << copasAD;
		cout << setw(9);
		if(mayorpremioWC == copasWC) {
			ConfigurarColor(12);
			cout << copasWC;
			ConfigurarColor(15);
		}
		else cout << copasWC;
		cout << setw(10);
		if(mayorpremioAH == copasAH && copasAH != 0) {
			ConfigurarColor(12);
			cout << copasAH;
			ConfigurarColor(15);
		}
		else cout << copasAH;
		cout << setw(12);
		if(mayorpremioBN == copasBN && copasBN != 0) {
			ConfigurarColor(12);
			cout << copasBN;
			ConfigurarColor(15);
		}
		else cout << copasBN;
		cout << endl << endl;
		cout << setw(36) << "Ranking de juegos por premios" << endl << endl;
		cout << setw(24) << "Maymen" << setw(10) << "Adivinum" << setw(9) 
			<< "Warcoin" << setw(10) << "Ahorcado" << setw(15) << "Batalla Naval" 
			<< endl;
		cout << setw(8) << "0" << setw(8) << "Diploma" << setw(6);
		if(mayordiploma == diplomasMM || mayordiploma == 0) {
			ConfigurarColor(9);
			cout << diplomasMM;
			ConfigurarColor(15);
		}
		else cout << diplomasMM; 
		cout << setw(9); 
		if(mayordiploma == diplomasAD && mayordiploma >= 1) {
			ConfigurarColor(9);
			cout << diplomasAD;
			ConfigurarColor(15);
		}
		else cout << diplomasAD; 
		cout << setw(9) << "0" << setw(10) << "0" << setw(12);
		if(mayordiploma == diplomasBN && mayordiploma >= 1) {
			ConfigurarColor(9);
			cout << diplomasBN;
			ConfigurarColor(15);
		}
		else cout << diplomasBN; 
		cout << endl;
		cout << setw(8) << "1" << setw(8) << "Moneda" << setw(6);
		if(mayormoneda == monedasMM || mayormoneda == 0) {
			ConfigurarColor(9);
			cout << monedasMM;
			ConfigurarColor(15);
		}
		else cout << monedasMM;
		cout << setw(9); 
		if(mayormoneda == monedasAD && mayormoneda >= 1) {
			ConfigurarColor(9);
			cout << monedasAD;
			ConfigurarColor(15);
		}
		else cout << monedasAD; 
		cout << setw(9) << "0" << setw(10) << "0" << setw(12);
		if(mayormoneda == monedasBN && mayormoneda >= 1) {
			ConfigurarColor(9);
			cout << monedasBN;
			ConfigurarColor(15);
		}
		else cout << monedasBN;
		cout << endl;
		cout << setw(8) << "2" << setw(8) << "Medalla" << setw(6); 
		if(mayormedalla == medallasMM && mayormedalla == 0) {
			ConfigurarColor(9);
			cout << medallasMM;
			ConfigurarColor(15);
		}
		else cout << medallasMM;
		cout << setw(9);
		if(mayormedalla == medallasAD && mayormedalla >= 1) {
			ConfigurarColor(9);
			cout << medallasAD;
			ConfigurarColor(15);
		}
		else cout << medallasAD;
		cout << setw(9) << "0" << setw(10);
		if(mayormedalla == medallasAH && mayormedalla >= 1) {
			ConfigurarColor(9);
			cout << medallasAH;
			ConfigurarColor(15);
		}
		else cout << medallasAH;
		cout << setw(12);
		if(mayormedalla == medallasBN && mayormedalla >= 1) {
			ConfigurarColor(9);
			cout << medallasBN;
			ConfigurarColor(15);
		}
		else cout << medallasBN;
		cout << endl;
		cout << setw(8) << "3" << setw(8) << "Trofeo" << setw(6);
		if(mayortrofeo == trofeosMM || mayortrofeo == 0) {
			ConfigurarColor(9);
			cout << trofeosMM;
			ConfigurarColor(15);
		}
		else cout << trofeosMM;
		cout << setw(9);
		if(mayortrofeo == trofeosAD && mayortrofeo >= 1) {
			ConfigurarColor(9);
			cout << trofeosAD;
			ConfigurarColor(15);
		}
		else cout << trofeosAD;
		cout << setw(9) << "0" << setw(10);
		if(mayortrofeo == trofeosAH && mayortrofeo >= 1) {
			ConfigurarColor(9);
			cout << trofeosAH;
			ConfigurarColor(15);
		}
		else cout << trofeosAH;
		cout << setw(12);
		if(mayortrofeo == trofeosBN && mayortrofeo >= 1) {
			ConfigurarColor(9);
			cout << trofeosBN;
			ConfigurarColor(15);
		}
		else cout << trofeosBN;
		cout << endl;
		cout << setw(8) << "4" << setw(8) << "Copa" << setw(6);
		if(mayorcopa == copasMM || mayorcopa == 0) {
			ConfigurarColor(9);
			cout << copasMM;
			ConfigurarColor(15);
		}
		else cout << copasMM;
		cout << setw(9);
		if(mayorcopa == copasAD && mayorcopa >= 1) {
			ConfigurarColor(9);
			cout << copasAD;
			ConfigurarColor(15);
		}
		else cout << copasAD;
		cout << setw(9);
		if(mayorcopa == copasWC && mayorcopa >= 1) {
			ConfigurarColor(9);
			cout << copasWC;
			ConfigurarColor(15);
		}
		else cout << copasWC;
		cout << setw(10);
		if(mayorcopa == copasAH && mayorcopa >= 1) {
			ConfigurarColor(9);
			cout << copasAH;
			ConfigurarColor(15);
		}
		else cout << copasAH;
		cout << setw(12);
		if(mayorcopa == copasBN && mayorcopa >= 1) {
			ConfigurarColor(9);
			cout << copasBN;
			ConfigurarColor(15);
		}
		else cout << copasBN;
		cout << endl << endl;
		cout << "9. Volver a men" << (char) 163 << " anterior" << endl << endl;
		cout << "==================================================================" 
			<< "==" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}

char MenuEstadisticasUsuarios(int puntosMM, int puntosAD, int puntosWC, 
							  int puntosAH, int puntosBN, 
							  char mejorjugadorMM[11], char mejorjugadorAD[11],
							  char mejorjugadorWC[11], char mejorjugadorAH[11],
							  char mejorjugadorBN[11]) {
	cout << "Estad" << (char) 161 << "sticas de Usuarios" << endl;
	cout << "==================================================================" 
		<< "==" << endl << endl;
	//Información para el jugador (mejores jugadores)
	cout << "Mejor jugador de MayMen: ";
	if(puntosMM == 0) {
		cout << "Nadie ha ganado hasta ahora." << endl; 
	}
	else cout << mejorjugadorMM << " con puntaje de " << puntosMM << "."
	   << endl;
	cout << "Mejor jugador de Adivinum: ";
	if(puntosAD == 0) {
		cout << "Nadie ha ganado hasta ahora." << endl; 
	}
	else cout << mejorjugadorAD << " con puntaje de " << puntosAD << "."
	   << endl;
	cout << "Mejor jugador de WarCoin: "; 
	if(puntosWC == 0) {
		cout << "Nadie ha ganado hasta ahora." << endl; 
	}
	else cout << mejorjugadorWC << " con puntaje de " << puntosWC << "."
	   << endl;
	cout << "Mejor jugador de Ahorcado: ";
	if(puntosAH == 0) {
		cout << "Nadie ha ganado hasta ahora." << endl; 
	}
	else cout << mejorjugadorAH << " con puntaje de " << puntosAH << "."
	   << endl;
	cout << "Mejor jugador de Batalla Naval: ";
	if(puntosBN == 0) {
		cout << "Nadie ha ganado hasta ahora."; 
	}
	else cout << mejorjugadorBN << " con puntaje de " << puntosBN << ".";
	cout << endl << endl; 
	//Opción para el jugador
	cout << "9. Volver a men" << (char) 163 << " anterior" << endl << endl;
	cout << "==================================================================" 
		<< "==" << endl << endl;
	cout << "Ingrese una opci" << (char) 162 << "n: ";
	char opcion;
	cin >> opcion;
	while(opcion <= 47 || opcion >= 58) {
		LimpiarPantalla();
		cout << "Estad" << (char) 161 << "sticas de Usuarios" << endl;
		cout << "==================================================================" 
			<< "==" << endl << endl;
		cout << "Mejor jugador de MayMen: ";
		if(puntosMM == 0) {
			cout << "Nadie ha ganado hasta ahora." << endl; 
		}
		else cout << mejorjugadorMM << " con puntaje de " << puntosMM << "."
		   << endl;
		cout << "Mejor jugador de Adivinum: ";
		if(puntosAD == 0) {
			cout << "Nadie ha ganado hasta ahora." << endl; 
		}
		else cout << mejorjugadorAD << " con puntaje de " << puntosAD << "."
		   << endl;
		cout << "Mejor jugador de WarCoin: "; 
		if(puntosWC == 0) {
			cout << "Nadie ha ganado hasta ahora." << endl; 
		}
		else cout << mejorjugadorWC << " con puntaje de " << puntosWC << "."
		   << endl;
		cout << "Mejor jugador de Ahorcado: ";
		if(puntosAH == 0) {
			cout << "Nadie ha ganado hasta ahora." << endl; 
		}
		else cout << mejorjugadorAH << " con puntaje de " << puntosAH << "."
		   << endl;
		cout << "Mejor jugador de Batalla Naval: ";
		if(puntosBN == 0) {
			cout << "Nadie ha ganado hasta ahora."; 
		}
		else cout << mejorjugadorBN << " con puntaje de " << puntosBN << ".";
		cout << endl << endl; 
		cout << "9. Volver a men" << (char) 163 << " anterior" << endl << endl;
		cout << "==================================================================" 
			<< "==" << endl << endl;
		cout << "Ingrese una opci" << (char) 162 << "n: ";
		cout << endl << endl;
		cout << "Debe ingresar un n" << (char) 163 << "mero. Vuelve a " 
			<< "intentarlo: ";
		cin >> opcion;
	}
	return opcion;
}
