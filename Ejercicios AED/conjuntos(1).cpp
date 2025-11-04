#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool buscar_disj(set<int> &a, set<int> &b){
	auto ita = a.begin();
	
	while(ita!=a.end()){
		auto itb = b.find(*ita);
		if(itb==b.end()) return false;
		ita++;
	}
	return true;
}
bool disjuntos(vector<set<int>> &v){
	if(v.empty()) return true;
	
	for(size_t i=0;i<v.size();i++){
		auto s1 = v[i];
		
		for(size_t j=0;j<v.size();j++){
			auto s2 = v[j];
			if(s1==s2){
				continue;
			} else {
				bool resultado = buscar_disj(s1,s2);
				if(!resultado) return resultado;
			}
		}
	}
	
	return true;
}
int main() {
	
	return 0;
}







