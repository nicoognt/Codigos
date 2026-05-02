#include <iostream>
using namespace std;
class VD{
private:
	int *ptr, cant;
public:
	VD(int _cant);
	VD(const VD &obj);
	~VD();
	void Duplicar();
	size_t VerTamanio();
	int VerElem(int pos);
};

VD::VD(int _cant){
	ptr = new int[_cant];
	for(int i=0;i<_cant;i++) { 
		ptr[i]=rand()%99+1;
	}
	cant = _cant;
}
VD::VD(const VD &obj){
	cant = obj.cant;
	ptr = new int[cant];
	for(int i=0;i<cant;i++) { 
		ptr[i] = obj.ptr[i];
	}
}
VD::~VD(){
	delete[] ptr;
}
	
void VD::Duplicar(){
	int *nuevo = new int[cant*2];
	for(int i=0;i<cant;i++) { 
		nuevo[i]=ptr[i];
	}
	for (int i=cant;i<cant*2;i++){
		nuevo[i] =rand()%50+100;
	}
	cant = cant*2;
	delete[] ptr;
	ptr = nuevo;
}

size_t VD::VerTamanio(){
	return cant;
}

int VD::VerElem(int pos){
	return ptr[pos-1];
}
int main() {
	int tam,pos;
	cout<<"ingrese el tamaño del arreglo: "; cin>>tam;
	VD vec(tam);
	
	size_t tamanio = vec.VerTamanio();
	cout<<"el tamaño del arreglo es "<<tamanio<<endl;
	
	vec.Duplicar();
	
	cout<<"el elem de qué posición desea saber?: "; cin>>pos;
	int elem = vec.VerElem(pos);
	cout<<"el elemento es "<<elem;
	
	return 0;
}

/*Implemente una clase VectorDinamico que posea como atributo un puntero a entero que apunte a la memoria donde
se almacenan los datos. Dicha clase debe poseer:
1. Un constructor que reciba el tamaño inicial del vector, reserve la memoria necesaria e inicialice los valores del
vector de manera aleatoria.
2. Un destructor que se encargue de liberar la memoria reservada.
3. Un método Duplicar(...) que duplique la cantidad de memoria reservada manteniendo los datos que ya
estaban en el vector e inicializando al azar los nuevos valores.
4. Un método VerTamanio() para cosultar el tamaño del vector, y un método VerElemento(...) que reciba el
número de elemento (índice) y devuelva su valor.
5. Cree un programa cliente que muestre la utilización de todas las funciones implementadas.
6. Explique: ¿Es necesario implementar un constructor de copia? ¿Por qué?*/
