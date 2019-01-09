#ifndef _DArray_h
#define _DArray_h 
#include <stdlib.h> 
#include <assert.h>
#include "dbg.h"
typedef struct DArray
{

int end; 
int max; 
size_t element_size ;
size_t expand_rate; 
void **contents;
} DArray;


DArray * DArray_create(size_t element_size, size_t initial_max);
void DArray_destroy(DArray *array); 
void DArray_clear(DArray *array);
int DArray_expand(DArray *array) ; 
int DArray_contract(DArray *array) ; 
int DArray_push(DArray *array, void *el);
void *DArray_pop(DArray *array); // Returns a pointer to the ELEMENT BEIBG POPED
void * DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end-1] )
#define DArray_first(A) ((A)->contents[0] )
#define DArray_end(A) ((A)->end) 
#define DArray_count (A) DArray_end (A) // end is an int that gets increamented 
#define DArray_max(A) ((A)->max) 
#define DEFAULT_EXPAND_RATE 1 

static inline void DArray_set(DArray *array, int i, void *el)
{
check(i< array->max, "Darray attempt to set contents at index beyond max index");
if(i>array->end) // Array Index provided is beyond the existing end of the aray
array->end=i; 

//Anyways 
array->contents[i]=el;
error: 
return;
}

//Get contents at the ith position
static inline void * DArray_get(DArray *array, int i)
{
check(i<array->max, "Darray attempt to get contents at index beyond max index"); 
return array->contents[i]; 

error:
return NULL;
}


static inline void *DArray_remove(DArray *array, int i)
{
void *el= array->contents[i];
array->contents[i]=NULL; 
return el; 
	
}

static inline void *DArray_new(DArray *array)
{
check(array->element_size>0, "Can't use DArray_new on 0 size darrays");
return calloc(1,array->element_size);;

error:
return NULL;
}

#define DArray_free(E) free((E))
#endif




