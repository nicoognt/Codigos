#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/**PancakeSort. Dada una pila de numeros S, implementar la funcion void pancake_sort(stack<int>&S) la 
cual ordena la pila solo haciendo operaciones en las cuales se invierte un rango contiguo de
elementos en el tope de la pila.PancakeSort. Dada una pila de numeros S, implementar la funcion 
void pancake_sort(stack<int>&S) la cual ordena la pila solo haciendo operaciones en las cuales se 
invierte un rango contiguo de elementos en el tope de la pila.
**/
void flip(vector<int> &v, int k){
	reverse(v.begin(),v.begin()+k);
}

void pancakeSortRecursive(vector<int> &S,int n){
	if(n <= 1){
		return;
	}
	
	// parte de ordenar
	auto it = max_element(S.begin(),S.end());
	int elems = distance(S.begin(),it);
	
	if (elems != n-1){
		
		if(elems != 0){
			flip(S,elems+1);
		}
		
		flip(S,n);
	}
	
	pancakeSortRecursive(S,n-1);
}

void pancakeSort(vector<int> &v){
	pancakeSortRecursive(v,v.size());
}
int main() {
	vector<int> v = {1,5,2,11,5,3};
	pancakeSort(v);
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	return 0;
}







