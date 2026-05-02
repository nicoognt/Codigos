#include <iostream>
#include <vector>
using namespace std;

/// En una carrera de ciclismo por etapas, el ganador es el competidor que acumula menor
/// cantidad de tiempo sumando sus tiempos de todas las etapas. Escriba un programa que permita ingresar la
/// cantidad de competidores de una carrera de tres etapas y a continuación, por cada competidor, ingresar primero
/// nombre y apellido, y luego los tres tiempos (uno por cada etapa). Cada tiempo se ingresa mediante dos enteros,
/// que corresponden a minutos y segundos. El programa debe mostrar el nombre del ganador y su tiempo total en
/// minutos y segundos. Advertencia: 40m 40s + 50m 50s no es 90m 90s, sino 91m 30s.
	
struct ciclista {
	string nom_ape;
	int etapa1_mins, etapa2_mins, etapa3_mins;
	int etapa1_segs, etapa2_segs, etapa3_segs;
	
};

void corredores(vector<ciclista> &a) {
	for (ciclista &x : a) {
		cin.ignore();
		getline(cin,x.nom_ape);
		cin.ignore();
		cin >> x.etapa1_mins;
		cin >> x.etapa1_segs;
		cin >> x.etapa2_mins;
		cin >> x.etapa2_segs;
		cin >> x.etapa3_mins;
		cin >> x.etapa3_segs;
	}
}

void corregir(int &minutos, int &segundos) {
	while (segundos >= 60) {
		segundos -= 60;
		minutos += 1;
	}
}

string ganador_carrera(const vector<ciclista> &x) {
	int suma_mins, suma_segs;
	string gano;
	int aux_m = 999, aux_s = 999;
	for (ciclista a : x) {
		suma_mins = a.etapa1_mins + a.etapa2_mins + a.etapa3_mins;
		suma_segs = a.etapa1_segs + a.etapa2_segs + a.etapa3_segs;
		
		corregir(suma_mins,suma_segs);
		if (suma_mins < aux_m) {
			gano = a.nom_ape;
		} else if (suma_segs < aux_s) {
			gano = a.nom_ape;
		}
		
	}
	return gano;
}

int main() {
	int n;
	cin >> n;
	vector<ciclista> v(n);
	corredores(v);
	
	string ganador = ganador_carrera(v);
	
	
	return 0;
}

