#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*Escriba una función C++ genérica llamada dosmayores_up(...) que reciba un vector como parámetro.
La función debe modificadar el vector: debe obtener los 2 mayores y ubicar el primer mayor en el 1er lugar (al comienzo del vector) intercambiando
los elementos correspondientes, y al 2do mayor en el 2do lugar, el resto de los elementos quedan en sus posiciones originales.
Nota: no utilice estructuras de control iterativas, solo recorra la secuencia a través de las funciones de la biblioteca <algorithm>.*/
void dosmayores_up(vector<int> &v){
	auto it = max_element(v.begin(),v.end());
	swap(*(v.begin()),*it);
	it = max_element(v.begin()+1,v.end());
	swap(*(v.begin()+1),*it);
}

int main() {
	vector<int> v(12);
	for(size_t i=0;i<v.size();i++) { 
		v[i] = 1 + rand()%150;
	}
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	
	cout << endl;
	dosmayores_up(v);
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	return 0;
}

