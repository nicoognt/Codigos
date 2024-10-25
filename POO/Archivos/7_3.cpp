#include <iostream>
using namespace std;
/*Programe una clase templatizada llamada VectorDinamico (similar a la de la guía 2). La clase debe poseer:
1. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
2. Un destructor que se encargue de liberar la memoria reservada.
3. Una sobrecarga del operador [] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
4. Modifique o sobrecargue el constructor para que permita generar valores aleatorios con los cuales inicializar
las posiciones del arreglo que reserva.
5. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int, double,
string, etc).*/
template<typename T>
class VectorDinamico {
private:
	T* ptr;
	int tamano;
public:
	VectorDinamico(int tam){
		ptr = new T[tam];
		tamano = tam;
		for(int i=0;i<tamano;i++) { 
			ptr[i] = rand()%100;
		}
	}
	~VectorDinamico() {
		delete[] ptr;
	}
	T operator[](int index) const {
		return ptr[index-1];
	}
	T& operator[] (int index) {
		return ptr[index-1];
	}
};
int main() {
	
	return 0;
}

