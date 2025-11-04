#include <iostream>
using namespace std;
void a(tree<int> &T, tree<int>::iterator p, int nivel, int &nivel_maximo){	if(nivel > nivel_maximo) nivel_maximo = nivel;			auto c = p.lchild();		while(c != T.end()) a(T, c++, nivel+1, nivel_maximo);}	int a(tree<int> &T){	if(T.begin() == T.end()) return -1;	int nivel = 0;	int nivel_maximo = 0;	a(T, T.begin(), nivel, nivel_maximo);		return nivel_maximo;}
int main() {
	
	return 0;
}







