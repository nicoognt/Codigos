addi x5,zero,12
addi x6,zero,-1

comp:
    blt x5,x6,store
    sw x6, 0(x10)
store:
    sw x6, 0(x10)