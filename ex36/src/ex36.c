#include<stdlib.h>
#include<stdio.h>

#define F(MAX) for(int i=0;i<(MAX);i++) 


int fun(){ return 5;}


void copy(char to[], char from[])
{
int i=0; 
while((to[i]=from[i])!=NULL)	
	{++i;}

return;
	
}

int safecopy(int from_len, char *from, int to_len, char *to)
{
	int i=0; 
	//transfer happens for stings size apart form the null character
	//Aim is find the sting that hs the lowest size
	int max=from_len>to_len-1? to_len-1: from_len; 
	if(from_len<0 ||to_len<0)
	return -1; 
	
	F(max)
	{
		to[i]=from[i];
	}
	
	to[to_len-1]='\0';
	
	return 0;
}
