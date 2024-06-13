#include <iostream>
#include <vector>
using namespace std;
/// Se ingresan 200 valores num�ricos provenientes de un sensor de presi�n. Debido a fallas de comunicaci�n, se ingresaron
/// algunos valores negativos. Realice un programa que reemplace todos los valores negativos por el promedio 
/// entre el m�ximo y m�nimo valor lista (tenga en cuenta de no considerar los valores
/// negativos en la obtenci�n del menor). Muestre el arreglo modificado y informe cu�ntos reemplazos hizo.

int main() {
	vector<float> v(200);
	float max=0, min=999;
	for(size_t i=0;i<v.size();i++) {
		if (v[i]<0) {
			continue;
		} else if (v[i]>max) {
			max=v[i];
		}
		if (v[i]<min) {
			min=v[i];
		}
	}
	float prom=(max+min)/2;
	int cont=0;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i]<0) {
			v[i]=prom;
			cont++;
		}
	}
	cout<<"Se hicieron "<<cont<<" reemplazos. El vector corregido es el siguiente: "<<endl;
	for(size_t i=0;i<v.size();i++) { 
		cout<<v[i];
	}
	return 0;
}

