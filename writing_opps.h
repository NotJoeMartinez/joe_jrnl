
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "db_opps.h"

void timestamp_string (char * myString)
{
    char     timestamp[16];
    time_t    caltime;
    struct tm * broketime;

    // find current time, convert to broken-down time
    time(&caltime);
    broketime = localtime(&caltime);

    // append timestamp in the format "_yymmdd_hhmmss"
    strftime(timestamp,16,"%y%m%d_%H%M%S",broketime);
    strcat(myString,timestamp);
	strcat(myString,".md");

    return;
}

void make_journal(){
	char journal_dir[180];
	printf("Enter the path of your new journal: ");
	fgets(journal_dir, 180, stdin);
	printf("Journal Dir: %s\n", journal_dir);

	char journal_name[180];
	printf("Enter the name of your new journal: ");
	fgets(journal_name, 180, stdin);
	printf("Journal Name: %s \n", journal_name);

	char journal_desc[100];
	printf("Enter a description for your journal: ");
	fgets(journal_desc, 180, stdin);

	// remove newline chars from path
	journal_dir[strcspn(journal_dir, "\n")] = 0;
	journal_desc[strcspn(journal_desc,"\n")] = 0;
	journal_name[strcspn(journal_name,"\n")] = 0;

	strcat(journal_dir,"/");
	strcat(journal_dir,journal_name);

	journal_dir[strcspn(journal_dir, "\n")] = 0;

	printf("Full Journal Path %s \n", journal_dir);

	add_jrnl(journal_name, journal_desc, journal_dir);
	printf("Added journal to db\n");

	// Make the directory if it does not exist
	struct stat st = {0};

	if (stat(journal_dir, &st) == -1) {
    	mkdir(journal_dir, 0700);
	}
	else{
		printf("Folder exists in %s \n", journal_dir);

	}

}

void write_to_journal(){

	char journal_dir[180];
	printf("Enter the path of your journal: ");
	fgets(journal_dir, 180, stdin);

	journal_dir[strcspn(journal_dir, "\n")] = 0;
	strcat(journal_dir,"/");	
	timestamp_string(journal_dir);

	journal_dir[strcspn(journal_dir, "\n")] = 0;

    FILE *fp;

    fp = fopen(journal_dir, "a");

    if(fp == NULL) {
        // char *exe_name = "nvim", *message = "Empty notebook is running.";
        char *exe_args[] = { "nvim", journal_dir, NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }
    else{
        char *exe_args[] = {"nvim", journal_dir, NULL};
        execv("/usr/local/bin/nvim", exe_args);
    }

	fclose(fp);
}

	