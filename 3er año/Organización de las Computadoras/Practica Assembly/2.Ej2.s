.data
vector: .word 10, 20, 30, 40, 50 #Crea 5 palabras (32 bits)

.text
main:
    addi t0,zero,0
    addi t1,zero,5
    # la = cargar direccion
    la a0, vector

sumar_vector:
    lw t2,0(a0)
    add t0,t0,t2
    addi a0,a0,4
    addi t1,t1,-1
    bne t1,zero,sumar_vector