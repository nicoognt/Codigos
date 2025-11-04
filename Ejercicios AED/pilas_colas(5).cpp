#include <iostream>
#include <list>
#include <queue>
using namespace std;
/**SortQueue. Escribir una funcion void sort(list<int> &L), que ordena los 
elementos de L de menor a mayor. Para ello utilizar el siguiente algoritmo 
simple, utilizando una cola auxiliar C: ir tomando el menor elemento de 
L, eliminarlo de L e insertarlo en C hasta que L este vacia. Luego insertar los elementos de C en L.
**/
void sort2(list<int> &L){
	queue<int> C;
	if (L.empty()) abort();
	
	while(!L.empty()){
		
		int min = *L.begin(); auto pos = L.begin();
		
		for(auto i=next(L.begin());i!=L.end();i++){
			if(*i<min){
				min = *i; pos = i;
			}
		}
		
		C.push(min);
		pos = L.erase(pos);
	}
	
	while(!C.empty()){
		int a = C.front();
		L.push_back(a);
		C.pop();
	}
}
int main() {
	list<int> lista = {1,5,2,3,3,27,0};
	cout << "lista antes: [";
	for(auto it = lista.begin();it!=lista.end();it++){
		if(it==prev(lista.end())){
			cout << *it << "]" << endl;
		} else {
			cout << *it << ", ";
		}
	}
	
	sort2(lista);
	
	cout << "lista despues: [";
	for(auto it = lista.begin();it!=lista.end();it++){
		if(it==prev(lista.end())){
			cout << *it << "]" << endl;
		} else {
			cout << *it << ", ";
		}
	}
	return 0;
}







