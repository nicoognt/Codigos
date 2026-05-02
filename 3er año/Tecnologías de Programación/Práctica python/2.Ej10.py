from abc import ABC, abstractmethod
from typing import List
from datetime import datetime
class IPersona:
    @abstractmethod
    def mostrar_informacion(self): pass
class Singleton(type):
    _instances = {}
    
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            # Si no existe, la crea
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        # Si ya existe, devuelve la guardada
        return cls._instances[cls]

class Docente(IPersona):
    def __init__(self,nombre:str,apellido:str,dni:int):
        self.nombre = nombre
        self.apellido = apellido
        self.dni = dni
    
    def mostrar_informacion(self):
        print(f"Docente: {self.apellido} {self.nombre}. DNI: {self.dni}")

class Comision:
    def __init__(self,docente_a_cargo:Docente,fecha:datetime,id:str):
        self.docente_a_cargo = docente_a_cargo
        self.fecha_inicio = fecha
        self.identificativo = id

class Universidad(metaclass=Singleton):
    def __init__(self):
        # ¡IMPORTANTE! Este __init__ se ejecutará UNA SOLA VEZ en todo tu programa.
        self.nombre = "Universidad Nacional del Litoral (UNL)"
        self.carreras = []
        self.docentes = []
        
    def listar_alumnos(self, catedra):
        catedra.mostrar_alumnos_inscriptos()

class Carrera:
    def __init__(self,nom:str):
        self.nombre = nom
        self.c_alumnos: List[Alumno] = []
    # Este método cuenta la cantidad de egresados de la carrera
    # y muestra el promedio de cada uno de ellos (Sin desaprobados)
    def listar_egresados(self) -> int:
        cant_egresados = 0
        # Recorro todos los alumnos de la CARRERA
        iter_alumnos = iter(self.c_alumnos)
        alumno = next(iter_alumnos, None)
        while alumno is not None:
            if alumno.esta_egresado():
                cant_egresados += 1
                alumno.calcular_promedio()
                print(alumno)
            alumno = next(iter_alumnos, None)
        return cant_egresados

class Catedra:
    def __init__(self,nombre:str,alumnos:list['Alumno'],comisiones:list[Comision] = []):
        self.nombre = nombre
        self.comisiones = comisiones
        self.alumnos_inscriptos = alumnos
    def mostrar_alumnos_incriptos(self):
        for alumno in self.alumnos_inscriptos:
            alumno.mostrar()

class Examen:
    def __init__(self, nota: float):
        self.nota = nota
    def get_nota(self) -> float:
        return self.nota

class Alumno(IPersona):
    def __init__(self,nombre:str,apellido:str,dni:int,fecha_egreso:datetime,examenes:list[Examen]):
        self.nombre = nombre
        self.apellido = apellido
        self.dni = dni
        self.fecha_egreso = fecha_egreso
        self.examenes = examenes
        self.promedio = None
    
    def mostrar_informacion(self):
        print(f"Alumno: {self.nombre} {self.apellido} - DNI: {self.dni}")
    def __str__(self):
        print(f"Egresado {self.nombre} - Promedio: {self.promedio}")
    
    def calcular_promedio(self) -> float:
        acumula_notas = 0
        cant_examenes_aprobados = 0
        for examen in self.examenes:
            if examen.nota >= 6:
                acumula_notas += examen.nota
                cant_examenes_aprobados += 1
                self.promedio = acumula_notas / cant_examenes_aprobados
    
    def esta_egresado(self) -> bool:
        return True if self.fecha_egreso != None else False


if __name__ == "__main__":
    f1 = datetime(2000,12,1)
    alumno1 = Alumno("Juan", f1, [Examen(7), Examen(8), Examen(5)])
    alumno2 = Alumno("María", None, [Examen(6), Examen(7), Examen(6)])
    carrera = Carrera()
    carrera.c_alumnos = [alumno1, alumno2]
    print(carrera.listar_egresados())