#include <stdio.h> // perror(), fprintf()
#include <stdlib.h>
#include <string.h> // strlen()
#include <time.h> // clock()
#include <CL/cl.h> // openCL headers
#include <math.h> // pow()

/* CONSTANTS */
const int NB_THREADS = 1; // number of threads
const int NB_GROUPS = 1; // number of groups
const int S_PASSWD = 3; // passwd of 4 characters
const char START_CHARACTER = 'a';
const char END_CHARACTER = 'z';

/* GLOBAL VARIABLES */


/* METHODS SIGNATURES */

// call in case of error in bruteforce_cpu
void error_cpu(void *);

// alloc a char* chain
void alloc_chain(char **, const int);

// init a char* chain
void init_chain(char *, const int, const char);

// generate all possibilities at int pos from char*
int generate_possibilities_at(char *, const char, const char,const int);

/* METHODS DECLARATIONS */

// call in case of error in bruteforce_cpu
void error_cpu(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
  perror("Error\n");
  exit(EXIT_FAILURE);
}

// alloc a char* chain
void alloc_chain(char **chain, const int s_chain) {  
  if (*chain == NULL) {
    *chain = (char *)malloc(sizeof(char) * (s_chain + 1));
  }
}

// init a char* chain
void init_chain(char *chain, const int s_chain, const char start) {  
  if (chain != NULL) {
    for (int i = 0; i < s_chain ; i++) chain[i] = start;

    chain[s_chain] = '\0';
  }
}

// generate all possibilities at int pos from char*
int generate_possibilities_at(char *chain, const char start, const char end, const int pos) {
  if (pos < 0 || pos > strlen(chain)) {
    error_cpu(chain);
  }
  char c = start;
  
  while ((int)c != (int)(end + 1)) {
    chain[pos] = c;
    printf("PASSWD: %s\n", chain);
    c++;
  }
  
  return (int)c;
}


/* main method */
int main(int argc, char *argv[]) {
  // variables
  clock_t start_t = 0,
    end_t = 0,
    time_t = 0;
  
  start_t = clock();
  
  // calculate all password possibilities
  // todo...
  
  end_t = clock();

  // calculate execution time
  time_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Time taken by CPU: %ld second(s).\n", time_t);
  
  // returns SUCCESS | FAILURE
  return EXIT_SUCCESS;
}
  
