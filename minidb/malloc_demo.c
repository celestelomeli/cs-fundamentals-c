// malloc_demo.c - Understanding dynamic memory allocation
// Run this to see malloc/free in action!

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== Dynamic Memory Demo ===\n\n");
    
    // CONCEPT 1: malloc allocates memory
    printf("1. Allocating space for 3 integers...\n");
    int *numbers = malloc(3 * sizeof(int));
    printf("   malloc gave us memory at address: %p\n", numbers);
    printf("   Size allocated: %zu bytes (3 × %zu)\n\n", 
           3 * sizeof(int), sizeof(int));
    
    // CONCEPT 2: Use it like an array
    printf("2. Storing values...\n");
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    printf("   numbers[0] = %d\n", numbers[0]);
    printf("   numbers[1] = %d\n", numbers[1]);
    printf("   numbers[2] = %d\n\n", numbers[2]);
    
    // CONCEPT 3: Growing - need more space!
    printf("3. Need more space! Growing from 3 to 6...\n");
    int *new_numbers = malloc(6 * sizeof(int));
    printf("   New memory at address: %p\n", new_numbers);
    
    // Copy old data to new location
    printf("   Copying old data to new location...\n");
    for (int i = 0; i < 3; i++) {
        new_numbers[i] = numbers[i];
    }
    
    // Free old memory
    printf("   Freeing old memory at %p\n", numbers);
    free(numbers);
    
    // Use new memory
    numbers = new_numbers;
    printf("   Now using new memory!\n\n");
    
    // Add more values
    printf("4. Adding more values to new space...\n");
    numbers[3] = 40;
    numbers[4] = 50;
    numbers[5] = 60;
    
    printf("   All values: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    // CONCEPT 4: Always free when done!
    printf("5. Cleaning up - freeing memory...\n");
    free(numbers);
    printf("   Memory returned to system!\n\n");
    
    printf("=== Key Takeaways ===\n");
    printf("✓ malloc = borrow memory from computer\n");
    printf("✓ Use it like an array\n");
    printf("✓ To grow: malloc new, copy old, free old\n");
    printf("✓ Always free when done!\n");
    
    return 0;
}
