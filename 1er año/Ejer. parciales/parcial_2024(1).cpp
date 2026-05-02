#include <iostream>
#include <vector>
using namespace std;
struct paciente {
	string ape_nom;
	int DNI;
	string OS;
	int fecha_nac;
};

int bajo_45(const vector<paciente> &a,int f_act) {
	int dif, cont = 0;
	for(size_t i=0;i<a.size();i++) { 
		dif = ((f_act/10000) - a[i].fecha_nac/10000);
		if (dif < 45)
			cont++;
	}
	return cont;
}

void agrega_inicio(vector<paciente> &b,paciente nuevo){
	bool no_esta = true;
	for(size_t i=0;i<b.size();i++) { 
		if (b[i].ape_nom = nuevo.ape_nom)
			no_esta = false;
	}
	if (no_esta) {
		b.resize(b.size()+1);
		for(int i=b.size()-1;i>0;--i) { 
			b[i+1] = b[i];
		}
		b[0] = nuevo;
	}
}

vector<paciente> lista_os(const vector<paciente> &c, string obra) {
	vector<paciente> auxiliar;
	for(size_t i=0;i<c.size();i++) { 
		if (c[i].OS == obra) {
			auxiliar.push_back(c[i]);
		}
	}
	return auxiliar;
}

int main() {
	int n;
	cin>>n;
	vector<paciente> paci(n);
	
	for(int i=0;i<n;i++) { 
		cout<<"Apellido y nombres del paciente "<<i<<": ";
		getline(cin,paci[i].ape_nom); cout<<endl;
		cout<<"DNI: ";
		cin.ignore();
		cin>>paci[i].DNI; cout<<endl;
		cout<<"Obra social (si no tiene, ingrese tres guiones): ";
		cin>>paci[i].OS; cout<<endl;
		cout<<"Fecha de nacimiento (aaaammdd): ";
		cin>>paci[i].fecha_nac; cout<<endl;
	}
	int fecha_actual;
	cin>>fecha_actual;
	
	int menor_45 = bajo_45(paci,fecha_actual);
	cout<<"Los pacientes menores a 45 años son "<<menor_45;
	paciente regis_nuevo;
	
	cout<<"Apellido y nombres del paciente nuevo: ";
	getline(cin,regis_nuevo.ape_nom); cout<<endl;
	cout<<"DNI: ";
	cin.ignore();
	cin>>regis_nuevo.DNI; cout<<endl;
	cout<<"Obra social (si no tiene, ingrese tres guiones): ";
	cin>>regis_nuevo.OS; cout<<endl;
	cout<<"Fecha de nacimiento (aaaammdd): ";
	cin>>regis_nuevo.fecha_nac; cout<<endl;
	agrega_inicio(paci,regis_nuevo);
	
	string obra_social;
	cin>>obra_social;
	vector<paciente> nueva_lista = lista_os(obra_social,paci);
	
	cout<<"Los pacientes con la obra social "<<obra_social<<" son: "<<endl;
	for(paciente x : nueva_lista) { 
		cout<<x.ape_nom;
		cout<<x.DNI;
		cout<<x.fecha_nac;
	}
	
	return 0;
}

