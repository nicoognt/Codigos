#include <iostream>
using namespace std;

class Punto{
private:
	int x,y;
public:
	Punto();
	void setPunto(int,int);
	int getPuntoX();
	int getPuntoY();
};

Punto::Punto() {
}
void Punto::setPunto(int _x,int _y){
	x = _x;
	y = _y;
}
int Punto::getPuntoX(){
	return x;
}
int Punto::getPuntoY(){
	return y;
}

int main() {
	Punto p1;
	p1.setPunto(15,12);
	cout<<p1.getPuntoX()<<endl;
	cout<<p1.getPuntoY();
	
	return 0;
}

