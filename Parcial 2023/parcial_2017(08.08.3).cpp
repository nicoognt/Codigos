#include <iostream>
#include <vector>
using namespace std;

struct Licencia {
	string software, nom_lic;
	float costo;
};

vector<float> calcular_costo(const vector<Licencia> &a, const vector<int> &b, int n) {
	vector<float> totales(n);
	for (int i=0;i<n;i++) {
		totales[i] = a[i].costo * b[i];
	}
	return totales;
}

int main() {
	int n;
	cin >> n;
	vector<Licencia> v(n);
	for (Licencia &x : v) {
		getline(cin,x.software);
		getline(cin,x.nom:lic);
		cin.ignore();
		cin >> x.costo;
	}
	
	vector<int> cant_comprar(n);
	for (int &b : cant_comprar) {
		cin >> b;
	}
	
	vector<float> total(n) = calcular_costo(v,cant_comprar,n);
	return 0;
}

