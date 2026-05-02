#include <iostream>
using namespace std;

 int facto(int n){
int aux=n,x=n-1;

while (x>1) {
	aux=aux*x;
	--x;
}
return aux;
 }

int main(int argc, char *argv[]) {
	int resul,num;
	cout<<"ingrese un número: ";
	cin>>num;
	resul=facto(num);
	cout<<num<<"! = "<<resul<<endl;
	return 0;
}

