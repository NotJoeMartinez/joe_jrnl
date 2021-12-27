#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

// int make_db();
// int read_db();
// int update_db(char path[100], char desc[100]);
// int test_db();


int make_db(){
 	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("jrnl.db", &db);

	// making sure the db was created
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

	char *sql = "CREATE TABLE IF NOT EXISTS joejrnl(jrnl_name TEXT, jrnl_path TEXT)";
	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);


	// sql quearies might fail check for erros and close db 
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;

}

int add_jrnl(char fpath[100], char desc[100]){
    make_db();
 	sqlite3 *db;
	char *err_msg = 0;

    printf("%s, %s\n", fpath, desc);
	int rc = sqlite3_open("jrnl.db", &db);

	// making sure the db was created
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    char query[512];
	char *sql = "INSERT INTO joejrnl VALUES(\'%s\',\'%s\');";
    sprintf(query, sql, fpath, desc);
    printf("%s\n",query);




	rc = sqlite3_exec(db, query, 0, 0, &err_msg);

	// sql quearies might fail check for erros and close db 
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}