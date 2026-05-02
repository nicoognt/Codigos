#include <iostream>
using namespace std;
class Racional{
private:
	int num, den;
public:
	Racional(int _num=0,int _den=0) : num(_num), den(_den) {}
	int VerNum() const {return num;}
	int VerDen() const {return den;}
	void setNum(int a) {num=a;}
	void setDen(int b) {den=b;}
	Racional operator+(Racional r2){
		Racional resul(
		num*r2.VerDen() + r2.VerNum()*den,
		den*r2.VerDen() );
		return resul;
	}
	Racional operator*(Racional r2){
		Racional aux(
		num*r2.VerNum(),
		den*r2.VerDen() );
		return aux;
	}
	bool operator<(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer<segu);
	}
	bool operator>(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer>segu);
	}
	bool operator==(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer==segu);
	}
	bool operator!=(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer!=segu);
	}
	bool operator<=(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer<=segu);
	}
	bool operator>=(Racional r2){
		float primer = num/den, segu = r2.VerNum()/r2.VerDen();
		return (primer>=segu);
	}
	
};
istream &operator>>(istream &i,Racional r){
	int a; i>>a; r.setNum(a);
	int b; i>>b; r.setDen(b);
	return i;
}
ostream &operator<<(ostream &o,Racional r){
	o<<r.VerNum()<<"/"<<r.VerDen();
	return o;
}

int main() {
	cout<<"Ingrese numerador y denominador de la fracción: ";
	Racional r1,r2;
	cin>>r1;
	cout<<"Ahora ingrese otra fracción en el mismo formato: ";
	cout<<"La suma entre las dos fracciones es: ";
	Racional suma = r1+r2;
	cout<<suma.VerNum()<<"/"<<suma.VerDen()<<endl;
	cout<<"Y la multiplicación es: ";
	Racional mul = r1*r2;
	cout<<mul.VerNum()<<"/"<<mul.VerDen()<<endl;
	
	return 0;
}

