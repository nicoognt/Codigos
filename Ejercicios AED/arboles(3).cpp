#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;
void lvlEt(tree<int> t, tree<int>::iterator p, int current_lvl, int target_lvl, int &cont){
	if(p==t.end()) return;
	if(current_lvl  == target_lvl) {
		cont++;
		return;
	}
	if(current_lvl > target_lvl) return;
	
	lvlEt(t,p.lchild(),current_lvl+1,target_lvl,cont);
	lvlEt(t,p.right(),current_lvl,target_lvl,cont);
}
int lvlEt(tree<int> t, int l){
	if(l==0) return 1;
	int cont = 0;
	
	lvlEt(t, t.begin(), 0, l, cont);
	return cont;
}
int main() {
	tree<int> t;
	return 0;
}







