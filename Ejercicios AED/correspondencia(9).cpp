#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <graphviz.hpp>
using namespace std;
/**isHamilt. Dado un grafo map<int, list<int> >G y una lista de vertices list<int> L determinar si L es un camino hamiltoniano en G.**/
bool es_camino(map<int,list<int>> &G, list<int> &L){
	for(auto it=L.begin();it!=prev(L.end());it++){
		int v1 = *it, v2 = *next(it);
		auto pos = G.find(v1);
		
		if(pos==G.end()){
			
			return false;
			
		} else {
			
			bool encontrado = false;
			
			for(auto itL=pos->second.begin();itL!=pos->second.end();itL++){
				if(*itL == v2) {
					encontrado = true;
					break;
				}
			}
			
			if(!encontrado) return false;
		}
	}
	return true;
}
bool verificarReps(list<int> l){
	auto it = l.begin();
	while(it!=l.end()){
		int cont = count(l.begin(),l.end(),*it);
		if(cont>1){
			return false;
		} else {
			it++;
		}
	}
	return true;
}
bool isHamilt(map<int,list<int>> &G, list<int> &L){
	if(!es_camino(G,L) || !verificarReps(L)) return false;
	
	if(G.size()==L.size()){
		return true;
	} else {
		return false;
	}
}
int main() {
	
	return 0;
}







