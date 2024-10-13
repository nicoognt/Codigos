#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ofstream bin_in("grupo.dat",ios::binary|ios::ate);
	if(!bin_in.is_open()) throw runtime_error("No se pudo abrir el archivo correctamente");
	
	cout << "Ingrese un par a reemplazar y la posición en la que lo desea hacer: " << "\n";
	pair<int,float> aux;
	int pos;
	cin >> aux.first >> aux.second >> pos;
	
	int linea = (pos*sizeof(pair<int,float>))-8;
	bin_in.seekp(linea);
	bin_in.write(reinterpret_cast<const char*>(&aux),sizeof(pair<int,float>));
	
	bin_in.close();
	cout << "Ya se actualizó el archivo binario :D. ¿Querés que lo muestre?" << "\n";
	string rta;
	cin >> rta;
	if (rta=="si" || rta=="Si"){
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
	} else {
		cout << "bue loco, andá nomás" << endl;
	}
	return 0;
}

