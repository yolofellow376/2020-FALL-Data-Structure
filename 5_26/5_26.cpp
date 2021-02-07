#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string.h>
using namespace std;

typedef struct scores
{
        int score;
        scores* next;
}Scores;
typedef struct node
{
        string name;
        node *next;
        scores *scores;
}Node;


void appendscore(Scores** head, int scores[], int length)
{

    for (int i=0; i<length; i++) 
	{
		
        Scores* score;
		score = (Scores*)malloc(sizeof(Scores));
        score->next = (*head);
		score->score = scores[length-i-1];
        (*head) = score;
    }

}

void appendstudent(Node** head, string name, int scores[], int length)
{

    Node* temp;
	temp=(Node*)malloc(sizeof(Node));
    Node *last;
	last=(*head);
	// display(head);
    temp->name=name;
	
    appendscore((&temp->scores),scores,length);
    // display(head);
    
    temp->next=NULL;
    if((*head)==NULL)
    {
        (*head)=temp;
        return;
    }
    // display(last);
    while (last->next!=NULL)
    {
        last=last->next;
    }
    //cout<<(last->next!=NULL);
    last->next=temp;
}
void ls(Scores *node)
{
	double total=0;
	int i=0;
    while (node != NULL)
    {
		cout<<" "<<node->score;
		total+=node->score;
        node = node->next;
        i++;
    }
    if (i==0)
    	cout<<setw(20)<<"    Average:(EMPTY) ";
    else
		cout<<setw(20)<<"    Average: "<<total/i;
}


void display(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->name;
        ls(node->scores);
        cout<<endl;
        node=node->next;
    }
}

int main()
{

    Node* head = NULL;
    string name;
    int data[4];
    char buffer[20];
	FILE *fp;
	fp=fopen("5_26_input.txt","r");
   	while (fgets(buffer, sizeof(buffer), fp)) //readfile
	{
		char *name;
		//cout<<strlen(buffer);
		name=new char[strlen(buffer)];
		name=buffer;
		name[strlen(buffer)-1]='\0';
		cout<<"input "<<name<<"'s score:";
		char score[20];
		cin.getline(score,20);
		
		//cout<<score;
		char * pch;
		char fortok[20];
		sprintf(fortok,"%s",score);
		int i;
  		pch = strtok (fortok," ");
  		while (pch != NULL)
  		{
  			i++;
    		pch = strtok (NULL, " ,.-");
  		}
  		int *scores;
  		scores=new int[i];
  		pch = strtok (score," ");
  		i=0;
		while (pch != NULL)
  		{
  			
  			scores[i]=atoi(pch);
    		pch = strtok (NULL, " ,.-");
    		i++;
  			
		}
		//cout<<i;
		appendstudent(&head,name,scores,i);
	}
    	
       
	 display(head);

    return 0;

}
