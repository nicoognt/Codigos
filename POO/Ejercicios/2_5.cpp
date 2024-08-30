#include <iostream>
#include <vector>
using namespace std;
struct Alumno{
	string Nombre;
	float Nota;
};
class Curso{
private:
	string asig;
	int tamano;
	vector<Alumno> lista;
public:
	Curso(string _asig,int _tamano);
	~Curso();
	void LlenarLista(string _Nombre, float _Nota, int posi);
	void Meter(string nuevoNom, float nuevaNota);
	void Modificar(string nomBuscar, float nota);
	void MostrarCurso();
	float Promedio();
	Alumno Mejor();
};
Curso::Curso(string _asig, int _tamano){
	tamano = _tamano;
	asig = _asig;
	lista.resize(tamano);
}
Curso::~Curso(){
}
void Curso::LlenarLista(string _Nombre, float _Nota, int pos){
	lista[pos] = {_Nombre,_Nota};
}
void Curso::Meter(string nuevoNom, float nuevaNota){
	for (size_t i=0;i<lista.size();i++){
		if (lista[i].Nombre<=nuevoNom){
			lista.resize(lista.size()+1);
			for (size_t j=lista.size()-2;j>i;j--){
				lista[i+1]=lista[i];
			}
			lista[i] = {nuevoNom,nuevaNota};
		}
	}
}

void Curso::Modificar(string nomBuscar, float nota){
	for(int i=0;i<tamano;i++) { 
		if (lista[i].Nombre==nomBuscar){
			lista[i].Nota = nota;
		}
	}
}

void Curso::MostrarCurso(){
	for(int i=0;i<tamano;i++) { 
		cout<<"Alumno: "<<lista[i].Nombre<<"/Nota: "<<lista[i].Nota<<endl;
	}
}

float Curso::Promedio(){
	float prom = 0;
	for(int i=0;i<tamano;i++) { 
		prom+=lista[i].Nota;
	}
	return prom/tamano;
}

Alumno Curso::Mejor(){
	Alumno a = {"a", 0};
	for(int i=0;i<tamano;i++) { 
		if (lista[i].Nota>a.Nota){
			a = lista[i];
		}
	}
	return a;
}
int main() {
	int als;
	cout<<"cuantos alum son?: "; cin>>als;
	Curso sexto("algebra",als);
	
	for(int i=0;i<als;i++) { 
		string Nom;
		float nota;
		cout<<"escriba el nombre y la nota del alum: ";
		cin>>Nom>>nota;
		sexto.LlenarLista(Nom,nota,i);
		cout<<endl;
	}
	
	string Alunuevo;
	float Notanueva;
	cout<<"ingrese el nombre del nuevo alumno y su nota: "; cin>>Alunuevo>>Notanueva;
	sexto.Meter(Alunuevo,Notanueva);
	
	bool rta;
	cout<<"quiere modificar la nota de algun alumno?: "; cin>>rta;
	if (rta){
		string nom;
		float _nota;
		cout<<"ingrese el nombre del alumno y su nueva nota: "; cin>>nom>>_nota;
		sexto.Modificar(nom,_nota);
	} else {
		cout<<"oka, seguimos con lo otro"<<endl;
	}
	
	sexto.MostrarCurso();
	
	float promedio = sexto.Promedio();
	cout<<"el promedio del curso es :"<<promedio<<endl;
	
	Alumno Mejor = sexto.Mejor();
	cout<<"El nombre del mejor alumno es "<<Mejor.Nombre<<". Su nota es "<<Mejor.Nota;
	return 0;
}

/*En base al mismo se desea crear una clase Curso para modelar el cursado de una materia. La clase deberá contener
el nombre de la materia y la cantidad de alumnos en el curso junto con una lista de los mismos. Proponga los
siguientes métodos:
1. Constructores y destructor según lo considere conveniente.
2. Un método que permita agregar un alumno recibiendo su nombre.
3. Un método que permita modificar la nota de un alumno (buscándolo por su nombre).
4. Métodos para poder consultar estos datos.
5. Un método que determine el promedio del curso.
6. Un método para obtener la calificación más alta y el nombre del alumno que la obtuvo*/
