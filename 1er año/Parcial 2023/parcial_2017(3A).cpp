#include <iostream>
#include <vector>
using namespace std;
/// Se ingresan como datos N valores numéricos ordenados en forma descendente (el valor de N se lee por teclado).
/// Realice un algoritmo que lea un nuevo valor y lo inserte en la lista de tal manera que el
/// orden se mantenga. Luego muestre la nueva lista resultante

int main() {
	int N;
	cin>>N;
	vector<int> v(N);
	for(int i=0;i<N;i++) { 
		cin>>v[i];
	}
	
	int nuevo;
	cin>>nuevo;
	for(int i=0;i<N;i++) { 
		if (nuevo<=v[i]) {
			int aux=i;
			v.resize(N+1);
			for (int j=v.size()-2;j>aux;i--) {
				v[i+1]=v[i];
			}
			v[aux]=nuevo;
		}
	}
	
	for(int i=0;i<N;i++) { 
		cout<<v[i];
	}
	return 0;
}

