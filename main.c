#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int i = 0; i <= 100; ++i) {
        sum += i;
    }

    printf("sum = %d\n", sum);
    printf("sum = %d\n", (1+100)*100/2);
    return 0;
}
