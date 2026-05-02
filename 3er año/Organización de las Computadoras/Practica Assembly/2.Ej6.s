addi x5,zero,0
addi x6,zero,10

for:
    bge x5,x6,done
    addi x5,x5,1
    
    j for
done:
    nop