#include <iostream>
#include <vector>
using namespace std;
int busca_pos(const vector<string> &palabrillas,string &nuevo_nombre) {
	for(size_t i=0;i<palabrillas.size();i++) { 
		if (palabrillas[i]>=nuevo_nombre) {
			return i;
		}
	}
	return palabrillas.size();
}

void inserta(vector<string> &palabras,int a,string &nuevo_nombre) {
	palabras.resize(palabras.size()+1);
	for (int i = palabras.size()-1;i>a;--i) {
		palabras[i+1] = palabras[i];
	}
	palabras[a] = nuevo_nombre;
}


int main() {
	vector<string> palabras(5);
//	creo el arreglo y le meto valores
	cout<<"escriba los nombres que conformarán la lista: "<<endl;
	for(size_t i=0;i<palabras.size();i++) { 
		cin>>palabras[i];
	}
	
	string nuevo_nombre;
	cout<<"cuál es el nuevo nombre a insertar?: ";
	cin>>nuevo_nombre;
	
	int a=busca_pos(palabras,nuevo_nombre);
	inserta(palabras,a,nuevo_nombre);
//	uso la función para insertar
	for(size_t i=0;i<palabras.size();i++) { 
		cout<<palabras[i]<<" ";
	}
	return 0;
}

