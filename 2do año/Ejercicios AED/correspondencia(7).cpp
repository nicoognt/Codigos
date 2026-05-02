#include <iostream>
#include <map>
#include <list>
using namespace std;
/**Camino. Implemente la funcion bool es_camino(map<int,list<int>> G, list<int> &L) 
que recibe una lista L y determina si es o no camino en el grafo G. El grafo se
representa como un mapa que relaciona cada vertice (clave) con la lista de sus vertices adyacentes (valor).
**/
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
int main() {
	map<int, list<int>> G;
	G[1] = {2, 3};
	G[2] = {1, 4};
	G[3] = {1, 5};
	G[4] = {2};
	G[5] = {3};
	
	list<int> L1 = {1, 2, 4};
	cout << "Camino L1: " << (es_camino(G, L1) ? "SI" : "NO") << endl;
	
	list<int> L2 = {1, 3, 5};
	cout << "Camino L2: " << (es_camino(G, L2) ? "SI" : "NO") << endl;
	
	list<int> L3 = {1, 4};
	cout << "Camino L3: " << (es_camino(G, L3) ? "SI" : "NO") << endl;
	
	list<int> L4 = {2, 5};
	cout << "Camino L4: " << (es_camino(G, L4) ? "SI" : "NO") << endl;
	return 0;
}







