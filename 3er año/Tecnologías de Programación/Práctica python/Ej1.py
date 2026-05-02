import datetime as dt
'''
Ejercicio 1: el usuario ingresa su año de nacimiento, el año actual, y el programa
calcula su edad
'''

nacimiento = int(input("Ingrese su año de nacimiento: "))
actual = dt.date.today()
edad = actual.year - nacimiento
print("Su edad es:", edad)