#include <iostream>
#include <vector>
#include <matrix>
using namespace std;
void agrandar(matrix<int> &m) {
	m.resize(m.size(0)+1,m.size(1));
	for(size_t i=0;i<m.size(1);i++) { 
		int suma=0;
		for(size_t j=0;j<m.size(0)-2;j++) { 
			suma+=m[j][i];
		}
		m[m.size(0)-1][i]=suma;
	}
}

int main() {
	vector<string> desc(30);
	matrix<int> ventas(10,30);
	int c_prod,c_ver,uni;
	for(int i=0;i<10*30;i++) { 
		cin>>c_prod>>c_ver>>uni;
		ventas[c_ver-1][c_prod-1]=uni;
	}
	agrandar(ventas);
	int aux,cant=0;
	for(int i=0;i<30;i++) { 
		if(ventas[4][i]>cant){
			cant=ventas[4][i];
			aux=i;
		}
	}
	cout<<"el producto con más ventas de la verdulería 5 es: "<<desc[aux]<<endl;
	cout<<"se vendieron "<<ventas[4][2]<<" unidades del producto 3 en la verdulería 5";
	return 0;
}

