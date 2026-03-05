// Arrays: Simple example of passing to functions

#include <stdio.h>

// Function that prints array elements
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main(void) {
    int numbers[3] = {10, 20, 30};
    
    // Print from main
    printf("In main:\n");
    printf("numbers[0] = %d\n", numbers[0]);
    printf("numbers[1] = %d\n", numbers[1]);
    printf("numbers[2] = %d\n", numbers[2]);
    
    // Print from function
    printf("\nIn function:\n");
    print_array(numbers, 3);
    
    return 0;
}
