# definition du compilateur
CC = gcc

# definition des options de compilation pour obtenir un fichier .o
PRODUCTFLAGS = -c -g -O3 -Wall
ENDFLAGS = -lm -lOpenCL

# Fichier executable server
bruteForce: bruteforce.o main.o
	$(CC) -o bruteForce bruteforce.o main.o $(ENDFLAGS)
main.o: main.c bruteforce.h
	$(CC) $(PRODUCTFLAGS) main.c 
bruteforce.o: bruteforce.c bruteforce.h
	$(CC) $(PRODUCTFLAGS) bruteforce.c

# cleaner
clean :
	rm -f bruteForce *.o *.do *~
