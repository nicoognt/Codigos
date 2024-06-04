#include <iostream>
#include <vector>
using namespace std;
//Escriba una función buscar que reciba un vector de strings v, un string s, y una posición p. La función
//debe buscar el valor s en el vector v, solo desde la posición p en adelante, y retornar la primera posición donde lo
//encuentre, o -1 en caso de no encontrarlo. b) Utilizando la función buscar, escriba una función reemplazar que
//reciba un vector de strings, y dos strings s1 y s2. La función debe reemplazar todas las ocurrencias de s1 en el
//vector por s2; y retornar la cantidad de reemplazos realizados.

int buscar(vector<string> v,string s,int p) {
	int aux;
	bool lo_encontre = false;
	for(size_t i=p;i<v.size();i++) { 
		if (v[i] == s and lo_encontre == false) {
			aux = i;
			lo_encontre = true;
		} else
			aux = -1;
	}
	return aux+1;
}
int reemplazar(vector<string> &a,string s1,string s2) {
	int cont = 0;
	for(int i=0;i<a.size();i++) { 
		if (a[i] == s1) {
			a[i] = s2;
			cont++;
		}
	}
	return cont;
}


int main() {
	
	return 0;
}

