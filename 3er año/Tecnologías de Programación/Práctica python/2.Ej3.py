import datetime as dt
class Alumno:
    def __init__(self,nom:str,dni:int,nac:dt.date):
        self.nombre = nom
        self.DNI = dni
        self.nacimiento = nac
    
    def _calcularEdad(self):
        hoy = dt.date.today()
        edad = self.nacimiento.year - hoy.year
        if (hoy.month,hoy.day) < (self.nacimiento.month,self.nacimiento.day):
            edad -= 1
        return edad
        
    def mostrar(self):
        print(f"{self.nombre}")

class Carrera:
    def __init__(self,nombre:str):
        self.nombre = nombre
        self.inscripciones = []
        
    def inscripcion(self,alumno:Alumno,fechaIns:dt.date):
        self.inscripciones.append((alumno,fechaIns))
    
    def mostrarse(self):
        print(f"Carrera: {self.nombre}")
        for par in self.inscripciones:
            par[0].mostrar()
            print(f"- {par[1]}")
            
class Facultad:
    def __init__(self,nombre:str):
        self.nom = nombre
        self.carreras = []
    
    def cargarCarreras(self,carrera):
        self.carreras = carrera
    
    def mostrarCarrerasYAlumnos(self):
        print(self.nom)
        for c in self.carreras:
            c.mostrarse()

if __name__ == "__main__":
    FICH = Facultad("Facultad de Ingeniería y Ciencias Hídricas")
    alumno1 = Alumno("Nicolas Genolet",47175600,dt.date(2006,4,19))
    alumno2 = Alumno("Alumno2",11111111,dt.date(2005,3,2))
    
    informatica = Carrera("ING en informatica")
    informatica.inscripcion(alumno1,dt.date.today())
    informatica.inscripcion(alumno2,dt.date(2022,8,22))
    
    ia = Carrera("ING en ia")
    ia.inscripcion(alumno1,dt.date(2024,1,1))
    ia.inscripcion(alumno2,dt.date(2020,5,15))
    
    FICH.cargarCarreras([informatica,ia])
    FICH.mostrarCarrerasYAlumnos()
    
    
    
    