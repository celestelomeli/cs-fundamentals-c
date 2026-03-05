// Structs: Grouping related data together

#include <stdio.h>
#include <string.h>

// Define a struct type
struct Student {
    int age;
    float gpa;
    char name[20];
    
};

// Function that takes a pointer to struct (efficient)
void print_student(struct Student *s) {
    printf("\nInside function:\n");
    printf("Name: %s\n", s->name);  // Use -> for pointer-to-struct
    printf("Age: %d\n", s->age);
    printf("GPA: %.1f\n", s->gpa);
}

int main(void) {
    // Create a struct variable
    struct Student alice;
    alice.age = 20;
    alice.gpa = 3.8;
    strcpy(alice.name, "Alice");
    
    // Access struct members with dot notation
    printf("Student Info:\n");
    printf("Name: %s\n", alice.name);
    printf("Age: %d\n", alice.age);
    printf("GPA: %.1f\n", alice.gpa);
    
    // Struct memory layout
    printf("\nMemory addresses:\n");
    printf("Struct starts at: %p\n", &alice);
    printf("age at: %p\n", &alice.age);
    printf("gpa at: %p\n", &alice.gpa);
    printf("name at: %p\n", &alice.name);
    
    // Pointer to struct (important for functions!)
    struct Student *ptr = &alice;
    
    // Two ways to access members through pointer:
    printf("\nAccessing via pointer:\n");
    printf("Age (ugly way): %d\n", (*ptr).age);  // Dereference then dot
    printf("Age (clean way): %d\n", ptr->age);   // Arrow operator
    printf("GPA: %.1f\n", ptr->gpa);
    printf("Name: %s\n", ptr->name);
    
    // Pass struct to function (pass pointer for efficiency)
    print_student(&alice);
    
    return 0;
}
