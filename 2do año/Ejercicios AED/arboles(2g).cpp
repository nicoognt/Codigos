#include <iostream>
using namespace std;
void borrarImpares(tree<int> T, tree<int>::iterator p){
	auto q = p.lchild();
	while(q!=T.end()){
		if(*q%2 != 0) {
			q = T.erase(q);
		} else {
			borrarImpares(T,q);
			q++;
		}
	}
}
void borrarImpares(tree<int> T){
	if(T.begin() == T.end()) return;
	if(*T.begin()%2 != 0){
		T.erase(T.begin());
	} else {
		borrarImpares(T,T.begin());
	}
}
int main() {
	
	return 0;
}







