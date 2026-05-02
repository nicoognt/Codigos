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
	virtual bool pertenece(Punto x)=0;
	virtual ~Recta() {}
};

class RectaGeneral : public Recta{
private:
	float a,b,c;
public:
	RectaGeneral(Punto p, Punto q) : Recta(p,q){
		a=q.y-p.y;
		b=p.x-q.x;
		c=-a*p.x-b*p.y;
	}
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
	bool pertenece(Punto aux) override {
		if (a*aux.x + b*aux.y + c==0){
			return true;
		}
		return false;
	}
};

class RectaExplicita : public Recta{
private:
	float m,b;
public:
	RectaExplicita(Punto p,Punto q) : Recta(p,q){
		m=(q.y-p.y)/(q.x-p.x);
		b=p.y-m*p.x;
	}
	string verEcuacion() override {
		if(b>0) {
			stringstream ss;
			ss<<"y="<<m<<"x+"<<b;
			string aux = ss.str();
			return aux;
		} else {
			stringstream ss;
			ss<<"y="<<m<<"x"<<b;
			string aux = ss.str();
			return aux;
		}
	}
	bool pertenece(Punto a) override {
		if (m*a.x+b==a.y){
			return true;
		}
		return false;
	}
};

int main() {
	cout<<"ingrese los datos del punto P: ";
	Punto P; cin>>P.x>>P.y;
	cout<<"ahora ingrese los datos del punto Q: ";
	Punto Q; cin>>Q.x>>Q.y;
	Recta *rt;
	rt = new RectaGeneral(P,Q);
	cout<<"la ecuacion de la recta es "<<rt->verEcuacion()<<endl;
	Punto x = {2,3};
	if (rt->pertenece(x)){
		cout<<"el punto pertenece a la recta"<<endl;
	} else {
		cout<<"el punto no pertenece a la recta"<<endl;
	}
	delete rt;
	rt = new RectaExplicita(P,Q);
	return 0;
}

