SRC= ../src/
LIB= ../lib/


othello: othello.o libothello.a
	gcc -L. othello.o -lothello -o othello

othello.o: $(SRC)othello.c $(LIB)ihm.h $(LIB)coups.h $(LIB)constantes.h $(LIB)regle.h 
	gcc $(SRC)othello.c -c -I $(LIB) -std=c99

regle.o: $(LIB)regle.c $(LIB)constantes.h
	gcc $(LIB)regle.c -c -I $(LIB) -std=c99

ihm.o: $(LIB)ihm.c $(LIB)constantes.h
	gcc $(LIB)ihm.c -c -I $(LIB) -std=c99

coups.o: $(LIB)coups.c $(LIB)constantes.h $(LIB)regle.h
	gcc $(LIB)coups.c -c -I $(LIB) -std=c99

constantes.o: $(LIB)constantes.c $(LIB)constantes.h
	gcc $(LIB)constantes.c -c -I $(LIB) -std=c99

libothello.a: constantes.o coups.o ihm.o regle.o
	ar crs libothello.a constantes.o coups.o ihm.o regle.o

clean:
	rm libothello.a *.o othello


