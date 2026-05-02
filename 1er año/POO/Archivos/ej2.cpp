#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumno{
	string nombre;
	int nota1, nota2;
};

string Condicion(const Alumno &x) {
	if ((x.nota1+x.nota2)/2 >= 70) return "Promocionado";
	else if ((x.nota1+x.nota2)/2 > 30) return "Regular";
	else return "Libre";
}

void Modificar(const Alumno &x){
	ifstream archi1("lista.txt");
	if (!archi1.is_open()) throw runtime_error("No se pudo abrir el ifs");
	
	vector<Alumno> v;
	Alumno aux;
	
	while(getline(archi1,aux.nombre) && (archi1>>aux.nota1>>aux.nota2)){
		archi1.ignore();
		v.push_back(aux);
	}
	
	archi1.close();
	
	for(size_t i = 0;i<v.size();i++){
		if (v[i].nombre==x.nombre){
			v[i].nota1 = x.nota1;
			v[i].nota2 = x.nota2;
		}
	}
	
	ofstream ar("lista.txt");
	for (Alumno &a : v){
		ar << a.nombre << "\n" << a.nota1 << " " << a.nota2 << "\n";
	}
	
	ar.close();
}

void Promedios () {
	ifstream archivo("lista.txt");
	if (!archivo.is_open()) throw runtime_error("No se pudo abrir el archivo ifs");
	vector<Alumno> v;
	Alumno aux;
	
	while(getline(archivo,aux.nombre) && (archivo>>aux.nota1>>aux.nota2)){
		archivo.ignore();
		v.push_back(aux);
	}
	archivo.close();
	
	ofstream Proms("promedios.txt");
	if(!Proms.is_open()) throw runtime_error("No se pudo abrir el ofs");
	
	Proms << left << setw(20) << "Nombre: " << setw(10) << "Promedio: " << "Condicion: " << endl;
	
	for(Alumno A : v) { 
		double promedio = (A.nota1+A.nota2)/2;
		Proms << left << setw(20) << A.nombre 
			<< fixed << setprecision(2) << setw(10) << promedio
			<< Condicion(A) << endl;
	}
	Proms.close();
} 


int main() {
	ofstream archi("lista.txt");
	if (!archi.is_open()) throw runtime_error("No se pudo abrir el archivo ofs");
	
	Alumno gral;
	
	cout<<"ingrese apellido y nombre del alumno, y luego sus dos notas (para terminar ingrese nombre x): "<<endl;
	getline(cin,gral.nombre);
	
	while(gral.nombre!="x"){
		cin>>gral.nota1>>gral.nota2;
		archi << gral.nombre << "\n" << gral.nota1 << " " << gral.nota2 << "\n";
		cin.ignore();
		getline(cin,gral.nombre);
	}
	
	archi.close();
	
	Alumno buscado;
	cout<<"Ingrese el nombre del alumno con las notas a modificar: " << endl;
	getline(cin,buscado.nombre);
	cin>>buscado.nota1>>buscado.nota2;
	Modificar(buscado);
	Promedios();
	cout << "La lista con los promedios y condiciones de los alumnos ya está cargada :D";
	
	return 0;
}

