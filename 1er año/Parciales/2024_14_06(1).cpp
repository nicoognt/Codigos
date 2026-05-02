#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

void gasto_mayor(const matrix<int> &m){
	for(size_t i=0;i<m.size(0);i++){
		for(size_t j=1;j<m.size(1);j++){
			if(m[i][j]>m[i][j-1]){
				cout<<"El hospital "<<i+1<<" tuvo un gasto mayor en el mes "<<j+1<<" con respecto al mes "<<j<<endl;
			}
		}
	}
}

pair<int,int> calculadora(const matrix<int> &m,int codigo){
	int mes,monto=0;
	for(size_t i=0;i<m.size(1);i++){
		if(m[codigo-1][i]>monto){
			monto = m[codigo-1][i];
			mes = i+1;
		}
	}
	return {mes,monto};
}

int main() {

/// a) Escriba un programa C++ que lea los presupuestos anuales asignados a 10 hospitales de
///	una provincia al inicio del año 2023 destinado a insumos. Estos datos se leen de a pares: cod hospital
///	(1..10), monto del presupuesto anual. Luego se deben ingresar los 4 datos de cada gasto efectuado por
///	cada hospital en el año: cod. hospital (1..10), dia (1..31), mes (1..12), monto.. Estos datos terminan con
///	cod. hospital cero. El programa debe organizar una matriz de 10 filas (hospitales) por 12 columnas
///	(meses) donde se indiquen en cada celda los montos por gastos de cada hospital en cada mes del año
///	2023. Considere que en un mismo mes un mismo hospital puede realizar varios gastos por mes.
	int codHospital,monto,mes,dia;
	vector<int> presupuestos(10);
	
	for(int i=0;i<10;i++) { 
		cin>>codHospital>>monto;
		presupuestos[codHospital]=monto;
	}
	
	matrix<int> gastos(10,12,0);
	cin>>codHospital;
	while(codHospital!=0){
		cin>>dia>>mes>>monto;
		gastos[codHospital-1][mes-1]+=monto;
		cin>>codHospital;
	}
	
/// Luego el programa debe informar: b) Cuáles hospitales terminaron con déficit al finalizar el año (mayores gastos que
///	el presupuesto anual);
	
	for(size_t i=0;i<gastos.size(0);i++){
		if(gastos[i][11]>presupuestos[i]){
			cout<<"El hospital "<<i+1<<" finalizó el año con déficit"<<endl;
		}
	}
	
/// c) Por cada mes, cuántos hospitales tuvieron un gasto mayor al mes anterior;
	gasto_mayor(gastos);
	
/// d) El mes y monto de mayor gasto de un hospital que el usuario ingresa como dato.
	cin>>codHospital;
	pair<int,int> mes_gasto = calculadora(gastos,codHospital);
	cout<<"En el mes "<<mes_gasto.first<<" se encontró el mayor gasto, con: "<<mes_gasto.second<<endl;
	return 0;
}

