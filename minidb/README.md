# MiniDB

A simple in-memory student database demonstrating dynamic memory allocation with `malloc`/`free` and multi-file C projects.

---

## What I Learned

- **Dynamic Memory Allocation** - `malloc` and `free`
- **Growing Arrays** - Allocate, copy, free pattern
- **Multi-file Projects** - Header files (`.h`) and implementation files (`.c`)
- **`typedef struct`** - Creating type aliases
- **String Handling** - `strcpy` for copying strings

---

## Project Structure

```
minidb/
├── db.h              - Database interface 
├── db.c              - Database implementation 
├── main.c            - Interactive menu program
├── malloc_demo.c     - Demo of malloc/free
└── README.md         - This file
```

---

## Files Explained

### `db.h` - The Interface
Declares what's available:
- `Student` struct (name, age, GPA)
- `db_add_student()` - Add a student
- `db_list_students()` - Display all students
- `db_delete_student()` - Remove a student
- `db_get_count()` - Get total count

### `db.c` - The Implementation
Contains the actual code:
- Dynamic array storage (`malloc`/`free`)
- Grows automatically 
- All database operations

### `main.c` - The Application
Interactive menu:
1. Add student
2. List all students
3. Delete student
4. Quit

---

## How to Build and Run

### Compile
```bash
gcc main.c db.c -o minidb
```

### Run
```bash
./minidb
```

### Example Session
```
Welcome to MiniDB!

=== MiniDB - Student Database ===
1. Add student
2. List all students
3. Delete student
4. Quit
Choice: 1
Enter name: Alice
Enter age: 20
Enter GPA: 3.8
Database grew to capacity 2
Added: Alice (age 20, GPA 3.8)

Choice: 2

=== Student Database ===
1. Alice (age 20, GPA 3.8)
Total: 1 students
```

---

## Key Concepts

### Dynamic Memory Allocation

**Fixed Array:**
```c
int numbers[10];  // Always 10, can't change
```

**Dynamic Array:**
```c
int *numbers = malloc(10 * sizeof(int));  
free(numbers);  // Clean up
```

### Growing Pattern

When array is full:
1. Allocate bigger array with `malloc`
2. Copy old data to new array
3. Free old array with `free`
4. Use new array

```c
Student *new_students = malloc(new_capacity * sizeof(Student));
for (int i = 0; i < count; i++) {
    new_students[i] = students[i];
}
free(students);
students = new_students;
```

### Multi-file Compilation

**Header file (`.h`)** - Declarations (what exists)  
**Implementation file (`.c`)** - Definitions (how it works)

```bash
gcc main.c db.c -o minidb
```

Compiles both files and links them together.

---

## Educational Demo

### `malloc_demo.c`
Shows `malloc`/`free` concepts in isolation:

```bash
gcc malloc_demo.c -o malloc_demo
./malloc_demo
```


## Memory Management

### The Three Variables

```c
static Student *students = NULL;  // Pointer to array
static int count = 0;             // Current students
static int capacity = 0;          // Allocated space
```

**Example Timeline:**
```
Start:     students=NULL, count=0, capacity=0
Add Alice: students=[Alice,_], count=1, capacity=2
Add Bob:   students=[Alice,Bob], count=2, capacity=2
Add Carol: students=[Alice,Bob,Carol,_], count=3, capacity=4
```

### Why `static`?

Makes variables private to `db.c` - other files can't access them directly. Must use the functions.

---

## Common Operations

### Add Student
```c
db_add_student("Alice", 20, 3.8);
```
- Checks if space available
- Grows array if needed
- Adds student to next slot

### List Students
```c
db_list_students();
```
- Loops through all students
- Prints each one

### Delete Student
```c
db_delete_student(0);  // Delete first student
```
- Removes student at index
- Shifts remaining students down

---

## Technical Highlights

### `typedef struct`

**Without typedef:**
```c
struct Student alice;  // Must say "struct"
```

**With typedef:**
```c
Student alice;  // Cleaner!
```

### String Parameters

```c
void db_add_student(char *name, int age, float gpa);
```

- `char *name` - Pointer (strings are arrays)
- `int age` - Value (single number)
- `float gpa` - Value (single number)

---

## Next Steps

Potential enhancements:
- [ ] Add file I/O (save/load database)
- [ ] Add search functionality
- [ ] Add update/edit student
- [ ] Add input validation
- [ ] Create Makefile

---

## Learning Outcomes

✅ Understanding `malloc` - requesting memory at runtime  
✅ Understanding `free` - returning memory to prevent leaks  
✅ Growing dynamic arrays - allocate, copy, free pattern  
✅ Multi-file projects - separation of interface and implementation  
✅ `typedef struct` - creating type aliases  
✅ String handling in C - `strcpy` and `char *`  

---

## Resources

- `UNDERSTANDING.md` - Visual guide to `db.h` and `db.c` relationship
- `malloc_demo.c` - Hands-on demo of dynamic memory concepts
