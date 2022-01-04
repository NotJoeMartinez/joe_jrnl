#include <stdio.h>
int main() {  
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);  
    
    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c = %d\n", c, c);

	int key;
	printf("Enter a number to add: ");
	scanf("%d", &key);
    printf("ASCII value of %c + %d = %c : %d\n", c, key, c+key, c+key);

    
    return 0;
}
