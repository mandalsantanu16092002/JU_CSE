	   LXI H,2060H
	   MOV B,M
	   MVI D,00
	   MVI E,01
	   DCR B

LOOP:	   MVI A,00
	   ADD D
	   ADD E
	   MOV D,E
	   MOV E,A
	   DCR B
	   JNZ LOOP
	   STA 2050H
	   HLT