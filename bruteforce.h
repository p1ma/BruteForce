#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

/* CONSTANTS */
extern const char START_CHARACTER; // \s
extern const char END_CHARACTER; // ~

/* METHODS SIGNATURE */
extern int alloc_ptr (char **ptr,
		     const unsigned int size);
extern int init_ptr (char **ptr,
		    const unsigned int size,
		    const char init_character);

extern void bruteforce (const unsigned int size);
extern void test_bruteforce (const unsigned int size,
			   const char *passwd_to_find);

extern void print_number_of_possibilities (const unsigned int size);

#endif /* BRUTEFORCE_H */
