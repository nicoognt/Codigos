#include <iostream>
#include <vector>
using namespace std;
vector<float> corregir(vector<float> &a) {
	float contador = 0;
	int cont = 0;
	for (size_t i=0;i<a.size();i++) {
		if (a[i] < 0.3) {
			contador += a[i];
			cont++;
		}
	}
	float promedio = contador/cont;
	for (size_t i=0;i<a.size()-1;i++) {
		if (a[i]<=3.5 and a[i+1]>=0.3) {
			a.resize(a.size()+1);
			int n = i;
			for (int j=a.size()-1;j<n;--j) {
				a[i+1] = a[i];
			}
			a[n] = promedio;
		}
	}
	return a;
}

int main() {
	
	return 0;
}

