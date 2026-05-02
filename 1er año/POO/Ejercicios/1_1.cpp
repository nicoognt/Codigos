#include <iostream>
using namespace std;

int main() {
	//declaración de las variables
	int x=10;
	int *ptr = new int;
	
	cout<<"Ingrese un valor entero: "; cin>>*ptr;
	
	//muestro los valores que me piden
	cout<<"Valor de x/dir. de memoria: "<<x<<"/"<<&x<<"\n";
	cout<<"Valor de ptr/dir. de memoria: "<<*ptr<<"/"<<ptr<<"\n";
	delete ptr;
	return 0;
}

