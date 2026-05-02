import math
'''
Ejercicio 2: ingresado un numero de segundos, el programa debe transformarlo a
horas, minutos y segundos.
'''

num = int(input("Ingrese el numero de segundos: "))
h = num/3600
horas = math.trunc(h)
num -= horas*3600
m = num/60
minutos = math.trunc(m)
num -= minutos*60

print("El tiempo es de: ",horas," horas, ",minutos," minutos y ",num, " segundos")