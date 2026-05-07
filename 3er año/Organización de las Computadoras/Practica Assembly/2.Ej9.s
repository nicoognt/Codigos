.text
main:
    #Guardo el numero a hacerle el factorial
    addi a0, zero, 6
    addi t0,zero,1
    jal ra, bucle_factorial
    
    addi a7,zero,10       # Código 10: Exit
    ecall
    
bucle_factorial:
    ble a0,t0,caso_base
    # Reservo lugar en el stack
    addi sp, sp, -8
    # Guardo el n y la posicion de retorno
    sw a0, 4(sp)
    sw ra, 0(sp)
    
    # Modifico el n para recursividad
    addi a0,a0,-1
    jal ra,bucle_factorial
    
    # --- LOGICA DE REGRESO ---
    lw t1,4(sp)    # Recupero 'n'
    lw ra, 0(sp)   # Recupero ra
    # Libero la memoria usada en ese escalón
    addi sp,sp,8
    
    # --- LOGICA DE MULTIPLICACION ---
    add t3, zero, a0    # Copiamos a0 en t3 para tener el valor base fijo
    add t2, zero, zero

bucle_sumador:
    add t2,t2,t3
    addi t1,t1,-1
    bne t1,zero,bucle_sumador
    add a0, zero, t2    
    ret
caso_base:
    addi a0, zero, 1
    ret