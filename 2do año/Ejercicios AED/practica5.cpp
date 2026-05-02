#include <iostream>
#include <numeric>
#include <list>
using namespace std;
/*Junta. Escribir una funcion void junta(list<int> &L, int c) que, dada una lista L, agrupa 
de a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la 
lista L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despues de aplicar el algoritmo junta(L,3) debe quedar L=(6,11,10,14,4) (notar que se 
agrupan los ultimos elementos, pese a no completar los tres requeridos). El algoritmo debe tener un tiempo de ejecucion O(n).
*/
void junta(list<int> &L, int c){
	//realizar la suma
	
	if (L.size()%c==0){
		for(auto it=L.begin();it!=L.end();it++){
			int suma = accumulate(it,next(it,c),0);
			it = L.erase(it,next(it,c));
			it = L.insert(it,suma);
		}
	} else {
		int pares = L.size()/c;
		int cont = 0;
		for(auto it=L.begin();cont<pares;it++){
			int suma = accumulate(it,next(it,c),0);
			it = L.erase(it,next(it,c));
			it = L.insert(it,suma);
			cont++;
		}
		int suma = 0;
		for (auto it=next(L.begin(),pares);it!=L.end();it++){
			suma += *it;
		}
		L.erase(next(L.begin(),pares),L.end());
		L.push_back(suma);
	}
}
int main() {
	list<int> l = {1,2,3,4,5,6,7,8};
	cout << "lista antes: [";
	for (int &n:l){
		cout << n << ", ";
	}
	cout << "]" << endl;
	int c = 9;
	if (c > l.size()){
		cout << "no se puede mogoliquito" << endl;
		return 0;
	} else {
		junta(l,c);
		cout << "lista despues de la suma: [";
		
		for (int &n:l){
			cout << n << ", ";
		}
		cout << "]" << endl;
		return 0;
	}
	
}







