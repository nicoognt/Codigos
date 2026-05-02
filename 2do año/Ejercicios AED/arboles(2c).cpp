#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;
void maxE(tree<int> T, tree<int>::iterator p, int &maxima){
	if(*p > maxima) maxima = *p;
	auto q = p.lchild();
	while(q!=T.end()) maxE(T,q++,maxima);
}
int maximo(tree<int> T){
	if(T.begin() == T.end()) throw runtime_error("Arbol invalido");
	int max_etiqueta = *T.begin();
	maxE(T,T.begin(),max_etiqueta);
	
	return max_etiqueta;
}
int main() {
	
	return 0;
}







