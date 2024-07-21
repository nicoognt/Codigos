#include <iostream>
#include <vector>
using namespace std;
/// a) Implemente una función C++ que reciba un vector de strings "casi ordenado"
/// alfabéticamente y lo modifique eliminando del vector todos aquellos elementos que no respeten el orden
/// alfabético (o creciente) con respecto al elemento anterior. La función NO debe utilizar un segundo vector auxiliar.
void ordenar(vector<string> &v){
	for(size_t i=1;i<v.size();i++) { 
		if (v[i]<v[i-1]){
			for(size_t j=i;j<v.size()-1;j++){
				v[j]=v[j+1];
			}
			v.resize(v.size()-1);
		}
	}
}
int main() {
/// b) Escriba además un programa para probar la función con un vector de strings que se ingrese
/// por teclado. Muestre el vector resultante totalmente ordenado.
/// Ejemplo: si v={"Carlos","Alba","Cintia","Saul","Zoe","Luisa","Marta"}; debe quedar: v={"Carlos","Cintia",
/// "Saul","Zoe"}
	vector<string> nombres(6);
	for(size_t i=0;i<nombres.size();i++) { 
		cin>>nombres[i];
	}
	//vector desordenado
	for(size_t i=0;i<nombres.size();i++) { 
		cout<<nombres[i];
	}
	
	ordenar(nombres);
	
	//vector ordenado
	for(size_t i=0;i<nombres.size();i++) { 
		cout<<nombres[i];
	}
	return 0;
}

