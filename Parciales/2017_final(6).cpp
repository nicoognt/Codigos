#include <iostream>
#include <vector>
using namespace std;
struct Persona{
	int dni,ano_n,mes_n,dia_n,edad;
	string ape,noms;
};

void eliminar(vector<Persona> &v, string ape) {
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].ape==ape){
			int aux=i;
			for(size_t j=aux;j<v.size()-1;j++) {
				v[i]=v[i+1];
			}
			v.resize(v.size()-1);
			break;
		}
	}
}

int main() {
	int N;
	cin>>N;
	vector<Persona> v(N);
	int suma=0;
	for(Persona &x : v){
		cin.ignore();
		getline(cin,x.ape);
		getline(cin,x.noms);
		cin.ignore();
		cin>>x.dni>>x.ano_n>>x.mes_n>>x.dia_n>>x.edad;
		suma+=x.edad;
	}
	float prom=suma/N;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].edad>prom) {
			cout<<v[i].ape<<v[i].noms<<", DNI: "<<v[i].dni<<", "<<v[i].edad<<" años"<<endl;
		}
	}
	/// antes de eliminar
	for(Persona a : v) {
		cout<<a.ape<<a.noms<<", DNI: "<<a.dni<<endl;
		cout<<a.ano_n<<a.mes_n<<a.dia_n<<", "<<a.edad<<" años"<<endl;
	}
	string ape_n;
	cin>>ape_n;
	eliminar(v,ape_n);
	/// después de eliminar
	for(Persona b : v) {
		cout<<b.ape<<b.noms<<", DNI: "<<b.dni<<endl;
		cout<<b.ano_n<<b.mes_n<<b.dia_n<<", "<<b.edad<<" años"<<endl;
	}
	return 0;
}

