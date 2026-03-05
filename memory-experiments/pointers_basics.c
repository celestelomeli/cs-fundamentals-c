// Pointer Basics: &(address-of), *(dereference), pointer declaration

#include <stdio.h>

int main(void) {
    int age = 30;
    int height = 180;
    
    int *age_ptr = &age;  // age_ptr stores address of age
    *age_ptr = 99;        // Modify age indirectly 

    printf("Value: %d\n", age);              // 99 changed via pointer
    printf("Address: %p\n", &age);           // Where age lives
    printf("Pointer value: %p\n", age_ptr);  // Same address
    printf("Dereferenced: %d\n", *age_ptr);  // 99 (indirect access)

    printf("Value: %d\n", height);
    printf("Address: %p\n", &height);        // 4 bytes away from age

    return 0;
}
