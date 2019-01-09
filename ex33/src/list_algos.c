#include <stdlib.h> 
#include "list_algos.h"
#include "dbg.h"


void  List_display(List *list)
{ int c=5;
	 if(List_count(list)>1  )
   {   printf ("The List now is -");
	   LIST_FOREACH(list,first,next,cur)
	   {
		   if(c)
		   {printf ("%s",(char*)cur->value);
	       --c; }
	   }
	   
	    printf ("\n");
    } 
}





/**********************************************************************
* Algo: Bubble Sort 
* Input : List
* Output: 0 is Success, 1 is Failed
/**********************************************************************/

int List_bubble_sort(List *list  )
{
   int sorted=1; 
   // 1 is the value for success, 0 for it is unsorted and 
   //needs sorting 
         
   if(List_count(list)<=1  )
   { return 0; // The list has only one element and has no need to be sorted
   }   
   //if(List_count(list)=0  )
   //{ return 0; // The list has no element and has no need to be sorted
   //}   
    do { sorted=1;
			// Parse whole array LIST_FOREACH(L,S,M,V)
			LIST_FOREACH(list,first,next,cur)
			{
				if(cur->next) //Next node from current is non zero
				{
				  if(strcmp(cur->value, cur->next->value)>0)  // strcmp-> checked confusion resolved always in accodance with the first, so <0 (p1<p2) => as expected, if >0 (p1>p2)
				  { // if true=> p1>p2 F>B, i.e F, B which is out of order, hence swap, if swap is needed => sorting is not over, the data structure is still unsorted => 
					  sorted =0;
					  ListNode_swap(cur, cur->next);
				 }	
				}
				
			}
		
		}
    while (sorted==0);
    
    return 0;
}

/**********************************************************************
* Algo: Merge Two Lists in Order
* Input : List Left, List right
* Output: Sorted List 
/**********************************************************************/
	 
List * List_merge(List *left, List *right)
{
List *result=List_create(); 
void *val=NULL; 

while ((List_count(left)>0) || (List_count(right)>0)) // when either of  the DS have  non zerro eles,nets
{
	if((List_count(left)>0) && (List_count(right)>0))
	{    /*Goal is tho pic the smallest-->*/
		if(strcmp(List_first(left), List_first(right))<=0) // p1=p2 or p1<p2
		{
			val=List_shift(left); //Remove from the top of list i.e from the first node onwards..p1<p2, p1 i.e left is smallest 
		}
		else   
		{
				
			val=List_shift(right); //Remove from the top of list i.e from the first node onwards  p1>p2 i.e right is smallest
		}
		
		List_push(result,val); // Resultant DS being pop ulated 
	}
	else if (List_count(left)>0) // The number of elee ments in the left DS is non zero
	   {
		val=List_shift(left);    //so po them from the array and fill these up
		List_push(result, val); // Resultant DS being populated
		}
	else if (List_count(right)>0) // No of elemnts in eight DS is non zero
	{
		val=List_shift(right);   //so po them from the array and fill these up
		List_push(result, val); // Resultant DS being populated
	}
	
}

return result;	
}

/**********************************************************************
* Algo: Merge Sort 
* Input : List
* Output: 0 is Success, 1 is Failed
/**********************************************************************/

List * List_merge_sort(List *list)
{
	 List* result;
	if(List_count(list)<=1){
		return list;}
	//Divide the list into two parts 
	List *left=List_create(); //make left list 
	List *right= List_create(); //make right list 
	int middle= List_count(list)/2; //get the centre point
	printf("****The Value of middle is %d\n", middle);
	List_display(list);
	
	LIST_FOREACH(list, first, next,cur)
	{
		if(middle>0)
		{
			//printf("If -The Value of middle is %d\n", middle);
			List_push(left,cur->value) ;
		}
		else
		{
			//printf("Else The Value of middle is %d\n", middle);
			List_push(right, cur->value);
		}
		
	middle--;
	}
	/* Thus our two lists are formed 
	 * Now to sort these two */
	 List *sorted_left=List_merge_sort(left);
	  List_display(left);
	 List *sorted_right=List_merge_sort(right);
	  List_display(right);
	 
  //Now to see if the old pointers got changed if they did then it meansn that 
  // The arrays got sorted, since this is a n resurive fubction it soesny make sense to have 
  // so musch strah in thebge hennxe we delete * /

if(sorted_left!=left)
 List_destroy(left); 

if(sorted_right!=right) 
List_destroy(right);

// Now to merge both of these two arrays in a sorted mannaer

result = List_merge(sorted_left, sorted_right); 
printf("##### This is after merging the left sorted and right sorted");
List_display(result	);
return result;
}    
	 
	 
/*********************************************************************/


/*******************************************************************/

/* Things I Learnt- Checking for specifics like next node not null, 
 * compare then swap, else not, 
 * till when to continue swapping=> Till the time, until which atleast one whole pass goes sorted for each comparison.
 * /




//int List_bubble_sort(List *list  )
//{
	//int sorted =1; // Failed 
    //int count= list->count;
    //ListNode *temp_node; 
    //ListNode *curr= list->first; // Initialize current node 
    //ListNode *next_t= (list->first)->next; //Initilaize next node 
   
 
    //Loop: 
    ////Compare
    //printf("Comparing curr->value= %s next_t->value=%s\n",curr->value, next_t->value); 
    //if((strcmp(curr->value, next_t->value)<0)) // In order A, B, C
    //{
	 //// In order	
	 //printf("Goig  to Inorde\n"); 
	//} 
	//else
	//{   printf("Going to swapping\n"); 
		////swap 
		//temp_node=curr; 
		//curr=next_t;
		//next_t=temp_node;
		//printf("After the swapping\n"); 

		//printf("%s, %s \n",curr->value, next_t->value ); 
				
		
	//}
   ////update next node & current node 
    
    
    //if(next_t->next!=NULL)
    //{     curr=next_t;
		  //next_t=next_t->next;
		   //printf("** next_t->net->value=%s\n",curr->value, next_t->next->value); 
		   //printf("Going  to Loop\n"); 
        //goto Loop; //Loop that goes n-1 (j )times // there should ne another loop that goes n-1-i times (j)
    //}
    //else
    //{   printf("Going to New\n");
		//goto NEW;
		
		////first parsing of the DL completed 
	//}
    
      //NEW: 
	////if list is not sorted 
	////sort 
	////else 
	////Don't sort
	//// if success 
	//sorted=1;
	//return sorted;
//}



/*
procedure bubbleSort( A : list of sortable items )
    n = length(A)
    repeat
        swapped = false
        for i = 1 to n-1 inclusive do
           // if this pair is out of order 
            if A[i-1] > A[i] then
                // swap them and remember something changed 
                swap( A[i-1], A[i] )
                swapped = true
            end if
        end for
    until not swapped
end procedure

*/
