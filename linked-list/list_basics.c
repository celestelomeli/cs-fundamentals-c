#include <stdio.h>
#include <stdlib.h>

// A node is a struct that points to the next node
struct Node {
    int data;
    struct Node *next;  // Pointer to next node
};

int main(void) {
    printf("=== Linked List ===\n\n");
    
    // Create first node
    printf("1. Creating first node with data = 10\n");
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;  // No next node yet
    printf("   [10] -> NULL\n\n");
    
    // Create second node and link it
    printf("2. Creating second node with data = 20\n");
    struct Node *second = malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;
    
    head->next = second;  // Link first to second
    printf("   [10] -> [20] -> NULL\n\n");
    
    // Create third node and link it
    printf("3. Creating third node with data = 30\n");
    struct Node *third = malloc(sizeof(struct Node));
    third->data = 30;
    third->next = NULL;
    
    second->next = third;  // Link second to third
    printf("   [10] -> [20] -> [30] -> NULL\n\n");
    
    // Print the entire list by following pointers
    printf("4. Printing list by following next pointers:\n   ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;  // Move to next node
    }
    printf("\n\n");
    
    // Free all nodes
    printf("5. Freeing all nodes...\n");
    current = head;
    while (current != NULL) {
        struct Node *temp = current;  // Remember node to free
        current = current->next;      // Move forward first
        free(temp);                   // Free the old node
        printf("   Freed node\n");
    }
    
    printf("\n=== Key Takeaways ===\n");
    printf("- Each node has data + pointer to next node\n");
    printf("- Last node points to NULL\n");
    printf("- Follow pointers to traverse the list\n");
    printf("- Free each node one by one\n");
    
    return 0;
}
