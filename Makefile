main : main.c lib.o
	cc -o main main.c lib.o

lib : matrixMain.o matrixMult.o
	cc -c lib matrixMain.o matrixMult.o

matrixMain.o : matrixMain.c matrix.h matrixDef.h
	cc -c matrixMain.c
matrixMult.o : matrixMult.c matrix.h matrixDef.h
	cc -c matrixMult.c

clean :
	rm matrixMain.o matrixMult.o