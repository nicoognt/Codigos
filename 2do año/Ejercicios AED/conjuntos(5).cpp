#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool review_inc(set<int> &A, set<int> &B){
	auto itA = A.begin();
	
	while(itA!=A.end()){
		auto itB = B.find(*itA);
		if(itB==B.end()) break;
	}
	
	if(itA==A.end()) return true;
	else return false;
}
bool cubreTodo(vector<set<int>> &v, set<int> &w){
	if(v.empty()) return true;
	
	for(size_t i=0;i<v.size();i++){
		auto s1 = v[i];
		bool incluido = review_inc(s1,w);
		
		if(!incluido) return incluido;
	}
	
	return true;
}
int main() {
	
	return 0;
}







