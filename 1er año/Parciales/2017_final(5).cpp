#include <iostream>
using namespace std;
struct Fecha{
	int ano,mes,dia;
};

int calcular_edad(Fecha act, Fecha x) {
	int resul = act.ano-x.ano;
	if(act.mes-x.mes<0) {
		resul--;
	}
	return resul;
}
int main() {
	
	return 0;
}

