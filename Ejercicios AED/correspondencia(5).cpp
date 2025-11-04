#include <iostream>
#include <map>
#include <list>
using namespace std;
/**cutoffmap. Implemente una funcion void cutoffmap(map<int, list<int>> &M, int p, int q) 
que elimina todas las claves que NO estan en el rango [p,q). En las asignaciones 
que quedan tambien debe eliminar los elementos de la lista que no estan en el rango. 
Si la lista queda vaca entonces la asignacion debe ser eliminada. 
Por ejemplo: si M = {1->(2,3,4), 5->(6,7,8), 8->(4,5), 3->(1,3,7)}, entonces 
cutoffmap(M,1,6) debe dejar M={1->(2,3,4), 3->(1,3)}. Notar que la clave 5 ha 
sido eliminada si bien esta dentro del rango porque su lista quedara vacia. 
Restricciones: el programa no debe usar contenedores auxiliares.
**/
void printMap(const map<int, list<int>> &M) {
	for (auto &p : M) {
		cout << p.first << " -> [";
		for (auto it = p.second.begin(); it != p.second.end(); ++it) {
			cout << *it;
			if (next(it) != p.second.end()) cout << ", ";
		}
		cout << "]" << endl;
	}
}
void cutoffmap(map<int,list<int>> &M, int p, int q){
	if(M.empty()) return;
	
	for(auto it=M.begin();it!=M.end();){
		if(it->first < p || it->first >= q){
			it = M.erase(it);
			continue;
		} else {
			for(auto itL=it->second.begin();itL!=it->second.end();){
				if(*itL < p || *itL >= q){
					itL = it->second.erase(itL);
					continue;
				} else {
					++itL;
				}
			}
			if(it->second.empty()){
				it = M.erase(it);
				continue;
			}
		}
		++it;
		
	}
}
int main() {
	map<int, list<int>> ejemplo;
	ejemplo[1] = {2, 3, 5};
	ejemplo[4] = {5, 4, 9};
	ejemplo[2] = {10};
	ejemplo[7] = {1, 2, 3};
	printMap(ejemplo);
	cout << endl;
	
	cutoffmap(ejemplo,1,6);
	
	printMap(ejemplo);
	return 0;
}







