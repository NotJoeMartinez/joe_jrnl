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

    // printf("new val %d\n", c+key);

    int final_val;
    if ((c + key) > 127){
        final_val = c + key;
        while(final_val > 127){
            final_val = final_val % 127;
        }
    }


    printf("New ASCII value of %c=%c after key of %d\n",c, final_val, key );

    
    return 0;
}
