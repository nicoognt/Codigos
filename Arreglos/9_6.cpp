#include <iostream>
#include <vector>
using namespace std;
void sumar_aporte(vector<int> &aporte,int mes,int monto) {
	aporte[mes] = aporte[mes] + monto;
}

int menor_aporte(vector<int> &aportesillo) {
	int aux = 9999999;
	for(size_t i=0;i<aportesillo.size();i++) { 
		if (aportesillo[i]<aux) {
			aux = i;
		}
	}
	return aux;
}
int main() {
	vector<int> aportes(12,0);
	int monto,dia,mes;
	
	cout<<"qué monto se recibió y en qué fecha: "<<endl;
	cin>>monto;
	while (monto!=0) {
		cin>>dia>>mes;
		sumar_aporte(aportes,mes,monto);
		cin>>monto;
	}
	for(size_t i=0;i<aportes.size();i++) { 
		cout<<aportes[i]<<" ";
	}
	
	int menor = menor_aporte(aportes);
	cout<<"el mes con menor aporte fue el "<<menor<<endl;
	return 0;
}

