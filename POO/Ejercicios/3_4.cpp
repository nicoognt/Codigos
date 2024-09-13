#include <iostream>
#include <iomanip>
using namespace std;
class Fraccion{
private:
	double num,den;
public:
	Fraccion(double _num,double _den) {num=_num;den=_den;}
	void MostrarFraccion() {
		if (num*den<0){
			cout<<"-"<<static_cast<int>(num)<<"/"<<static_cast<int>(den)<<endl;
		} else {
			cout<<"+"<<static_cast<int>(num)<<"/"<<static_cast<int>(den)<<endl;
		}
	}
	double Convertir_Double() const {return num/den;}
};
class NumeroMixto {
private:
	int pEntera;
	Fraccion fr;
public:
	NumeroMixto(int _pEntera, double n, double d) : pEntera(_pEntera), fr(n,d) {}
	void MostrarNumero() {cout<<pEntera;fr.MostrarFraccion();}
	double ConvertirADouble() {return static_cast<double>(pEntera) + fr.Convertir_Double();}
};
int main() {
	int pe;
	double n,d;
	cout<<"parte entera, num y den: "<<endl; cin>>pe>>n>>d;
	NumeroMixto nm(pe,n,d);
	nm.MostrarNumero();
	cout<<"el resultado es "<<nm.ConvertirADouble();
	return 0;
}

