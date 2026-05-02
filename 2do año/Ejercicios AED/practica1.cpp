#include <iostream>
#include <list>
using namespace std;

void basic_sort(list<int> &L){
	list<int> L2;
	
	while (!L.empty()){
		int menor = L.front();
		list<int>::iterator aux = L.begin();
		
		for (auto it=L.begin();it!=L.end();it++){
			if(*it<menor){
				menor=*it;
				aux=it;
			}
		}
		
		L2.push_back(menor);
		L.erase(aux);
	}
	
	L = L2;
}
int main() {
	list<int> l = {1,5,2,22,12,30,4};
	cout << "valores antes de la funcion: [";
	for (int n : l){
		cout << n << " ";
	}
	cout << "]" << endl;
	
	basic_sort(l);
	
	cout << "valores despues de la funcion: [";
	for (int n : l){
		cout << n << " ";
	}
	cout << "]" << endl;
	return 0;
}







