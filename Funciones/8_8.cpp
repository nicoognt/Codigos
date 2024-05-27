#include <iostream>
using namespace std;
//Una Empresa paga a sus 25 operarios semanalmente de acuerdo con la
//cantidad de horas trabajadas, a razón de X pesos la hora hasta 40 hs. y un 50%
//más por todas las horas que pasan de 40. Escriba un programa que permita
//ingresar el costo inicial por hora (X), y luego la cantidad de horas trabajadas por
//cada empleado e informe el salario que le corresponde cobrar. Finalmente, debe
//informar a modo de resumen: a) los salarios máximo, mínimo y promedio, y b) el
//monto total que la empresa pagó en concepto de salarios.
int cuanto_cobra(int precio_hs,int hs_tra) {
	int salario;
	if (hs_tra <= 40) {
		salario = hs_tra * 40;
	} else {
		salario = hs_tra * 40 + (hs_tra - 40) * 1.5;
	}
	return salario;
}
void maximo_minimo(int salario,int &max_sal,int &min_sal) {
	if (salario > max_sal) {
		max_sal = salario;
	}
	if (salario < min_sal) {
		min_sal = salario;
	}
}
float promedio(int total) {
	return total / 20;
}

int main() {
	int precio_hs,hs_tra,salario,max_sal,min_sal = 9999999,cont = 1,total = 0;
	
	cin>>precio_hs;
	while (cont <= 25) {
		cout<<"cuántas horas trabajó el empleado N° "<<cont<<"?: ";
		cin>>hs_tra;
		
		salario = cuanto_cobra(precio_hs,hs_tra);
		maximo_minimo(salario,max_sal,min_sal);
		total += salario;
		
		cout<<"al empleado "<<cont<<" le corresponde cobrar $"<<salario<<endl;
		cont++;
	}
	cout<<"el salario máximo cobrado fue de $"<<max_sal<<", y el mínimo fue de $"<<min_sal<<endl;
	cout<<"además, el salario promedio calculado es de $"<<promedio(total)<<endl;
	return 0;
}

