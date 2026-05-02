.text
main:
    addi t0,zero,7
while: 
    # Condicion
    blt t0,zero,fin
    
    # Impresion
    addi a7,zero,1
    mv a0,t0
    ecall
    
    # Decrementar contador
    addi t0,t0,-1
    # Repetir bucle
    j while
fin:
    nop