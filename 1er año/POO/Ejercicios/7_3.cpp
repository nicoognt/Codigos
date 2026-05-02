#include <iostream>
using namespace std;

template<typename T>
class VectorDinamico{
private:
	T* ptr;
public:
	VectorDinamico(int tam){
		ptr = new T[tam];
	}
	~VectorDinamico(){
		delete[] ptr;
	}
};
int main() {
	
	return 0;
}

