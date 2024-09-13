#include <iostream>
using namespace std;

bool es_primo(int numero) {
	bool es_primo=true;
	for (int i=2; i*i<=numero;i++) {
		if (numero%i==0) {
			return false;
		}
	} 
	return true;
}

int main(int argc, char *argv[]) {
	int num;
	cout<<"ingrese un valor: ";
	cin>>num;
	if (es_primo(num)){
		cout<<"el número es primo"<<endl;
	} else {
		cout<<"el número no es primo"<<endl;
	}
	return 0;
}

