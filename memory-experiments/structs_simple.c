// Simple: How does a pointer know where everything is?

#include <stdio.h>

struct Box {
    int a;
    int b;
};

int main(void) {
    struct Box mybox;
    mybox.a = 10;
    mybox.b = 20;
    
    printf("The box lives at address: %p\n", &mybox);
    printf("  a is at: %p\n", &mybox.a);
    printf("  b is at: %p\n", &mybox.b);
    
    // Pass &mybox to pass ONE number (the address)
    printf("\n&mybox is just a number: %p\n", &mybox);
    printf("That's all the function gets - just this address.\n");
    
    // The function also knows the TYPE: struct Box
    // Function knows: "at this address, first 4 bytes = a, next 4 bytes = b"
    
    struct Box *ptr = &mybox;
    printf("\nptr stores: %p (just the starting address)\n", ptr);
    printf("ptr->a means: go to %p and read 4 bytes → %d\n", ptr, ptr->a);
    printf("ptr->b means: go to %p + 4 bytes and read 4 bytes → %d\n", ptr, ptr->b);
    
    return 0;
}
