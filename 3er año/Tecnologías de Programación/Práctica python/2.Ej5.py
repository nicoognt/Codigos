'''
Ejercicio 5: Se necesita diseñar un conjunto de clases que modele un sistema de facturación.
Las clases deben representar las facturas y sus elementos, como los detalles de
cada factura. Se requiere implementar un método para mostrar la suma total de
todas las facturas emitidas.
'''
import datetime as dt
import random
class Factura:
    def __init__(self,empresa_emisora,cliente,fecha:dt.date):
        self.numero_factura = random.randint(1,100000000)
        self.empresa_emisora = empresa_emisora
        self.cliente = cliente
        self.fecha_emision = fecha
        self.productos = []
    def calcular_total(self) -> float:
        total = 0
        for producto in self.productos:
            total += producto.get_precio()
        return total
    def agregar_producto(self,productos:'list[Producto]'):
        self.productos += productos
    
    def mostrar_detalles(self):
        for i in range(1,len(self.objetos)+1):
            print(f"Detalle {i}: {objetos[i].mostrar_informacion}")
class Empresa:
    #defino los datos de la empresa
    def __init__(self,nombre:str,cuit:int):
        self.nombre = nombre
        self.cuit = cuit
        self.facturas_emitidas = []
    # se agregar unitariamente una factura
    def agregar_factura(self,factura:Factura):
        self.facturas_emitidas.append(factura)
    
    #suma la totalidad de emision
    def suma_total(self) -> float:
        total = 0
        for factura in self.facturas_emitidas:
            total += factura.calcular_total()
        return total
    
class Producto:
    def __init__(self,nombre:str,precio_unidad:float,cantidad_comprada:int):
        self.nombre = nombre
        self.precio = precio_unidad
        self.cantidad = cantidad_comprada
    def get_precio(self): 
        return self.precio*self.cantidad
    def get_cantidad(self): 
        return self.precio
    def mostrar_informacion(self):
        print(f"{self.nombre} - {self.cantidad} unidad/es. Total item: ${self.get_precio()}")
    
if __name__ == "__main__":
    
    empresaA=Empresa("Danonino",30-12345678-1)
    empresaB=Empresa("Dannete",30-234567123-1)
    facturaA=Factura(empresaA,empresaB,dt.date.today())
    
    objeto1 = Producto("martillo",225,2)
    objeto2 = Producto("tornillo 12 mm",50,20)
    objetos = [objeto1,objeto2]
    facturaA.agregar_producto(objetos)
    empresaA.agregar_factura(facturaA)
    
    objeto3 = Producto("destornillador",3600.12,100)
    objeto4 = Producto("picaporte de madera",4.46,2)
    facturaB = Factura(empresaA,empresaB,dt.date.today())
    objetos = [objeto3,objeto4]
    facturaB.agregar_producto(objetos)
    empresaA.agregar_factura(facturaB)
    
    print(f"El total de la empresa A en facturas es de ${empresaA.suma_total()}")