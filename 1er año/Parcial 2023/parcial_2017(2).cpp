#include <iostream>
#include <vector>
using namespace std;
/// Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
/// ocurrido en un partido de tenis. tipo puede ser "ace", "error no forzado", "tiro ganador", "doble falta", y
/// "quiebre". jugador puede ser 1 o 2. a) Escriba una función llamada resumen_partido que reciba un
/// arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
/// para ese jugador. b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
/// mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada
/// jugador.

struct Evento {
	string tipo;
	int jugador;
};



void llenar(vector<Evento> &a,int jug, string e) {
	Evento aux;
	aux.tipo = e;
	aux.jugador = jug;
	a.push_back(aux);
}

vector<Evento> resumen_partido(vector<Evento> &b, int numero) {
	vector<int> aux(5,0);
	for(size_t i=0;i<b.size();i++) { 
		if (b[i].jugador==numero) {
			if(b[i].tipo=="ace") {
				aux[0] += 1;
			}else if(b[i]=="error no forzado") {
				aux[1] += 1;
			}else if(b[i]=="tiro ganador") {
				aux[2] += 1;
			}else if(b[i]=="doble falta") {
				aux[3] += 1;
			}else {
				aux[4] += 1;
			}
		}
	}
	return aux;
}

int main() {
	int num_jugador;
	string even;
	
	vector<Evento> competencia;
	
	cin >> num_jugador;
	while (num_jugador != 0) {
		getline(cin,even);
		ingresar_eventos(competencia,num_jugador,even);
		cin.ignore();
		cin >> num_jugador;
	}
	
	cin >> num_jugador
	vector<int> eventos_jugadorx(5,0) = resumen_partido(competencia,num_jugador);
	return 0;
}

