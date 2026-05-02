#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
///a) Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado por un conjunto de 200 pares de números generados aleatoriamente.
///Cada par de datos se conforma por un entero y un flotante.
///b) Escriba otro programa que lea el archivo generado por el primero para verificar si se escribieron correctamente.
int main() {
	ofstream bin_in("grupo.dat",ios::binary);
	if (!bin_in.is_open()) throw runtime_error("No se pudo abrir correctamente el archivo");
	
	srand(time(0));
	for(int i=0;i<200;i++) { 
		int a = rand()%49+1;
		float b = rand()%49+1;
		pair<int,float> aux = make_pair(a,b);
		bin_in.write(reinterpret_cast<const char*>(&aux),sizeof(a));
	}
	
	bin_in.close();
	
	ifstream bin_out("grupo.dat",ios::binary|ios::ate);
	if(!bin_out.is_open()) throw runtime_error("No se pudo abrir correctamente el archivo");
	int bytes = bin_out.tellg();
	int tam = bytes/sizeof(pair<int,float>);
	bin_out.seekg(0);
	
	vector<pair<int,float>> v(tam);
	bin_out.read(reinterpret_cast<char*>(&v[0]),tam*sizeof(pair<int,float>));
	
	for(const pair<int,float> A : v) { 
		cout << A.first << " " << A.second << endl;
	}
	bin_out.close();
	return 0;
}

