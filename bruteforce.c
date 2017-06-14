#include "bruteforce.h" // bruteforce header
#include <stdlib.h> // malloc(), free()
#include <math.h> // pow()

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
	      unsigned int position,
	      const char end_character) {
  
  for (int index = 0; index < position; index++) {
    if (passwd[index] != end_character) return true;
  }
  return false;
}

char *next(char *passwd,
	   int position,
	   const char start_character,
	   const char end_character) {
  if (passwd[position] == end_character) {
    if (position < 0) {
      return passwd;
    } else {
      passwd[position] = start_character;
      return next(passwd, position - 1, start_character, end_character);
    }
  } else {
    passwd[position] += 0x01;
  }
  return passwd;
}

int bruteforce (char *passwd,
		const unsigned int size,
		const char start_character,
		const char end_character,
		FILE *output) {
  int status = 0;
  // check if passwd is NULL or not
  if (passwd == NULL) {
    status = init_ptr(passwd, size, START_CHARACTER);
    
    if (status == -1) return status; 
  }

  // check if output is valid
  if (output == NULL) {
    status = -1;
    return status;
  }
  
  // variables and constant
  const int pos_max = size;
  int starter_pos = pos_max - 1;
  long long int attempt = 1;

  // bruteforce loop
  while (has_next(passwd, pos_max, end_character)) {
    // print passwd
    //printf("passwd: %s\n", passwd);

    // write passwd into output
    fprintf(output, "%s\n", passwd);

    // calc the next passwd
    passwd = next(passwd, starter_pos, start_character, end_character);
    attempt++;
  }
  
  // print the last one
  //printf("passwd: %s\n", passwd);

  // write passwd into output
  fprintf(output, "%s\n", passwd);
  
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
