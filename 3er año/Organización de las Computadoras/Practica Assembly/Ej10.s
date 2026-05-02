# Comparar dos valores en registro y almacenar el mayor en otro registro
li t0,15
li t1,2

bge t0,t1,guardar
mv t2,t1
guardar:
    mv t2,t0