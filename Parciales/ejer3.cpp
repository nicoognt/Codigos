#include <iostream>
#include <matrix>
#include <string>
#include <vector>
using namespace std;

struct cantidad {
	int autos;
	int utilitario;
};

int main() {
	int n;
	cin >> n;
	matrix<string> m(n,4);
	
	int alum;
	int ev;
	string docente;
	cin >> alum;
	while (alum != -1) {
		cin >> ev;
		cin.ignore();
		getline(cin,docente);
		m[alum][ev] = docente;
		
		cin >> alum;
	}
	
	for(size_t i=0;i<m.size(0);i++) { 
		int cont = 0;
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] != "No rindi�") {
				cont++;
			}
		}
		cout << "En la instancia " << i+1 << " se presentaron " << cont << "alumnos";
	}
	
	vector<int> lista;
	for(size_t i=0;i<m.size(0);i++) { 
		if (m[i][0] == "No rindi�" and m[i][1] == "No rindi�" and m[i][2] == "No rindi�" and m[i][3] == "No rindi�") {
			lista.push_back(i);
		}
	}
	
	cin >> docente;
	int cont = 0;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] == docente) {
				cont++;
			}
		}
	}
	
	cout << docente << " corrigi� " << cont << " parciales";
	return 0;
}

