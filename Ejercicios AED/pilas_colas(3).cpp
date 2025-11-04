#include <iostream>
using namespace std;
bool chequeo(stack<char> &S){
	if(S.empty()) abort();
	
	int cont1 = 0, cont2 = 0;
	
	while(!S.empty()){
		
		if(S.top()=='(') cont1++;
		
		if (cont1 < cont2){
			return false;
		}
		
		if(S.top()==')') cont2++;
		
		S.pop();
	}
	
	if (cont1==cont2) {
		return true;
	} else {
		return false;
	}
}
int main() {
	
	return 0;
}







