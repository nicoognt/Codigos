#include <iostream>
using namespace std;
struct Tiempos {
	int fecha;
	int mins1, mins2, mins3;
	int segs1, segs2, segs3;
};

int main() {
	int N;
	cin >> N;
	vector<Tiempos> v(N);
	
	for (Tiempos &x : v) {
		cin >> x.fecha;
		cin >> x.mins1 >> x.segs1;
		cin >> x.mins2 >> x.segs2;
		cin >> x.mins3 >> x.segs3;
	}
	
	int menor_mins1 = menor_mins2 = menor_mins3 = 999;
	int menor_segs1 = menor_segs2 = menor_segs3 = 999;
	
	
	for (int i = 0;i<N;i++) {
		int mins = v[i].mins1, segs = v[i].segs1;
		while (segs >=60) {
			segs -= 60;
			mins += 1;
		}
		if (mins < menor_mins1) {
			menor_mins1 = mins;
			menor_segs1 = segs;
		} else if (segs < menor_segs1) {
			menor_mins1 = mins;
			menor_segs1 = segs;
		}
	}
	for (int i = 0;i<N;i++) {
		int mins = v[i].mins2, segs = v[i].segs2;
		while (segs >=60) {
			segs -= 60;
			mins += 1;
		}
		if (mins < menor_mins2) {
			menor_mins2 = mins;
			menor_segs2 = segs;
		} else if (segs < menor_segs2) {
			menor_segs2 = segs;
		}
	}
	for (int i = 0;i<N;i++) {
		int mins = v[i].mins3, segs = v[i].segs3;
		while (segs >=60) {
			segs -= 60;
			mins += 1;
		}
		if (mins < menor_mins3) {
			menor_mins3 = mins;
			menor_segs3 = segs;
		} else if (segs < menor_segs3) {
			menor_segs3 = segs;
		}
	}
	
	for (int i=0;i<N;i++) {
		int prom_mins = (v[i].mins1 + v[i].mins2 + v[i].mins3)/3;
		int prom_segs = (v[i].segs1 + v[i].segs2 + v[i].segs3)/3;
		cout << prom_mins << "', " << prom_segs << "''" << endl;
	}
	
	Tiempos primero, segundo;
	primero.mins1 = primero.mins2 = primero.mins3 = 999
	primero.segs1 = primero.segs2 = primero.segs3 = 999
	for (int i=0;i<N;i++) {
		int suma_mins = v[i].mins1 + v[i].mins2 + v[i].mins3;
		int suma_segs = v[i].segs1 + v[i].segs2 + v[i].segs3;
		while (suma_segs >= 60) {
			suma_segs -= 60;
			suma_mins += 1;
		}
		if (suma_mins < primero.mins1) 
		
	}
	
	return 0;
}

