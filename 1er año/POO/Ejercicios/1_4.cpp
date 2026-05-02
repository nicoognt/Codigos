#include <iostream>
using namespace std;
struct Arreglo {
	int *p;
	int size;
};
void redimensionar(Arreglo &x,int tamano_nuevo){
	Arreglo nuevo;
	nuevo.size = tamano_nuevo;
	nuevo.p = new int[tamano_nuevo];
	
	for(int i=0;i<x.size;i++) { 
		*(nuevo.p+i) = *(x.p+i);
	}
	for (int i=x.size;i<nuevo.size;i++) {
		*(nuevo.p+i) = 0;
	}
	
	x = nuevo;
}

int main() {
	int n;
	cout<<"Ingrese el tamaño del arreglo: ";
	cin>>n;
	
	Arreglo x1;
	x1.p = new int[n];
	x1.size = n;
	for(int i=0;i<x1.size;i++) { 
		*(x1.p+i) = rand()%100+100;
		cout<<*(x1.p+i)<<endl;
	}
	
	int c;
	cout<<"Tamaño nuevo: ";
	cin>>c;
	
	redimensionar(x1,c);
	
	for(int i=0;i<x1.size;i++) { 
		cout<<*(x1.p+i)<<endl;
	}
	
	delete[] x1.p;
	return 0;
}

