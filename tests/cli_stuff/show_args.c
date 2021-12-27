#include <stdio.h>  /* printf */
#include <getopt.h> /* getopt */

int main(int argc, char *argv[])
{
  int opt;

  while ((opt = getopt(argc, argv, ":n:b:X")) != -1) 
  {
     switch (opt) 
     {
      case 'n':
        printf("Option a has arg: %s\n", optarg);
        break;
      case 'b':
        printf("Option b has arg: %s\n", optarg);
        break;
      case 'X':
        printf("Option X was provided\n");
        break;
      case '?':
        printf("Unknown option: %c\n", optopt);
        break;
      case ':':
        printf("Missing arg for %c\n", optopt);
        break;
     }
  }

    /* Get all of the non-option arguments */
  if (optind < argc) 
  {
    printf("Non-option args: ");
    while (optind < argc)
      printf("%s ", argv[optind++]);
    printf("\n");
  }
  
  return 0;
}
