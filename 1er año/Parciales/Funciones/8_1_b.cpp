#include <iostream>
using namespace std;

int hipot(int l1,int l2,int l3) {
	int hipotenusa;
	if (l1*l1+l2*l2==l3*l3) {
		hipotenusa=l3;
	} else if (l2*l2+l3*l3==l1*l1) {
		hipotenusa=l1;
	} else {
		hipotenusa=l2;
	}
	return hipotenusa;
}

int main(int argc, char *argv[]) {
	int l1,l2,l3;
	cout<<"ingrese los valores para los catetos: "<<endl;
	cin>>l1>>l2>>l3;
	int hipo=hipot(l1,l2,l3);
	cout<<"la hipotenusa del triángulo mide: "<<hipo<<endl;
	
	return 0;
}

