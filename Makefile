# definition du compilateur
CC = gcc

# definition des options de compilation pour obtenir un fichier .o
PRODUCTFLAGS = -c -O3 -Wall
ENDFLAGS = -lm -lOpenCL

# definition des options de compilation pour obtenir un fichier .do
DEBUGFLAGS = -c -g -O3 

# Fichier executable server
bruteforce: main.o
	$(CC) -o bruteForce main.o $(ENDFLAGS)
main.o: main.c 
	$(CC) $(PRODUCTFLAGS) main.c 

# cleaner
clean :
	rm -f bruteForce *.o *.do *~
