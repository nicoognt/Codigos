#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*Implemente una función genérica unique_no_sort que elimine los elementos repetidos de un contenedor (de cualquier tipo) sin 
modificar el orden de los elementos que no se eliminan (es decir, sin ordenar previamente, por lo que no podrá usar unique).*/
template<typename T>
void unique_no_sort(vector<T> &v){
	vector<T> nuevo;
	set<T> unicos;
	
	for(size_t i=0;i<v.size();i++) { 
		if(unicos.find(v[i])==unicos.end()){
			unicos.insert(v[i]);
			nuevo.push_back(v[i]);
		}
	}
	
	v = nuevo;
}

int main() {
	vector<int> v = { 1,2,3,2,1,4,0,4,1 };
	
	unique_no_sort(v);
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	return 0;
}

