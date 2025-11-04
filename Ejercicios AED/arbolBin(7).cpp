#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
bool semejante(btree<int> &T,btree<int>::iterator nt,btree<int> &Q,btree<int>::iterator nq){
	if(nt==T.end() xor nq==Q.end()) return false;
	if(nt==T.end() && nq==Q.end()) return true;
	if(*nt>=*nq) return false;
	
	bool left_match = semejante(T,nt.left(),Q,nq.left()), right_match = semejante(T,nt.right(),Q,nq.right());
	
	return left_match && right_match;
}

bool search_and_check(btree<int> &A,btree<int> &B,btree<int>::iterator nb){
	if(nb==B.end()) return false;
	if(semejante(A,A.begin(),B,nb)) return true;
	
	if(search_and_check(A,B,nb.left())) return true;
	
	return search_and_check(A,B,nb.right());
}

bool contenido(btree<int> &A, btree<int> &B){
	if(A.begin()==A.end()) return true;
	if(B.begin()==B.end()) return false;
	
	return search_and_check(A,B,B.begin());
}
int main() {
	
	return 0;
}







