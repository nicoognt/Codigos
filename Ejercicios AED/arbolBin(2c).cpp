#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
bool equality(btree<int> &T,btree<int>::iterator nt,btree<int> &Q,btree<int>::iterator nq){
	if(nt==T.end() xor nq==Q.end()) return false;
	if(nt==T.end() && nq==Q.end()) return true;
	if(*nt != *nq) return false;
	
	bool left_branch = equality(T,nt.left(),Q,nq.left());
	bool right_branch = equality(T,nt.right(),Q,nq.right());
	
	return left_branch && right_branch;
}

bool equality(btree<int> &T, btree<int> &Q){
	return equality(T,T.begin(),Q,Q.begin());
}
int main() {
	
	return 0;
}







