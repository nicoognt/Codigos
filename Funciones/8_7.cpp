#include <iostream>
using namespace std;

int MCD(int a,int b) {
	if (a==b) {
		return a;
	} else if (a>b) {
		return MCD(a-b,b);
	} else {
		return MCD(a,b-a);
	}
}

int main() {
	int a,b;
	cout<<"ingrese los valores para calcular su MCD: "<<endl;
	cin>>a>>b;
	int mcd = MCD(a,b);
	cout<<"el máximo común divisor entre "<<a<<" y "<<b<<" es "<<mcd<<endl;
	return 0;
}

