#include <stdio.h>

int multiplyBy9(int n) {

    return (n << 3) + n;        // Multiply by 8 using left shift and then add the original number
}

int main() {
    int num;
    int result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = multiplyBy9(num);
    printf("%d multiplied by 9 is: %d\n", num, result);

    return 0;
}
