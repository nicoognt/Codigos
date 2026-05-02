#include <iostream>
#include <list>
#include <iterator>
using namespace std;
/**dados un numero n y una lista de nombres, que es el ordenamiento en el sentido de las agujas del reloj 
de los soldados en el crculo (comenzando por aquel a partir del cual se inicia la cuenta), escribir un 
procedimiento list<string> josephus(list<string>& nombres, int n) que retorna una lista con los nombres de los soldados
en el orden que han de ser eliminados y en ultimo lugar el nombre del soldado que escapa.
**/
list<string> josephus(list<string> &nombres, int n){
	if(nombres.empty()) abort();
	list<string> aux;
	
	auto comienzo = nombres.begin();
	
	while(nombres.size() > 0){
		if(distance(comienzo,nombres.end()) < n){
			//lo nuevo
		   comienzo = nombres.begin();
		   int nuevo_n = n - distance(comienzo,nombres.end()) - 1;
		   
		   //lo de abajo
		   advance(comienzo,nuevo_n);
		   cout << "nombre encontrado: " << *comienzo << endl;
		   aux.push_back(*comienzo);
		   comienzo = nombres.erase(comienzo);
		} else {
			
			advance(comienzo,n-1);
			cout << "nombre encontrado: " << *comienzo << endl;
			aux.push_back(*comienzo);
			comienzo = nombres.erase(comienzo);
		}
		
	}
	return aux;
}
int main() {
	list<string> nom = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
	int n = 4;
	
	list<string> eliminados = josephus(nom,n);
	
	cout << "orden de eliminacion: [";
	for (auto it=eliminados.begin();it!=eliminados.end();it++){
		if(it == prev(eliminados.end())){
			cout << *it << "]" << endl;
		} else {
			cout << *it << ", ";
		}
	}
	return 0;
}







