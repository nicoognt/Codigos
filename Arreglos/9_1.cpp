#include <iostream>
#include <vector>
using namespace std;

float prom(const vector<float> notas) {
	float promedio = 0;
	for(size_t i=0;i<notas.size();i++) { 
		promedio = promedio + notas[i];
	}
	return promedio/notas.size();
}

int main() {
	vector<float> notas(5);
	cout<<"ingrese las notas: "<<endl;
	
	for(size_t i=0;i<notas.size();i++) { 
		cin>>notas[i];
	}
	
	float promedio = prom(notas);
	cout<<"el promedio es "<<promedio<<endl;
	cout<<"las notas que superan el promedio son: "<<endl;
	for(size_t i=0;i<notas.size();i++) { 
		if (notas[i]>promedio) {
			cout<<notas[i]<<endl;
		}
	}
	
	
	return 0;
}

