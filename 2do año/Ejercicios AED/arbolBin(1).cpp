#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
void prefijo(btree<int> &T, btree<int>::iterator p){
	if(p==T.end()) return;
	cout << *p << " ";
	
	prefijo(T,p.left());
	prefijo(T,p.right());
}
void infijo(btree<int> &T,btree<int>::iterator p){
	if(p==T.end()) return;
	
	infijo(T,p.left());
	cout << *p << " ";
	infijo(T,p.right());
}
void postfijo(btree<int> &T, btree<int>::iterator p){
	if(p==T.end()) return;
	
	prefijo(T,p.left());
	prefijo(T,p.right());
	cout << *p << " ";
}

void prefijo(btree<int> &T){
	if(T.begin()==T.end()) return;
	
	prefijo(T,T.begin());
}
void infijo(btree<int> &T){
	infijo(T,T.begin());
}
void postfijo(btree<int> &T){
	postfijo(T,T.begin());
}
int main() {
	
	return 0;
}







