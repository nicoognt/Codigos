#include <iostream>
#include <vector>
using namespace std;
//Un hospital lleva un registro de los pacientes internados: nombre, DNI, diagnóstico,
//número de habitación. a) Defina un struct paciente con los datos mencionados. b)
//Lea en un arreglo de pacientes los datos de N pacientes. Informe: c) En qué
//habitación se encuentra internado el paciente "Cosme Fulanito" d) Cuántos
//pacientes están internados con diagnóstico de "Apendicitis". e) Los datos del
//paciente internado en la habitación 101
struct paciente {
	string nombre;
	int dni;
	long diagnos;
	int habitacion;
};

void completar(vector<paciente> &pac) {
	for(size_t i=0;i<pac.size();i++) { 
		cin>>pac[i].nombre>>pac[i].dni>>pac[i].diagnos>>pac[i].habitacion;
	}
}

int hallar_habitacion(const vector<paciente> a,string nom){
	int auxiliar;
	for (size_t i = 0;i < a.size();i++) {
		if (a[i].nombre == nom) {
			auxiliar = a[i].habitacion;
		}
	}
	return auxiliar;
}
	
int apendicitis(const vector<paciente> b) {
	int cont = 0;
	for(size_t i=0;i<b.size().size();i++) { 
		if (b[i].diagnos == "Apendicitis") {
			cont++;
		}
	}
	return cont;
}
void hab_101(const vector<paciente> c) {
	cout<<c[101].nombre<<endl;
	cout<<c[101].dni<<endl;
	cout<<c[101].diagnos<<endl;
	cout<<c[101].habitacion<<endl;
}
int main() {
	int N;
	cout<<"¿Cuántos pacientes serán ingresados?: ";
	cin>>N;
	vector<paciente> lista(N);
	completar(lista);
	string aux;
	cout<<"¿A qué paciente quiere encontrar?: ";
	cin>>aux;
	int habi = hallar_habitacion(lista,aux);
	cout<<"La habitación de Cosme Fulanito es la "<<habi;
	int apen = apendicitis(lista);
	cout<<"Hay "<<apen<<" pacientes internados con Apendicitis."<<endl;
	hab_101(lista);
	return 0;
}

