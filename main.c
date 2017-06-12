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
void error_cpu(void *); // call in case of error in bruteforce_cpu
void alloc_chain(char **, const int); // alloc a char* chain
void init_chain(char *, const int, const char); // init a char* chain
int generate_possibilities_at(char *, const char, const char,const int); // generate all possibilities at int pos from char*
int bruteforce_cpu(const char, const char, const int); // 0 if success else -1

/* METHODS DECLARATIONS */
void error_cpu(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
  perror("Error\n");
  exit(EXIT_FAILURE);
}

void alloc_chain(char **chain, const int s_chain) {  
  if (*chain == NULL) {
    *chain = (char *)malloc(sizeof(char) * (s_chain + 1));
  }
}

void init_chain(char *chain, const int s_chain, const char start) {  
  if (chain != NULL) {
    for (int i = 0; i < s_chain ; i++) chain[i] = start;

    chain[s_chain] = '\0';
  }
}

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

int bruteforce_cpu(const char start, const char end, const int size) {
  // variables
  int res = EXIT_SUCCESS;
  unsigned int nb_characters = (int)(end - start + 1);
  unsigned long long int possibilities = 0;
  unsigned long long int attempt = 0;
  unsigned int position = size - 1;
  char *passwd = NULL;

  // alloc passwd
  alloc_chain(&passwd, size);

  // init passwd
  init_chain(passwd, size, start);

  // calculate all possibilities
  possibilities = pow(nb_characters, size);

  // print possibilities
  printf("Number of possibilities: %llu.\n", possibilities);

  // bruteforce loop
  for(int pos = position ; pos >= 0; pos--) {
    for(int pos_after = (size - 1); pos_after >= pos ; pos_after--) {
      for(int c = (int)start; c <= (int) end; c++) {
	attempt += generate_possibilities_at(passwd, start, end, pos_after);
	init_chain(passwd, size, c);
      }
    }
  }

  printf("Brute force over, %llu attempts done.\n", attempt);
  
  // free memory
  free(passwd);

  // exit
  return res;
}

/* main method */
int main(int argc, char *argv[]) {
  // variables
  int res = EXIT_FAILURE;
  clock_t start_t = 0,
    end_t = 0,
    time_t = 0;
  
  start_t = clock();
  
  // calculate all password possibilities
  res = bruteforce_cpu(START_CHARACTER, END_CHARACTER, S_PASSWD);
  
  end_t = clock();

  // calculate execution time
  time_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Time taken by CPU: %ld second(s).\n", time_t);
  
  // returns SUCCESS | FAILURE
  return res;
}
  
