#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*Escriba un programa que defina un vector dinámico de 30 enteros aleatorios menores que 25. Luego:
1. Ordene en forma descendente los elementos ubicados entre las posiciones 10 y 20 inclusive, y muestre el vector.
2. Inserte en un nuevo vector los elementos que fueron ordenados en el apartado anterior, y quítelos del vector original.
3. Permita ingresar un valor por teclado, y muestre cuántas veces aparece dicho valor en el vector.
4. Elimine todas las ocurrencias del valor ingresado en el punto anterior, utilizando la función remove.
Responda: ¿Pueden las funciones globales de la STL eliminar realmente los elementos (liberando la memoria de un contenedor)?*/
int main() {
	vector<int> v(30);
	for(int &x : v){
		x = 1+rand()%24;
	}
	
	for(const int &x : v){
		cout << x << "  ";
	}
	auto itini = next(v.begin(),10), itfin = next(v.begin(),20);
	sort(itini,itfin);
	reverse(itini,itfin);
	
	cout << "\n";
	for(const int &x : v){
		cout << x << "  ";
	}
	
	vector<int> v1(distance(itini,itfin));
	copy(itini,itfin,v1.begin());
	v.erase(itini,itfin);
	
	
	cout << "\n" << "valor a buscar: "; int n; cin>>n;
	size_t reps = count(v1.begin(),v1.end(),n);
	cout << "\n" << "el valor se repite " << reps << " veces" << endl;
	
	auto ite = remove(v1.begin(),v1.end(),n);
	v1.erase(ite,v1.end());
	cout << "\n";
	for(const int &x : v1){
		cout << x << "  ";
	}
	return 0;
}

