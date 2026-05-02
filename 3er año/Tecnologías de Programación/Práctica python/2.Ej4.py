import datetime as dt
import hashlib as hl

class Persona:
    def __init__(self,nombre: str,apellido: str, fecha_nacimiento: dt.date,contra:str):
        self.nombre = nombre
        self.apellido = apellido
        self.fecha_nacimiento = fecha_nacimiento
        self.contra = self._hashear(contra)
        
    def _hashear(self,texto):
        return hl.sha256(texto.encode()).hexdigest()
    def validarContrasenia(self,password:str):
        m = self._hashear(password)
        return self.contra == m
    def _calcular_edad(self):
        hoy = dt.date.today()
        #se puede dividir por año, mes y dia
        edad = hoy.year - self.fecha_nacimiento.year
        
        #se revisa que no esté por cumplir en ese año
        if (hoy.month, hoy.day) < (self.fecha_nacimiento.month, self.fecha_nacimiento.day):
            edad-=1
        return edad
    
    def mostrar(self):
        edad = self._calcular_edad()
        print(f"{self.nombre}, {self.apellido}: {edad} años.") 
        
if __name__ == "__main__":
    persona = Persona("Nicolas", "Genolet", dt.date(2006,4,19),"password")
    persona.mostrar()
    
    juan = Persona("Juan", "Perez", "1990-11-11", "password")
    print(juan.validarContrasenia("password")) # Salida: True
    print(juan.validarContrasenia("incorrecto")) # Salida: False
