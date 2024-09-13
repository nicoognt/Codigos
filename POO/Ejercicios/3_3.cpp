#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Monomio{
private:
	int coef,exp;
public:
	Monomio(int _coef,int _exp) {coef=_coef;exp=_exp;}
	int Evaluar(int x) const {return coef*pow(x,exp);}
	void MostrarDatos(){cout<<coef<<"x^"<<exp<<" ";}
	int Coeficiente() {return coef;}
};

class Polinomio{
private:
	vector<Monomio> terminos;
	unsigned int grado;
public:
	Polinomio(int _grado) {grado=_grado;}
	void AgregarTerminos(const Monomio &m) {
		if (terminos.size()<=grado){
			terminos.push_back(m);
		}
	}
	int Grado() {return grado;}
	void Mostrar() {
		for(size_t i=0;i<terminos.size();i++) { 
			if (i > 0 && terminos[i].Coeficiente() > 0){
				cout<<"+";
			}
			terminos[i].MostrarDatos();
		}
	}
	int Evaluar(int x) {
		int suma=0;
		for(size_t i=0;i<terminos.size();i++) { 
			suma+=terminos[i].Evaluar(x);
		}
		return suma;
	}
};
int main() {
	cout<<"De que grado sera el polinomio?: ";
	int grado;
	cin>>grado;
	Polinomio p1(grado);
	int coef,exp;
	
	for(int i=0;i<p1.Grado()+1;i++){
		cout<<"Termino de grado "<<p1.Grado()-i<<": ";
		cin>>coef>>exp;
		Monomio aux(coef,exp);
		p1.AgregarTerminos(aux);
	}
	p1.Mostrar();
	int x;
	cout<<"En que valor desea evaluar el polinomio?: ";
	cin>>x;
	cout<<"el resultado es "<<p1.Evaluar(x);
	return 0;
}

//Implemente una clase Monomio para representar un monomio de la forma a*xn a partir de un coeficiente y un
//exponente, con un método Evaluar(...) que reciba un real y retorne el valor del monomio evaluado con ese real, y los
//demás métodos que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la clase Monomio
//para modelar un polinomio, y añada un método Evaluar(...) para evaluar un polinomio en un valor x real dado. ¿Qué
//relación debe haber entre las clases Monomio y Polinomio?
