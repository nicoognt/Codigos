#include <iostream>
using namespace std;

int main() {
	//declaraci�n de variables necesarias
	int N;
	cout<<"�De qu� tama�o ser� el arreglo?: ";
	cin>>N;
	int *ptr = new int[N];
	//valores random
	for(int i=0;i<N;i++) { 
		ptr[i]=rand()%500+1000;
	}
	//b�squeda del mayor
	int valor=0;
	for(int i=0;i<N;i++) { 
		if(ptr[i]>valor) {
			valor=ptr[i];
		}
	}
	//muestro el mayor
	cout<<"El valor es: "<<valor<<" y su direcci�n en la memoria es "<<&valor;
	delete[] ptr;
	return 0;
}

