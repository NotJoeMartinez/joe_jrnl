#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

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

	char *sql = "CREATE TABLE IF NOT EXISTS joejrnl(jrnl_name TEXT, jrnl_desc TEXT, jrnl_path TEXT)";
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

int add_jrnl(char name[100], char desc[100], char fpath[100]){
    make_db();
 	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("jrnl.db", &db);

	// making sure the db was created
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    char query[512];
	char *sql = "INSERT INTO joejrnl VALUES(\'%s \', \'%s\',\'%s\');";
    sprintf(query, sql, name, desc, fpath);
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


int list_jrnls(){
 	sqlite3 *db;
	char *err_msg = 0;
    sqlite3_stmt *res;

	int rc = sqlite3_open("jrnl.db", &db);

	char *sql = "SELECT * FROM joejrnl;";

	// rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    printf("%s\n",rc);

	// sql quearies might fail check for erros and close db 
    if (rc == SQLITE_OK) {
        
        sqlite3_bind_int(res, 1, 3);
    } else {
        
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    
    int step = sqlite3_step(res);
    
    if (step == SQLITE_ROW) {
        
        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s\n", sqlite3_column_text(res, 1));
        printf("%s\n", sqlite3_column_text(res, 2));
        
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return 0;


}