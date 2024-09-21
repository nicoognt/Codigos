#include <iostream>
#include <vector>
using namespace std;
/**a) Diseñe una clase Pasajero para guardar los datos de un pasajero de un vuelo de avión.
La clase debe guardar un string con apellido y nombre, tipo de pasaje (estándar o 1ra clase) y peso del
equipaje a despachar. Estos datos deben inicializarse en el constructor de la clase.
b) Reutilizando la clase Pasajero, diseñe una clase Vuelo para representar los datos de un vuelo. La
clase debe tener un constructor que permita definir los aeropuertos de origen y destino, y la cantidad de
asientos disponibles de cada tipo. Debe tener además:
- c) un método para agregar un pasajero al vuelo; este método deberá retornar true si el pasajero debe
pagar por exceso de equipaje (si su equipaje supera los 15ks para un pasaje estándar, o los 30ks para
1ra clase).
- d) un método para consultar la cantidad de asientos disponibles de un cierto tipo (el tipo será el
argumento, estándar o 1ra clase, y se calcula restando al total los ocupados por pasajeros ya
cargados).
- e) un método para obtener el peso total del equipaje (sumando el de todos los pasajeros).
Declare en ambas clases todos los métodos que considere adecuados o necesarios, pero implemente
solo los constructores y los métodos que se piden explícitamente en c, d y e (para los demás, solo
escriba el prototipo).**/
class Pasajero{
private:
	string nombre,pasaje;
	float kg_equi;
public:
	Pasajero(string _n,string _p,float _kg) : nombre(_n),pasaje(_p),kg_equi(_kg) {}
	float VerPeso() const {return kg_equi;}
	string VerPasaje() const {return pasaje;}
};

class Vuelo{
private:
	string origen,destino;
	vector<Pasajero*> trips;
	int estandar,primera;
public:
	Vuelo(string _origen,string _destino,int _estandar,int _primera) : origen(_origen), destino(_destino),estandar(_estandar),primera(_primera) {}
	bool AgregarPas(Pasajero* x){
		if (x->VerPasaje()=="estandar"){
			if(x->VerPeso()>15){
				trips.push_back(x);
				return true;
			} else {
				trips.push_back(x);
				return false;
			}
		} else {
			if (x->VerPeso()>30){
				trips.push_back(x);
				return true;
			} else {
				trips.push_back(x);
				return false;
			}
		}
	}
	int AsientosDisponibles(string clase){
		int cont=0;
		for(Pasajero* x : trips) {
			if (x->VerPasaje()==clase){
				cont++;
			}
		}
		if (clase=="estandar"){
			return estandar-cont;
		} else {return primera-cont;}
	}
	float PesoTotal() {
		float cont = 0;
		for(Pasajero* x : trips) { 
			cont+=x->VerPeso();
		}
		return cont;
	}
};
int main() {
	
	return 0;
}

