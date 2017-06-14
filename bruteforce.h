#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
/* INCLUDES */
#include <stdbool.h> // bool
#include <stdio.h> // printf(), fwrite()

/* CONSTANTS */
extern const char START_CHARACTER; // \s
extern const char END_CHARACTER; // ~

/* METHODS SIGNATURE */
extern int init_ptr (char *ptr,
		     const unsigned int size,
		     const char init_character);

extern bool has_next(char *passwd,
		     unsigned int position,
		     const char end_character);

extern char *next(char *passwd,
		  int position,
		  const char start_character,
		  const char end_character);

extern int bruteforce (char *passwd,
		       const unsigned int size,
		       const char start_character,
		       const char end_character,
		       FILE *output);

extern int test_bruteforce (const unsigned int size,
			    const char *passwd_to_find);

extern int print_number_of_possibilities (const unsigned int size);

#endif /* BRUTEFORCE_H */
