#include <iostream>
using namespace std;

int main() {
	//declaración de variables necesarias
	int N;
	cout<<"¿De qué tamaño será el arreglo?: ";
	cin>>N;
	int *ptr = new int[N];
	//valores random
	for(int i=0;i<N;i++) { 
		ptr[i]=rand()%500+1000;
	}
	//búsqueda del mayor
	int valor=0;
	for(int i=0;i<N;i++) { 
		if(ptr[i]>valor) {
			valor=ptr[i];
		}
	}
	//muestro el mayor
	cout<<"El valor es: "<<valor<<" y su dirección en la memoria es "<<&valor;
	delete[] ptr;
	return 0;
}

