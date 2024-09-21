#include <iostream>
using namespace std;
/**Escriba una función que reciba 2 punteros indicando el comienzo y el final de un arreglo, y
un entero m. La función debe generar un nuevo arreglo que contenga m veces cada elemento del
arreglo original. Por ej, si el arreglo original es {2,4,6,8} y m=3, entonces el arreglo generado debe ser
{2,2,2,4,4,4,6,6,6,8,8,8} (se repite 3 veces cada uno). Escriba una programa cliente que permita al
usuario cargar un arreglo de n elementos (n es dato que ingresa el usuario), y muestre los arreglos que
genera la función para cada valor de m desde 2 hasta 5 (incluido)**/
int* Generar(int* pri,int* seg,int m){
	int tamano=seg-pri;
	int* nuevo = new int[tamano*m];
	
	int indice=0;
	for(int i=0;i<tamano;++i) { 
		for(int j=0;j<m;j++) { 
			nuevo[indice++]= pri[i];
		}
	}
	return nuevo;
}
int main() {
	
	return 0;
}

