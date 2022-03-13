#include <stdio.h>
#include <stdlib.h> // For exit()

void encrypt_file(char decrypted[100], char encrypted[100]);
  
int main(){

    char decrypted[100] = "message.txt";
    char encrypted[100] = "encrypted_message.txt";
    encrypt_file(decrypted, encrypted);

}

void encrypt_file(char decrypted[100],char encrypted[100]){
    FILE *fptr1, *fptr2;
    char c;
  
    // Open one file for reading
    fptr1 = fopen(decrypted, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", decrypted);
        exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen(encrypted, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", encrypted);
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", encrypted);
  
    fclose(fptr1);
    fclose(fptr2);
}