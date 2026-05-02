class Trabajador:
    def __init__(self,nom:str,apes:str,dni:int,direc:str):
        self.nombre = nom
        self.apellidos = apes
        self.DNI = dni
        self.direccion = direc
    def mostrarDatos(self):
        print(f"{self.nombre} {self.apellidos}")
    def verTipo(self):
        pass
    
class Jefe(Trabajador):
    def __init__(self,nom:str,apes:str,dni:int,direc:str,sueldo:float):
        super().__init__(nom,apes,dni,direc)
        self.sueldo = sueldo
        self.trabajadores_a_cargo = []
    
    def calcularPago(self,periodos:float) -> float:
        return self.sueldo*periodos
    
    def agregarTrabajador(self,persona:Trabajador):
        self.trabajadores_a_cargo.append(persona)
    def removerTrabajador(self,persona:Trabajador):
        self.trabajadores_a_cargo.remove(persona)
    
    def mostrarTrabajadores(self):
        for trabajador in self.trabajadores_a_cargo:
            print(trabajador)
    
class Mensualizado(Trabajador):
    def __init__(self,nom:str,apes:str,dni:int,direc:str,sueldo:float):
        super().__init__(nom,apes,dni,direc)
        self.__sueldo = sueldo
    def calcularPago(self,periodos:float) -> float:
        return self.__sueldo*periodos
    def verTipo(self) -> str:
        return "Mensualizado, tipo xx"
    
    def __str__(self):
        super().mostrarDatos()
        self.verTipo()

class Jornalizado(Trabajador):
    def __init__(self,nom:str,apes:str,dni:int,direc:str,precio_hora:float,precio_hs_rest:float):
        super().__init__(nom,apes,dni,direc)
        self.precio_x_hora = precio_hora
        self.precio_hs_restantes = precio_hs_rest
    
    def obtenerPago(self,horas_trabajadas:float):
        if horas_trabajadas <= 40:
            return horas_trabajadas*self.precio_x_hora
        else:
            resto = horas_trabajadas-40
            total = int(horas_trabajadas)*self.precio_x_hora
            total += resto*self.precio_hs_restantes
            return total
    
    def __str__(self):
        super().mostrarDatos()
        self.verTipo()
    
    def verTipo(self) -> str:
        return "Jornalizado"
