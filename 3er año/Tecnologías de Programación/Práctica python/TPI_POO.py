# Consigna de TPI, TecProg
# Bibliotecas importadas
import datetime as dt
import hashlib as hl

# Modulo: transportes
class Transporte:
    def __init__(self,nro:int, patente:str) -> None:
        self.numero_id = nro
        self.patente = patente
    
    def get_patente(self) -> str: return self.patente
class Avion(Transporte):
    def __init__(self, nro:int, patente:str, tiempo:float):
        super().__init__(nro,patente)
        self.tiempo_vuelo = tiempo
class Camion(Transporte):
    def __init__(self, nro:int, patente:str, cap:float):
        super().__init__(nro,patente)
        self.capacidad_kg = cap

#Modulo: cargamento
class Paquete:
    def __init__(self, peso:float):
        self.peso = peso
    def get_peso(self) -> float: return self.peso
class Contenedor:
    # Constructor por defecto, se crea la lista vacía para los paquetes que tenga dentro
    def __init__(self):
        self.paquetes_contenidos = []
    
    def agregar_paquete(self, pack:Paquete) -> None:
        self.paquetes_contenidos.append(pack)
    
    # Se respeta el único punto de salida y la ley de Demeter
    def get_peso_total(self) -> float:
        suma = 0
        for paquete in self.paquetes_contenidos:
            suma += paquete.get_peso()
        return suma

#Modulo: despacho (relacionado con los paquetes y contenedores)
class Despacho:
    def __init__(self, fecha:dt.date, estado:str):
        self.fecha_despacho = fecha
        self.estado = estado
        self.contenedores = []
        self.transporte_asignado = None
    
    def agregar_contenedor(self, cont:Contenedor) -> None:
        self.contenedores.append(cont)
    
    def get_peso_total(self) -> float:
        peso_total = 0
        for container in self.contenedores:
            peso_total += container.get_peso_total()
        
        # Redondeo a 3 cifras, no me interesa tener 14 decimales
        peso_total = round(peso_total,3)
        return peso_total
    
    def asignar_transporte(self, trans:Transporte) -> None:
        self.transporte_asignado = trans

#Modulo: Configuracion/seguridad
class Configuracion:
    def __init__(self, clave:str):
        self.contrasenia = self._hashear(clave)
    
    # Hasheo a hexadecimal
    def _hashear(self, clave:str):
        return hl.sha256(clave.encode()).hexdigest()
    
    def validar_clave(self, texto_validar:str) -> bool:
        txt_hash = self._hashear(texto_validar)
        return txt_hash == self.contrasenia
class SistemaLogistica:
    def __init__(self, sistema:Configuracion):
        self.sistema_seguridad = sistema
