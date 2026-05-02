#include <iostream>
using namespace std;
int *buscar(int *puntero_arreglo,int tamano_arreglo,int numeroBuscado){
	
	for(int i=0;i<tamano_arreglo;i++) { 
		if(puntero_arreglo[i]==numeroBuscado){
			return puntero_arreglo+i;
		}
	}
	return nullptr;
}

int main() {
	int tamano;
	cout<<"Tamaño del arreglo: ";
	cin>>tamano;
	int *ptr = new int[tamano];
	for(int i=0;i<tamano;i++) { 
		ptr[i]=i;
	}
	
	int numBuscado;
	cout<<"¿Qué número desea buscar dentro del arreglo?: ";
	cin>>numBuscado;
	
	int *p2 = buscar(ptr,tamano,numBuscado);
	if (p2!=nullptr) {
		int indice=p2-ptr;
		cout<<numBuscado<<" se encuentra en la posicion "<<indice<<". Direccion: "<<p2;
	} else {
		cout<<numBuscado<<" no se encuentra en el arreglo";
	}
	delete[] ptr;
	
	return 0;
}

