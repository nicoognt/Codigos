#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
/*Realice las mismas operaciones que en el ejericio anterior, pero utilizando
ahora un arreglo estático de 20 elementos enteros (int v[20]).*/
int rand10() {return (rand()%20-10);}

bool es_par(int valor) {return (valor%2==0);}

bool menor_abs(int a, int b){
	if (abs(a)==abs(b)) return a<b;
	return abs(a)<abs(b);
}
int main() {
	int v[20];
	int* p1 = &v[0]; int* p2 = &v[20];
	generate(p1,p2,rand10);
	cout << "Lista original:\n";
	for(int i=0;i<20;i++) { 
		cout << v[i] << endl;
	}
	
	cout << "\n";
	size_t cuantos = count_if(p1,p2,es_par);
	cout << "Dentro del arreglo estático hay " << cuantos << " elementos pares\n";
	
	sort(p1,p2,menor_abs);
	cout << "Lista ordenada por valores absolutos:\n";
	for(int i=0;i<20;i++) { 
		cout << v[i] << endl;
	}
	cout << "\n";
	
	auto it = unique(p1,p2);
	int v1[distance(p1,it)];
	for(int i=0;i<distance(p1,it);i++) { 
		v1[i] = v[i];
	}
	
	cout << "Lista con valores repetidos al final:\n";
	for(int i=0;i<20;i++) { 
		cout << v[i] << endl;
	}
	cout << "Lista final:\n";
	for(int i=0;i<distance(p1,it);i++) { 
		cout << v1[i] << endl;
	}
	return 0;
}

