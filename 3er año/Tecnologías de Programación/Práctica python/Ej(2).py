'''
Ejercicio 2: el programa solicita N numeros y luego calcula su suma
'''

num = int(input("Ingrese un numero: "))
if num == 0:
    print("Se ha cancelado la suma :C")
else:
    suma = 0
    suma += num
    while num != 0:
        num = int(input("Ingrese un numero: "))
        suma += num
    print("La suma final es: ",suma)