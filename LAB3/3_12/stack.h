#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
	void * dataptr;
	struct node *link;
}STACK_NODE;

typedef struct
{
	int count;
	STACK_NODE* top;
}STACK;

STACK* creatStack(void)
{
	STACK* stack;
	stack=(STACK*)malloc(sizeof(STACK));
	if(stack)
	{
		stack->count=0;
		stack->top=NULL;
	}
	return stack;
}
bool pushStack(STACK *stack,void *dataInPtr)
{
	STACK_NODE *newptr;
	newptr=(STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!newptr)
		return false;
	newptr->dataptr=dataInPtr;
		
	newptr->link=stack->top;
	stack->top=newptr;
		
	(stack->count)++;
	return true;
}
void* popStack(STACK *stack)
{
	void *dataOutPtr;
	STACK_NODE *temp;
	
	if(stack->count==0)
		dataOutPtr=NULL;
	else
	{
		temp=stack->top;
		dataOutPtr=stack->top->dataptr;
		stack->top=stack->top->link;
		free(temp);
		(stack->count)--;
	} 
	return dataOutPtr;
}
void * stackTop(STACK *stack)
{
	if(stack->count==0)
		return NULL;
	else
		return stack->top->dataptr;
}

bool emptyStack(STACK *stack)
{
	return(stack->count==0);
}
bool fullStack(STACK *stack)
{
	STACK_NODE *temp;
	
	if((temp=(STACK_NODE*)malloc(sizeof(*(stack->top)))))
	{
		free(temp);
		return false;
	}
	
	return true;
		
}
int stackCount(STACK* stack)
{
	return stack->count;
}
STACK* destroyStack(STACK *stack)
{
	STACK_NODE *temp;
	if(stack)
	{
		while(stack->top !=NULL)
		{
			free(stack->top->dataptr);
			
			temp=stack->top;
			stack->top=stack->top->link;
			free(temp);
		}
		
		free(stack);
	}
	return NULL;
}


