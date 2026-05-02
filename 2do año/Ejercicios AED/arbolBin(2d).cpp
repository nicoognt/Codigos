#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
void mirrored(btree<int> &T,btree<int>::iterator nt){
	if(nt==T.end()) return;
	else {
		btree<int> tmp;
		tmp.splice(tmp.begin(),nt.left());
		T.splice(nt.left(),nt.right());
		T.splice(nt.right(),tmp.begin());
		
		mirrored(T,nt.right());
		mirrored(T,nt.left());
	}
}

void mirrored(btree<int> &T){
	mirrored(T,T.begin());
}
int main() {
	
	return 0;
}







