addi t0, zero, 5   
addi t1, zero, 3

# 2. Operaciones
add x11, t0, t1
sub x12, t0, t1
mul x13, t0, t1
div x14, t0, t1

# 3. Guardado en memoria (usando saltos de 4 bytes)
sw x11, 0(x7)
sw x12, 4(x7)
sw x13, 8(x7)
sw x14, 12(x7)