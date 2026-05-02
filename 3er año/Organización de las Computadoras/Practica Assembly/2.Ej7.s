main:
    addi x5,zero,5
    addi x6,zero,-1
    addi x7,zero,0
    # reviso si es negativo
    blt x5,zero,save_m
    # reviso si es cero
    beq x5,zero,save_z
    # reviso si es positivo
    bge x5,zero,save_p
save_m:
    addi x28,zero,0
    sw x28, 0(a0)
    j fin
save_z:
    addi x28,zero,1
    sw x28, 0(a0)
    j fin
save_p:
    addi x28,zero,2
    sw x28, 0(a0)
    j fin
fin:
    nop