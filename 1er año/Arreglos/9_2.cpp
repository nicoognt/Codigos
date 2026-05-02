#include <iostream>
#include <vector>
using namespace std;

void azar(vector<int> &vector_a_modificar) {
	for(size_t i=0;i<vector_a_modificar.size();i++) { 
		vector_a_modificar[i]=rand()%50+100;
	}
}
void cambiate_pa(vector<int> &vector_random,int m,int p) {
	vector_random.resize(vector_random.size() + 1);
	for (int i=vector_random.size()-1;i>=p;i--) {
		vector_random[i]=vector_random[i-1];
	}
	vector_random[p-1] = m;
}

int main() {
	vector<int> nums(20);
	//funcion para poner numeros al azar
	azar(nums);
	cout<<"el nuevo vector es: "<<endl;
	//mostrar el vector con los nuevos valores
	for(size_t i=0;i<nums.size();i++) { 
		cout<<nums[i]<<" ";
	} cout << endl;
	//ahora hay que mover la lista desde P, una posición más para meter M
	//alguna función que lo haga
	cout<<"qué valor nuevo quiere insertar? En qué posición?: "<<endl;
	int m,p;
	cin>>m>>p;
	cambiate_pa(nums,m,p);
	cout<<"el vector corrido es: ";
	//muestro el nuevo vector
	for(size_t i=0;i<nums.size();i++) { 
		cout<<nums[i]<<" ";
	}
	return 0;
}


