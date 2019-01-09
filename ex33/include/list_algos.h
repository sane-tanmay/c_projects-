#ifndef list_algos_h
#define list_algos_h

#include "list.h"


typedef int (*List_compare)(const void *a, const void *b);

List * bubble_sort(List *list);


void  List_display(List *list);
List *List_merge_sort(List * list);

inline void ListNode_swap(ListNode *a, ListNode *b)
{
// Before  B, A	
void *temp=a->value; // ptr1
a->value=b->value; 
b->value=temp;	//After A, B 
}



	
	
#endif 
