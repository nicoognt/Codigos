#include <iostream>
#include <list>
using namespace std;
/*SelectionSort. Escribir una funcion void selection_sort(list<int> &L), que ordena los elementos de L
de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo (swap) con el primer
elemento de la lista. Luego intercambiar el menor elemento de la lista restante, con el segundo elemento, y 
asi sucesivamente. Esta funcion debe ser IN PLACE.
*/
void selection_sort(list<int> &L){
	for(auto pos=L.begin();pos!=L.end();pos++){
		auto it_min = pos;
		
		for (auto it=next(pos);it!=L.end();it++){
			if(*it<*it_min) it_min = it;
		}
		swap(*pos,*it_min);
	}
}
int main() {
	list<int> l = {1,4,2,22,12,40,41,1};
	cout << "lista antes: ";
	for (int &n : l){
		cout << n << ", ";
	}
	cout << endl;
	selection_sort(l);
	cout << "lista despues: ";
	for (int &n : l){
		cout << n << ", ";
	}
	cout << endl;
	return 0;
}







