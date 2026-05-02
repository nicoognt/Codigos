#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T mayor(T x, T y){
	if (x>y) return x;
	return y;
}

template<typename A>
A mayor(const vector<A> &v){
	A aux = v[0];
	for(size_t i=1;i<v.size();i++) { 
		if(v[i]>aux) aux= v[i];
	}
	return aux;
}
int main() {
	vector<int> v = { 1,2,3,4,5,6 };
	int resul = mayor(v);
	cout << resul;
	
	return 0;
}

