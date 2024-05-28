#include <iostream>
#include <matrix>
using namespace std;
void completar_lluvias(matrix<float> &m_lluvias,int precipitacion,int departamento,int mes) {
	m_lluvias[departamento][mes] = precipitacion;
}

float prom(float suma,int cont) {
	return suma / cont;
}

void datos_faltantes(matrix<float> lluvia) {
	float promedio;
	int suma,cont;
	for (size_t i=0;i<lluvia.size(0);i++) {
		suma = 0,cont = 0;
		for (size_t j=0;j<lluvia.size(1);j++) {
			if (lluvia[i][j] != -1) {
				suma += lluvia[i][j];
				cont++;
			}
		}
		promedio = prom(suma,cont);
		for (size_t j=0;j<lluvia.size(1);j++) {
			if (lluvia[i][j] == -1) {
				lluvia[i][j] = promedio;
			}
		}
	}
}

void total_lluvias(matrix<float> &lluvias) {
	float suma;
	for(size_t i=0;i<lluvias.size(0);i++) { 
		suma = 0;
		for(size_t j=0;j<lluvias.size(1)-1;j++) { 
			suma += lluvias[i][j];
		}
		lluvias[i][lluvias.size(1)] = suma;
	}
}

void mostrar(const matrix<float> m_lluv) {
	for(size_t i=0;i<m_lluv.size(0);i++) { 
		for(size_t j=0;j<m_lluv.size(1);j++) { 
			cout<<m_lluv[i][j]<<" ";
		}
		cout << endl;
	} 
}

void full_lluvias(const matrix<float> &llu) {
	for(size_t i=0;i<llu.size(0);i++) { 
		for(size_t j=0;j<llu.size(1);j++) { 
			cout<<llu[i][j]<<" ";
		}
		cout << endl;
	} 
}

void vector_todas(const matrix<float> xd,vector<float> &v_lluvias) {
	for (size_t i=0;i<xd.size(0);i++) {
		v_lluvias[i] = xd[i][xd.size(1)];
	}
	for(size_t i=0;i<v_lluvias.size();i++) { 
		cout<<v_lluvias[i];
	}
}

int main() {
	matrix<float> m_lluvia(5,12,-1);
	vector<float> v_suma_lluvias(5);
	int cont=1,precip,mes,departamento;
	while (cont <= 60) {
		cin>>departamento>>mes>>precip;
		completar_lluvias(m_lluvia,precip,departamento,mes);
		cont++;
	}
	
	datos_faltantes(m_lluvia);
	mostrar(m_lluvia);
	
	m_lluvia.resize(5,m_lluvia.size(1)+1);
	
	total_lluvias(m_lluvia);
	full_lluvias(m_lluvia);
	vector_todas(m_lluvia,v_suma_lluvias);
	
	
	
	return 0;
}

