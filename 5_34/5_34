#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring> 
using namespace std;
typedef struct node
{
	string code;
	string name;
	int invested;
	int shares_held;
	float current_price;
	node* next;
}Node;
void push(Node** n, int code,string name,int invested,int shares_held,	int current_price)
{
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->code=code;
	temp->name=name;
	temp->invested=invested;
	temp->shares_held=shares_held;
	temp->current_price=current_price;
	//cout<<check;
	temp->next = (*n);
	(*n) = temp;
}
struct List
{
    Node *head_price;
    Node *head_invested;
    Node *rear_price;
    Node *rear_invested;
    int num;
};
List* createList(void)
{
    List *t;

    t=(List*)malloc(sizeof(List));
    t->head_price=NULL;
    t->head_invested=NULL;
    t->rear_price=NULL;
    t->rear_invested=NULL;
    t->num=0;
    return t;
}
int length(Node *n)
{
	int length=0;
	while (n!=NULL)
	{
		length++;
		n=n->next;
	}
	return length;
}
void display(Node *n)
{
	while (n!=NULL)
	{
		cout<<n->code<<" "<<n->name<<" "<<n->invested<<" "<<n->shares_held<<" "<<n->current_price;
		n=n->next;
	}
	cout<<endl;
}
void search_1900(List* pList,Node **pPre,Node **pLoc,Node *node,Node **pPre2)
{
    //1900
    *pPre=NULL;
    *pPre2=NULL;
    *pLoc=pList->head_price;
    if(pList->num==0)
        return;
    if(node->price>(pList->rear_price)->price)
    {
        *pPre=pList->rear_price;
        pLoc=NULL;

    }
    while(node->price>((*pLoc)->price))
    {
        *pPre=*pLoc;
        *pLoc=(*pLoc)->F_1900;
    }
    //2000

    *pLoc=pList->head_2000;
    if(pList->num==0)
        return;
    if(node->popu_2000>(pList->rear_2000)->popu_2000)
    {
        *pPre2=pList->rear_2000;
        pLoc=NULL;

    }
    while(node->popu_2000>((*pLoc)->popu_2000))
    {
        *pPre=*pLoc;
        *pLoc=(*pLoc)->F_2000;
    }
}

void _insert_1900(List *pList,Node *pPre,Node *pNew,Node *pPre2)
{
    if(pPre==NULL)
    {   //1900
        pNew->B_1900=NULL;
        pNew->F_1900=pList->head_1900;
        pList->head_1900=pNew;
        if(pList->num==0)
            pList->rear_1900=pNew;
        else
            (pNew->F_1900)->B_1900=pNew;
    }
    else
    {
        //1900
        pNew->F_1900=pPre->F_1900;
        pPre->F_1900=pNew;

        pNew->B_1900=pPre;
        if(pNew->F_1900==NULL)
            pList->rear_1900=pNew;
    }
    if(pPre!=NULL&&(pPre->F_1900!=NULL))
        (pNew->F_1900)->B_1900=pNew;
    //2000
    if(pPre2==NULL)
    {
        pNew->B_2000=NULL;
        pNew->F_2000=pList->head_2000;
        pList->head_2000=pNew;
        if(pList->num==0)
            pList->rear_2000=pNew;
        else
            (pNew->F_2000)->B_2000=pNew;
    }
    else
    {

        pNew->F_2000=pPre2->F_2000;
        pPre2->F_2000=pNew;

        pNew->B_2000=pPre2;
        if(pNew->F_2000==NULL)
            pList->rear_2000=pNew;
    }
    if(pPre2!=NULL&&(pPre2->F_2000!=NULL))
        (pNew->F_2000)->B_2000=pNew;
    ++(pList->num);
}
void addNode(List *pList,Node *node)
{
    Node *pPre;
    Node *pPre2;
    Node *pLoc;
    //new node
    Node *pNew;
    pNew=new Node;

    pNew=node;

    search_1900(pList,&pPre,&pLoc,node,&pPre2);
    _insert_1900(pList,pPre,pNew,pPre2);
}
int main()
{
	Node *data;
	FILE *fp;
	fp=fopen("5_34.txt","r");
	char buffer[100];
	int code;
	string name;
	int invested;
	int shares_held;
	int current_price;
	List *all;
	all=createList();
	while (fgets(buffer, sizeof(buffer), fp)) //readfile
	{	
	
		char * pch;
		cout<<buffer;
  		pch = strtok (buffer," ");
  		int j=0;
  		Node *temp;
  		temp=(Node*)malloc(sizeof(Node));
  		temp->next=NULL;
  		while (pch != NULL)
  		{
    		//cout<<pch<<endl;
			if(j==0)
			{
				temp->code=pch;
			}
			else if(j==1)
			{
				temp->name=pch;
			}
			else if (j==2)
			{
				temp->invested=atoi(pch);	
			}
			else if (j==3)
			{
				temp->shares_held=atoi(pch);
			}
			else if(j==4)
			{
				temp->current_price=atof(pch);
			}
			pch = strtok (NULL, " ,.-");
			
			j++;
		} 
		addNode(all,&temp);
		//cout<<temp->code<<" "<<temp->name<<" "<<temp->invested;
		//display(temp);	
	
	}
	while(1)
	{
		char c;
		cout<<"(1)display code forward\n(2)display code backward\n(3)display price forward\n(4)display price backward\n";
		cin>>c;
	}
	  
	
	return 0;
}
 
