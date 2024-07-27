#ifndef SLL_SLL
#define SLL_SLL

#include <stdlib.h>

struct SLL_Node {
    void* data; struct SLL_Node* next;
};
typedef struct SLL_Node SLL_Node;

///// Nodes /////
void SLL_NodeWriteData(SLL_Node* node, void* data, size_t sizeof_data);
SLL_Node* SLL_NodeCreate();

///// Linked Lists /////
SLL_Node* SLL_ListGetIndex(SLL_Node* head, int index);
SLL_Node* SLL_ListGetLast(SLL_Node* any_node);
int SLL_ListGetLength(SLL_Node* head);
SLL_Node* SLL_ListAppend(SLL_Node* any_node, SLL_Node* appendee);
SLL_Node* SLL_ListCut(SLL_Node* head, SLL_Node* any_node);
void SLL_FreeNode(SLL_Node* node);
void SLL_ListFree(SLL_Node* head);

#endif