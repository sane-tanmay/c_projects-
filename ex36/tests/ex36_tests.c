#include "minunit.h"
#include "dbg.h"
#include "bstrlib.h"

static int a; 

char *test_bfromcstr()
{
int p=fun();
char array[7]="Single";
char * array_ptr=array;

printf("Tests=%d\n", p); 
//expected value, if not then
mu_assert(p==5,"The array isnt initialized");



bstring b = bfromcstr("Teststs");

if(!b) return 7;

printf("slen=%d \t", b->slen);
printf("mlen=%d", b->mlen);

printf("%s\n ",b->data );
int i=0;
for(i=0; i<10;i++)
{
if(*(b->data+i)!='/0')	
{printf("%d%c=%x\n",i, *(b->data+i),*(b->data+i));}
else
{
printf("This is a bstring so null characters");
}

mu_assert(b!=NULL,"The array isnt initialized");
mu_assert(b->slen==7,"The slen isnt initialized");

}







return NULL; 

}

char * all_tests()
{
mu_suite_start();
mu_run_test(test_bfromcstr);

}

RUN_TESTS(all_tests);




