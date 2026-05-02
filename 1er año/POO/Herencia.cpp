#include <iostream>
using namespace std;

class Persona{
private:
	string nombre;
	int dni,edad;
public:
	Persona(string,int,int);
	void mostrarDatos();
};
class Corredor:public Persona{
private:
	int kms;
public:
	Corredor(string,int,int,int);
	void mostrarKMS();
};

Persona::Persona(string _nombre,int _dni,int _edad){
	nombre = _nombre;
	dni = _dni;
	edad = _edad;
}
Corredor::Corredor(string _nombre,int _dni,int _edad,int _kms) : Persona(_nombre,_dni,_edad){
	kms = _kms;
}

void Persona::mostrarDatos(){
	cout<<"Hola, soy "<<nombre<<", tengo "<<edad<<" años y mi DNI es "<<dni<<"."<<endl;
}
void Corredor::mostrarKMS(){
	mostrarDatos();
	cout<<"He participado en varias carreras y llevo recorridos "<<kms<<" km."<<endl;
}
int main() {
	Corredor c1("Angel",12345678,17,112);
	c1.mostrarKMS();
	return 0;
}

