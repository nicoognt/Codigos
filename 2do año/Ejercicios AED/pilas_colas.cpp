#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
a. Asignar i al segundo elemento desde la parte superior de la pila, dejando
la pila sin sus dos elementos de la parte superior.
b. Asignar i al segundo elemento desde la parte superior de la pila, sin modificarla
c. Dado un entero n, asignar i al elemento n-esimo desde la parte superior de la 
pila, dejando la pila sin sus n elementos superiores.
d. Asignar i al elemento del fondo de la pila, dejando la pila vacia.
e. Asignar i al elemento del fondo de la pila, dejando la pila sin modificar.
**/
void asignar1(stack<int> &s, int i){
	// borro los dos de arriba
	s.pop(); s.pop();
	s.push(i);
}
	
void asignar2(stack<int> &s, int i){
	int aux = s.top();
	s.pop();
	s.top() = i;
	s.push(aux);
}

void asignar3(stack<int> &s, int n, int nuevo){
	if(s.size() >= n){
		for(int i=0;i<n;i++) { 
			s.pop();
		}
		s.push(nuevo);
	} else {
		abort();
	}
}

void asignar4(stack<int> s, int nuevo){
	for(size_t i=0;i<s.size();i++) { 
		s.pop();
	}
	s.push(nuevo);
}

void asignar5(stack<int> &s, int nuevo){
	vector<int> aux;
	size_t tam = s.size();
	
	for(size_t i=0;i<tam;i++) { 
		aux.push_back(s.top());
		s.pop();
	}
	
	aux[tam-1] = nuevo;
	
	for(int i = tam-1;i>=0;i--){
		s.push(aux[i]);
	}
}
int main() {
	stack<int> s;
	s.push(1); s.push(2); s.push(3); s.push(4);
	int i = 999;
	asignar5(s,i);
	while (!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	
	return 0;
}







