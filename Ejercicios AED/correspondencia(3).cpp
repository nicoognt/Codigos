#include <iostream>
#include <map>
using namespace std;
/**InverseMaps. Dos correspondencias M1 y M2 son inversas una de la otra si
tienen el mismo numero de asignaciones y para cada par de asignacion x->y en
M1 existe el par y->x en M2. Escribir un predicado bool areinverse(map<int,int> &M1, map<int,int> &M2);
que determina si las correspondencias M1 y M2 son inversas.
**/
bool areinverse(map <int,int> &M1, map<int,int> &M2){
	if(M1.size() != M2.size()){
		return false;
	}
	
	for(auto it=M1.begin();it!=M1.end();it++){
		int keyM1 = it->first;
		int valM1 = it->second;
		
		auto it2 = M2.find(valM1);
		
		if(it2==M2.end() || it2->second != keyM1){
			return false;
		}
	}
	
	return true;
}

int main() {
	map<int,int> M1 = {{1,2},{3,4}};
	map<int,int> M2 = {{2,1},{4,3}};
	
	if (areinverse(M1,M2)){
		cout << "son inversos\n";
	} else {
		cout << "no son inversos\n";
	}
	return 0;
}







