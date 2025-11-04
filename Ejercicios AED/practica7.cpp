#include <iostream>
#include <list>
using namespace std;
/**Ascendente1. Escribir una funcion void ascendente1(list<int> &L, list<list<int>> &LL) que,
dada una lista L, genera una lista de listas LL de tal forma de que cada sublista es ascendente.
**/
void ascendente1(list<int> &L, list<list<int>> &LL){
	if(!LL.empty()) LL.erase(LL.begin(),LL.end());
	
	list<int> aux;
	
	for(auto it=L.begin();it!=L.end();it++){
		if ((next(it) != L.end()) && (*it < *next(it))){
			aux.push_back(*it);
		} else {
			aux.push_back(*it);
			LL.push_back(aux);
			aux.clear();
		}
	}
	if (!aux.empty()) LL.push_back(aux);
}

int main() {
	list<int> L = {1,2,5,3,4,2,7,9};
	list<list<int>> LL;
	
	ascendente1(L,LL);
	return 0;
}







