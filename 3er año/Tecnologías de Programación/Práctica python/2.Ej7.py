import datetime as dt
class persona:
    def __init__(self,nombre:str,apellido:str,telefono:int):
        self.nombre_duenio = nombre
        self.apellido_duenio = apellido
        self.telefono_duenio = telefono

class venta:
    def __init__(self,monto:float,comprador:persona,fecha:dt.date,objeto:'vehiculo'):
        self.monto = monto
        self.comprador = comprador
        self.fecha_venta = fecha
        self.objeto = objeto
        
    def get_monto(self) -> float:
        return self.monto
    
    def get_vehiculo(self) -> 'vehiculo':
        return self.objeto
    

class vehiculo:
    def __init__(self,marca:str,modelo:str,patente:str,precio:float,km:int):
        self.marca = marca
        self.modelo = modelo
        self.patente = patente
        self.precio_venta = precio
        self.kilometraje = km
        
        if km > 0:
            self.estado = "Usado"
            nom = input("Ingrese el nombre del dueño anterior: ")
            ape = input("Ingrese su apellido: ")
            tel = input("Ingrese su telefono: ")
            
            duenio = persona(nom,ape,tel)
            self.duenio_anterior = duenio
        else:
            self.estado = "Nuevo"
    
    
    def get_estado(self) -> str:
        return self.estado

    def get_tipo(self) -> str:
        pass

class concesionaria:
    def __init__(self):
        self.ventas_registradas = []
    
    def agregar_venta(self,comprador:persona,monto:float,objeto_comprado:vehiculo):
        hoy = dt.date.today()
        nueva_venta = venta(monto,comprador,hoy,objeto_comprado)
        self.ventas_registradas.append(nueva_venta)
    
    def calcular_ventas_usados(self) -> float:
        total = 0.0
        for venta in self.ventas_registradas:
            obj = venta.get_vehiculo()
            if obj.get_tipo() == "Nacional" and obj.get_estado() == "Usado":
                total += venta.get_monto()
        
        return total
        

class auto(vehiculo):
    def __init__(self,marca:str,modelo:str,patente:str,precio:float,km:int,tipo:str):
        super().__init__(marca,modelo,patente,precio,km)
        
        self.tipo = tipo
        if tipo == "Importado":
            origen = input("Ingrese el pais de origen del auto: ")
            impuestos = float(input("Ingrese el costo de importacion: "))

            self.pais_origen = origen
            self.impuestos = impuestos
    
    def get_tipo(self) -> str:
        return self.tipo
    

if __name__ == "__main__":
    conc = concesionaria()
    namir = persona("Namir","Gareis",3435148429)
    flor = persona("Flor","Acosta",3425120440)
    auto1 = auto("chevrolet","corvette v7","AA000NG",30000,148000,"Importado")
    auto2 = auto("chevrolet","camaro","AB181PT",1500000,35000,"Nacional")
    
    
    conc.agregar_venta(namir,50000,auto1)
    conc.agregar_venta(flor,12,auto2)
    
    print(f"El total reunido en ventas de autos nacionales usados es de ${conc.calcular_ventas_usados()}")
    