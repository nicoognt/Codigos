#include <iostream>
#include <cmath>
using namespace std;
/**En un juego el usuario controla una partícula que debe moverse por la pantalla e ir
absorbiendo otras partículas más pequeñas. Al tocar una partícula más pequeña, la del jugador la
absorbe y entonces crece en tamaño. Pero si intenta absorber una más grande, pierde una vida.
a) Diseñe una clase Particula. Debe tener un constructor que reciba su radio, y un método para obtener
su área (pi*r²). b) Implemente una sobrecarga del operador < para comparar dos partículas según su
radio. c) Implemente una sobrecarga para el operador += que permita sumar dos partículas (el
resultado debe guardarse en la primera). La partícula resultante debe tener un área igual a la suma de
las dos originales (entonces, si a1 y a2 son las áreas originales, el radio de la nueva será sqrt((a1+a2)/pi) ).
d) Implemente una clase Jugador que represente la partícula del jugador. Esta, además de su radio,
debe tener una cantidad de vidas (que se reciba como argumento en su constructor).
e) Implemente una función libre (no será método de ninguna clase) colision que reciba al jugador y otra
partícula contra la cual colisiona. Si la otra es menor a la del jugador, debe sumar ambas en la del
jugador (es decir, crece la del jugador). Si la otra es mayor o igual, debe restarle una vida al jugador. La
función retornará false cuando las vidas lleguen a 0; true en caso contrario**/
class Particula{
private:
	float radio,area;
public:
	Particula(float _radio) : radio(_radio),area(3.14*_radio*_radio) {}
	float VerRadio() const {return radio;}
	float VerArea() const {return area;}
	bool operator<(Particula &p2){
		return (this->radio<p2.VerRadio());
	}
	bool operator>=(Particula &p2){
		return (this->radio>=p2.VerRadio());
	}
	Particula& operator+=(Particula& p2){
		area += p2.VerArea();
		radio = sqrt(area/3.14);
		return *this;
	}
};

class Jugador : public Particula{
private:
	int vidas;
public:
	Jugador(float _radio,int _vidas) : Particula(_radio),vidas(_vidas) {}
	void RestarVida() {vidas--;}
	int VerVidas() const {return vidas;}
};

bool Colision(Jugador& x,Particula& p){
	if (x>=p){
		x+=p;
	} else {
		x.RestarVida();
	}
	if (x.VerVidas()==0){
		return false;
	}
	return true;
}
int main() {
	
	return 0;
}

