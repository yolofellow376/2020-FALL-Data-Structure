#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "stack.h"
#define Max 100
int size1=0,size2=0;
int right[100];
int left[100];
void match(STACK *ptr, char *array, int line, STACK *occ)//比對 
{
	int i=0, j=0;

	while (!((array[i]=='\n')||(array[i]=='\0')))//逐一檢驗字元 
	{
		//printf("array[%d]: %c\n",i, array[i]);
		if (array[i]=='{')//先檢查是否為括號 
		{
      right[size2]=line;
      
			pushStack(ptr, &right[size2]);
      size2++;
		
    }	
		else if ('}' == array[i])//如果是右括號 
		{
			if (ptr->count==0) //判斷stack有沒有東西,若沒有 
			{
          left[size1]=line;
          //printf("found:%d\n",temp[size]);
          
          pushStack(occ,&left[size1]);
          size1++;
     
			}
			else//若有東西 
			{
 						popStack(ptr);//抵銷掉 
          
			}
		}	
		else //如果位元不是括號,就直接下一個字元 
		{
		}
    i++;
	}

}
void print(STACK *stack)
{
  int line;
  while(stack->top!=NULL)
  {
    //printf("checkp");
    line=*((int*)stack->top->dataptr);
    printf("%d\n",line);
    stack->top=stack->top->link;
  }
}
int main()
{
	char array[100] ;
  FILE *fp;
  fp=fopen("1.txt","r");
	STACK* ptr=creatStack();
  STACK* occ=creatStack();
  int line=0;
  while(fgets(array, sizeof(array), fp) != NULL) 
  {
        line++;
        //printf("%d, %s\n",line,array);
        match(ptr, array,line,occ);
  }
  
  void* p=stackTop(occ);
  printf("沒配對的左括號位置\n");
  print(ptr);
  printf("沒配對的右括號位置\n");
  print(occ);
  if ((occ->count==0)&&(ptr->count==0))
  {
    printf("valid\n");

  }
  else{ printf("invalid\n");}
  
  destroyStack(ptr);
  destroyStack(occ);
  return 0 ;

}
