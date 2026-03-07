// main.c - MiniDB interactive program
// This is the "front end" that users interact with

#include <stdio.h> //  standard input/output (for printf, scanf)
#include "db.h"  // Include database functions

// Display the menu
void show_menu(void) {
    printf("\n=== MiniDB - Student Database ===\n");
    printf("1. Add student\n");
    printf("2. List all students\n");
    printf("3. Delete student\n");
    printf("4. Quit\n");
    printf("Choice: ");
}

int main(void) {
    printf("Welcome to MiniDB!\n");
    
    int choice;
    int running = 1;  // Keep program going until user quits
    
    // Main loop
    while (running) {
        show_menu();
        scanf("%d", &choice);
        
        // Handle user's choice
        if (choice == 1) {
            // Add a student
            char name[50];
            int age;
            float gpa;
            
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter GPA: ");
            scanf("%f", &gpa);
            
            db_add_student(name, age, gpa);
            
        } else if (choice == 2) {
            // List all students
            db_list_students();
            
        } else if (choice == 3) {
            // Delete student
            db_list_students();  // Show list first
            
            if (db_get_count() > 0) {
                int index;
                printf("Enter student number to delete: ");
                scanf("%d", &index);
                db_delete_student(index - 1);  // Convert to 0-based index
            }
            
        } else if (choice == 4) {
            // Quit
            printf("Goodbye!\n");
            running = 0;
            
        } else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
