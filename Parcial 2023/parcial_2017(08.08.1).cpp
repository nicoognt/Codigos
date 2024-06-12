#include <iostream>
#include <vector>
using namespace std;
bool validar_contrasena(string contra) {
	bool permitido = true;
	if (contra == "1234" or contra == "asdf" or contra == "pass" or contra == "") {
		return false;
	} else 
		return true;
}

int main() {
/// Escriba un programa en C++ que simule un sistema de control de acceso por contraseña de la siguiente manera: a) En una primer etapa debe permitir cargar
/// los datos de los usuarios válidos (pares de datos: nombre y contraseña). No se conoce la cantidad de usuarios válidos y los datos terminan con el usuario “ZZZ”.
	vector<pair<string,string>> acceso;
	string usuario, contrasena;
	
	cin >> usuario;
	while (usuario != "ZZZ") {
		cin >> contrasena;
		if (validar_contrasena(contrasena)) {
			pair<string,string> a = make_pair(usuario,contrasena);
			acceso.push_back(a);
		} else {
			cout << "Error!. La contraseña no es correcta. Intente nuevamente: ";
		}
		cin >> usuario;
	}
	
	
	int cont = 0;
	while (cont < 5) {
	for (size_t i=0;i<acceso.size();i++) {
		cout << "Por favor, indentifíquese: ";
		cin >> usuario;
		cout << "Contraseña: ";
		cin >> contrasena;
		if (acceso[i].first==usuario and acceso[i].second==contrasena) {
			cout << "Bienvenido al sistema sr/sra " << usuario;
		} else {
			cout << "Incorrecto. Intente de nuevo." << endl;
			cont++;
		}
	}
	}
	if (cont == 5) {
		cout << "Fuera bicho!" << endl;
	}
	
/// En esta carga inicial, debe verificar mediante un función validar_contraseña que la contraseña no sea
/// "1234", "asdf", "pass" ni la cadena vacía; mostrando un mensaje de error y solicitando el reingreso de la misma
/// en estos casos. (nota: proponga usted el prototipo de la función e impleméntela). 
/// b) Luego, simular el verdadero intento de acceso al sistema. El programa debe mostrar el mensaje "Por favor, identifíquese:" y solicitar nombre
/// y contraseña. Si se ingresa un par nombre+contraseña existente (que coincida con los cargados en el apartado a)
/// debe mostrar el mensaje "Bienvenido al sistema sr X" (reemplazando X por el nombre del usuario); sino,
/// luego de 5 intentos fallidos debe mostrar el mensaje "Fuera bicho!".
	return 0;
}

