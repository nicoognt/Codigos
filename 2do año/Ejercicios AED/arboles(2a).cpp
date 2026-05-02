#include <iostream>
#include <tree.hpp>

using namespace aed;
using namespace std;
int contarHojas(tree<int> &arbol, tree<int>::iterator p){		if (p == arbol.end()) return 0;	if (p.lchild() == arbol.end()) return 1;
	
	int total = 0;
	auto c = p.lchild();
	
	while(c!=arbol.end()) total += contarHojas(arbol,c++);
	return total;	}
int main() {
	
	return 0;
}







