#include <iostream>
#include <vector>
using namespace std;
class Persona {
private:
	string nombre;
	int dia,mes,ano;
public:
	Persona(string _nom,int _dia,int _mes,int _ano) {nombre=_nom;dia=_dia;mes=_mes;ano=_ano;}
	int Edad(int dA,int mA,int anoA) const {return anoA-ano;}
	string Nombre() {return nombre;}
};

class Alumno : public Persona{
private:
	float promedio;
	int matsApro;
public:
	Alumno(float pro,int MA,string _nom,int _dia,int _mes,int _ano) : Persona(_nom,_dia,_mes,_ano){promedio=pro;matsApro=MA;}
	void agregarMateria(float nota){promedio=(matsApro*promedio+nota)/(matsApro+1);matsApro++;}
	float Merito() const {return promedio*matsApro;}
	float verProm() {return promedio;}
	int cuantasMaterias() const {return matsApro;}
};

class Docente : public Persona{
private:
	int diaI,mesI,anoI;
public:
	Docente(int dia,int mes,int ano,string _nom,int _dia,int _mes,int _ano) : Persona(_nom,_dia,_mes,_ano){diaI=dia;mesI=mes;anoI=ano;}
	int Antiguedad(int d,int m,int a) {return a-anoI;}
};

class Curso{
private:
	string nombre;
	Docente Profe;
	vector<Alumno> alumnos;
	int cantMax;
public:
	Curso(string nom,const Docente &a,int maximo) : nombre(nom), Profe(a),cantMax(maximo) {}
	void agregarAlumno(const Alumno &nuevo){alumnos.push_back(nuevo);}
	int verCuantosHay(){return alumnos.size();}
	int verMax() {return cantMax;}
	Alumno MejorPromedio(){
		float mejor=0;
		Alumno aux(0,0,"a",1,2,3);
		for(size_t i=0;i<alumnos.size();i++){
			if (alumnos[i].verProm()>mejor){
				mejor=alumnos[i].verProm();
				aux=alumnos[i];
			}
		}
		return aux;
	}
	
};
int main() {
	Docente p(1,1,1,"Cesar Castillo",2,2,2);
	Curso curso1("Matematica",p,5);
	while(curso1.verCuantosHay()<curso1.verMax()){
		if(curso1.verCuantosHay()<curso1.verMax()){
			string nomAlu;
			int diaAlu,mesAlu,anoAlu,matsAlu;
			float promAlu;
			getline(cin,nomAlu);
			cin.ignore();
			cin>>diaAlu>>mesAlu>>anoAlu>>matsAlu>>promAlu;
			Alumno alu(promAlu,matsAlu,nomAlu,diaAlu,mesAlu,anoAlu);
			curso1.agregarAlumno(alu);
			string rta;
			cout<<"¿desea agregar otro alumno (s/n)?: ";
			cin>>rta;
			if (rta!="s"){
				break;
			}
		} else {
			cout<<"No se puede agregar más alumnos, se alcanzó el cupo máximo"<<endl;
		}
	}

	return 0;
}
