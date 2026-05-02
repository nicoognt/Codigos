'''
Ejercicio 1: dada la clase Persona y Principal, codificarlas y demostrar
el concepto de identidad (id) de un objeto
'''

class Persona:
    def __init__(self,nombre: str,edad: int):
        self.nombre = nombre
        self.edad = edad

class Principal:
    def __init__(self):
        pass
    
    def ejecutar(self):
        persona1 = Persona("Nicolas",19)
        persona2 = Persona("Gandolfo",20)
        
        print(f"Indentidad de persona1: {id(persona1)}")
        print(f"Indentidad de persona2: {id(persona2)}")
        
        print("Tienen el mismo valor?: ",persona1 == persona2)
        print("TIenen misma identidad?: ",persona1 is persona2)
        
if __name__ == "__main__":
    principal = Principal()
    
    principal.ejecutar()
    