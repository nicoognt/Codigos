#include <iostream>
#include <cmath>
using namespace std;

float disc(int a,int b,int c) {
	return b*b-4*a*c;
}

pair<float,float> raices_reales(int a, int b, int c) {
	pair<float,float> r;
	float discriminante = disc(a,b,c);
	if (discriminante>=0) {
		r.first=(-b+sqrt(disc(a,b,c)))/(2*a);
		r.second=(-b-sqrt(disc(a,b,c)))/(2*a);
	}
	return r;
}
pair<float,float> raices_complejas(int a,int b,int c) {
	pair<float,float> rc;
	float discriminante = disc(a,b,c);
	if (discriminante<0) {
		rc.first = -b/(2*a);
		rc.second = sqrt(-1*discriminante);
	}
	return rc;
}
int main(int argc, char *argv[]) {
	
	int a,b,c;
	cout<<"ingrese valores para a, b y c"<<endl;
	cin>>a>>b>>c;
	float discriminante=disc(a,b,c);
	
	if (discriminante>=0) {
		pair<float,float> r = raices_reales(a,b,c);
		float r1 = r.first, r2 = r.second;
		cout<<"x1 = "<<r1<<endl<<"x2 = "<<r2;
	} else {
		pair<float,float> r = raices_complejas(a,b,c);
		float p_real = r.first,p_imagin = r.second;
		cout<<p_real<<" + "<<p_imagin<<"i"<<endl;
		cout<<p_real<<" - "<<p_imagin<<"i";
	}
	
	return 0;
}

