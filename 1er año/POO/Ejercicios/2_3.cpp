#include <iostream>
#include <cmath>
using namespace std;
class poli {
private: 
	int grado;
	int *coef;
public:
	poli(int _grado);
	void cambiarCoe(int nuevoCoe, int g);
	float evaluar(int x);
	void mostrar();
	~poli();
};

poli::poli(int _grado){
	grado = _grado;
	coef = new int[_grado];
	for (int i=0;i<_grado;i++){
		coef[i]=0;
	}
}
poli::~poli(){
	delete[] coef;
}

void poli::cambiarCoe(int nuevoCoe,int g){
	coef[g] = nuevoCoe;
}

float poli::evaluar(int x){
	float suma=0;
	for (int i=0;i<grado;i++){
		suma+=coef[i]*pow(x,grado-i);
	}
	suma+=coef[grado];
	return suma;
}
void poli::mostrar(){
	for (int i=0;i<grado;i++){
		if (coef[i]!=0) {
			if (coef[i]>0 && i!=0){
				cout<<"+"<<coef[i]<<"x^"<<grado-i;
			} else {
				cout<<coef[i]<<"x^"<<grado-i;
			}
		} else {
			continue;
		}
	}
	if (coef[grado]>0){
		cout<<"+"<<coef[grado];
	} else {
		cout<<coef[grado];
	}
}
int main() {
	int gra;
	cout<<"de qué grado es el polinomio?: ";
	cin>>gra;
	poli pol1(gra);
	for(int i=0;i<gra+1;i++) { 
		int co;
		cout<<"coef de grado "<<gra-i<<": ";
		cin>>co;
		pol1.cambiarCoe(co,i);
	}
	pol1.mostrar();
	cout<<"\n";
	int x;
	cout<<"en qué valor desea evaluar el polinomio?: ";
	cin>>x;
	float resultado = pol1.evaluar(x);
	cout<<"el resultado es "<<resultado;
	return 0;
}

