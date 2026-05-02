#include <iostream>
#include <tree.hpp>
#include <list>
#include 
using namespace aed;
using namespace std;
void prefijo(tree<int> &T, tree<int>::iterator p, list<int> &L){
	if(p == T.end()) return;
	L.push_back(*p);
	
	tree<int>::iterator c = p.lchild();
	while(c!=T.end()) prefijo(T,c++,L);
}
int main() {
	
	return 0;
}







