#include <iostream>
#include <vector>
using namespace std;
struct Atleta{
	string ape_noms;
	int num,h1,m1,s1;
};

Atleta calculadora(const vector<Atleta> &v) {
	Atleta aux = {"asd", 1, 999, 999, 999};
	for(Atleta A : v) {
		if(A.h1<aux.h1) {
			aux=A;
		} else if(A.m1<aux.m1) {
			aux.ape_noms=A.ape_noms;
			aux.num=A.num;
			aux.m1=A.m1;
			aux.s1=A.s1;
		} else if(A.s1<aux.s1){
			aux.ape_noms=A.ape_noms;
			aux.num=A.num;
			aux.s1=A.s1;
		}
	}
	return aux;
}

int main() {
	vector<Atleta> v(35);
	int aux=0;
	while (aux<35) {
		Atleta a;
		getline(cin,a.ape_noms);
		cin.ignore();
		cin>>a.num>>a.h1>>a.m1>>a.s1;
		v[a.num-1]=a;
		aux++;
	}
	
	Atleta ganador=calculadora(v);
	cout<<ganador.ape_noms<<ganador.num<<ganador.h1<<ganador.m1<<ganador.s1;
	
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].h1!=0) {
			cout<<v[i].ape_noms<<v[i].num<<v[i].h1<<v[i].m1<<v[i].s1;
		} else if(v[i].m1!=0) {
			cout<<v[i].ape_noms<<v[i].num<<v[i].h1<<v[i].m1<<v[i].s1;
		} else if(v[i].s1!=0) {
			cout<<v[i].ape_noms<<v[i].num<<v[i].h1<<v[i].m1<<v[i].s1;
		}
	}
	
	return 0;
}

