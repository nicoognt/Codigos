#include <iostream>
#include <sstream>
using namespace std;
struct Punto{
	float x,y;
};
class RectaExplicita{
private:
	float m,b;
public:
	RectaExplicita(Punto p,Punto q) {m=(q.y-p.y)/(q.x-p.x);b=p.y-m*p.x;}
	float verM() const {return m;}
	float verB() const {return b;}
	bool Pertenece(const Punto &p) {
		if(m*p.x+b==p.y)
			return true;
		return false;
	}
	string ObtenerEcuacion() {
		stringstream ss;
		if(b<0){
			ss<<"y="<<m<<"x"<<b;
		} else if(b>0){
			ss<<"y="<<m<<"x"<<"+"<<b;
		} else {
			ss<<"y="<<m<<"x";
		}
		string aux = ss.str();
		return aux;
	}
};
int main() {
	Punto p1 = {7,2},p2 = {9,4};
	RectaExplicita r1(p1,p2);
	cout<<"pendiente: "<<r1.verM()<<"\n"<<"ordenada al origen: "<<r1.verB()<<endl;;
	string ec = r1.ObtenerEcuacion();
	cout<<ec<<endl;;
	Punto raro = {5,1};
	if(r1.Pertenece(raro)){
		cout<<"el punto pertenece a la recta";
	} else {
		cout<<"el punto no pertecene a la recta";
	}
	return 0;
}

