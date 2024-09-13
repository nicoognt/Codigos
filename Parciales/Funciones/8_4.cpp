#include <iostream>
using namespace std;

int num_mayor(int a,int b) {
	int mayor;
	if (a>b) {
		mayor=a;
	}else{
		mayor=b;
	}
	return mayor;
}

int num_mayor(int a,int b,int c) {
	int mayor;
	if (a>b and a>c) {
		mayor=a;
	} else if (b>a and b>c) {
		mayor=b;
	} else { 
		mayor=c;
	}
	return mayor;
}

int main(int argc, char *argv[]) {
	int a,b,c,mayor;
	cin>>a>>b>>c;
	mayor=num_mayor(a,b,c);
	cout<<mayor<<endl;
	return 0;
}

