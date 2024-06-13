#include <iostream>
#include <matrix>
using namespace std;
int main() {
	int alumno, materia, nota;
	matrix<int> carrera(200,35);

/// Se pretende analizar el rendimiento académico de 200 egresados de una carrera cuyo plan contiene 35 materias. 
/// Escriba un programa que permita a) ingresar 200x35 ternas de datos compuestas por
/// número de alumno (1 a 200), número de materia (1 a 35) y nota final (6 a 10) 
	for (int i=0; i<200*35;i++) {
		cin >> alumno >> materia >> nota;
		carrera[alumno][materia] = nota;
	}

/// y muestre: b) el mejor promedio de la carrera;
	float mejor_promedio = -1;
	int mejor_alumno;
	for(size_t i=0;i<carrera.size(0);i++) { 
		int cont = 0;
		for(size_t j=0;j<carrera.size(1);j++) { 
			cont += carrera[i][j];
		}
		float prom = cont/35;
		if (prom > mejor_promedio) {
			mejor_promedio = prom;
			mejor_alumno = i;
		}
	}
	cout << mejor_promedio;
	
/// c) la materia más difícil (la que tenga menor promedio de nota), y d) la nota que obtuvo el alumno del mejor promedio para esa materia más difícil.
	float menor_promedio = 2001;
	int materia_mas_dificil;
	for(size_t i=0;i<carrera.size(1);i++) { 
		int cont = 0;
		for(size_t j=0;j<carrera.size(0);j++) { 
			cont += carrera[j][i];
		}
		float promedio = cont/200;
		if (promedio < menor_promedio) {
			menor_promedio = promedio;
			materia_mas_dificil = i;
		}
	}
	cout << materia_mas_dificil << carrera[mejor_alumno][materia_mas_dificil];
	
	return 0;
}

