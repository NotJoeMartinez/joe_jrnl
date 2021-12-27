#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

    FILE *fp;

    fp = fopen(argv[1], "a");

    if(fp == NULL) {
        // char *exe_name = "nvim", *message = "Empty notebook is running.";
        char *exe_args[] = { "nvim", "filename.md", NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }
    else{
        char *exe_args[] = {"nvim",argv[1], NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }

	fclose(fp);
	return 0;
}