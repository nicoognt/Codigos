#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
/**mergeMap. Dadas dos correspondencias A y B, que asocian enteros con listas
ordenadas de enteros, escribir una funcion void merge_map(map<int, list<int>> &A, map<int, list<int>> &B, map<int, list<int>> &C) 
que devuelve en C una correspondencia que asigna al elemento x la fusion
ordenada de las dos listas A[x] y B[x]. Si x no es clave de A, entonces 
C[x] debe ser B[x] y viceversa. Sugerencia: utilice la funcion merge implementada en uno de los ejercicios anteriores.
**/
void merge_map(map<int,list<int>> &A,map<int, list<int>> &B,map<int,list<int>> &C){
	if(!C.empty()) C.clear();
	
	for(auto p : A){
		int x = p.first;
		auto pos = B.find(x);
		
		if(pos == B.end()){
			list<int> xd = A[x];
			xd.sort();
			C[x] = xd;
		} else {
			list<int> A1 = A[x], B1 = B[x];
			list<int> aux;
			
			for(auto itA=A1.begin();itA!=A1.end();itA++){
				aux.push_back(*itA);
			}
			for(auto itB=B1.begin();itB!=B1.end();itB++){
				aux.push_back(*itB);
			}
			
			aux.sort();
			C[x] = aux;
		}
	}
}
int main() {
	
	return 0;
}







