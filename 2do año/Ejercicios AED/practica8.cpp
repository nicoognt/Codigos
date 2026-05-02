#include <iostream>
#include <list>
#include <vector>
using namespace std;
/**Ascendente2. Escribir una funcion void ascendente2(list<int> &L, vector<list<int>> &VL) que, 
dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es ascendente.
**/
void ascendente2(list<int> &L, vector<list<int>> &VL){
	if(L.empty()) return;
	
	list<int> aux;
	
	for(auto i=L.begin();i!=L.end();i++){
		if (next(i) != L.end() && *i < *next(i)){
			aux.push_back(*i);
		} else {
			aux.push_back(*i);
			VL.push_back(aux);
			aux.clear();
		}
	}
	if (!aux.empty()) VL.push_back(aux);
}

int main() {
	list<int> L;
	vector<list<int>> VL;
	
	ascendente2(L,VL);
	return 0;
}







