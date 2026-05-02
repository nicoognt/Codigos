#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;
/**Camaleon. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y) y bool dist(int x, int y) que
retornen verdadero si x es menor, mayor o menor en valor absoluto que y respectivamente. Luego implemente una funcion
ordena(list<int> &L, bool (*f)(int,int)) que ordene la lista L dependiendo de la funcion f pasada como parametro.
**/
bool mayor(int x, int y){return (abs(x)>abs(y));}
bool menor(int x, int y){return (abs(x)<abs(y));}
bool dist(int x, int y){return (abs(x)!=abs(y));}

void ordena(list<int> &L, bool (*f)(int, int)){
	if(L.empty()) abort();
	
	for(auto i=L.begin();i!=L.end();i++){
		for(auto j=next(i);j!=L.end();j++){
			if(!f(*i,*j)){
				swap(*i,*j);
			}
		}
	}
	
}
int main() {
	list<int> L = {-1,5,-2,-3,7,8,2};
	cout << "lista antes: [";
	for(auto i=L.begin();i!=L.end();i++){
		if(i==prev(L.end())) cout << *i;
		else cout << *i << ", ";
	}
	cout << "]\n";
	
	ordena(L,mayor);
	
	cout << "lista despues: [";
	for(auto i=L.begin();i!=L.end();i++){
		if(i==prev(L.end())) cout << *i;
		else cout << *i << ", ";
	}
	cout << "]\n";
	return 0;
}







