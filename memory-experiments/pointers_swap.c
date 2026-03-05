// Pointer Swap: Functions need pointers to modify caller's variables

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  // Get value at a's address
    *a = *b;        // Write b's value to a's address
    *b = temp;      // Write temp to b's address
}

int main(void) {
    int x = 5;
    int y = 10;

    printf("Before: x=%d, y=%d\n", x, y);
    swap(&x, &y);  // Pass addresses so function can modify originals
    printf("After: x=%d, y=%d\n", x, y);

    return 0;
}
