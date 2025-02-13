#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*Escriba un programa que permita al usuario ingresar 15 valores por teclado, los almacene en un vector y luego: 
1. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes:
• utilizando el operador []
• utilizando iteradores 
• utilizando el for basado en rangos
• ¿en qué caso es conveniente utilizar cada mecanismo?
2. Calcule y muestre:
• los valores de los elementos máximo y mínimo
• la suma de todos los elementos del arreglo
• el promedio y la mediana de los elementos del arreglo
3. Permita al usuario ingresar un valor, e informe si se encuentra en el vector, y en caso afirmativo, en qué posición.*/
int main() {
	vector<int> v(15);
	for(int i=0;i<15;i++) { 
		v[i] = (1+rand()%10);
	}
	
	cout << "operador []" << endl;
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << endl;
	}
	cout << endl << "rango" << endl;
	for(const int &x : v){
		cout << x << endl;
	}
	cout << endl << "iterador" << endl;
	for(auto it=v.begin();it!=v.end();++it){
		cout << *it << endl;
	}
	cout << endl;
	
	cout << "el elemento maximo es " <<  *max_element(v.begin(),v.end()) << "\n" << "y el minimo es " << *min_element(v.begin(),v.end()) << endl;
	cout << "la suma total es " << accumulate(v.begin(),v.end(),0) << " y el promedio: " << accumulate(v.begin(),v.end(),0) / v.size() << endl;
	
	sort(v.begin(),v.end());
	cout << "la mediana es " << v[v.size()/2] << endl;
//ejercicio 3
	cout << "numero a buscar : ";
	int num; cin >> num;
	vector<int>::iterator it = find(v.begin(),v.end(),num);
	if(it == v.end()){
		cout << "no se encontró el elemento" << endl;
	} else {
		cout << "la posicion del elemento es " << it - v.begin();
	}
	return 0;
}

