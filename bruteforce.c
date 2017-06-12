#include "bruteforce.h" // bruteforce header
#include <stdlib.h> // malloc(), free()
#include <math.h> // pow()
#include <stdio.h> // printf()

/* CONSTANTS */
const char START_CHARACTER = 0x20; // Space
const char END_CHARACTER = 0x7E; // ~

/* METHODS DECLARATION */

int alloc_ptr (char **ptr,
	      const unsigned int size) {
  int status = 0; // success
  
  *ptr = (char *)malloc(sizeof(char) * (size + 1)); // + 1 bcs '\0'
  
  // check if success
  if (*ptr == NULL) {
    status = -1; // failure
    free(*ptr);
  }
  
  return status;
}

int init_ptr (char **ptr,
	     const unsigned int size,
	     const char init_character) {
  int status = 0; // success
  
  if (*ptr == NULL) {
    status = alloc_ptr(ptr, size);
    if (status == -1) {
      return status; // failure
    }
  }
  
  char *passwd = *ptr;
  for (int index = 0 ; index < size ; index++) {
    passwd[index] = init_character;
  }
  passwd[size] = 0x00;
  
  return status;
}

void bruteforce (const unsigned int size) {
  return;
}
void test_bruteforce (const unsigned int size,
		     const char *passwd_to_find) {
  return;
}

void print_number_of_possibilities (const unsigned int size) {
  unsigned int range = (int)(END_CHARACTER - START_CHARACTER) + 1;
  unsigned long long int possibilities = pow(range, size);

  printf("Number of possibilities: %llu.\n", possibilities);
}
