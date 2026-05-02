#include <iostream>
using namespace std;
//pongo fechas de la forma 20060419
int difer(int fecha1,int fecha2){
	int dias1,dias2,total;
	
	dias1=(fecha1/10000)*365+((fecha1%10000)/100)*30+fecha1%100;
	dias2=(fecha2/10000)*365+((fecha2%10000)/100)*30+fecha2%100;
	
	if (dias1>dias2) {
		total=(dias1-dias2)/365;
	} else {
		total=(dias2-dias1)/365;
	}
	return total;
}

int main(int argc, char *argv[]) {
	int fecha1,fecha2,diferencia;
	cout<<"escriba la fecha en formato aaaa/mm/dd: "<<endl;
	cin>>fecha1>>fecha2;
	diferencia=difer(fecha1,fecha2);
	cout<<"la diferencia entre las fechas es de "<<diferencia<<endl;
	return 0;
}

