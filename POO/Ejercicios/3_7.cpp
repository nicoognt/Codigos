#include <iostream>
#include <sstream>
using namespace std;
struct Punto {
	float x,y;
};
class Recta {
private:
	Punto p,q;
public:
	Recta(Punto _p,Punto _q) : p(_p),q(_q) {}
	virtual string verEcuacion() =0;
};

class RectaGeneral : public Recta{
private:
	float a,b,c;
public:
	RectaGeneral(Punto p, Punto q){
		a=q.y-p.y;
		b=p.x-q.x;
		c=-a*p.x-b*p.y;
	}
	float verA() {return a;}
	float verB() {return b;}
	float verC() {return c;}
	string verEcuacion() override {
		stringstream ss;
		if(b>0 && c>0){
			ss<<a<<"x+"<<b<<"y+"<<c<<"=0";
		} else if(b>0){
			ss<<a<<"x+"<<b<<"y"<<c<<"=0";
		} else if(c>0) {
			ss<<a<<"x"<<b<<"y+"<<c<<"=0";
		} else {
			ss<<a<<"x"<<b<<"y"<<c<<"=0";
		}
		string aux = ss.str();
		return aux;
	}
};
int main() {
	
	return 0;
}

