#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;
void totalEt(tree<int> t, tree<int>::iterator p, int &total){
	total += *p;
	auto q = p.lchild();
	while(q!=t.end()) totalEt(t,q++,total);
}
int totalEt(tree<int> t){
	if(t.begin() == t.end()) throw runtime_error("error con el arbol");
	int total=0;
	total += *t.begin();
	
	totalEt(t, t.begin().lchild(), total);
	return total;
}
int main() {
	tree<int> t;
	return 0;
}







