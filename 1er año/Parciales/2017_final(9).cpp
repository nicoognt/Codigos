#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<pair<string,int>> v(200);
	int cont=0,cod,cant;
	string desc;
	while(cont<200) {
		cin.ignore();
		getline(cin,desc);
		cin,ignore();
		cin>>cod>>cant;
		v[cod-1]={desc,cant};
		cont++;
	}
	vector<int> lista(200,0);
	int vendido;
	cin>>cod;
	while(cod!=0) {
		cin>>vendido;
		lista[cod-1]+=vendido;
		cin>>cod;
	}
	int x;
	cin>>x;
	while(x!=0) {
		for(size_t i=0;i<v.size();i++) { 
			if(v[i].second-lista<x) {
				cout<<v[i].first;
			}
		}
		cin>>x;
	}
	return 0;
}

