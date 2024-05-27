#include <iostream>
#include <vector>
using namespace std;

void aprobado_o_no(vector<string> &aprob, vector<string> &desap,float nota, string &nom) {
	if (nota>=6) {
		aprob.push_back(nom);
	} else {
		desap.push_back(nom);
	}
}

int main() {
	vector<string> aprobados;
	vector<string> desaprobados;
	
	float N;
	string nombre;
	
	cout<<"escriba la nota del alumno y luego su nombre (finalice la carga con la nota 0): "<<endl;
	cin>>N;
	while (N!=0) {
		cin>>nombre;
		aprobado_o_no(aprobados,desaprobados,N,nombre);
		cin>>N;
	}
	
	cout<<"los alumnos que apobaron son: "<<endl;
	for(size_t i=0;i<aprobados.size();i++) { 
		cout<<aprobados[i]<<" ";
	} cout << endl;
	cout<<"y los que desaprobaron: "<<endl;
	for(size_t i=0;i<desaprobados.size();i++) { 
		cout<<desaprobados[i]<<" ";
	}
	return 0;
}

