// Hash table with chaining

#include <stdio.h> // Standard I/O for printing
#include <stdlib.h> // For malloc and free
#include <string.h> // String functions for copying and comparing

#define TABLE_SIZE 10  // Small size for collisions

// Node for linked list 
struct Entry {
    char *key;           // Name (pointer to string)
    int value;           // age (integer)
    struct Entry *next;  // pointer to next entry (collision)
};

// Array of linked lists
struct Entry *hash_table[TABLE_SIZE];

// Hash function to convert string to index
int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];  // Add up ASCII values
    }
    return sum % TABLE_SIZE; 
}

// Insert key-value pair
void insert(char *key, int value) {
    int index = hash(key);
    printf("  Inserting '%s' (age %d) at index %d\n", key, value, index);
    
    // Create new entry
    struct Entry *new_entry = malloc(sizeof(struct Entry)); // allocate memory for Entry struct
    new_entry->key = malloc(strlen(key) + 1); // allocate memory for key string
    strcpy(new_entry->key, key); // copy key string into allocated space
    new_entry->value = value; // set value
    new_entry->next = hash_table[index];  // set next to point to current first entry at index
    
    hash_table[index] = new_entry;  // Put at front of chain
}

// Lookup value by key
int lookup(char *key) {
    int index = hash(key);
    struct Entry *current = hash_table[index]; // current
    
    // Traverse chain at index 
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) { //  if current's key matches search key
            return current->value;  // return current's value
        }
        current = current->next;
    }
    
    return -1;  // Not found
}

int main(void) {
    printf("=== Hash Table Basics ===\n\n");
    
    // Initialize all hash table slots to null
    for (int i = 0; i < TABLE_SIZE; i++) { 
        hash_table[i] = NULL;
    }
    
    // Insert some students
    printf("1. Inserting students:\n");
    insert("Alice", 20);
    insert("Bob", 25);
    insert("Charlie", 22);
    insert("Diana", 23);
    printf("\n");
    
    // Lookup and print values
    printf("2. Looking up students:\n");
    printf("  Alice's age: %d\n", lookup("Alice"));
    printf("  Bob's age: %d\n", lookup("Bob"));
    printf("  Charlie's age: %d\n", lookup("Charlie"));
    printf("  Diana's age: %d\n", lookup("Diana"));
    printf("  Zoe's age: %d (not found)\n\n", lookup("Zoe"));
    
    // Show hash values
    printf("3. Hash values:\n");
    printf("  hash('Alice') = %d\n", hash("Alice"));
    printf("  hash('Bob') = %d\n", hash("Bob"));
    printf("  hash('Charlie') = %d\n", hash("Charlie"));
    printf("  hash('Diana') = %d\n\n", hash("Diana"));
    
    // Cleanup memory
    printf("4. Cleaning up...\n");
    for (int i = 0; i < TABLE_SIZE; i++) { 
        struct Entry *current = hash_table[i]; 
        while (current != NULL) { 
            struct Entry *temp = current; // temp to keep track of current entry to free
            current = current->next; // move to next entry before freeing current
            free(temp->key); // free the key string
            free(temp);  // free the entry struct 
        }
    }
    
    printf("\n=== Key Concepts ===\n");
    printf("- Hash function converts key to index\n");
    printf("- Collisions handled with linked lists\n");
    printf("- Fast lookup: O(1) average case\n");
    printf("- Like a dictionary: key → value\n");
    
    return 0;
}
