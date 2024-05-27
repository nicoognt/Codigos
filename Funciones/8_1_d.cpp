#include <iostream>
using namespace std;

pair<int,float> division_con_resto(int num,int den) {
	
	pair<int,float> r;
	r.first = num/den;
	r.second = num%den;
	
	return r;
}

int main(int argc, char *argv[]) {
	
	int dividendo,divisor;
	cout<<"ingrese el número a dividir y el divisor: ";
	cin>>dividendo>>divisor;
	
	pair<int,float> resul = division_con_resto(dividendo,divisor);
	cout<<"el cociente entre "<<dividendo<<" y "<<divisor<<" es "<<resul.first<<", y su resto es "<<resul.second<<endl;
	return 0;
}

