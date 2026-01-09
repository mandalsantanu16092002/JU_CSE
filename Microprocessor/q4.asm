lxi H, 201EH
mov C, M
mvi B, 00H
lxi H, 3010H
lxi D, 3014H
dad B
dcx H
xchg
dad B
dcx H
xchg
LOOP: mov A, M
stax D
dcx D
dcx H
dcr C
jnz LOOP
hlt