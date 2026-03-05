// Arrays and Pointers: Arrays are pointers to their first element

#include <stdio.h>

// When you pass an array to a function, it becomes a pointer
void print_array(int *arr, int size) {
    printf("Inside function:\n");
    for (int i = 0; i < size; i++) {
        printf("  arr[%d] = %d (address: %p)\n", i, arr[i], &arr[i]);
    }
}

int main(void) {
    int numbers[3] = {10, 20, 30};
    
    // Array name is a pointer to first element
    printf("Array address: %p\n", numbers);
    printf("First element address: %p\n", &numbers[0]);
    
    // Each element has its own address (4 bytes apart)
    printf("\nIndividual addresses:\n");
    printf("&numbers[0] = %p\n", &numbers[0]);
    printf("&numbers[1] = %p\n", &numbers[1]);
    printf("&numbers[2] = %p\n", &numbers[2]);
    
    // Two ways to access elements
    printf("\nUsing array notation:\n");
    printf("numbers[0] = %d\n", numbers[0]);
    printf("numbers[1] = %d\n", numbers[1]);
    printf("numbers[2] = %d\n", numbers[2]);
    
    printf("\nUsing pointer notation:\n");
    printf("*numbers = %d\n", *numbers);              // Same as numbers[0]
    printf("*(numbers + 1) = %d\n", *(numbers + 1));  // Same as numbers[1]
    printf("*(numbers + 2) = %d\n", *(numbers + 2));  // Same as numbers[2]
    
    // Pointer arithmetic: numbers + 1 means "skip 1 int (4 bytes)"
    printf("\nPointer arithmetic:\n");
    printf("numbers + 0 = %p\n", numbers + 0);
    printf("numbers + 1 = %p\n", numbers + 1);
    printf("numbers + 2 = %p\n", numbers + 2);
    
    // Pass array to function (array becomes pointer)
    printf("\nPassing to function:\n");
    print_array(numbers, 3);
    
    return 0;
}
