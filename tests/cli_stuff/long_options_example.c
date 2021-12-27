#include <getopt.h> /* getopt */
#include <stdlib.h> /* exit   */
#include <stdio.h>  /* printf */

int main(int argc, char **argv)
{
  int c;

  while (1) 
{
    int option_index = 0;
    static struct option long_options[] = 
    {
        {"newjournal",     required_argument, NULL,  'j'},
        {"newentry",  required_argument,       NULL,  'e'},
        {"readjournal",  required_argument, NULL,  'l'},
        {"readentry", required_argument,       NULL,  'r'},
        {"help",  no_argument, NULL,  'h'},
        {NULL,      0,                 NULL,    0}
    };

    c = getopt_long(argc, argv, "-:j:e:l:r:h", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) 
    {
      case 0:
        printf("long option %s", long_options[option_index].name);
        if (optarg)
           printf(" with arg %s", optarg);
        printf("\n");
        break;

      case 1:
        printf("regular argument '%s'\n", optarg);
        break;

      case 'j':
        printf("option a with value '%s'\n", optarg);
        break;

     case 'e':
        printf("option p\n");
        break;

      case 'l':
        printf("option d with value '%s'\n", optarg);
        break;

     case 'r':
        printf("option v\n");
        break;

      case 'h':
        printf("option c with value '%s'\n", optarg);
        break;

      case '?':
        printf("Unknown option %c\n", optopt);
        break;

      case ':':
        printf("Missing option for %c\n", optopt);
        break;

      default:
        printf("?? getopt returned character code 0%o ??\n", c);
     }
}
}