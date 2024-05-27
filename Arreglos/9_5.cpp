#include <iostream>
#include <vector>
using namespace std;
int buscar(vector<int> &nums) {
	for(size_t i=0;i<nums.size();i++) { 
		if (nums[i]==523) {
			return i;
		}
	}
	return nums.size();
}

void eliminar(vector<int> &num, int &pos) {
	for (size_t i=pos;i<num.size()-1;i++) {
		num[i] = num[i+1];
	}
	num.resize(num.size()-1);
}

int main() {
	int N;
	cout<<"este programa te permite ingresar los valores que tendr� un vector y, si hay un 523, lo eliminar� en todas sus posiciones y mostrar� el vector modificado."<<endl;
	cout<<"cu�ntos espacios tendr� el vector?: ";
	cin>>N;
	vector<int> numeros(N);
	
	for(size_t i=0;i<numeros.size();i++) { 
		cin>>numeros[i];
	}
	
	for(size_t i=0;i<numeros.size();i++) { 
		if (numeros[i]==523) {
			int pos = buscar(numeros);
			eliminar(numeros,pos);
		}
	}
	
	cout<<"a continuaci�n se mostrar� el vector modificado sin el n�mero 523: "<<endl;
	for(size_t i=0;i<numeros.size();i++) { 
		cout<<numeros[i]<<" ";
	}
	return 0;
}

