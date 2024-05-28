#include <iostream>
#include <matrix>
using namespace std;
void meter_datos(matrix<int> &m_empresa) {
	int suc,art,ventas;
	for(size_t i=0;i<m_empresa.size(0)*m_empresa.size(1);i++) { 
		cin>>suc>>art>>ventas;
		m_empresa[suc][art] = ventas;
	}
}
void cantidad_vendida(const matrix<int> &empresa) {
	int total;
	for (size_t i=0;i<empresa.size(1);i++) {
		total = 0;
		for (size_t j=0;j<empresa.size(0);j++) {
			total += empresa[i][j];
		}
		cout<<"la cantidad vendida del art "<<i<<" es de "<<total<<endl;
	}
}

int ventas_3(matrix<int> &emp) {
	int total = 0;
	for (size_t i=0;i<emp.size(1);i++) {
		total += emp[3][i];
	}
	return total;
}

int suc1_art6(matrix<int> &m_emp) {
	return m_emp[1][6];
}

int mayor_8(matrix<int> &empresilla) {
	int max = -1;
	for (size_t i=0;i<empresilla.size(0);i++) {
		if (empresilla[i][8] > max) {
			max = i;
		}
	}
	return max;
}

int main() {
	matrix<int> m_empresa(4,25);
	
	meter_datos(m_empresa);
	cantidad_vendida(m_empresa);
	
	
	cout<<"la sucursal N° 3 tuvo "<<ventas_3(m_empresa)<<" ventas"<<endl;
	cout<<"la sucursal N° 1 vendió "<<suc1_art6(m_empresa)<<" unidades del art 6"<<endl;
	cout<<"la sucursal que más unidades vendió del art 8 fue la "<<mayor_8(m_empresa);
	return 0;
}

