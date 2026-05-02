#include <iostream>
#include <graphviz.hpp>
#include <map>
#include <list>
using namespace std;
/**CompConexa. Dado un grafo como map<int,list<int>> G encontrar los 
subconjuntos del mismo list<list<int>> D que estan desconectados, es decir,
los conjuntos de vertices de cada una de las componentes conexas. 
Por ejemplo, si G={1->{2},2->{1},3->{4},4->{3}}, entonces debe retornar 
D=({1,2},{3,4}). La signatura de la funcion a implementar es void comp_conexas(map<int,list<int>> &G, list<list<int>> &D).
**/
void comp_conexas(map<int,list<int>> &G, list<list<int>> &D){
	list<int> L;
	for(auto p : G){
		L.push_back(p.first);
		for(auto it=p.second.begin();it!=p.second.end();it++){
			
		}
	}
}
int main() {
	
	return 0;
}







