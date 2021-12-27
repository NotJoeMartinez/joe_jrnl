#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

    FILE *fp;
    int childpid;
    int count1 = 0, count2 = 0;

    fp = fopen(argv[1], "a");

    if(fp == NULL) {
        // char *exe_name = "nvim", *message = "Empty notebook is running.";
        char *exe_args[] = { "nvim", "filename.md", NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }
    else
    {
        char *exe_args[] = {"nvim",argv[1], NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }

    printf("Before it forks");

    sleep(5);

    childpid = fork();

    if(childpid == 0) {
        printf("This is a child process\n");
        while(count1 < 10) {
            printf("Child Process: %d\n", count1);
            sleep(1);
            count1++;
        } 
    } else {
        printf("This is the parent process\n");
        while(count2 < 20) {
            printf("Parent Process: %d\n", count2);
            sleep(1);
            count2++;
        } 
    }
    fclose(fp);
    return 0;
}
 
