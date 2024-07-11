#include <iostream>
using namespace std;

class Humano{
private:      //atributos
	string sexo,nombre;
	float altura,peso;
public:       //metodos
	Humano(string,string,float,float);         /// Constructor de objetos
	~Humano();                                 /// Destructor de objetos
	void mostrarDatos();
	void noPuedo();
};

Humano::Humano(string _sexo,string _nombre,float _altura,float _peso){
	sexo = _sexo;
	nombre = _nombre;
	altura = _altura;
	peso = _peso;
}

Humano::~Humano(){
}

void Humano::mostrarDatos(){
	cout<<"Hola, soy "<<nombre<<", mido "<<altura<< " m y peso "<<peso<<" kg"<<endl;
}
void Humano::noPuedo(){
	if (sexo=="Femenino" or sexo=="F"){
		cout<<"Soy "<<nombre<<" y no puedo generar mucha testosterona"<<endl;
	} else {
		cout<<"Soy "<<nombre<<" y no puedo generar estrógeno"<<endl;
	}
}

int main() {
	Humano h1("F","Maria",1.75,68);
	Humano h2("M","Pedro",1.80,70);
	h1.mostrarDatos();
	h2.mostrarDatos();
	h1.noPuedo();
	h2.noPuedo();
	
	return 0;
}

