#include <iostream>
#include <vector>
using namespace std;
//a) Defina un struct para guardar notas de parciales de un alumno: apellido y
//nombre, notas de dos parciales y sus respectivos recuperatorios (las instancias
//que no rindió tendrán -1).
//b) Defina otro struct para guardar el resultado final del cursado de un alumno:
//apellido y nombre, condición final ("libre", "promocionado" o "regular") y nota final
//(de 1 a 10, solo si promociona, será -1 en caso contrario).
//c) Escriba una función que reciba una instancia del primer struct y retorne una del
//segundo. La función debe calcular la condición y la nota final (redondeando el
//promedio) según las reglas de esta materia.
//d) Escriba un programa cliente para probar la función.

struct Alumno {
	string nombre;
	vector<float> notas_parcial;
	vector<float> notas_recuperatorio;
};
struct Cond_final {
	string nombre;
	string condicion;
	float nota_final;
};
float prom(float suma) {
	return suma / 2;
}

float sum(Alumno xd) {
	float suma = 0;
	if (xd.notas_parcial[0] > xd.notas_recuperatorio[0] and xd.notas_parcial[1] > xd.notas_recuperatorio[1]) {
		suma = xd.notas_parcial[0] + xd.notas_parcial[1];
	} else if (xd.notas_parcial[0] < xd.notas_recuperatorio[0] and xd.notas_parcial[1] < xd.notas_recuperatorio[1]) {
		suma = xd.notas_recuperatorio[0] + xd.notas_recuperatorio[1];
	} else if (xd.notas_parcial[0] > xd.notas_recuperatorio[0] and xd.notas_parcial[1] < xd.notas_recuperatorio[1]) {
		suma = xd.notas_parcial[0] + xd.notas_recuperatorio[1];
	} else {
		suma = xd.notas_recuperatorio[0] + xd.notas_parcial[1];
	}
	return suma;
}

Alumno completar() {
	Alumno x;
	cout<<"Nombre: ";
	getline(cin, x.nombre);
	cout<<"Ingrese las dos notas de los parciales y luego, de los recuperatorios (si no asistió ingrese -1): ";
	x.notas_parcial.resize(2);
	x.notas_recuperatorio.resize(2);
	for(size_t i=0;i<2;i++) { 
		cin>>x.notas_parcial[i];
	}
	for(size_t i=0;i<2;i++) { 
		cin>>x.notas_recuperatorio[i];
	}
	return x;
}
void condicion(const Alumno downlin) {
	float suma = sum(downlin);
	float promedio = prom(suma);
	Cond_final aux;
	if (promedio >= 6) {
		aux.nombre = downlin.nombre;
		aux.condicion = "Promocionado";
		aux.nota_final = promedio;
	} else if (promedio >= 4) {
		aux.nombre = downlin.nombre;
		aux.condicion = "Regular";
		aux.nota_final = -1;
	} else {
		aux.nombre = downlin.nombre;
		aux.condicion = "Libre";
		aux.nota_final = -1;
	}
}

int main() {
	Alumno primero = completar();
	Alumno segundo = completar();
	
	condicion(primero);
	condicion(segundo);
	return 0;
}

