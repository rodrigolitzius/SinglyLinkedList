#include <stdlib.h>
#include "string.h"
#include <stdbool.h>
#include <assert.h>

#include "sll.h"

///// Nodes /////
void SLL_NodeSetData(SLL_Node* node, void* data) {
    node->data = data;
}

void SLL_NodeSetNext(SLL_Node* node, SLL_Node* next_node) {
    node->next = next_node;
}

void SLL_NodeWriteData(SLL_Node* node, void* data, size_t sizeof_data) {
    assert(node != NULL);

    if (node->data) {
        free(node->data);
    }

    SLL_NodeSetData(node, malloc(sizeof_data));
    memcpy(node->data, data, sizeof_data);
}

SLL_Node* SLL_NodeCreate() {
    SLL_Node* node = malloc(sizeof(SLL_Node));

    SLL_NodeSetData(node, NULL);
    SLL_NodeSetNext(node, NULL);

    return node;
}

/////////////// Linked Lists ///////////////

///// Get /////
SLL_Node* SLL_ListGetIndex(SLL_Node* head, int index) {
    assert(head != NULL);

    SLL_Node* temp_node = head;

    // Handles negative indices
    if (index < 0) { 
        int list_length = SLL_ListGetLength(head);

        index = list_length + index;
        if (index < 0) {
            index = 0;
        }
    }

    int i = 0;
    while (true) {
        if (i == index) {
            return temp_node;
        }

        if (!temp_node->next) {
            return temp_node;
        }

        temp_node = temp_node->next;
        i += 1;
    }
}

SLL_Node* SLL_ListGetLast(SLL_Node* any_node) {
    assert(any_node != NULL);

    SLL_Node* temp_node = any_node;

    while (temp_node->next) {
        temp_node = temp_node->next;
    }

    return temp_node;
}

int SLL_ListGetLength(SLL_Node* head) {
    assert(head != NULL);

    int length = 1;

    SLL_Node* temp_node = head;
    while (temp_node->next) {
        temp_node = temp_node->next;
        length += 1;
    }

    return length;
}

///// Add /////
SLL_Node* SLL_ListAppend(SLL_Node* any_node, SLL_Node* appendee) {
    assert(any_node != NULL);

    SLL_Node* last_node = SLL_ListGetLast(any_node);
    SLL_NodeSetNext(last_node, appendee);

    return appendee;
}

///// Remove /////
SLL_Node* SLL_ListCut(SLL_Node* head, SLL_Node* any_node) {
    assert(any_node != NULL);

    SLL_Node* next_node = any_node->next;

    // If you want to remove the head for some reason...
    if (head == any_node) {
        SLL_FreeNode(head);
        return next_node;
    }

    // Find the node before any_node
    SLL_Node* previous_node = head;
    while (previous_node->next != any_node) {
        previous_node = previous_node->next;
    }

    SLL_NodeSetNext(previous_node, next_node);
    
    SLL_FreeNode(any_node);

    return next_node;
}

///// Free /////
void SLL_FreeNode(SLL_Node* node) {
    assert(node != NULL);

    if (node->data) {
        free(node->data);
    }

    free(node);
}

void SLL_ListFree(SLL_Node* head) {
    SLL_Node* temp_node = head;

    while (temp_node) {
        SLL_Node* next_node = temp_node->next;
        SLL_FreeNode(temp_node);
        temp_node = next_node;
    }
}