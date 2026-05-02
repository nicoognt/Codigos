# realizar la operaci?n
# valor absoluto

li t0,-42
bge t0,zero,es_positivo

sub t1,zero,t0

es_positivo:
    mv t1,t0