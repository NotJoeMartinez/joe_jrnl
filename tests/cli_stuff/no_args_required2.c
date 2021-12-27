#include <stdio.h>  /* printf     */
#include <getopt.h> /* getopt API */

int main(int argc, char *argv[])
{
  int opt;

  while ((opt = getopt(argc, argv, "abX")) != -1) 
  {
     switch (opt) 
     {
      case 'a':
        printf("Option a was provided\n");
        break;
      case 'b':
        printf("Option b was provided\n");
        break;
      case 'X':
        printf("Option X was provided\n");
        break;
     }
  }
  
  return 0;
}