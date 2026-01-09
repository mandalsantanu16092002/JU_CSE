	mvi A, 80H
	out 40H
LD: 	mvi A, BCH
	out 40H
	mvi A, 5EH
	out 41H
	mvi A, 00H
	out 42H
	mvi A, 11H
	out 43H
	call DELAY
	mvi A, 00H
	out 40H
	mvi A, 00H
	out 41H
	mvi A, 00H
	out 43H
	call DELAY
	jmp LD

DELAY: 	lxi H, FFFFH
L2: 	dcx H
	mov A, L
	ora H
	jnz L2
	ret
