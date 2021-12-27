#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

int make_db();
int read_db();
int update_db(char path[100], char desc[100]);
int test_db();

int main(){
	// make_db();
    // test_db();
    test_db();
	return 0;
}

int test_db(){

    char paths[10][100][100]= {
        {"~/code/c_shit/joe_jrnl/tests/cli_stuff", "Commanline Testing"},
        {"~/code/c_shit/joe_jrnl/tests/external_editing", "External Editor Testing"},
        {"~/code/c_shit/joe_jrnl/tests/importing_stuff", "Import Statment testing"},
        {"~/code/c_shit/joe_jrnl/tests/sqlite3_tests", "Database Testing"},
        };
    
    for (int i=0; i<=3; i++){
        update_db(paths[i][0],paths[i][1]);
    }

    return 0;
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

int update_db(char fpath[100], char desc[100]){
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