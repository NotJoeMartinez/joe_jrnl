# joe_jrnl 
A commandline journal application written in C. 

### Problems to solve
- Dynamically create new file names
	- generate a date time string 
	- concatinate this string to a filepath with a txt varable

- Allowing for creation of entries in external editor  
  - https://stackoverflow.com/questions/61662295/open-file-in-vi-vim-using-c-language

- Sqlite3 interface 
  - https://zetcode.com/db/sqlitec/

- CLI options 
  - `-h`
	- Help: Describes what the program does
	- This is a journaling application that allows you to password protect your ideas
  - `-ne` 
    - New Entry: Opens a text editor to write your thoughts 
	- Needs a Journal name specify 
  - `-nj` 
    - New Journal: Prompts the user for a password and file path for journal
  - `-rj`
    - Read Journal: Lists entires or filenames of journal
  - `-re` 
    - Reads Entry: Reads Entires based on Filename 

