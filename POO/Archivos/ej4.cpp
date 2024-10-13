#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

size_t comisiones(int alumnos, int divisor=1){
	if (alumnos<=30) {
		return 1;
	} else if ((alumnos+divisor-1)/divisor<=30){
		return divisor;
	} else {
		return comisiones(alumnos,divisor+1);
	}
}

int main() {
	ifstream alumnos("inscriptos.txt");
	if(!alumnos.is_open()) throw runtime_error("No se pudo abrir el archivo correctamente");
	
	vector<string> v;
	string nom;
	while(getline(alumnos,nom)){
		v.push_back(nom);
	}
	alumnos.close();
	size_t coms = comisiones(v.size());
	cout << "se necesitarán "<< coms << " comisiones" << endl;
	
	size_t indice = 0;
	for(size_t i=1;i<=coms;i++) { 
		stringstream nomArchivo;
		size_t tope = 0;
		nomArchivo << "comision" << i <<".txt";
		ofstream archivo(nomArchivo.str());
		if(!archivo.is_open()){
			cerr << "Error al crear el archivo " << nomArchivo.str();
		}
		archivo << "Alumnos de la comision " << i <<":" << endl;
		while(tope <= v.size()/coms && indice < v.size()) {
			archivo << v[indice] << endl;
			indice++;
			tope++;
		}
		archivo.close();
	}
	
	return 0;
}

