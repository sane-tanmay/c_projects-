#ifndef lcthw_list_h
#define lcthw_list_h
#include <stdlib.h> 





struct ListNode; 
typedef struct ListNode
{
	struct ListNode *next; 
	struct ListNode *prev; 
	void *value; 
} ListNode; 


typedef struct List 
{
int count; 
ListNode* first; 
ListNode* last;	
}List; 

List *List_create(); 
void List_destroy (List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);

#define List_count(A) ((A)->count)

/*Add updated macros */
//#define List_first(A) ((A)->first->value)
#define List_first(A) ((A)->first !=NULL? (A)->first->value: NULL)

// This is one way, wherein we are not checking for the pointer non zero values.
// Honestly this macro is mis leading, we are needing to show the value of that pointer by first 

/*Add updated macros */
//#define List_last(A)  (A->last->value)



void List_push(List * list, void *value);
void *List_pop(List * list);
#define List_last(A) ((A)->last !=NULL? (A)->last->value: NULL)
void List_unshift(List *list, void *value);
void *List_shift (List *list); 
/*To remove a node */
void * List_remove (List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                                   ListNode *V = NULL;\
for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif



