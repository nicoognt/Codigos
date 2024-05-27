#include <iostream>
using namespace std;

void mil_primos(int num) {...
int main(int argc, char *argv[]) {
	int n=2,cont=0;
	while (cont<=1000) {
		if (mil_primos(n)){
			cont++;
			n++;
		}else{
			n++;
		}
	}
	
	return 0;
}

