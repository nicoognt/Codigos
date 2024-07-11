#include <iostream>
#include <matrix>
using namespace std;
struct Datos {
	int cant1,cant2,cant3;           /// siendo el orden: soja, trigo, maíz
};

int calculadora(const matrix<Datos> &m,int anio) {
	int aux,suma=0;
	for(size_t i=0;i<m.size(0);i++) { 
		if(m[i][anio-2005].cant1>suma){
			aux=i;
			suma=m[i][anio-2005].cant1;
		}
	}
	return aux+1;
}
int main() {
	matrix<Datos> m(8,10);
	int cont=0,cod,ano,cant;
	string tipo;
	
	while (cont<240) {
		cin>>cod>>ano>>cant>>tipo;
		if(tipo=="soja") {
			m[cod-1][ano-2005].cant1=cant;
		} else if(tipo=="trigo") {
			m[cod-1][ano-2005].cant2=cant;
		} else {
			m[cod-1][ano-2005].cant3=cant;
		}
		cont++;
	}
	
	cout<<"las provincias con menos producción de trigo en 2014 que en 2005 son: "<<endl;
	for(size_t i=0;i<m.size(0);i++) { 
		if(m[i][0].cant2>m[i][9].cant2) {
			cout<<i+1<<endl;
		}
	}
	int ano_x;
	cin>>ano_x;
	int mas_prod = calculadora(m,ano_x);
	cout<<mas_prod;
	int suma=0;
	for(size_t i=0;i<m.size(0);i++) { 
		suma+=m[i][8].cant3;
	}
	cout<<suma;
	return 0;
}

