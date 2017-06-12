#include "bruteforce.h"
#include <stdio.h> // perror(), fprintf()
#include <stdlib.h>
#include <time.h> // clock()


/* main method */
int main(int argc, char *argv[]) {
  int status = EXIT_SUCCESS; // return status
  char *passwd = NULL;
  
  // check args
  if (argc == 2) {
    // variables
    clock_t start_t = 0,
      end_t = 0,
      time_t = 0;

    const unsigned int s_passwd = atoi(argv[1]);

    print_number_of_possibilities(s_passwd);
    
    status = init_ptr(&passwd, s_passwd, 'a');
    printf("Password initialized: %s\n", passwd);
    
    start_t = clock();
  
    // calculate all password possibilities
  
    end_t = clock();

    // calculate execution time
    time_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Time taken by CPU: %ld second(s).\n", time_t);
  } else {
    printf("Bad usage, ./bruteforce size_of_password \n");
    status = EXIT_FAILURE;
  }

  // clean memory
  free(passwd);
  
  // returns status
  return status;
}
  
