#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

#define TYPE int

void print_ll(SLL_Node* node) {
    SLL_Node* temp_node = node;

    int i = 0;
    while (temp_node) {
        printf("Node Address: %p\n", (void*) temp_node);

        printf("Node data (TYPE): ");
        if (temp_node->data) { printf("%d\n", *((TYPE*) temp_node->data)); }
        else { printf("NULL\n"); }

        printf("Node next: %p\n", (void*) temp_node->next);

        printf("==============================\n\n");

        temp_node = temp_node->next;
        i++;
    }
}

int main() {
    SLL_Node* head = SLL_NodeCreate();
    SLL_NodeWriteData(SLL_ListGetLast(head), &(int){1}, sizeof(int));

    SLL_ListAppend(head, SLL_NodeCreate());
    SLL_NodeWriteData(SLL_ListGetLast(head), &(int){10}, sizeof(int));

    SLL_ListAppend(head, SLL_NodeCreate());
    SLL_NodeWriteData(SLL_ListGetLast(head), &(int){100}, sizeof(int));

    SLL_ListAppend(head, SLL_NodeCreate());
    SLL_NodeWriteData(SLL_ListGetLast(head), &(int){1000}, sizeof(int));

    SLL_ListAppend(head, SLL_NodeCreate());
    SLL_NodeWriteData(SLL_ListGetLast(head), &(int){10000}, sizeof(int));
    
    print_ll(head);
    SLL_ListFree(head);

    return EXIT_SUCCESS;
}