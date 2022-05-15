#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * error_code 0: show help
 * error_code 1: unrecognize argument 
 * error_code 2: file does not exist 
 * error_code 3: missing encryption file path 
 * error_code 4: missing decryption file path 
*/

#define SHOW_HELP 0 
#define UNREC_ARGS 1
#define NO_FILE 2 
#define MISS_ENC 3
#define MISS_DEC 4

void encrypt(int key, char fpath[]);
void decrypt(int key, char fpath[]);
void print_error(int error_code);
void print_message(char fpath[]);
int mod(int a, int b);

int main(int argc, char* argv[]){

	if (argc < 2){
		print_error(SHOW_HELP);
		exit(0);
	}

	char arg_e[] = "-e";
	char arg_el[] = "encrypt";

	char arg_d[] = "-d";
	char arg_dl[] = "decrypt";

	 
	// ecnrypt file
	if( (strcmp(argv[1], arg_e) == 0) || (strcmp(argv[1], arg_el) == 0) ){
		printf("Encrypting \n");
		
		if (argc < 3){
			print_error(MISS_ENC);
			exit(0);
		}

		FILE* fp = fopen(argv[2], "r");
		if (fp == NULL){
			print_error(NO_FILE);
			fclose(fp);
			exit(0);
		}
		
		printf("Enter Key for %s: ", argv[2]);
		int key;
		scanf("%d", &key);
		encrypt(key, argv[2]);
		return 0;
	}

	// decrypt file
	else if( (strcmp(argv[1], arg_d) == 0) || (strcmp(argv[1], arg_dl) == 0) ){
		printf("Decrypting \n");

		if (argc < 3){
			print_error(MISS_DEC);
			exit(0);
		}
			
		FILE* fp = fopen(argv[2], "r");
		if (fp == NULL){
			print_error(NO_FILE);
			fclose(fp);
			exit(0);
		}
		
		printf("Enter Key for %s: ", argv[2]);
		int key;
		scanf("%d", &key);
		decrypt(key, argv[2]);
		
		return 0;
	}

	else {
			print_error(UNREC_ARGS);
			exit(0);

	}

;



	return 0;
}

void encrypt(int key, char fpath[]){
	
	char lowers[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char uppers[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	printf("Encrypting %s with key %d\n",fpath, key);

	FILE* fp = fopen(fpath, "r");	

	FILE* nfp = fopen("encrypted_message.txt", "w");

	char ch = fgetc(fp);


	char newch;
	while(ch != EOF){

		// check to see if it's a letter
		if ( (97 <= ch && ch <= 122) || (65 <= ch && ch <= 89) ){

			for (int i=0; i<26; i++){
				if (ch == lowers[i]){
					// new lower index
					int nli = i + key; 
					if (nli > 25 || nli < 0){
						nli = mod(nli,26); 
					}
					newch = lowers[nli];
					fputc(newch,nfp);
					break;
				}

				else if(ch == uppers[i]){
					int nli = i + key; 
					if (nli > 25 || nli < 0){
						nli = mod(nli,26); 
					}
					newch = uppers[nli];

					fputc(newch,nfp);
					break;				
				}

				}

		}

			else {

			fputc(ch,nfp);

		}


		ch = fgetc(fp);
	}
	fclose(nfp);
	fclose(fp);
	printf("Encrypted to encrypted_message.txt\n");
	printf("\n");
	print_message("encrypted_message.txt");

}

void decrypt(int key, char fpath[]){

	char lowers[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char uppers[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	printf("Decrypting %s with key %d\n",fpath, key);

	FILE* fp = fopen(fpath, "r");	

	FILE* nfp = fopen("decrypted_message.txt", "w");

	char ch = fgetc(fp);


	char newch;
	while(ch != EOF){

		// check to see if it's a letter
		if ( (97 <= ch && ch <= 122) || (65 <= ch && ch <= 89) ){

			for (int i=0; i<26; i++){
				if (ch == lowers[i]){
					// new lower index
					int nli = i - key; 

					if (nli < 0){
							nli = mod(nli,26);
					}

					newch = lowers[nli];
					fputc(newch,nfp);
					break;
				}

				else if(ch == uppers[i]){
					printf("upperch= %c \n", ch);
					int nli = i - key; 

					if (nli < 0){
							nli = mod(nli,26);
					}

					newch = uppers[nli];
					printf("%d\n",nli);
					fputc(newch,nfp);
					break;				
				}

				}

		}

			else {

			fputc(ch,nfp);

		}


		ch = fgetc(fp);
	}
	fclose(nfp);
	fclose(fp);
	printf("decrypted to decrypted_message.txt\n\n");
	print_message("decrypted_message.txt");
	
}

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

void print_message(char fpath[]){
	FILE* fp = fopen(fpath, "r");	
	char ch;
	do {
        /* Read single character from file */
        ch = fgetc(fp);

        /* Print character read on console */
        putchar(ch);

    } while(ch != EOF); /* Repeat this if last read character is not EOF */

	fclose(fp);
}


/*
 * error_code 0: show help
 * error_code 1: unrecognize argument 
 * error_code 2: file does not exist 
 * error_code 3: missing encryption file path 
 * error_code 4: missing decryption file path 
*/
void print_error(int error_code){
	
	if (error_code == 0 ){
		printf("ERROR: No argument supplied \n");
		printf("Usage: \n");
		printf("\t./a.out encrypt [-e] [path/to/file.txt] \n");
		printf("\t./a.out decrypt [-d] [path/to/file.txt] \n");
	}
	else if(error_code == 1){
		printf("ERROR: Unrecongized argument \n");
		printf("Usage: \n");
		printf("\t./a.out encrypt [-e] [path/to/file.txt] \n");
		printf("\t./a.out decrypt [-d] [path/to/file.txt] \n");	
	}
	else if (error_code == 2){
		printf("Error: File does not exist\n");
	}
	else if (error_code == 3 ){
		printf("Error: Missing filepath \n");
		printf("Usage: \n");
		printf("\t./a.out encrypt [-e] [path/to/file.txt] \n");
	}
	else if(error_code == 4){
		printf("ERROR: Missing filepath \n");
		printf("Usage: \n");
		printf("\t./a.out decrypt [-d] [path/to/file.txt] \n");	
	}
}