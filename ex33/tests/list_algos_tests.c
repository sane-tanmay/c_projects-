#include "minunit.h"
#include "list_algos.h"
#include <assert.h> 
#include <string.h> 

#define NUM_VALUES  5

//char *values []= {"XXXX", "1234", "abcd", "xjvef", "NDSS"}; // These are not in order

char *values []= {"F", "B", "C", "D", "E"}; // These are  in order
char *values_in_order []= {"A", "B", "C", "D", "E"}; // These are in order as per the check expected oredre is A, B , C
char *values_out_order []= {"F", "B", "C", "D", "E"}; //This would cause an error,as per the check  expected order is A, B, C not F, A, B , strcmp compares the first character to begin with 

//char *values=(char**)values_out_order;

List *create_words()
{
int i=0; 
List *words=List_create(); 
for(i=0; i < NUM_VALUES; ++i)
{
List_push(words, values[i]);
}
return words;
}

char*test_create_words()
{
	List * words=create_words(); 
	mu_assert(List_first(words)==values[0],"The first value didnt match ");
	mu_assert(((words->first)->next)->value==values[1],"The second value didnt match ");
	mu_assert((((words->last)->prev)->prev)->value==values[2],"The third value didnt match ");
	mu_assert(((words->last)->prev)->value==values[3],"The fourth value didnt match ");
	mu_assert(List_last(words)==values[4],"The last i.e 5 value didnt match ");
	
return NULL;}

int is_sorted(List *words)
{
	LIST_FOREACH(words, first, next, cur)
	{
		if(cur->next && strcmp(cur->value,cur->next->value)>0)
		{
		printf("strcmp = %d,The Values cur->value=%s, cur->next->value=%s ",strcmp(cur->value,cur->next->value),(char*)cur->value, (char *)cur->next->value);
		debug("%s %s", (char*)cur->value, (char *)cur->next->value); // Assumption do only big to small is in order else out of order
		return 0; 
		}
	}
return 1;
}

char *test_is_sorted ()
{
	List * words=create_words(); 
	mu_assert((is_sorted(words)==0),"Is sorted returned 0, should have returned 1");
	
return NULL; 
}

char *test_bubble_sort()
{
List *words=create_words();	
//should work on a list that needs sorting 
int rc=List_bubble_sort(words);
mu_assert(rc==0, "Bubble Sort Failed ");
mu_assert(is_sorted(words), "Words are not sorted after bubble sort"); // this is a test to check if the 
//should work on a list that is sorted
rc=List_bubble_sort(words);
mu_assert(rc==0, "Bubble Sort of already sorted failed ");
mu_assert(is_sorted(words), "Words should be sort if already bubble sorted"); // this is a test to check if the sorting sorts a sorted list 
List_destroy(words);

//should work on a list that is empty
// create an empty list
words=List_create(words);
rc=List_bubble_sort(words);
mu_assert(rc==0, "Bubble Sort of empty list failed ");
mu_assert(is_sorted(words), "Words should be already sorted if empty"); // this is a test to check if the 
List_destroy(words);

return NULL;
}


char * test_ListNode_swap()
{
	List * words=create_words(); 
	ListNode_swap(words->first, words->first->next);
	mu_assert ((words->first->value=="B" && (words->first)->next->value=="F"), "Swap noes isnt as expected"); // this is a test to check if the 
return NULL; 
}
char *test_merge_sort()
{
    List *words = create_words();

    // should work on a list that needs sorting
    List *res = List_merge_sort(words);
    mu_assert(is_sorted(res), "Words are not sorted after merge sort.");
  
    printf("\n\n**Test function-");
    List_display(res);
  
    List *res2 = List_merge_sort(res);
    mu_assert(is_sorted(res),
            "Should still be sorted after merge sort.");
    
    printf("**Test function2-");
    List_display(res2);
    
    List_destroy(res2);
    List_destroy(res);

    List_destroy(words);
    return NULL;
}


char * all_tests()
{
mu_suite_start(); 
//mu_run_test(test_create_words);
//mu_run_test(test_is_sorted);
//mu_run_test(test_ListNode_swap);	
//mu_run_test(test_bubble_sort);	
mu_run_test(test_merge_sort);	
	
}

RUN_TESTS(all_tests); 
