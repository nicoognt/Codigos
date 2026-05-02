import math
'''
Ejercicio 8: dado el radio de la base y la altura del cilindro, el programa
calcula el volumen de este
'''

r = float(input("Ingrese el radio de la base en metros: "))
h = float(input("Ingrese la altura en metros: "))
vol = math.pi*r**2*h
print("El volumen del cilindro es de ",vol,"metros cúbicos")