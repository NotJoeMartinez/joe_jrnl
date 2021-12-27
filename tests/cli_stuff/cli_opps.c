#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

// https://opensource.com/article/19/5/how-write-good-c-main-function

#define OPTSTR "a:b:f"
extern char *optarg;

void opt_a();
void opt_b();

int main(int argc, char **argv) {
    int opt;
    char *bar = NULL;
    char *foo = NULL;
   
    while((opt=getopt(argc, argv, OPTSTR)) != EOF)
       switch(opt) {
          case 'a':
              opt_a();
              bar = optarg;
              break;
          case 'b':
              opt_b();
              foo = optarg;
              break;
          case 'h':
          default:
              fprintf(stderr, "Huh? try again.");
              exit(-1);
              /* NOTREACHED */
       }
    printf("%s\n", foo ? foo : "Empty foo");
    printf("%s\n", bar ? bar : "Empty bar");
}


void opt_a(){
    printf("User chose Option a\n");
}
void opt_b(){
    printf("User chose Option b\n");
}