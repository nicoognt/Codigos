#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*Desarrolle una clase templatizada llamada ManejadorArchivo que posea m�todos y atributos para manipular un
archivo binario que contenga registros del tipo de dato especificado por el par�metro (mediante un vector en memoria,
no directamente sobre el archivo). La clase debe poseer m�todos para:
1. Abrir un archivo binario y cargar los registros en memoria.
2. Obtener el registro en una posici�n especificada por el usuario.
3. Modificar el registro en una posici�n determinada.
4. Actualizar la informaci�n del archivo con los cambios.
Utilice la clase desde un programa cliente para leer los registros escritos en el archivo binario generado en el ejercicio
6.5*/
template<typename J>
class ManejadorArchivo{
private:
	fstream bin;
	vector<J> v;
public:
	ManejadorArchivo(string nom) {
		bin.open(nom,ios::binary|ios::in|ios::ate);
		if(!bin.is_open()) throw runtime_error("No se pudo abrir/crear el archivo");
		int n = bin.tellg()/sizeof(J);
		bin.seekg(0);
		
		for(size_t i=0;i<n;i++) {
			J aux;
			bin.write(reinterpret_cast<const char*>(&aux),sizeof(J));
			v[i] = aux;
		}
	}
	~ManejadorArchivo() {
		bin.close();
	}
	J ObtenerRegis(int pos){
		return v[pos-1];
	}
	void ModificarRegis(int pos, J nuevo) {
		v[pos-1] = nuevo;
	}
	void Actualizar() {
		bin.seekp(0);
		for(size_t i=0;i<v.size();i++) { 
			bin.write(reinterpret_cast<const char*>(&v[i]),sizeof(J));
		}
	}
};
int main(int argc, char *argv[]) {
	
	return 0;
}

