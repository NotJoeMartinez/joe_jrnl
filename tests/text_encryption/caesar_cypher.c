//Simple C program to encrypt and decrypt a string
#include <getopt.h>
#include <stdio.h>
#include <string.h>
int caesar_math(char str[100], int key);
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
       int e_char;
       e_char = caesar_math(c, key);
       fputc(e_char, fptr2);
       c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", encrypted);
  
    fclose(fptr1);
    fclose(fptr2);
}

int caesar_math(char c[10], int key){
   int final_val;
   if ((c + key) > 127){
        final_val = c + key;
        while(final_val > 127){
            final_val = final_val % 127;
        }
    }
   return final_val;
}