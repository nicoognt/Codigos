import math
'''
Ejercicio 3: el programa calcula raices cuadradas indefinidamente hasta que 
se ingresa un numero negativo
'''

num = float(input("Ingrese su numero: "))
while num >= 0:
    resultado = math.sqrt(num)
    print("El resultado es ",resultado)
    num = float(input("Vuelva a ingresar un numero: "))
print("Pusiste un numero negativo estupido, se corto todo >:(")