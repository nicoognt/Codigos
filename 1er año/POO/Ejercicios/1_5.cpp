#include <iostream>
using namespace std;
struct Arreglo {
	int *p;
	int size;
};

void insertar (Arreglo &ar, int posi, int valor){
	++ar.size;
	for(int i=posi;i<ar.size-1;i++){
		*(ar.p+i)=*(ar.p+i+1);
	}
	*(ar.p+posi)=valor;
}

int main() {
	//hago un struct para modificar el tamaño del arreglo
	Arreglo x;
	x.size = 15;
	x.p = new int[x.size];
	for(int i=0;i<15;i++) { 
		*(x.p+i)=0;
	}
	//creo el valor a insertar y en que posicion
	int pos,valor;
	cout<<"Ingrese el valor a insertar y en que posicion: ";
	cin>>valor>>pos;
	//funcion
	insertar(x,pos-1,valor);
	//muestro el nuevo arreglo
	for(int i=0;i<x.size;i++) { 
		cout<<*(x.p+i)<<endl;
	}
	delete[] x.p;
	return 0;
}

/*Escriba un programa que genere un arreglo aleatoriamente, luego permita al usuario ingresar un valor M y una
posicion P, y finalmente inserte el valor M en la posicion P del arreglo. Muestre el arreglo modificado. Nota: Para la
insercion, implemente una funcion insertar(...).*/
