#include <iostream>
#include <vector>
using namespace std;
/**a) Un color en un programa se suele modelar mediante 3 valores numéricos (entre 0 y 1)
que indican cuánto de luz roja(r), cuánto de luz verde(g) y cuánto de luz azul(b) hay que mezclar para
formarlo. Escriba una clase Color para representar un color de esta forma, con:
- un constructor que reciba los 3 valores, y métodos para consultarlos.
- una sobrecarga para el operador + que permita sumar dos colores. Por ej, si el primero tiene los
valores r=1, g=0.5, b=0, y el 2do r=0.2, g=0.2, b=0.2, el resultado tendrá r=1.2, g=0.7, b=0.2 (se suma
rojo con rojo, verde con verde y azul con azul).
- un método Normalizar que corrija los valores: si alguno es mayor a 1, que se le asigne 1. Por ej: r=1.2,
g=0.7, b=0.2 pasaría a ser r=1, g=0.7, b=0.2.
- una sobrecarga para mostrar un color por pantalla (debe mostrar los tres valores identificándolos con
las letras r, g y b. Por ej: "r=1.2, g=0.7, b=0.2")
b) En un videojuego, el personaje principal va cambiando de color a medida que adquiere poderes.
Cada vez que obtiene un nuevo poder el color del poder se suma a su color actual. Implemente una
clase Personaje con:
- Un constructor que reciba el nombre del jugador y su color inicial, y métodos para consultarlos.
- Un método TienePoder que reciba el nombre de un poder y retorne true si el personaje ya lo tiene (la
clase deberá guardar internamente los nombres de los poderes que tiene el personaje).
- Un método AgregarPoder que reciba el nombre (string) y el color de un poder. Si el personaje ya tenía
ese poder, el método debe retornar false. Si no lo tenía debe debe actualizar el color normalizado del
personaje (es decir, sumarlo al que tenía y normalizar el resultado) y retornar true.**/
class Color{
private:
	float r,g,b;
public:
	Color(float _r,float _g,float _b) : r(_r),g(_g),b(_b) {}
	int VerR() const {return r;}
	int VerG() const {return g;}
	int VerB() const {return b;}
	void Normalizar() {
		if(r>1) {r=1;}
		if(g>1) {g=1;}
		if(b>1) {b=1;}
	}
	Color operator+(const Color &c){
		Color resul(
					r + c.VerR(),
					g + c.VerG(),
					b + c.VerB() );
		return resul;
	}
};

ostream &operator<<(ostream &o,Color &c){
	o<<"r="<<c.VerR()<<", g="<<c.VerG()<<", b="<<c.VerB();
	return o;
}
class Personaje{
private:
	string nombre;
	Color inicial;
	vector<string> poderes;
public:
	Personaje(string _nom,Color c) : nombre(_nom),inicial(c) {}
	string VerNom() const {return nombre;}
	void VerColor() {
		cout<<"r="<<inicial.VerR()<<", g="<<inicial.VerG()<<", b="<<inicial.VerB();
	}
	bool TienePoder(string poder){
		if (poderes.size()==0) {
			return false;
		} else {
			for(size_t i=0;i<poderes.size();i++) { 
				if(poderes[i]==poder){
					return true;
				}
			}
			return false;
		}
	}
	bool AgregarPoder(string poder,Color c){
		if(TienePoder(poder)){
			return false;
		} else {
			poderes.push_back(poder);
			inicial=inicial+c;
			inicial.Normalizar();
			return true;
		}
	}
};
int main() {
	
	return 0;
}

