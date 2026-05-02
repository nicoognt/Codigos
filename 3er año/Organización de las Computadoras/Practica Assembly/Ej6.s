# reviso el ultimo bit con andi
# y luego voy moviendo hacia la derecha
# el numero

li t0,21
li t1,0

bucle:
    andi t2,t0,1
    add t1,t1,t2
    
    srli t0,t0,1
    bne t0,zero,bucle

    