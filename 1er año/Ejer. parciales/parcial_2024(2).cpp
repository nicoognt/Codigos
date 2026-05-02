#include <iostream>
#include <matrix>
#include <vector>
using namespace std;
struct Gastos {
	float restante;
	float gasto;
};

void gasto_mitad(const matrix<Gastos> &b, const vector<float> &v_ini) {
	for(size_t i=0;i<b.size(0);i++) { 
		if ((b[i][7].restante/v_ini[i])*100 == 50) {
			cout<<i;
		}
	}
}

void gasto_mas(const matrix<Gastos> &c) {
	for (size_t i=0;i<c.size(0);i++) {
		for(size_t j=0;j<c.size(1);j++) { 
			if (c[i][j].restante < 0) 
				cout<<i<<endl;
		}
	}
}

int main() {
	int cod_proy, fecha;
	float gastado;
	vector<float> monto(10);
	matrix<Gastos> lista(10,12);
	
	cin>>cod_proy;
	while (cod_proy!=0) {
		cin>>fecha;
		int mes=fecha/100-1;
		cin>>gastado;
		lista[cod_proy-1][mes].gasto+=gastado;
		lista[cod_proy-1][mes].restante=monto[cod_proy-1]-lista[cod_proy-1][mes].gasto;
		cin>>cod_proy;
	}
	cout<<"Los proyectos que utilizaron el 50% de la suma fueron: "<<endl;
	gasto_mitad(lista,monto);
	
	cout<<"Los proyectos que gastaron por arriba del monto que recibieron a principios de año son: "<<endl;
	gasto_mas(lista);
	return 0;
}

