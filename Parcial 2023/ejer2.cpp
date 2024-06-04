#include <iostream>
#include <vector>
using namespace std;
//El c�digo fuente de un proyecto de software muy grande est� dividido en muchos archivos. Se desea
//analizar la longitud de cada uno y del proyecto completo. a) Escriba un programa que permita cargar por cada uno
//de los N (dato) archivos 3 valores: nombre, cantidad de l�neas de c�digo, cantidad de funciones que define; y guarde
//toda esta informaci�n en un �nico vector. b) Luego debe informar por cada archivo el promedio de l�neas por
//funci�n; c) los nombres de los dos archivos con m�s l�neas de c�digo; y d) las cantidades totales de l�neas y de
//funciones sumando todos los archivos. Importante: Resuelva implementando una funci�n para cada uno de los �tems
//c) y d) que calcule lo que se requiere informar desde el programa principal (main).

struct Archivo {
	string nombre;
	int lineas_cod;
	int cant_func;
};

void llenar(vector<Archivo> &b) {
	for(size_t i=0;i<b.size();i++) { 
		cin>>b.nombre>>b.lineas_cod>>b.cant_func;
	}
}

int main() {
	int N;
	cin>>N;
	vector<Archivo> a(N);
	llenar(a);
	
	return 0;
}

