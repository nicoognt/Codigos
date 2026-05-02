# Multiplicar dos numeros mediante sumas repetidas
li t0,3
li t1,4

bucle:
    add t2,t2,t1
    addi t1,t1,-1
    bne t1,zero,bucle