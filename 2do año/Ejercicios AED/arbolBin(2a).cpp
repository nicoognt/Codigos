#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
bool semejante(btree<int> &T,btree<int>::iterator nt,btree<int> &Q,btree<int>::iterator nq){
	if(nt==T.end() xor nq==Q.end()) return false;
	if(nt==T.end() && nq==Q.end()) return true;
	
	bool left_match = semejante(T,nt.left(),Q,nq.left()), right_match = semejante(T,nt.right(),Q,nq.right());
	
	return left_match && right_match;
}

bool semejante(btree<int> &T, btree<int> &Q){
	return semejante(T,T.begin(),Q,Q.begin());
}
int main() {
	
	return 0;
}







