#include <iostream>
#include <list>
#include <map>
using namespace std;
/**Aplica. Escribir una funcion void apply_map(list<int> &L, map<int,int> &M, list<int> &ML) que, 
dada una lista L y una correspondencia M retorna por ML una lista con los resultados de 
aplicar M a los elementos de L. Si algun elemento de L no esta en el dominio de M, entonces el 
elemento correspondiente de ML no es incluido. Por ejemplo, si L = (1,2,3,4,5,6,7,1,2,3) 
y M= {(1,2),(2,3),(3,4),(4,5),(7,8)}, entonces, despues de hacer apply_map(L,M,ML), 
debe quedar ML = {(2,3,4,5,8,2,3,4)}.
**/
void apply_map(list<int> &L, map<int,int> &M, list<int> &ML){
	if(L.empty()) return; 
	if(!ML.empty()) ML.clear();
	
	for(int x : L){
		auto pos = M.find(x);
		if(pos!=M.end()){
			ML.push_back(pos->second);
		}
	}
}
int main() {
	
	return 0;
}







