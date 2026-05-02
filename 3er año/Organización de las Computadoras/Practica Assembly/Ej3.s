# intercambiar 2 registros
li t0,10
li t1,20

# truco, sumar los dos registros en uno
# y restar lo necesario para que se "inviertan"
add t0,t0,t1

sub t1,t0,t1
sub t0,t0,t1