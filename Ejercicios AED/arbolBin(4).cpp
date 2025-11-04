#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;
void bin2ord(btree<int> &B,btree<int>::iterator nb,tree<int> &T,tree<int>::iterator nt){
	if(nb==B.end()) return;
	if(nb.left()==B.end() xor nb.right()==B.end()){
		nt = T.insert(nt,-1);
	} else if(nb.left()!=B.end() && nb.right()!=B.end()){
		nt = T.insert(nt,*nb);
	}
	
	bin2ord(B,nb.left(),T,nt.lchild());
	bin2ord(B,nb.right(),T,nt.lchild().right());
}

void bin2ord(btree<int> &B, tree<int> &T){
	bin2ord(B,B.begin(),T,T.begin());
}
int main() {
	
	return 0;
}







