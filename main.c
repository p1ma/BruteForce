#include "bruteforce.h"
#include <stdio.h> // perror(), fprintf()
#include <stdlib.h>
#include <time.h> // clock()
#include <signal.h> // signal()
#include <unistd.h> // sleep()

/* GLOBAL VARIABLES */
char *g_passwd = NULL;
FILE *g_file = NULL;

/* IN CASE OF CTRL-C */
void ctrl_c(int);

/* main method */
int main(int argc, char *argv[]) {
  // connect signal SIGINT with method ctrl_c
  signal(SIGINT, ctrl_c);
  
  // status variable
  int status = EXIT_SUCCESS; // return status
  
  // check args
  if (argc == 3) {
    // variables
    clock_t start_t = 0,
      end_t = 0,
      time_t = 0;
    long long int attempt = 0;
    long long int possibilities = 0;
    int status = 0;
    
    const unsigned int s_passwd = atoi(argv[2]);

    // init ptrs
    g_passwd = (char *)malloc(sizeof(char) * (s_passwd + 1));
    status = init_ptr(g_passwd,
		      s_passwd,
		      START_CHARACTER);
    // if error then clean and exit
    if (status == -1) goto clean;

    // output file
    g_file = fopen(argv[1], "a+");
    
    // returns and prints on stdout the number of possibilities
    possibilities = print_number_of_possibilities(s_passwd);

    // start timer
    start_t = clock(); 
    
    // calculate all password possibilities
    attempt = bruteforce(g_passwd,
			 s_passwd,
			 START_CHARACTER,
			 END_CHARACTER,
			 g_file);

    // if error happened then ..
    if (attempt == -1) goto clean;

    // if all passwd were not find then error
    if (attempt != possibilities) {
      printf("Error bruteforcing...\n");
      goto clean;
    }
    
    // end timer
    end_t = clock();

    // print attempt
    printf("Attempts done: %lld\n", attempt);
    printf("Total possibilities: %lld\n", possibilities);

    // calculate execution time
    time_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Time taken by CPU: %ld second(s).\n", time_t);
  } else {
    printf("Bad usage, ./bruteforce size_of_password \n");
    status = EXIT_FAILURE;
  }

  // clean memory
 clean :
  free(g_passwd);
  if (g_file != NULL) fclose(g_file);
  
  // returns status
  return status;
}

void ctrl_c(int signum) {
  if (signum == SIGINT) {
    free(g_passwd);
    if (g_file != NULL) fclose(g_file);
    exit(EXIT_SUCCESS);
  }
}

