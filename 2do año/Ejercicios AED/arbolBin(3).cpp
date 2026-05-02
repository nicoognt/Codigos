#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
void cant_nodos_prof(btree<int> &T,btree<int>::iterator p, int prof, int &cont,int lvl){
	if(p==T.end()) return;
	if(lvl>=prof){
		cont++;
	}
	
	cant_nodos_prof(T,p.left(),prof,cont,lvl+1);
	cant_nodos_prof(T,p.right(),prof,cont,lvl);
}
int cant_nodos_prof(btree<int> &A, int prof){
	int cont = 0, lvl=0;
	cant_nodos_prof(A,A.begin(),prof,cont,lvl);
	return cont;
}
int main() {
	
	return 0;
}







