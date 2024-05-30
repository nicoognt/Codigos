#include <iostream>
using namespace std;

struct Complejo {
	int a;
	int b;
	string imagin="i";
};

Complejo completar() {
	Complejo x;
	cout<<"Parte real: ";
	cin>>x.a;
	cout<<"Parte imaginaria: ";
	cin>>x.b;
	return x;
}

Complejo realizar_operacion(const Complejo uno,const Complejo dos, string operacion) {
	Complejo aux;
	if (operacion == "suma") {
		aux.a = uno.a + dos.a;
		aux.b = uno.b + dos.b;
	} else if (operacion == "resta") {
		aux.a = uno.a - dos.a;
		aux.b = uno.b - dos.b;
	} else {
		aux.a = uno.a * dos.b;
		aux.b = uno.b * dos.b;
	}
	return aux;
}

void mostrar(const Complejo xd) {
	if (xd.b < 0) 
		cout<<xd.a<<" - "<<xd.b*-1<<xd.imagin<<endl;
	else 
		cout<<xd.a<<" + "<<xd.b<<xd.imagin<<endl;
}

int main() {
	Complejo primero = completar();
	Complejo segundo = completar();
	Complejo resultado;
	mostrar(primero);
	mostrar(segundo);
	
	string operacion;
	cout<<"¿Qué operación quiere realizar sobre los números?: ";
	cin>>operacion;
	resultado = realizar_operacion(primero,segundo,operacion);
	mostrar(resultado);
	return 0;
}

