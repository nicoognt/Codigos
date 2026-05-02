#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;
void maxEt(tree<int> t, tree<int>::iterator p, int &max_et){
	if(*p>max_et && *p%2==0) max_et = *p;
	auto q = p.lchild();
	while(q!=t.end()) maxEt(t,q++,max_et);
}
int maxEt(tree<int> t){
	if(t.begin()==t.end()) throw runtime_error("error con el arbol");
	int max_et;
	if(*t.begin()%2==0) max_et = *t.begin();
	
	maxEt(t,t.begin(),max_et);
	
	return max_et;
}
int main() {
	tree<int> t;
	return 0;
}







