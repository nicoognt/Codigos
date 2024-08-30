#include <iostream>
#include <cmath>
using namespace std;
class EC{
private: 
	int a, b, c;
public:
	EC(int _a, int _b, int _c);
	bool TieneReales();
	pair<float,float> Reales();
	pair<float,float> Complejas();
	~EC();
};
EC::EC(int _a, int _b, int _c){
	a = _a;
	b = _b;
	c = _c;
}
EC::~EC(){
}

bool EC::TieneReales(){
	return (b*b-4*a*c>=0);
}

pair<float,float> EC::Reales(){
	float r1 = (-b+sqrt(b*b-4*a*c))/2*a, r2 = (-b-sqrt(b*b-4*a*c))/2*a;
	return {r1,r2};
}

pair<float,float> EC::Complejas(){
	float pr = -b/2*a, pi = sqrt(-1*(b*b-4*a*c));
	return {pr,pi};
}

int main() {
	int a,b,c;
	cout<<"ingrese los coefs: ";
	cin>>a>>b>>c;
	EC ec1(a,b,c);
	if (ec1.TieneReales()) {
		pair<float,float> r = ec1.Reales();
		cout<<r.first<<"\n"<<r.second;
	} else {
		pair<float,float> pr_pi = ec1.Complejas();
		cout<<pr_pi.first<<" +/- "<<pr_pi.second;
	}
	
	return 0;
}

/*Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadr�ticas de la forma ax^2 + bx + c = 0 .
La clase debe incluir:
1. Un constructor que reciba los valores de los coeficientes a, b y c.
2. Un m�todo TieneRaicesReales(...) que retorne verdadero si las ra�ces de la ecuaci�n son reales.
3. Dos m�todos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las ra�ces reales (en caso de que lo sean).
4. Dos m�todos VerParteReal(...) y VerParteImag(...) que permitan obtener las partes real e imaginaria de las ra�ces complejas (en caso de que lo sean).
5. Cree un programa cliente que utilice un objeto de la clase Ecuaci�nCuadratica para determinar las ra�ces de
una ecuaci�n cuadr�tica cuyos coeficientes sean ingresados por el usuario, y las muestre en el formato que
corresponda (seg�n sean reales o complejas).*/
