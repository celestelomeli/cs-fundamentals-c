// doubly_linked.c - Doubly linked list can go forward and backward

#include <stdio.h>
#include <stdlib.h>

// Node with two pointers (next and prev)
struct Node {
    int data;
    struct Node *next;  // Forward pointer
    struct Node *prev;  // Backward pointer
};

int main(void) {
    printf("=== Doubly Linked List ===\n\n");
    
    // Create three nodes
    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    
    first->data = 10;
    second->data = 20;
    third->data = 30;
    
    // Link forward like singly linked list
    first->next = second;
    second->next = third;
    third->next = NULL;
    
    // Link backward 
    first->prev = NULL;
    second->prev = first;
    third->prev = second;
    
    printf("Created: NULL ← [10] ⇄ [20] ⇄ [30] → NULL\n\n");
    
    // Forward
    printf("Going FORWARD:\n   ");
    struct Node *current = first;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
    
    // Backward 
    printf("Going BACKWARD:\n   ");
    current = third;  // Start at the end
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;  // prev instead of next
    }
    printf("\n\n");
    
    // Free all nodes
    printf("Freeing nodes...\n");
    current = first;
    while (current != NULL) {
        struct Node *temp = current; //temp to keep track of current node to free
        current = current->next;
        free(temp);
    }
    
    return 0;
}
