#include <iostream>
#include <cmath>
using namespace std;
/**En un juego el usuario controla una part�cula que debe moverse por la pantalla e ir
absorbiendo otras part�culas m�s peque�as. Al tocar una part�cula m�s peque�a, la del jugador la
absorbe y entonces crece en tama�o. Pero si intenta absorber una m�s grande, pierde una vida.
a) Dise�e una clase Particula. Debe tener un constructor que reciba su radio, y un m�todo para obtener
su �rea (pi*r�). b) Implemente una sobrecarga del operador < para comparar dos part�culas seg�n su
radio. c) Implemente una sobrecarga para el operador += que permita sumar dos part�culas (el
resultado debe guardarse en la primera). La part�cula resultante debe tener un �rea igual a la suma de
las dos originales (entonces, si a1 y a2 son las �reas originales, el radio de la nueva ser� sqrt((a1+a2)/pi) ).
d) Implemente una clase Jugador que represente la part�cula del jugador. Esta, adem�s de su radio,
debe tener una cantidad de vidas (que se reciba como argumento en su constructor).
e) Implemente una funci�n libre (no ser� m�todo de ninguna clase) colision que reciba al jugador y otra
part�cula contra la cual colisiona. Si la otra es menor a la del jugador, debe sumar ambas en la del
jugador (es decir, crece la del jugador). Si la otra es mayor o igual, debe restarle una vida al jugador. La
funci�n retornar� false cuando las vidas lleguen a 0; true en caso contrario**/
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

