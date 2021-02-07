#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string.h>
#include <list>
using namespace std; 
  
struct NODE 
{ 
   	NODE* left=NULL;
	NODE* right=NULL; 
    int data; 
    bool is_left_thr=false;   
    bool is_right_thr=false; 
}; 
 
NODE* nextone(NODE *root) 
{ 
    if (root->is_right_thr==true) 
    {
		//cout<<root->data<<endl;	
	   	return root->right; 
  	}
   
    root=root->right; 
    while (root->is_left_thr==false) 
    {
	  	//cout<<root->data<<endl;
		root=root->left; 
	}	
	return root; 
} 
  
// Printing the threaded tree 
void iterative_inorder(NODE* root) 
{ 
    if (root == NULL) 
        return; 
  	FILE *fp;
  	fp=fopen("7_24_output.txt","w");
    NODE* temp=root; 
    while (temp->is_left_thr == false) 
        temp=temp->left; 
    while (temp!= NULL) 
    { 
        cout<<temp->data<<endl;
		char s[20];
		sprintf(s,"%d\n",temp->data);
		fwrite(s,strlen(s),1,fp);
	    temp=nextone(temp); 
    } 
} 
void recursive_inorder(NODE* root) //for testing
{ 
    if (root==NULL) 
        return; 
    recursive_inorder(root->left); 
    cout << (root->data)<<endl; 
    recursive_inorder(root->right); 
} 
NODE* insert(NODE *rootin, int data) 
{ 
   	NODE *current=NULL;
    NODE *root=rootin; 
    int count=0;
    while (root!= NULL)  //locate where to insert
    { 
        //count++;
        //cout<<count;
		if (root->data==data) 
        { 
            cout<<"alreadt in"<<endl; 
            //cout<<root->data<<endl;
             //cout<<count;
			return rootin; 
        } 
  
        current=root; 
        if (root->data>data) 
        { 
            if (root->is_left_thr==false) 
            {
				//cout<<root->data<<endl;
				root=root->left; 
            }
			else
            {
			    //cout<<root->data<<endl;
			     //cout<<count;
				break;
			}
        } 
        else
        { 
            if (root->is_right_thr == false) 
            {
            	//cout<<root->data<<endl;
			   root=root->right; 
            } 
			else
			{
                //cout<<root->data<<endl;
                 //cout<<count;
				break;
				//cout<<root->data<<endl; 
	    	}
		} 
    } 
  	//the real add in
    NODE* temp;
	temp=new NODE; 
	temp->is_left_thr=true; 
    temp->is_right_thr=true; 
    temp->data=data; 
    
  
    if(current==NULL) 
    { 
        rootin=temp; 
    }
	else if(current->data<data) 
    { 
        temp->left=current; 
        temp->right=current->right;
		//add at right of current
        current->is_right_thr=false; 
        current->right=temp; 
    } 
    else if(current->data>data) 
    { 
        temp->left=current->left; 
        temp->right=current; 
        //add at left of current
        current->is_left_thr=false; 
        current->left=temp; 
    } 

    return rootin; 
} 
  

int main() 
{ 
   	NODE *root = NULL; 
  	FILE* fp;
	fp=fopen("7_24_input.txt","r");
    char buffer[100];
    int* inn;
	while (fgets(buffer, sizeof(buffer), fp)) //READ
	{
		//cout<<buffer;
		int number=atoi(buffer);
		//inn=new int;
		//*inn=number;
		//cout<<input;	
		root=insert(root,number);
	
	}

    iterative_inorder(root); 
    cout<<endl;
    //recursive_inorder(root); 
  
    return 0; 
} 
