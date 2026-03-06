// db.h - Database header file (the "menu")
// File declares what's available to use

#ifndef DB_H
#define DB_H

// Student record - typedef lets us write "Student" instead of "struct Student"
typedef struct {
    char name[50];  // Student name
    int age;        // Student age
    float gpa;      // Student GPA
} Student;

// Database functions - these are the "menu" of what you can do with the database
void db_add_student(char *name, int age, float gpa);  // Add a student
void db_list_students(void);                          // List all students
void db_delete_student(int index);                    // Delete student by index
int db_get_count(void);                               // Get number of students

#endif
