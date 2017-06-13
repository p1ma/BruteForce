#include "bruteforce.h" // bruteforce header
#include <stdlib.h> // malloc(), free()
#include <math.h> // pow()
#include <stdio.h> // printf()

/* CONSTANTS */
const char START_CHARACTER = 0x20; // Space
const char END_CHARACTER = 0x7E; // ~

/* METHODS DECLARATION */

int init_ptr (char *ptr,
	      const unsigned int size,
	      const char init_character) {
  int status = -1; // failure
  
  if (ptr == NULL) {
    return status; // failure
  }
  
  char *passwd = ptr;
  for (int index = 0 ; index < size ; index++) {
    passwd[index] = init_character;
  }
  passwd[size] = 0x00;
  passwd = NULL;
  status = 0;
  
  return status;
}

bool has_next(char *passwd,
	      const unsigned int size,
	      const char end_character) {
  
  for (int index = 0; index < size; index++) {
    if (passwd[index] != end_character) return true;
  }
  return false;
}

char *next(char *passwd,
	   const int size,
	   const char start_character,
	   const char end_character) {
  return passwd;
}

int bruteforce (char *passwd, const unsigned int size) {
  // check if passwd is NULL or not
  if (passwd == NULL) {
    int st = init_ptr(passwd, size, START_CHARACTER);
    
    if (st == -1) return st; 
  }
  
  // variables and constant
  const int pos_max = size;
  int start_pos = pos_max - 1;
  long long int attempt = 0;
  printf("start_pos: %d, pos_max: %d\n", start_pos, pos_max);
  return attempt;
}

int test_bruteforce (const unsigned int size,
		     const char *passwd_to_find) {
  return 0;
}

int print_number_of_possibilities (const unsigned int size) {
  unsigned int range = (int)(END_CHARACTER - START_CHARACTER) + 1;
  unsigned long long int possibilities = pow(range, size);

  printf("Number of possibilities: %llu.\n", possibilities);

  return possibilities;
}
