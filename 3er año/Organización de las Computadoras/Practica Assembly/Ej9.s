# Rotar el valor de 0b1101 un bit a la derecha

li t0,13
andi t1,t0,1

srli t0,t0,1
slli t1,t1,3
or t0,t0,t1