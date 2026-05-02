'''
Ejercicio 4: segun el consumo de electricidad, se determina el monto a pagar y
la categoria de consumo
'''

kWh = float(input("Ingrese su consumo electrico en kWh: "))
if kWh <= 100:
    precio = kWh*200
    categoria = "Bajo"
elif kWh <= 300:
    precio = kWh*300
    categoria = "Medio"
elif kWh > 300:
    precio = kWh*400
    categoria = "Alto"

print("Pertenece a la categoria de consumo ",categoria,". Su total a pagar es de $",precio)

