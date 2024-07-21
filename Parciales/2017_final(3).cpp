#include <iostream>
#include <vector>
using namespace std;
struct Atleta{
	string nom;
	int dni;
	float tiempo;
};

Atleta buscar(const vector<Atleta> &v,int dni_n) {
	Atleta aux;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].dni==dni_n) {
			aux=v[i];
		}
	}
	return aux;
}

int main() {
	vector<Atleta> v(20);
	int cod,aux=0;
	while (aux!=19) {
		Atleta b;
		cin>>cod;
		cin.ignore();
		getline(cin,b.nom);
		cin.ignore();
		cin>>b.dni>>b.tiempo;
		v[cod-1]=b;
		aux++;
	}
	int dni_n;
	cin>>dni_n;
	
	Atleta x=buscar(v,dni_n);
	
	cout<<x.nom<<endl;
	cout<<x.dni<<endl;
	cout<<x.tiempo<<endl;
	return 0;
}

