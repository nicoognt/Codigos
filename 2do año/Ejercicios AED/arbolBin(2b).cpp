#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
bool mirror_sem(btree<int> &T,btree<int>::iterator nt,btree<int> &Q,btree<int>::iterator nq){
	if(nt==T.end() xor nq==Q.end()) return false;
	if(nt==T.end() && nq==Q.end()) return true;
	
	bool left_vs_right = mirror_sem(T,nt.left(),Q,nq.right());
	bool right_vs_left = mirror_sem(T,nt.right(),Q,nq.left());
	
	return left_vs_right && right_vs_left;
}

bool mirror_sem(btree<int> &T, btree<int> &Q){
	return mirror_sem(T,T.begin(),Q,Q.begin());
}
int main() {
	
	return 0;
}







