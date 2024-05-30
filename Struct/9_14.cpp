#include <iostream>
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
	vector<float> notas_parcial(2);
	vector<float> notas_recuperatorio(2);
};
struct Cond_final {
	string nombre;
	string condicion;
	float nota_final;
};
float prom(float suma) {
	return suma / 2;
}

Alumno completar() {
	Alumno x;
	cout<<"Nombre: ";
	getline(cin, x.nombre);
	cout<<"Ingrese las dos notas de los parciales y luego, de los recuperatorios (si no asistió ingrese -1): ";
	for(size_t i=0;i<x.notas_parcial.size();i++) { 
		cin>>x.notas_parcial[i];
	}
	for(size_t i=0;i<x.notas_recuperatorio.size();i++) { 
		cin>>x.notas_recuperatorio[i]
	}
	return x;
}
void condicion(const Alumno downlin) {
	float suma = downlin.notas_parcial[0] + downlin.notas_parcial[1];
	float promedio = prom(suma);
	
}

int main() {
	Alumno primero = completar();
	Alumno segundo = completar();
	
	condicion(primero);
	mostrar(primero);
	condicion(segundo);
	mostrar(segundo);
	return 0;
}

