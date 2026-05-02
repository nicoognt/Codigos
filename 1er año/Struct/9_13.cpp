#include <iostream>
#include <cmath>
using namespace std;
struct Raices {
	int r1;
	int r2;
};


float disc(int a,int b,int c) {
	return b*b-4*a*c;
}

void mostrar(Raices aux,float discri) {
	if (discri >= 0) {
		cout<<"Raíces: "<<endl;
		cout<<aux.r1<<", ";
		cout<<aux.r2;
	} else {
		cout<<aux.r1<<" +/- "<<aux.r2<<"i";
	}
}

Raices calcular_raices(Raices anashex,int a,int b,int c) {
	float discrim = disc(a,b,c);
	if (discrim >= 0) {
		anashex.r1 = (-b + sqrt(discrim))/(2 * a);
		anashex.r2 = (-b - sqrt(discrim))/(2 * a);
	} else {
		anashex.r1 = -b / (2 * a);
		anashex.r1 = sqrt((-1) * discrim);
	}
	return anashex;
}
int main() {
	int a,b,c;
	cout<<"Ingrese los valores de los coeficientes a,b y c: ";
	cin>>a>>b>>c;
	float discriminante = disc(a,b,c);
	
	if (discriminante >= 0) {
		Raices func = calcular_raices(func,a,b,c);
		mostrar(func,discriminante);
	} else {
		Raices func_2 = calcular_raices(func_2,a,b,c);
		mostrar(func_2,discriminante);
	}
	return 0;
}

