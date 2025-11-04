#include <iostream>
#include <list>
using namespace std;
/*Invierte. Escribir una funcion void invert(list<int> &L), que invierte el orden 
de la lista L. Este algoritmo debe implementarse in place y debe ser O(n). Restriccion: no utilizar el metodo size().
*/
void invert(list<int> &L){
	int size = 0;
	for (auto it=L.begin();it!=L.end();it++){
		size++;
	}
	int fin = size/2;
	for (int i=0;i<fin;i++){
		auto p1=next(L.begin(),i);
		auto p2=prev(L.end(),i+1);
		swap(*p1,*p2);
	}
}

int main() {
	list<int> l = {1,2,3,4,5,6,7};
	cout << "lista antes: [";
	for (int &n:l){
		cout << n << ", ";
	}
	cout << "]" << endl;
	
	invert(l);
	
	cout << "lista despues: [";
	for (int &n:l){
		cout << n << ", ";
	}
	cout << "]" << endl;
	return 0;
}







