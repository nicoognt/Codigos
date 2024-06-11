#include <iostream>
#include <vector>
using namespace std;
/// Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
/// ocurrido en un partido de tenis. tipo puede ser "ace", error no forzado", "tiro ganador", "doble falta", y
/// "quiebre". jugador puede ser 1 o 2. a) Escriba una función llamada resumen_partido que reciba un
/// arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
/// para ese jugador. b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
/// mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada
/// jugador.

struct Evento {
	string tipo;
	int jugador;
};

void competencia(vector<Evento> &a) {
	
}

int main() {
	vector<Evento> competencia;
	ingresar_eventos(competencia);
	vector<Evento> v;
	int num_jugador;
	
	
	return 0;
}

