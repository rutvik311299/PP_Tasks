#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {

        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];
    int i = 0;
    char ch;

    printf("Enter a string: ");

    while (1) {
        ch = getchar();  // Read a character

        if (ch == '\n') {
            break;
        }

        str[i] = ch;  // Store the character in the string
        i++;
    }
    str[i] = '\0';

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
