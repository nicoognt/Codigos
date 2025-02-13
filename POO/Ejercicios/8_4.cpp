#include <iostream>
#include <list>
using namespace std;
/*Cree un programa que lea valores flotantes por teclado y los inserte en una lista. Muestre la lista, inserte en medio de 
cada par de elementos contiguos el promedio de dichos elementos y muestre la lista modificada.
Responda: ¿es posible ordenar solamente una porción de la lista de la misma manera que se hizo con el vector en el ejercicio 2?*/
int main() {
	list<int> l;
	int x = 2*rand()%10;
	while(x!=0){
		l.push_back(x);
		x = 2*rand()%10;|
	}
	
	for(auto it = l.begin(); it!=l.end(); ++it){
		cout << *it << "  ";
	}
	
	for(auto it = l.begin() ; next(it)!=l.end(); it++){
		float promedio = (*it + *(next(it)))/2;
		l.insert(next(it),promedio);
		++it;
	}
	
	cout << "\n";
	for(auto it = l.begin(); it!=l.end(); ++it){
		cout << *it << "  ";
	}
	return 0;
}

