default : main.o matrix.o
	cc -o test main.o matrixMain.o matrixArithmetic.o matrixMult.o

main.o : main.c matrix.h
	cc -c main.c
matrix.o : matrixMain.c matrixArithmetic.c matrix.h matrixDef.h
	cc -c matrixMain.c matrixArithmetic.c matrixMult.c

clean :
	rm *.o