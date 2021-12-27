
#include <stdio.h>

/* A simple C program that prints the contents of argv */

int main(int argc, char **argv) {
    int i;
   
    for(i=0; i<argc; i++)
      printf("%s\n", argv[i]);
}