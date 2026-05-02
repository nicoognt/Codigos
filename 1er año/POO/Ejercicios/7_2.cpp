#include <iostream>
using namespace std;

template<typename T>
void clamp(T &x, T sup, T inf){
	if (x>sup) {
		x = sup;
	} else if (x<inf) {
		x = inf;
	}
}
int main() {
	float f = 0.5, a, b;
	cin>>a>>b;
	clamp(f, a, b);  //el error surge por querer meter un int en un float
	return 0;
}

