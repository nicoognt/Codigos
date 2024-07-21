#include <iostream>
#include <matrix>
using namespace std;
void calculadora(matrix<int> &m){
	//variables necesarias y procedimiento
	int filaPrimera,filaSegunda,contPri=0,contSeg=0;
	for(size_t i=0;i<m.size(0);i++){
		int suma=0;
		for(size_t j=0;j<m.size(1);j++) { 
			suma+=m[i][j];
		}
		if(suma>contPri){
			filaSegunda=filaPrimera;
			contSeg=contPri;
			filaPrimera=i;
			contPri=suma;
		} else if(suma>contSeg){
			filaSegunda=i;
			contSeg=suma;
		}
	}
	
	for(size_t i=0;i<m.size(1);i++) { 
		m[0][i] = m[filaPrimera][i];
		m[1][i] = m[filaSegunda][i];
	}
}
int main() {
	matrix<int> m(4,4);
	//ingreso de datos
	for(int i=0;i<4;i++) { 
		for(int j=0;j<4;j++) { 
			cin>>m[i][j];
		}
	}
	
	return 0;
}

