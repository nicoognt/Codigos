#include <iostream>
#include <cmath>
using namespace std;
class Tanque {
private:
	float kg;
public:
	Tanque(float _kg) : kg(_kg) {}
	float MostrarPeso() const {return kg;}
	virtual float Volumen()=0;
	virtual ~Tanque() {}
};
class Cilindro : public Tanque{
private:
	float radio,altura;
public:
	Cilindro(float _radio,float _altura,float _kg) : Tanque(_kg),radio(_radio),altura(_altura) {}
	float MostrarRadio() const {return radio;}
	float MostrarAltura() const {return altura;}
	float Volumen() override {return (3.14*radio*radio)*altura;}
};

class Esfera : public Tanque{
private:
	float radio;
public:
	Esfera(float _radio, float _kg) : Tanque(_kg),radio(_radio) {}
	float Volumen() override {return (4.0/3.0*3.14*radio*radio*radio);}
};
int main() {
	Tanque *tan;
	cout<<"ingrese los datos de radio, altura y peso: ";
	float r,h,p; cin>>r>>h>>p;
	tan = new Cilindro(r,h,p);
	cout<<"el volumen del cilindro es de "<<tan->Volumen()<<"m3"<<endl;
	delete tan;
	cout<<"ahora ingrese los datos para el tanque esférico (radio y peso):"; cin>>r>>p;
	tan = new Esfera(r,p);
	cout<<"el volumen del tanque esférico es de "<<tan->Volumen()<<"m3"<<endl;
	delete tan;
	return 0;
}

