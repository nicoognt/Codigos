#include <iostream>
#include <matrix>
using namespace std;
float calcular_promedio(int suma, int contador) {
	return suma/contador;
}

int main() {
/// La Fórmula 1 está buscando mejorar la seguridad agregando nuevos elementos para proteger
/// las cabezas de los pilotos. Se probaron tres sistemas: el "shield" (una especie de "parabrisas" blindado), el "halo"
/// (un armazón de carbono) y el "ghost" (sin piloto en el auto, manejado con control remoto). Ciertos equipos han
/// probado algunos de estos elementos y han calificado los resultados en una escala de 1 a 5 estrellas. Se requiere
/// un programa C++ para analizar estos datos y ayudar a decidir cuál es la mejor opción.
	
	
/// a) Se ingresan ternas de datos compuestas por un código de equipo (de 1 a 10), un código de sistema (1-shield, 2-halo, 3-ghost), y la
/// calificación (1 a 5 estrellas). Los datos finalizan con código de equipo 0. Organice estos datos en una matriz de
///	10x3 (10 equipos, 3 sistemas), donde cada posición debe guardar la cantidad de estrellas asignadas por ese
///	equipo a ese sistema, o -1 si ese equipo no probó ese sistema.
	int cod_equipo, cod_sist, est;
	matrix<int> estrellas(10,3);
	
	cin >> cod_equipo;
	while (cod_equipo != 0) {
		cin >> cod_sist >> est;
		estrellas[cod_equipo][cod_sist] = est;
		cin >> cod_equipo;
	}
///	b) muestre solo los equipos que calificaron los tres sistemas, con sus respectivas calificaciones.
	for (size_t i=0;i<estrellas.size(0);i++) {
		bool probo_todo = true;
		for(size_t j=0;j<estrellas.size(1);j++) { 
			if (estrellas[i][j]==-1) {
				probo_todo=false;
			}
		}
		if (probo_todo) {
			cout << "El equipo " << i+1 << " probó todos los sistemas. Sus notas son: " << estrellas[i][0] << ", " << estrellas[i][1] << " y " << estrellas[i][2] << endl;
		}
	}
///	c) Informe el nombre del sistema que obtuvo un mayor promedio de estrellas (el promedio se calcula considerando todos los equipos que probaron el sistema, sin considerar los -1).
///	Defina y utilice para ello una función calcular_promedio que calcule el promedio de un sistema.
	
	int mejor_prom = -1;
	int aux;
	for(size_t i=0;i<estrellas.size(1);i++) { 
		int cont = 0, suma = 0;
		for(size_t j=0;j<estrellas.size(0);j++) { 
			if (estrellas[j][i] != -1) {
				suma += estrellas[j][i];
				cont++;
			}
		}
		float promedio = calcular_promedio(suma,cont);
		if (promedio > mejor_prom) {
			mejor_prom = promedio;
			aux = i;
		}
	}
	cout << "El sistema con mayor promedio de estrellas es el " << aux+1 << endl;
	return 0;
}

