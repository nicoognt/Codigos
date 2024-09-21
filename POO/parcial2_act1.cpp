#include <iostream>
#include <vector>
using namespace std;
/**a) Dise�e una clase Pasajero para guardar los datos de un pasajero de un vuelo de avi�n.
La clase debe guardar un string con apellido y nombre, tipo de pasaje (est�ndar o 1ra clase) y peso del
equipaje a despachar. Estos datos deben inicializarse en el constructor de la clase.
b) Reutilizando la clase Pasajero, dise�e una clase Vuelo para representar los datos de un vuelo. La
clase debe tener un constructor que permita definir los aeropuertos de origen y destino, y la cantidad de
asientos disponibles de cada tipo. Debe tener adem�s:
- c) un m�todo para agregar un pasajero al vuelo; este m�todo deber� retornar true si el pasajero debe
pagar por exceso de equipaje (si su equipaje supera los 15ks para un pasaje est�ndar, o los 30ks para
1ra clase).
- d) un m�todo para consultar la cantidad de asientos disponibles de un cierto tipo (el tipo ser� el
argumento, est�ndar o 1ra clase, y se calcula restando al total los ocupados por pasajeros ya
cargados).
- e) un m�todo para obtener el peso total del equipaje (sumando el de todos los pasajeros).
Declare en ambas clases todos los m�todos que considere adecuados o necesarios, pero implemente
solo los constructores y los m�todos que se piden expl�citamente en c, d y e (para los dem�s, solo
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

