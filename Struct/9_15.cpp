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
	string diagnos;
	int habitacion;
};

void completar(vector<paciente> &pacientes,int N);
paciente x;
int aux = 1;
for (size_t i = 0;i<pacientes.size();i++) {
	cout<<"Nombre: ";
	cin>>x.nombre;
	pacientes[i].nombre = x.nombre;
	cout<<"DNI: ";
	cin>>x.dni;
	pacientes[i].dni = x.dni;
	cout<<"Diagnóstico: ";
	cin>>x.diagnos;
	pacientes[i].diagnos = x.diagnos;
	cout<<"Habitación: ";
	cin>>x.habitacion;
	pacientes[i].habitacion = x.habitacion;
	aux++;
}

int main() {
	int N;
	cout<<"¿Cuántos pacientes serán ingresados?: ";
	cin>>N;
	vector<paciente> lista(N);
	completar(lista,N);
	
	return 0;
}

