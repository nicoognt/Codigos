#include <iostream>
#include <cmath>
using namespace std;
/**a) Escriba una función llamada espejo que reciba 2 punteros indicando el comienzo y el final
de un arreglo, y genere un nuevo arreglo que sea el doble de largo que el original, y contenga primero
los elementos del arreglo original en el orden original, y luego todos los elementos menos el último, pero
en el orden inverso. Por ejemplo, si el arreglo original contiene {1,2,3,4,5}, el nuevo debe contener
{1,2,3,4,5,4,3,2,1}. b) Escriba una programa cliente que permita al usuario cargar un arreglo de n
elementos (n es dato que ingresa el usuario), y muestre el arreglo que genera la función.**/
int* Espejo(int* inicio,int* fin){
	int tamano=fin-inicio;
	int* nuevo= new int[tamano*2];
	for(int i=0;i<tamano;i++) { 
		nuevo[i]=inicio[i];
	}
	int indice=tamano-2;
	for(int i=tamano;i<(tamano*2)-1;i++){
		nuevo[i]=inicio[indice--];
	}
	return nuevo;
}
int main() {
	cout<<"cuantos elementos ingresará: ";
	int n; cin>>n;
	int* datos = new int[n];
	int* fin = datos+n;
	cout<<"ingrese los valores:"<<endl;
	for(int i=0;i<n;i++) { 
		cin>>datos[i];
	}
	cout<<"arreglo original:"<<endl;
	for(int i=0;i<n;i++) { 
		cout<<datos[i]<<endl;
	}
	int* Nuevo= Espejo(datos,fin);
	int tamano=fin-datos;
	for(int i=0;i<tamano*2;i++) { 
		cout<<Nuevo[i]<<" ";
	}
	
	delete[] Nuevo;
	delete[] datos;
	
	return 0;
}

