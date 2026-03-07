// db.c - Database implementation (the "kitchen")
// This file has the actual code that does the work

#include <stdio.h> //  Standard I/O for printing
#include <stdlib.h>  // For malloc and free
#include <string.h>  // For strcpy
#include "db.h"      // Include our header file

// Global variables - the actual database storage
static Student *students = NULL;  // Pointer to array of students (starts empty)
static int count = 0;             // How many students we have
static int capacity = 0;          // How much space we allocated

// Add a student to the database
void db_add_student(char *name, int age, float gpa) {
    // STEP 1: Do we need more space?
    if (count >= capacity) {
        // Grow the array (start with 2, then double each time)
        int new_capacity = (capacity == 0) ? 2 : capacity * 2;
        
        // Allocate new bigger array
        Student *new_students = malloc(new_capacity * sizeof(Student));
        
        // Copy old students to new array
        for (int i = 0; i < count; i++) {
            new_students[i] = students[i];
        }
        
        // Free old array and use new one
        free(students);
        students = new_students;
        capacity = new_capacity;
        
        printf("Database grew to capacity %d\n", capacity);
    }
    
    // STEP 2: Add the new student
    strcpy(students[count].name, name); // strcpy to copy string from where name points to in struct's name array
    students[count].age = age; // copy int
    students[count].gpa = gpa; // copy float
    count++;
    
    printf("Added: %s (age %d, GPA %.1f)\n", name, age, gpa);
}

// List all students
void db_list_students(void) {
    if (count == 0) {
        printf("No students in database.\n");
        return;
    }
    
    printf("\n=== Student Database ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (age %d, GPA %.1f)\n", 
               i + 1, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
    printf("Total: %d students\n\n", count);
}

// Delete a student by index
void db_delete_student(int index) {
    if (index < 0 || index >= count) {
        printf("Invalid index!\n");
        return;
    }
    
    printf("Deleted: %s\n", students[index].name);
    
    // Shift all students after this one down
    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    
    count--;
}

// Get number of students
int db_get_count(void) {
    return count;
}
