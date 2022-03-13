//Simple C program to encrypt and decrypt a string
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

int caesar_math(char str[100], int key, int mode);
void crypto_opps(char input[100], int mode);

int main(int argc, char* argv[]){
   int opt;
   while((opt = getopt(argc, argv, ":e:d:")) != -1){
      switch(opt){
         case 'e':
            crypto_opps(argv[2], 1);
            break;
         case 'd':
            crypto_opps(argv[2],0);
            break;
      }
   }

} 


void crypto_opps(char input[100], int mode){

   int key;
   char prepstring[100];

   printf("Enter the key: ");
   scanf("%d", &key);

   if(mode==1){
      strcpy(prepstring, "encrypted_");
   }

   if(mode == 0){
      strcpy(prepstring, "decrypted_");
   }
   // clearjunk
   input[strcspn(input, "\n")] = 0;


   strcat(prepstring,input);


    FILE *fptr1, *fptr2;
    char c;
  
    // Open one file for reading
    fptr1 = fopen(input, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", input);
      //   exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen(prepstring, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", prepstring);
      //   exit(0);
    }
  
    // Open and encrypt file charcater by character 
    c = fgetc(fptr1);
    while (c != EOF){
       int e_char;
       e_char = caesar_math(c, key, mode); 
       fputc(e_char, fptr2);
       c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", prepstring);
  
    fclose(fptr1);
    fclose(fptr2);
}

int caesar_math(char c[10], int key, int mode){

   int final_val;
   if (mode == 1){
      if ((c + key) > 127){
         final_val = c + key;
         while(final_val > 127){
               final_val = final_val % 127;
         }
      }
   }

   if (mode == 0){
      if ((c - key) > 127){
         final_val = c - key;
         while(final_val > 127){
            final_val = final_val % 127;
         }
      }

   }
   
   printf("final val: %d\n", final_val);
   return final_val;
}