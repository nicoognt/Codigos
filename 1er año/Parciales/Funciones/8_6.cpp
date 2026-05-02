#include <iostream>
using namespace std;

int power(int base,int exp) {
	if (exp==1) {
		return base;
	} else if (exp%2==0) {
		return power(base,exp/2)*power(base,exp/2);
	} else {
		return base*power(base,exp-1);
	}
}

int main() {
	int base,exponente;
	cout<<"ingrese base y exponente: ";
	cin>>base>>exponente;
	int potencia = power(base,exponente);
	cout<<"el resultado es "<<potencia<<endl;
	return 0;
}

