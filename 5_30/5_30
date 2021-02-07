#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring> 
using namespace std;
typedef struct node
{
	int data;
	node* next;
}Node;
void push(Node** n, int data)
{
	Node* temp = (Node*) malloc(sizeof(Node));
	temp->data = data;
	//cout<<check;
	temp->next = (*n);
	(*n) = temp;
}
void swap(Node** a, Node** b )
{
	Node* t = (*a);
	(*a) = (*b);
	//cout<<a<<b;
	(*b) = t;
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
}1
void display(Node *n)
{
	while (n!=NULL)
	{
		cout<<n->data;
		n=n->next;
	}
	cout<<endl;
}
Node* addifsamelength(int* carry,Node* n1, Node* n2)
{
	if (n1 == NULL)
		return NULL;
	Node* results = (Node *)malloc(sizeof(Node));
	int temp;
	
	//display(result);
	results->next = addifsamelength(carry,n1->next, n2->next);
	//display(result);
	temp= (n1->data)+(n2->data)+(*carry);
	(*carry)= temp/10;
	temp= temp% 10;
	results->data=temp;
	return results;
}
void addcarry(Node** results,Node* n1, Node* current, int* carry)
{
	int temp;
	if (n1!=current)
	{
		//display(results);
		addcarry(results,n1->next, current, carry);
		//display(results);
		temp=(n1->data)+(*carry);
		(*carry)=temp/10;
		temp=temp%10;
		push(results, temp);
	}

}

void add(Node** result, Node* n1, Node* n2)
{
	Node *current;


	int s1,s2,carry = 0; 
	s1=length(n1);
	s2 =length(n2);
	if (s1==s2)
	{
		*result = addifsamelength(&carry,n1, n2);
 		//display(result);
	 }
	else
	{
		int xg;
		xg=abs(s1-s2);
		if (s1 < s2)
		{
			//display(n1);
			swap(&n1, &n2);
			//display(n1);
		}
		for (current=n1;xg--;current=current->next);
		{
			*result =  addifsamelength(&carry,current, n2);
			//display(result);
		}
		addcarry(result,n1, current, &carry);
	}
	if (carry==1)
		push(result,carry);
}
int main()
{
	Node *n1=NULL, *n2=NULL, *result=NULL;
	string s1,s2;
	stringstream stoi;
	cin>>s1>>s2;
	//cout<<s1<<s2;
	for(int i=0;i<s1.size();i++)
    {
        int t;
        stoi<<s1[i];
        stoi>>t;
        //cout<<t;
        push(&n1, t);
        stoi.clear();
    }
    for(int i=0;i<s2.size();i++)
    {
        int t;
        stoi<<s2[i];
        stoi>>t;
        //cout<<t;
        push(&n2, t);
        stoi.clear();
    }
    //display(n1);
    //display(n2);
    add(&result,n1,n2);
    display(result);

	return 0;
}
 
