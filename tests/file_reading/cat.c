#include <stdio.h>
#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)
// int fscanf(FILE *fp, char *format, ...);
// int fprintf(FILE *fp, char *format, ...);
void filecopy(FILE *, FILE *);

/* cat: concatenate files, version 1 */
main(int argc, char *argv[]) {
	FILE *fp;
		/* no args; copy standard input */
		if (argc == 1){ 
			filecopy(stdin, stdout);
		}
		else{
			while(--argc > 0){
				if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
				}
				else {
					char *output="message2.txt";
					filecopy(fp, output);
					fclose(fp);
				}
			return 0;
			}
		}
}
/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp){
	int c;
	while ((c = getc(ifp)) != EOF){
	putc(c, ofp);
	}
}
