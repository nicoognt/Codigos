#include <iostream>
#include <list>
#include <stack>
using namespace std;
/**SortStack. Escribir una funcion void sort(list<int> &L), que ordena los elementos
de L de mayor a menor. Para ello emplear el siguiente algoritmo simple, utilizando
una pila auxiliar P: ir tomando el menor elemento de L, eliminarlo de L e insertarlo
en P hasta que L este vacia. Luego insertar los elementos de P en L.
**/
void sort(list<int> &L){
	if (L.empty()) abort();
	stack<int> s;
	
	while(L.size() != 0){
		
		int min = *L.begin();
		list<int>::iterator pos = L.begin();
		
		for(auto i=next(L.begin());i!=L.end();i++){
			if(*i<min){
				min = *i;
				pos = i;
			}
		}
		
		s.push(min);
		pos = L.erase(pos);
	}
	
	while(!s.empty()){
		int a = s.top();
		L.push_back(a);
		s.pop();
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
	
	sort(lista);
	
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







