#include <iostream>
#include <matrix>
using namespace std;

int main() {
/// Una empresa que comercializa jugos en caja, tiene 15 vendedores quienes que levantan
/// pedidos de clientes durante el mes de junio (30 días). Por cada pedido, se ingresan sin orden alguno las ternas
/// correspondientes al código del vendedor (1 a 15), el dia (1...30) y la cantidad de cajas de jugo encargadas,
/// pudiendo haber más de un pedido diario del mismo vendedor. Los datos finalizan con el código de vendedor
/// igual a 0.
	matrix<int> jugos(15,30,0);
	int cod_ven, dia, pedidos;
	cin>>cod_ven;
	while (cod_ven!=0) {
		cin>>dia>>pedidos;
		jugos[cod_ven][dia]+=pedidos;
		cin>>cod_ven;
	}
/// Luego, se desea obtener e informar:
/// a) ¿Cuál es el código de vendedor que más pedidos hizo para el día 10?
	int mayor, pedidos_mayor=-1;
	for(size_t i=0;i<jugos.size(0);i++) { 
		if (jugos[i][9]>pedidos_mayor) {
			pedidos_mayor=jugos[i][9];
			mayor=i;
		}
	}
/// b) ¿Cuál es la cantidad vendida por día considerando todos los vendedores?
	for(size_t i=0;i<jugos.size(1);i++) { 
		int suma=0;
		for(size_t j=0;j<jugos.size(0);j++) { 
			suma+=jugos[j[i];
		}
		cout<<suma;
	}
/// c) ¿Cuántas cajas vendió en total el vendedor 10?
	int total=0;
	for(size_t i=0;i<jugos.size(1);i++) { 
		total=jugos[9][i];
	}
	cout<<total;
	return 0;
}

