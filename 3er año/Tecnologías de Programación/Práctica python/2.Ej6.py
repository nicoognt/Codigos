'''
Se requiere desarrollar un sistema de nómina para los trabajadores de una
empresa. Los datos personales de los trabajadores incluyen Nombre y Apellidos,
Dirección y DNI. Existen diferentes tipos de trabajadores:
Mensualizados: Estos empleados reciben una cantidad fija cada mes, basada en
la categoría que tienen.
Jornalizados: Estos empleados reciben un pago por cada hora trabajada durante
el mes. El precio es fijo para las primeras 40 horas y diferente para las horas
restantes.
Jefe: Estos empleados tienen un salario fijo, que es un acuerdo personal con la
Problema 6: Sistema de nómina de trabajadores
empresa.
Cada empleado tiene obligatoriamente un jefe, excepto los jefes que no tienen
ninguno. El sistema debe ser capaz de calcular las remuneraciones de cada
trabajador en un período dado.
'''

class Trabajador:
    def __init__(self,nom:str,apes:str,dni:int,direc:str):
        self.nombre = nom
        self.apellidos = apes
        self.DNI = dni
        self.direccion = direc

class Jefe(Trabajador):
    def __init__(self,sueldo:float):
        self.sueldo = sueldo
    def calcularPago(self,periodos:float) -> float:
        return self.sueldo*periodos

class Mensualizado(Trabajador):
    def __init__(self,jefe:Jefe,sueldo:float):
        self.jefe_a_cargo = jefe
        self.sueldo = sueldo
    def calcularPago(self,periodos:float) -> float:
        return self.sueldo*periodos

class Jornalizado(Trabajador):
    def __init__(self,jefe:Jefe,precio_hora:float,precio_hs_rest:float):
        self.jefe_a_cargo = jefe
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
