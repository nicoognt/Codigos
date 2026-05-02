addi t0,zero,1
addi t1,zero,1 # para evitar un 1*0
addi t2,zero,4

bucle:
    mul t1,t1,t0
    addi t0,t0,1
    addi t2,t2,-1
    bne t2,zero,bucle
# Un bucle con salto tarda
# cant.inst + 1-2 ciclos