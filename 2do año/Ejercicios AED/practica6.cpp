#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
#include <algorithm>
using namespace std;
/** ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
distintas longitudes, escribir una funcion void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP), que
busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5),
SEQ=(4,5,1) y REEMP=(9,7,3), entonces despues de llamar a reemplaza(L,SEQ,REEMP), debe quedar 
L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). 
Para implementar este algoritmo primero buscar desde el principio la secuencia SEQ, al encontrarla, reemplazar por REEMP,
luego seguir buscando a partir del siguiente elemento al ultimo de REEMP.
**/
void reemplaza(list<int> &L, list<int> &SEQ, list<int> &REEMP){
	if (SEQ.empty()) return;
	auto it = L.begin();
	while (it!=L.end()){
		if (distance(it,L.end()) < (int)SEQ.size()) break;
		
		auto it_end = next(it,SEQ.size());
		if (equal(SEQ.begin(),SEQ.end(),it)){
			it = L.erase(it,it_end);
			it = L.insert(it,REEMP.begin(),REEMP.end());
			
			advance(it,REEMP.size());
		} else {
			++it;
		}
	}
	
}


int main() {
	
	list<int> original = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> SEQ = {4,5,1};
	list<int> REEMP = {9,7,3};
	
	cout << "lista antes: [";
	for (auto it=original.begin();it!=original.end();it++){
		if (it == prev(original.end())) cout << *it;
		else cout << *it << ", ";
	}
	cout << "]" << endl;

	// aplico la funcion
	reemplaza(original,SEQ,REEMP);
	
	cout << "lista despues: [";
	for (auto it=original.begin();it!=original.end();it++){
		if (it == prev(original.end())) cout << *it;
		else cout << *it << ", ";
	}
	cout << "]" << endl;
	return 0;
}







