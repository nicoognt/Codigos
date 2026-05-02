from abc import ABC, abstractmethod
import datetime as dt
#Ejercicio 12: Banco
'''
CDRG es un banco multinacional que trabaja con un único tipo de cuenta. Cada
cuenta conoce a su titular (apellido, nombre y CUIL) y la historia de transacciones,
que pueden ser de depósito, extracción y consulta de saldo. Todas las
transacciones poseen una fecha asociada. Además, las de depósito y extracción
incluyen el monto de la operación. El banco opera con distintas monedas, por lo
que el monto se indica como una cantidad de dinero y la moneda en que se realiza
la operación. Las monedas pueden ser: peso, dólar y real.
a) Hacer el diagrama UML especi�cando la asociación entre clases, cardinalidad y
navegabilidad para este dominio.
b) Implemente el siguiente comportamiento, respetando el diagrama del ejercicio
anterior:
El banco cobra una comisión de administración de la cuenta en
función del total de transacciones de un período. Para determinar
dicho costo, aplica la siguiente fórmula: (a) La cantidad de
transacciones del período (b) Sumatoria de transacciones del
período en pesos argentinos (moneda base) 30 – ( (b / a) x 0.5 % ) =
comisión
Por ejemplo: (20,000 / 20) = 1,000 => 1,000 * 0.005 = 5 => 30 – 5 =
$ 25
Listar las comisiones de cada una de las cuentas del banco. Detallando el número
de cuenta y el monto (siempre en pesos) de la comisión.
Ayuda: Monto >> convertir_a_peso(): Convierte el monto a Peso. Por ejemplo, para
convertir 400 guaraníes a pesos (400 g / 200, la relación contra el peso) son 2
pesos. Piense dónde recae esta responsabilidad teniendo en cuenta TDA y
DEMETER. Tenga en cuenta que las relaciones de conversión de monedas son
variables.
'''
class Titular:
    def __init__(self,apellido:str,nombre:str,cuil:int):
        self.apellido = apellido
        self.nombre = nombre
        self.CUIL = cuil
class Monto:
    def __init__(self,cantidad:float,moneda:float):
        self.cantidad = cantidad
        self.moneda = moneda.lower()
    def convertir_a_peso(self,tasas_conversion:dict):
        tasa = tasas_conversion.get(self.moneda,1.0)
        self.moneda = "peso"
        self.cantidad = self.moneda * tasa
    def get_cantidad(self) -> float:
        return self.cantidad
    
class ITransaccion(ABC):
    def mostrar_fecha(self): pass
class IOperacion(ABC):
    def devolver_monto(self): pass
class Deposito(ITransaccion,IOperacion):
    def __init__(self,fecha:dt.date,monto:Monto):
        self.fecha_transaccion = fecha
        self.monto = monto
    def mostrar_fecha(self):
        print(f"Fecha de la operacion: {self.fecha_transaccion.day}/{self.fecha_transaccion.month}/{self.fecha_transaccion.year}")
    def devolver_monto(self):
        return self.monto.get_cantidad()
class Extraccion(ITransaccion,IOperacion):
    def __init__(self,fecha:dt.date,monto:Monto):
        self.fecha_transaccion = fecha
        self.monto = monto
    def mostrar_fecha(self):
        print(f"Fecha de la operacion: {self.fecha_transaccion.day}/{self.fecha_transaccion.month}/{self.fecha_transaccion.year}")
    def devolver_monto(self):
        return self.monto.get_cantidad()
class ConsultaSaldo(ITransaccion):
    def __init__(self,fecha:dt.date):
        self.fecha_transaccion = fecha
    def mostrar_fecha(self):
        print(f"Fecha de la operacion: {self.fecha_transaccion.day}/{self.fecha_transaccion.month}/{self.fecha_transaccion.year}")
class Cuenta:
    def __init__(self,num:int,tit:Titular,transacciones:list[ITransaccion]):
        self.numero_cuenta = num
        self.titular_cuenta = tit
        self.transacciones_realizadas = transacciones
    def calcular_comision(self,tasas_cambio:dict) -> float:
        a = len(self.transacciones_realizadas)
        if a == 0: return 30.0
        
        b = 0
        for transacciones in self.transacciones_realizadas:
            transacciones.monto.convertir_a_peso(tasas_cambio)
            b += transacciones.monto.get_cantidad()
        
        comision = 30 - (b/a)*0.005
        return max(0.0, comision)
class Banco:
    def __init__(self):
        self.cuentas = []
        # El diccionario con las relaciones de conversión variables
        self.cotizaciones = {
            "peso": 1.0,
            "dolar": 1000.0,
            "real": 200.0,
            "guarani": 0.005
        }

    def listar_comisiones(self):
        print("--- Listado de Comisiones ---")
        for cuenta in self.cuentas:
            # Le pasamos las cotizaciones a la cuenta para que calcule
            comision_total = cuenta.calcular_comision(self.cotizaciones)
            
            # Mostramos el resultado con f-strings limitando a 2 decimales (.2f)
            print(f"Cuenta Nro: {cuenta.numero} | Comisión: ${comision_total:.2f}")

        