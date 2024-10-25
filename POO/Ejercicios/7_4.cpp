#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos y atributos para manipular un
archivo binario que contenga registros del tipo de dato especificado por el parámetro (mediante un vector en memoria,
no directamente sobre el archivo). La clase debe poseer métodos para:
1. Abrir un archivo binario y cargar los registros en memoria.
2. Obtener el registro en una posición especificada por el usuario.
3. Modificar el registro en una posición determinada.
4. Actualizar la información del archivo con los cambios.
Utilice la clase desde un programa cliente para leer los registros escritos en el archivo binario generado en el ejercicio
6.5*/
template<typename J>
class ManejadorArchivo{
private:
	fstream bin;
	vector<J> v;
public:
	ManejadorArchivo(string nom, vector<J> a) {
		bin.open(nom,ios::binary|ios::in|ios::out|ios::ate);
		if(!bin.is_open()) throw runtime_error("No se pudo abrir/crear el archivo");
		bin.seekp(0);
		
		for(size_t i=0;i<a.size();i++) { 
			bin.write(reinterpret_cast<const char*>(&a[i]),sizeof(J));
		}
		v = a;
	}
	~ManejadorArchivo() {
		bin.close();
	}
	J ObtenerRegis(int pos){
		bin.seekg(pos*sizeof(J));
		
		J aux;
		bin.read(reinterpret_cast<char*>(&aux),sizeof(J));
		
		return aux;
	}
	void ModificarRegis(int pos, J nuevo) {
		bin.seekp(pos*sizeof(J));
		bin.write(reinterpret_cast<const char*>(&nuevo),sizeof(J));
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

