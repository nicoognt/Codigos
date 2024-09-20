#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Instrumento {
private:
	string nombre;
public:
	Instrumento(string _nombre) : nombre(_nombre) {}
	string VerNombre() {return nombre;}
	virtual string Sonido() const = 0;
	virtual ~Instrumento() {}
};

class Tecla{
private:
	string nombre;
	bool apretada;
public:
	Tecla(string _nombre) : nombre(_nombre) {}
	string VerNota() {return nombre;}
	void Apretar() {apretada=true;}
	void Soltar() {apretada=false;}
	bool EstaApretada() {return apretada;}
};
class Pedal{
private:
	float presion;
public:
	Pedal() {presion=0;}
	void setPresion(float _presion) {presion=_presion;}
	float getPresion() {return presion;}
};
class Piano : public Instrumento{
private:
	vector<Tecla*> notas;
	Pedal _ped;
public:
	Piano(string _nombre) : Instrumento(_nombre), _ped() {}
	void IngresarNotas(string _nombre) {
		Tecla *tec = new Tecla(_nombre);
		notas.push_back(tec);
	}
	string Sonido() const override {
		stringstream ss;
		for(size_t i=0;i<notas.size();i++) { 
			if(notas[i]->EstaApretada()){
				ss<<notas[i]->VerNota()<<" ";
			}
		}
		return ss.str();
	}
	string ApretarT(string nom,int i) {
		notas[i]->Apretar();
		return notas[i]->VerNota();
	}
	void SoltarT(string nom,int i) {
		notas[i]->Soltar();
	}
	float PresionarPedal(float _presion) {
		_ped.setPresion(_presion);
		return _ped.getPresion();
	}
	~Piano() {
		for (Tecla *t : notas){
			delete t;
		}
	}
};
int main() {
	
	return 0;
}

// Defina una clase Tecla para representar una tecla de un piano. Cada tecla puede estar o no apretada, y tiene
// además una nota asociada (cuyo nombre se representará con un string). Su interfaz debe tener tener entonces:
// un constructor que reciba el nombre de la nota
// un método VerNota que retorne el nombre de la nota
// un método Apretar que cambie el estado de la tecla a apretada.
// un método Soltar que cambie el estado de la tecla a no apretada.
// un método EstaApretada que retorne true si la tecla está apretada, false en caso contrario
// Defina una clase Pedal para representar el pedal de un piano. El pedal debe almacenar un valor (float) que
// indique la presión que el músico ejerce sobre el pedal. El constructor debe inicializar la presión en 0, y la clase debe
// tener métodos para modificarla y consultarla.

// Reutilizando las clases Tecla, Pedal e Instrumento defina una clase Piano que modele un instrumento de tipo ”piano”
// con solo 7 teclas (“do”, “re”, “mi”, “fa”, “sol”, “la” y “si”) y 1 pedal. La clase piano debe tener métodos para:
//	• apretar una tecla, indicando el número de tecla, y que retorne la nota que debería sonar.
//	• soltar una tecla, indicando el número de tecla
//	• presionar el pedal, indicando la presión que se aplica
// Nota: el método Sonido de Instrumento debe retornar el sonido que haría el instrumento en su estado actual. En el
// piano, será la suma de las teclas que estén apretadas.
