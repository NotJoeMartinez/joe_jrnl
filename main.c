
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include "writing_opps.h"

void show_help();

int main(int argc, char* argv[]){

  if (argc < 2){
    printf("No argument supplied\n");
    show_help();
  }

	int c;
	while (1) {
    int option_index = 0;
    static struct option long_options[] = {
        {"new-journal",  no_argument, NULL,  'j'},
        {"new-entry",  no_argument,       NULL,  'e'},
        {"list-journals",  no_argument, NULL,  'l'},
        {"read-entry", required_argument,       NULL,  'r'},
        {"help",  no_argument, NULL,  'h'},
        {NULL,      0,                 NULL,    0}
    };

    c = getopt_long(argc, argv, "-:j:e:l:r:h", long_options, &option_index);

    if (c == -1)
      break;

    switch (c) {

       case 'j':
	   		make_journal();
        	break;

     case 'e':
	 	    write_to_journal();
        break;

      case 'l':
        printf("Listing journals:\n");
        list_jrnls();
        break;

     case 'r':
        printf("Reading entry: '%s'\n", optarg);
        break;

      case 'h':
        show_help();
        break;

      case '?':
        printf("Unknown option %c\n", optopt);
        break;

      case ':':
        printf("Missing option for %c\n", optopt);
        break;

      default:
        printf("Error: getopt returned character code 0%o ??\n", c);
     }
}

		return 0;


}


void show_help(){
        printf("Help Page:\n");
        printf("--new-journal\n");
        printf("--new-entry\n");
        printf("--list-journals\n");
        printf("--read-entry\n");
}