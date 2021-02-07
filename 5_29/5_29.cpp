#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string.h>
using namespace std;


typedef struct polynomial
{
    int coeff;
    int exponent;
    polynomial *next;
}POLY;


void display(POLY* t)
{
	POLY *temp = t ;

	while(temp!=NULL)
	{
		cout<<temp->coeff<<" "<<temp->exponent<<endl;
		temp=temp->next ;
	}
}
void add(POLY* p1,POLY* p2)
{
	POLY* temp;
	POLY* result=NULL;
	POLY* temp1, * temp2 ;
	temp1 =p1 ;
	temp2 =p2 ;
    
	while (((temp1!=NULL)||(temp2!=NULL)))
	{
		
		//cout<<(temp1!=NULL)<<" "<<(temp2!=NULL)<<endl;
		//cout<<temp1->coeff<<" "<<temp1->exponent<<endl;
		if (result==NULL)
		{
			result=(POLY*)malloc(sizeof(POLY));
			temp=result ;
		
		}
		else
		{
			temp->next=(POLY*)malloc(sizeof(POLY));
			temp=temp->next;
		}
		if(temp1==NULL)
		{
			temp->coeff=temp2->coeff;
			temp->exponent=temp2->exponent;
			temp2=temp2->next;
			continue; 
		}
		if(temp2==NULL)
		{
			
			temp->coeff=temp1->coeff;
			temp->exponent=temp1->exponent;
			temp1=temp1->next;
			//cout<<"chel";
			continue; 
		}
		if ( temp1->exponent<temp2->exponent)
		{
			
			temp->coeff=temp2->coeff;
			temp->exponent=temp2->exponent;
			temp2=temp2->next;
		}
		else if (temp1->exponent>temp2->exponent )
		{
			temp->coeff=temp1->coeff ;
			temp->exponent=temp1->exponent ;
			temp1=temp1->next ;
			
		}
		else if (temp1->exponent == temp2->exponent )
		{
			temp->coeff=temp1->coeff+temp2->coeff;
			temp->exponent=temp1->exponent ;
			//if (temp1->next!=NULL)
			   //cout<<temp1->next->exponent<<" "<<temp1->exponent<<endl;
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	//cout<<(temp1!=NULL);
	//cout<<((temp1!=NULL)||(temp2!=NULL));
	display(result);	
}
void sub(POLY* p1,POLY* p2)
{
	POLY* temp;
	POLY* result=NULL;
	POLY* temp1, * temp2 ;
	temp1 =p1 ;
	temp2 =p2 ;

	while (((temp1!=NULL)||(temp2!=NULL)))
	{
		
		//cout<<(temp1!=NULL)<<" "<<(temp2!=NULL)<<endl;
		//cout<<temp1->coeff<<" "<<temp1->exponent<<endl;
		if (result==NULL)
		{
			result=(POLY*)malloc(sizeof(POLY));
			temp=result ;
		
		}
		else
		{
			temp->next=(POLY*)malloc(sizeof(POLY));
			temp=temp->next;
		}
		if(temp1==NULL)
		{
			temp->coeff=temp2->coeff;
			temp->exponent=temp2->exponent;
			temp2=temp2->next;
			continue; 
		}
		if(temp2==NULL)
		{
			
			temp->coeff=temp1->coeff;
			temp->exponent=temp1->exponent;
			temp1=temp1->next;
			//cout<<"chel";
			continue; 
		}
		if (temp1->exponent<temp2->exponent)
		{
			
			temp->coeff=-(temp2->coeff);
			temp->exponent=temp2->exponent;
			temp2=temp2->next;
		}
		else if (temp1->exponent>temp2->exponent )
		{
			temp->coeff=temp1->coeff ;
			temp->exponent=temp1->exponent ;
			temp1=temp1->next ;
			
		}
		else if (temp1->exponent == temp2->exponent )
		{
			
			temp->coeff=temp1->coeff-temp2->coeff;
			temp->exponent=temp1->exponent ;
			//if (temp1->next!=NULL)
			   //cout<<temp1->next->exponent<<" "<<temp1->exponent<<endl;
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	//cout<<(temp1!=NULL);
	//cout<<((temp1!=NULL)||(temp2!=NULL));
	display(result);	
}
void append (POLY *t,float coef,int expo)
{
	POLY *temp=t;
	if (temp==NULL)
	{
		//cout<<"check";
		temp=(POLY*)malloc(sizeof(POLY));
		t=temp;
	}
	else
	{
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=(POLY*)malloc(sizeof(POLY));
		temp=temp->next;
	}
	temp->coeff=coef;
	temp->exponent=expo;
	temp->next=NULL;
}
int main()

{
    char buffer[20];
	FILE *fp;
	int i=0;
	int count=1;
	POLY *p1;
	p1=(POLY*)malloc(sizeof(POLY));
	POLY *p2;
	p2=(POLY*)malloc(sizeof(POLY));
	fp=fopen("text.txt","r");
   	while (fgets(buffer, sizeof(buffer), fp)) //readfile
	{	
		//cout<<i;
		if(buffer[0]=='p')
		{			
			i++;
			count--;
			continue;	
		}
		char * pch;
  		pch = strtok (buffer," ");
  		int j=0,coe,expo;
  		while (pch != NULL)
  		{
    		//cout<<pch<<endl;
			if(j==0)
    		{
				coe=atoi(pch);
    			j++;
    		}
			else
    			expo=atoi(pch);
			pch = strtok (NULL, " ,.-");
  		}
  		//cout<<coe<<" "<<expo;
		if (i==1)
		{
			if(count==0)
			{
				p1->coeff=coe;
				p1->exponent=expo;
        p1->next=NULL;
				count++;
				continue;
			}
			append(p1,coe,expo);
		}
		else if (i==2)
		{
			if(count==0)
			{
	
				p2->coeff=coe;
				p2->exponent=expo;
        p2->next=NULL;
				count++;
				continue;
			}
			append(p2,coe,expo);
		}	
		//cout<<buffer;
	}
	display(p1);
	cout<<endl;
	display(p2);
	cout<<"select add or substract:(1)add(2)subtract:";
	int choose=0;
	cin>>choose;
	if(choose==1)
	{
		//cout<<endl;
		add(p1,p2);
	}
	else if(choose==2)
	{
			//cout<<endl;
		sub(p1,p2);
	}
    
    

    return 0;

}
