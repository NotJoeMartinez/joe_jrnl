//Simple C program to encrypt and decrypt a string
#include <getopt.h>
#include <stdio.h>
void interactive();
void file_mode(char fpath[100]);


int main(int argc, char* argv[]){
   int opts;
   while(1){
      int option_index = 0;
      static struct option long_options[] = {
        {"interactive",  no_argument, NULL,  'i'},
        {"file", required_argument, NULL,  'f'},
        {"help",  no_argument, NULL,  'h'},
        {NULL, 0, NULL, 0}
    };

    opts = getopt_long(argc, argv, "-:i:f:h", long_options, &option_index);

    if (opts == -1)
      break;


   switch (opts){
      case 'i':
         interactive();
         break;
      case 'f':
         file_mode(optarg);
         break;
      case 'h':
         break;
      }

   }
   return 0;

}


void file_mode(char fpath[100]){
   printf("Enter a password for your file: ");
   char key[100];
   fgets(key, 180, stdin);
   printf("key: %s\n", key);
}

void interactive(){

   //using switch case statements
   int i, x;
   char str[100];

   printf("\nPlease enter a string:\t");
   gets(str);

   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the string.\n");
   printf("2 = Decrypt the string.\n");
   scanf("%d", &x);

   int key;
   printf("Enter a password for the string 1-10: ");
   scanf("%d", &key);
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