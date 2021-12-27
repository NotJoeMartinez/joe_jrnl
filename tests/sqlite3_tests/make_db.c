#include <stdio.h>
#include <sqlite3.h>

int make_db();
int read_db();
int update_db();
int test_db();

int main(){
	make_db();
    test_db();
	return 0;
}

int test_db(){

    static struct path_map = {
    "/Users/supernova/code/c_shit/journal_app/tests/cli_stuff"
    "/Users/supernova/code/c_shit/journal_app/tests/external_editing"
    "/Users/supernova/code/c_shit/journal_app/tests/importing_stuff"
    "/Users/supernova/code/c_shit/journal_app/tests/sqlite3_tests"
    }
}

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

int update_db(){
 	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("jrnl.db", &db);

	// making sure the db was created
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

	char *sql = "INSERT INTO joejrnl VALUES('','')";

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