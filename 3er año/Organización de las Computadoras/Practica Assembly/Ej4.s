# usar un registro con el numero,
# uno con la cantidad de multiplicaciones y
# y otro con el resultado

li t0,4
li t1,3
li t2,0

# declaro la etiqueta para realizar
# el bucle
bucle:
    add t2,t2,t0
    addi t1,t1,-1
    bne t1,zero,bucle
