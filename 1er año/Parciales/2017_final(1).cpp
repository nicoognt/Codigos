#include <iostream>
#include <vector>
using namespace std;
pair<int,int> calculadora(const vector<int> &v) {
	int mayor=0,segundo=0;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i]>mayor) {
			segundo=mayor;
			mayor=v[i];
		} else if (v[i]>segundo) {
			segundo=v[i];
		}
	}
	return {mayor,segundo};
}

int main() {
	vector<int> v(30);
	for(int &x : v) {
		cin>>x;
	}
	pair<int,int> ma_me = calculadora(v);
	cout<<ma_me.first;
	cout<<ma_me.second;
	return 0;
}


