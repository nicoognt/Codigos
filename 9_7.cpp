#include <iostream>
#include <matrix>
#include <vector>
using namespace std;

void terna_puntaje(matrix<float> &comp) {
	int alumno,prueba;
	float puntaje;
	for (size_t i=0;i<comp.size(1)*3;i++) {
		cout<<"ingrese el código del alumno, de prueba y su puntaje: ";
		cin>>alumno>>prueba>>puntaje;
		comp[prueba][alumno] = puntaje;
	}	
}
void ganador_segundo(const matrix<float> &m_puntajes,const vector<int> &v_dni) {
	float puntaje_max = 0,total = 0,puntaje_segundo = 0;
	int ganador,segundo;
	for(int i=0;i<m_puntajes(1);i++) {
		total = m_puntajes[0][i]+m_puntajes[1][i]+m_puntajes[2][i];
		if (total>puntaje_max) {
			puntaje_segundo = puntaje_max;
			segundo = ganador;
			puntaje_max = aux;
			ganador = i;
		} else if (total>puntaje_segundo) {
			puntaje_segundo = total;
			segundo = i;
		}
	}
	cout<<"el ganador es "<<v_dni[ganador]<<" con un puntaje de "<<puntaje_max<<". Su nota en computación fue "<<m_puntajes[3][ganador]<<endl;
	
}
void num_dni(vector<int> &v_dni) {
	for(size_t i=0;i<v_dni.size();i++) { 
		cout<<"ingrese el dni del inscripto N° "<<i+1<<": ";
		cin>>v_dni[i];
	}
}
	
int main() {
	int N,alumno,prueba,ganador;
	float puntaje,puntaje_max;
	cin>>N;
	vector<int> v_dni(N);
	matrix<float> m_competencia(3,N);
	
	num_dni(dni);
	terna_puntaje(competencia);
	ganador_competencia(m_competencia,v_dni);
	
	return 0;
}

