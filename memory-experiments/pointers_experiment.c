// Pass-by-Value vs Pass-by-Pointer: Compare addresses to see the difference

#include <stdio.h>

// BROKEN: Gets copies at different addresses
void broken_swap(int a, int b) {
    printf("  Inside broken_swap BEFORE: a=%d, b=%d\n", a, b);
    printf("  Address of a: %p\n", &a);  // Different from x1
    printf("  Address of b: %p\n", &b);  // Different from y1
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("  Inside broken_swap AFTER: a=%d, b=%d\n", a, b);
}

// WORKS: Gets addresses, modifies originals
void working_swap(int *a, int *b) {
    printf("  Inside working_swap BEFORE: *a=%d, *b=%d\n", *a, *b);
    printf("  Address stored in a: %p\n", a);  // Same as x2
    printf("  Address stored in b: %p\n", b);  // Same as y2
    
    int temp = *a;
    *a = *b;
    *b = temp;
    
    printf("  Inside working_swap AFTER: *a=%d, *b=%d\n", *a, *b);
}

int main(void) {
    // TEST 1: Pass by value (broken)
    printf("=== TEST 1: BROKEN (pass by value) ===\n");
    int x1 = 5;
    int y1 = 10;
    printf("BEFORE call: x1=%d, y1=%d\n", x1, y1);
    printf("Address of x1: %p\n", &x1);
    printf("Address of y1: %p\n", &y1);
    
    broken_swap(x1, y1);  // Passes values, not addresses
    
    printf("AFTER call: x1=%d, y1=%d\n", x1, y1);
    printf("x1 and y1 UNCHANGED!\n\n");
    
    // TEST 2: Pass by pointer (works)
    printf("=== TEST 2: WORKING (pass by pointer) ===\n");
    int x2 = 5;
    int y2 = 10;
    printf("BEFORE call: x2=%d, y2=%d\n", x2, y2);
    printf("Address of x2: %p\n", &x2);
    printf("Address of y2: %p\n", &y2);
    
    working_swap(&x2, &y2);  // Passes addresses
    
    printf("AFTER call: x2=%d, y2=%d\n", x2, y2);
    printf("x2 and y2 SWAPPED!\n");
    
    return 0;
}

// KEY: Compare addresses in output - broken version has different addresses
