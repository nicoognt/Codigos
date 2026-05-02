li t0,6
li t1,0
andi t2,t0,1

beq t2,zero,asignar
j fin
asignar:
    addi t1,t1,1

fin:
    nop