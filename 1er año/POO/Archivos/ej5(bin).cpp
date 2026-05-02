#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class Puntuacion{
private:
	vector<float> v;
public:
	Puntuacion(int n) {
		v.resize(n);
	}
	void Agregar(vector<float> tabla) {v = tabla;}
	
	void Nuevo_Valor(float nuevo){
		for(size_t i=0;i<v.size();i++) { 
			if (v[i]<=nuevo){
				for(size_t j=v.size()-1;j>i;j--){
					v[j+1] = v[j];
				}
				v[i] = nuevo;
				break;
			}
		}
	}
	
	int Consultar(int i) const {return v[i];}
	void Almacenar(){
		ofstream bin_in("lista.dat",ios::binary);
		if(!bin_in.is_open()) throw runtime_error("No se pudo crear el archivo");
		
		for(size_t i=0;i<v.size();i++) { 
			bin_in.write(reinterpret_cast<const char*>(&v[i]),sizeof(int));
		}
		
		bin_in.close();
	}
	
	vector<int> Recuperar(){
		vector<int> aux(v.size());
		ifstream bin_out("lista.dat",ios::binary|ios::ate);
		if(!bin_out.is_open()) throw runtime_error("No se pudo abrir el archivo");
		
		int cant_datos = bin_out.tellg()/sizeof(int);
		
		bin_out.read(reinterpret_cast<char*>(&v[0]),cant_datos * sizeof(int));
		bin_out.close();
		
		return aux;
	}
	
};
int main() {
	
	return 0;
}

