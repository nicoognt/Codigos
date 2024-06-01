#include <iostream>
#include <vector>
using namespace std;
//Un hospital lleva un registro de los pacientes internados: nombre, DNI, diagn�stico,
//n�mero de habitaci�n. a) Defina un struct paciente con los datos mencionados. b)
//Lea en un arreglo de pacientes los datos de N pacientes. Informe: c) En qu�
//habitaci�n se encuentra internado el paciente "Cosme Fulanito" d) Cu�ntos
//pacientes est�n internados con diagn�stico de "Apendicitis". e) Los datos del
//paciente internado en la habitaci�n 101
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
	cout<<"Diagn�stico: ";
	cin>>x.diagnos;
	pacientes[i].diagnos = x.diagnos;
	cout<<"Habitaci�n: ";
	cin>>x.habitacion;
	pacientes[i].habitacion = x.habitacion;
	aux++;
}

int main() {
	int N;
	cout<<"�Cu�ntos pacientes ser�n ingresados?: ";
	cin>>N;
	vector<paciente> lista(N);
	completar(lista,N);
	
	return 0;
}

