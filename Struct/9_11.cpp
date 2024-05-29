#include <iostream>
#include <vector>
using namespace std;

struct ficha_alumno {
	string nombre_alumno;
	int dni;
	vector<int> calificaciones;
};
 void leer_datos(ficha_alumno){
	ficha_alumno x;
	cout<<"nombre: ";
	cin>>nombre_alumno;
	cout<<"dni: ";
	cin>>dni;
	for(size_t i=0;i<cal.size();i++) { 
		cin>>cal[i];
	}
 }

int main() {
 ficha_alumno n1;	
 ficha_alumno n2;	
 ficha_alumno n3;
 
 leer_datos(ficha_alumno);
	
	return 0;
}

