#include <iostream>
#include <map>
#include <list>
using namespace std;
/**map2list. Escribir una funcion que dado un map M retorna las listas de
claves y valores, utilice la signatura void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals). 
Ejemplo: si M={1->2, 3->5, 8->20}, entonces debe retornar Keys = (1,3,8) y Vals = (2,5,20).
**/
void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	if(!M.empty()){
		Keys.clear();
		Vals.clear();
		
		for(auto p:M){
			Keys.push_back(p.first);
			Vals.push_back(p.second);
		}
	}
}
int main() {
	map<int,int> M;
	M.insert({1,3}); M.insert({2,4}); M.insert({3,5});
	
	return 0;
}







