#include <iostream>
#include <vector>
using namespace std;

struct ficha_alumno {
	string nombre_alumno;
	int dni;
	vector<int> calificaciones;
};

ficha_alumno leer_datos(){
	ficha_alumno x;
	cout<<"nombre: ";
	cin>>x.nombre_alumno;
	cout<<"dni: ";
	cin>>x.dni;
	x.calificaciones.resize(32);
	cout<<"notas: "<<endl;
	for(size_t i=0;i<x.calificaciones.size();i++) { 
		cin>>x.calificaciones[i];
	}
	return x;
}

void meter_calif(ficha_alumno &x) {
	x.calificaciones[6] = 8;
	x.calificaciones[11] = 7;
	x.calificaciones[12] = 10;

}
int main() {
 ficha_alumno n1 = leer_datos();	
 ficha_alumno n2 = leer_datos();	
 ficha_alumno n3 = leer_datos();

 meter_calif(n1);
	return 0;
}

