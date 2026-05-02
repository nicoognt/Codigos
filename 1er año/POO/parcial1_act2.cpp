#include <iostream>
#include <vector>
using namespace std;
/**a) Escriba una clase abstracta IA para representar a una inteligencia artificial que responde
preguntas. La clase debe recibir el nombre de la misma en su constructor, guardarlo y tener un metodo
para consultarlo. Debe tener ademas un metodo virtual ObtenerRespuesta que reciba una pregunta y
retorne una respuesta (ambas seran strings).
b) Implemente 2 clases representando 2 inteligencias diferentes:
- Memory: Debe recibir en su constructor una lista de preguntas y respuestas. El metodo
ObtenerRespuesta debe buscar la pregunta en esa lista y retornar la respuesta correspondiente. Si la
pregunta no esta en la lista, debe elegir una respuesta al azar.
- Multivac: El metodo ObtenerRespuesta debe responder a todo con "Datos insuficientes para una
respuesta esclarecedora.".
c) Escriba una funcion que reciba una IA (que pueda ser cualquiera, una de las 2 implementadas en b,
o incluso otra) y permita al usuario ingresar preguntas y ver las respuestas hasta que ingrese "Salir".
Escriba un programa cliente que permita al usuario elegir uno de los dos tipos de inteligencia, cree la
instancia de la clase adecuada e invoque con ella a la funcion. Nota: en el main, donde se deber√≠a
carga u obtener la lista de preguntas y respuestas para Memory, solo declare la o las variables
necesarias y ponga simplemente una comentario diciendo "// aqui deberia cargar la lista‚"**/
class IA {
private:
	string nombre;
public:
	IA(string _nombre) : nombre(_nombre) {}
	string VerNom() const {return nombre;}
	virtual string ObtenerRespuesta(string preg) = 0;
	virtual ~IA() {}
};

class Memory : public IA{
private:
	vector<string> preg, rta;
public:
	Memory(string nom,vector<string> _preg,vector<string> _rta) : IA(nom),preg(_preg),rta(_rta) {}
	string ObtenerRespuesta(string pregunta) override {
		int aux;
		bool si_esta=false;
		for(size_t i=0;i<preg.size();i++) { 
			if(preg[i]==pregunta){
				aux=i;
				si_esta=true;
			}
		}
		if(si_esta){
			return rta[aux];
		} else {
			int a = rand()%rta.size();
			return rta[a];
		}
	}
};
class Multivac : public IA{
public:
	Multivac(string _nombre) : IA(_nombre) {}
	string ObtenerRespuesta(string preg) override{
		return "Datos insuficientes para una respuesta esclarecedora";
	}
};
void Preguntas(string preg, IA *memory){
	cin>>preg;
	while(preg!="Salir"){
		memory->ObtenerRespuesta(preg); cout<<endl;
		cin>>preg;
	}
}
int main() {
	cout<<"øQuÈ IA prefiere, Memory o Multivac?: ";
	string ia; cin>>ia;
	if(ia=="Memory"){
		cout<<"Cuantas preguntas tiene para hacer?: ";
		int n; cin>>n;
		string pg;
		vector<string> preguntas(n);  //aca se cargarian las preguntas
		vector<string> respuestas(n); //aca se cargarian las respuestas
		IA *intArt = new Memory("Memory",preguntas,respuestas);
		Preguntas(pg,intArt);
		delete intArt;
	} else {
		IA *inteli = new Multivac("Multivac");
		cout<<"Ingrese su pregunta o 'Salir' para finalizar el programa: "<<endl;
		string pg;
		Preguntas(pg,inteli);
		delete inteli;
	}
	
	return 0;
}

