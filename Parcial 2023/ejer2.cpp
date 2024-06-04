#include <iostream>
#include <vector>
using namespace std;
//El código fuente de un proyecto de software muy grande está dividido en muchos archivos. Se desea
//analizar la longitud de cada uno y del proyecto completo. a) Escriba un programa que permita cargar por cada uno
//de los N (dato) archivos 3 valores: nombre, cantidad de líneas de código, cantidad de funciones que define; y guarde
//toda esta información en un único vector. b) Luego debe informar por cada archivo el promedio de líneas por
//función; c) los nombres de los dos archivos con más líneas de código; y d) las cantidades totales de líneas y de
//funciones sumando todos los archivos. Importante: Resuelva implementando una función para cada uno de los ítems
//c) y d) que calcule lo que se requiere informar desde el programa principal (main).

struct Archivo {
	string nombre;
	int lineas_cod, cant_func;
};
struct Totales {
	int tot_lineas;
	int tot_funcs;
};

pair<Archivo,Archivo> DosMayores(const vector<Archivo> &aux) {
	Archivo may = { "", -1, 0}, seg ={ "", -1, 0};
	for(size_t i=0;i<aux.size();i++) { 
		if (aux[i].lineas_cod > may.lineas_cod) {
			seg = may;
			may = aux[i];
		} else if (aux[i].lineas_cod > seg.lineas_cod) {
			seg = aux[i];
		};
	}
	return {may, seg};
}

pair<int,int> total(const vector<Archivo> &c) {
	int tot_lineas = 0, tot_funcs = 0;
	for (Archivo aux : c) {
		tot_lineas += aux.lineas_cod;
		tot_funcs += aux.cant_func;
	}
	return {tot_lineas, tot_funcs };
}

int main() {
	int N;
	cin>>N;
	vector<Archivo> a(N);
	
	for(size_t i=0;i<a.size();i++) { 
		cin.ignore();
		getline(cin,a[i].nombre);
		cin>>a[i].lineas_cod;
		cin>>a[i].cant_func;
	}
	
	for(Archivo b : a) { 
		cout << b.nombre << ": " << b.lineas_cod/b.cant_func;
	}
	
	pair<Archivo,Archivo> May = DosMayores(a);
	pair<int,int> tot = total(a);
	cout << "La cantidad total de lineas es: " << tot.first << ", y la de funciones, " << tot.second << endl;
	return 0;
}

