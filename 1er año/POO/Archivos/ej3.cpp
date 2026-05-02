#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
struct CampoValor{
	string campo,valor;
};

class ConfigFile{
private:
	vector<CampoValor> v;
public:
	ConfigFile(const string &NombreArchivo){
		ifstream lectura(NombreArchivo);
		if (!lectura.is_open()) throw runtime_error("No se pudo abrir el archivo deseado");
		
		string linea;
		while(getline(lectura,linea)){
			if (linea[0]=='#') {
				continue;
			}
			
			size_t posi = linea.find('=');
			if (posi != string::npos){
				string campo = linea.substr(0,posi), valor= linea.substr(posi + 1);
				CampoValor aux = {campo,valor};
				v.push_back(aux);
			}
		}
		lectura.close();
	}
	
	string ValorBuscado(const string &buscar){
		string a;
		for(const CampoValor &aux : v){
			if (aux.campo==buscar) {
				a = aux.valor;
			}
		}
		return a;
	}
	
	void CambiarCampo(const CampoValor &aux){
		for(CampoValor &a : v){
			if(a.campo==aux.campo){
				a = aux;
				break;
			}
		}
	}
	
	void Actualizar(const string &NombreArchi){
		ofstream escritura(NombreArchi);
		if (!escritura.is_open()) throw runtime_error("No se pudo abrir el archivo deseado");
		
		for(const CampoValor &a : v){
			escritura << a.campo << '=' << a.valor << endl;
		}
		escritura.close();
	}
};

int main() {
	string nom_archivo,rta,camp,val;
	cout<<"Ingrese el nombre del archivo con los parámetros: ";
	cin>>nom_archivo;
	ConfigFile c1(nom_archivo);
	
	cout << "¿Desea conocer el valor de algun campo concreto?" << endl;
	cin >> rta;
	if (rta=="si" || rta=="Si"){
		cout << "ingresa el nombre del campo: ";
		cin >> camp;
		cout << c1.ValorBuscado(camp) << endl;
	} else {
		cout << "fua que amargado" << endl;
	}
	
	cout << "Ahora vamos a cambiar el valor de algún campo. Ingrese el nombre del campo y su nuevo valor: ";
	cin>>camp;
	cin.ignore();
	getline(cin,val);
	c1.CambiarCampo({camp,val});
	cout << "El campo ya fue modificado. ¿Querés que actualice el archivo?" << endl;
	cin >> rta;
	if (rta=="si" || rta=="Si"){
		c1.Actualizar(nom_archivo);
		cout << "Ya actualicé el archivo. Disfrutalo :D";
	} else {
		cout << "bue no querés nada. Sos re putito";
	}
	
	return 0;
}

