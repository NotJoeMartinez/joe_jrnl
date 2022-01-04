//Simple C program to encrypt and decrypt a string
#include <getopt.h>
#include <stdio.h>
#include <string.h>
char caesar_math(char str[100], int key);
void file_mode(char fpath[100]);
void encrypt_file(char decrypted[100], char encrypted[100], int key);

int main(){
   char fpath[100]= "message.txt";
   file_mode(fpath);
} 

void file_mode(char fpath[100]){
   int key;
   char encrypted[50];
   printf("Enter the shift: ");
   scanf("%d", &key);
   printf("key: %d\n", key);
   printf("%s\n", fpath);

   fpath[strcspn(fpath, "\n")] = 0;
   strcpy(encrypted,fpath);
   char words[100] = "encrypted_";
   strcat(words,encrypted);

   encrypt_file(fpath, words, key);
}

void encrypt_file(char decrypted[100],char encrypted[100], int key){
    FILE *fptr1, *fptr2;
    char c;
  
    // Open one file for reading
    fptr1 = fopen(decrypted, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", decrypted);
      //   exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen(encrypted, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", encrypted);
      //   exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF){
       caesar_math(c, key);
       fputc(c, fptr2);
       c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", encrypted);
  
    fclose(fptr1);
    fclose(fptr2);
}

char caesar_math(char str[100], int key){
   //using switch case statements
   int i, x;

   switch(x){

   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + key; //the key for encryption is 3 that is added to ASCII value

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - key; //the key for encryption is 3 that is subtracted to ASCII value

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError\n");
   }
}