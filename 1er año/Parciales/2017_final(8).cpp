#include <iostream>
using namespace std;
void calculadora(vector<float> &v,const matrix<float> &m) {
	for(size_t i=0;i<m.size(0);i++) { 
		int cont=0;
		for(size_t j=0;j<m.size(1);j++) { 
			if(m[i][j]>cont){
				cont=m[i][j];
			}
		}
		v[i]=cont;
	}
}
int main() {
	
	return 0;
}

