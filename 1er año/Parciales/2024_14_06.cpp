#include <iostream>
#include <vector>
using namespace std;
struct Fecha{
	int dia,mes,anio;
};
struct Persona {
	string ape,noms,cat;
	long dni;
};

int edad(Fecha naci,Fecha hoy){
	int anos = hoy.anio-naci.anio;
	if(hoy.mes-naci.mes<0){
		anos--;
	}
	return anos;
}
	
void actualizar(Persona &a,int e){
	if(e<=12){
		a.cat="Infantil";
	} else if(e<=18){
		a.cat="Juvenil";
	} else {
		a.cat="Mayor";
	}
}

int main() {
	
	Fecha f_nac,f_hoy={19,7,2024};
	cout<<"Ingrese la fecha de nacimiento: "<<endl;
	cin>>f_nac.dia>>f_nac.mes>>f_nac.anio;
	int e=edad(f_nac,f_hoy);
	
	int N;
	cin>>N;
	vector<pair<Persona,Fecha>> club(N);
	
	int cuota1,cuota2,cuota3;
	cin>>cuota1>>cuota2>>cuota3;
	for(int i=0;i<N;i++) { 
		Persona auxP;
		Fecha auxF;
		cin>>auxP.ape>>auxP.noms>>auxP.dni>>auxP.cat;
		cin>>auxF.dia>>auxF.mes>>auxF.anio;
		club[i] = {auxP,auxF};
	}
	
	for(int i=0;i<N;i++) { 
		e=edad(club[i].second,f_hoy);
		actualizar(club[i].first,e);
	}
	
	int contInfantiles=0,contJuveniles=0,contMayores=0;
	for(int i=0;i<N;i++) { 
		if(club[i].first.cat=="Infantil"){
			contInfantiles++;
		} else if(club[i].first.cat=="Juvenil"){
			contJuveniles++;
		} else {
			contMayores++;
		}
	}
	
	int total = contInfantiles*cuota1+contJuveniles*cuota2+contMayores*cuota3;
	cout<<total;
	return 0;
}

