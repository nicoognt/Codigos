#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;
void maxLeafEt(tree<int> t, tree<int>::iterator p, int &maxLeaf){
	if(p.lchild()==t.end()) maxLeaf = *p;
	auto q = p.lchild();
	while(q!=t.end()) maxLeafEt(t,q++,maxLeaf);
}
int maxLeafEt(tree<int> t){
	if(t.begin()==t.end()) throw runtime_error("error con el arbol");
	int maxLeaf;
	if(t.begin().lchild() == t.end()) maxLeaf = *t.begin();
	
	maxLeafEt(t,t.begin(),maxLeaf);
	return maxLeaf;
}
int main() {
	tree<int> t;
	return 0;
}








