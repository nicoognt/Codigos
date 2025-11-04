#include <iostream>
#include <map>
#include <list>
using namespace std;
/**list2map. Escribir una funcion que dadas las listas de claves (k1,k2,k3, ...) y 
valores (v1,v2,v3, ...) retorna el map M con las asignaciones correspondientes
{ k1->v1, k2->v2, k3->v3, ...}. Utilice la signatura void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals). 
Nota: si hay claves repetidas, solo debe quedar la asignacion correspondiente a la ultima
clave en la lista. Si hay menos valores que claves utilizar cero como valor. Si hay mas valores que claves, ignorarlos.
**/
void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	auto itK = Keys.begin();
	auto itV = Vals.begin();
	
	while(itK!=Keys.end()){
		if(itV!=Vals.end()){
			M[*itK] = *itV;
			++itV;
		} else {
			M[*itK] = 0;
		}
		
		itK++;
	}
}

int main() {
	
	return 0;
}







