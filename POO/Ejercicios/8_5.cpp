#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
/*Declare un std::vector de enteros de tamaño 20 y luego:
1. Implemente una función int rand10()que genere un entero aleatorio entre -10 y 10, y utilícela como argumento
para el algoritmo generate para inicializar el arreglo con valores aleatorios.
2. Implemente una función bool es_par(int x) que retorne true si el entero que recibe es par; y utilícela en combinación
con count_if para contar cuantos elementos pares hay en el contenedor generado.
3. Implemente una función bool menor_abs(int a, int b) que reciba dos enteros y retorne verdadero cuando el valor absoluto
del primero sea menor que el valor absoluto del segundo; y utilice esta función como argumento de sort para ordenar el vector por valor absoluto.
4. Elimine los elementos repetidos utilizando los algoritmos genéricos de la STL, y luego muestre el arreglo resultante.
• Ayuda: recuerde que el algoritmo unique requiere que los valores repetidos estén contiguos en la secuencia para funcionar correctamente.
Si en el punto 3 ordenó solo por valor absoluto, valores repetidos podría estar separados.
Por ejemplo, el vector {1,-2,2,-2,-3,3,3} debería quedar {1,-2,2,-3,3} (eliminar el 2do -2, y los dos últimos -3, pero unique no lo hará bien).
- Pruebe usar la sobrecarga de unique que recibe el comparador con menor_abs. ¿Qué problema tiene para este caso?
– Intente ordenar primero de la forma habitual, y luego por valor absoluto (para ello investique la diferencia entre sort y stable_sort).
– Modifique su función menor_abs para que en caso de recibir dos nro con igual valor absoluto pero diferente signo, considere menor al 
negativo, y resuelva ahora el problema utilizando un solo sort.*/
int rand10(){
	return (rand()%20-10);
}
bool es_par(int valor){return (valor%2==0);}

bool menor_abs(int a, int b){
	if(abs(a)==abs(b)){
		return a<b;
	}
	return (abs(a)<abs(b));
}
int main() {
	vector<int> v(20);
	generate(v.begin(),v.end(),rand10);
	
	cout << "Lista original:" << endl;
	for(auto it=v.begin();it!=v.end();++it){
		cout << *it << endl;
	}
	cout << "\n";
	size_t cuantos = count_if(v.begin(),v.end(),es_par);
	cout << "Dentro del vector v hay " << cuantos << " elementos pares\n";
	
	sort(v.begin(),v.end(),menor_abs);
	cout << "Lista ordenada por valores absolutos:" << endl;
	for(auto it=v.begin();it!=v.end();++it){
		cout << *it << endl;
	}
	cout << "\n";
	
	auto itfin = unique(v.begin(),v.end());
	v.erase(itfin,v.end());
	cout << "Lista sin los valores repetidos:\n";
	for(auto it=v.begin();it!=v.end();++it){
		cout << *it << endl;
	}
	cout << "\n";
	return 0;
}

