#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string.h>
#include <list>
#include "P7-BST-ADT.h"
using namespace std;
struct people
{
    string name;
    string pnumber;
};
int compare(void *data1,void *data2)
{
    char s1[100],s2[100];
   // cout<<((struct people*)data1)->name;
    strcpy(s1,(((struct people*)data1)->name).c_str());
    strcpy(s2,(((struct people*)data2)->name).c_str());
    return stricmp(s1,s2);
}
void preorder(NODE* root)
{
    int i;
    if (root==NULL)
    	return;
    cout<<setw(8)<<((people*)root->dataPtr)->name<<"   "<<((people*)root->dataPtr)->pnumber;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    BST_TREE *treeroot;

    FILE* fp;
	fp=fopen("HW7_22.txt","r");
    treeroot=BST_Create(compare);
    char buffer[100];
    people* input;
	while (fgets(buffer, sizeof(buffer), fp)) //READ
	{
		
		char * pch;
  		pch = strtok (buffer," ");
  		string name=pch;
		pch = strtok (NULL," ");
		string pnum=pch;
		//cout<<name<<" "<<pnum;
		input=new people;
		input->name=name;
		input->pnumber=pnum;
		BST_Insert(treeroot,(void*)input);
	
	}
	NODE* temp=treeroot->root;
	preorder(temp);
    
    fclose(fp);
    
    
    int key=0;
    while(key!=5)
    {
        
		cout<<"(1) Search"<<endl
        	<<"(2) Insert "<<endl
        	<<"(3) Delete "<<endl
        	<<"(4) Print "<<endl
        	<<"(5) Exit "<<endl
        	<<"Enter your choice "<<endl;
	    cin>>key;
        switch(key)
        {
        case 1:
            {
                cout<<"Name : ";
                string lookfor;
                cin>>lookfor;
                people* found=(people*)BST_Retrieve(treeroot,(void*)(&lookfor));
                if(found)
                {
                	cout<<"Phone number: "<<found->pnumber<<endl;
				}
				else
				{
					cout<<"Not found"<<endl;
				}
				break;

            }
        case 2:
            {
               	cout<<"Name : ";
               	string insertname;
                cin>>insertname;
                cout<<"Phone number: ";
                string insertpnum;
                cin>>insertpnum;
                //cout<<insertpnum;
                insertpnum.push_back('\n');
                //cout<<insertpnum;
                people* insert;
                insert=new people;
                insert->name=insertname;
                insert->pnumber=insertpnum;
                BST_Insert(treeroot,(void*)insert);
                break;
            }
        case 3:
            {
                cout<<"Name : ";
               	string deletename;
                cin>>deletename;
             	bool del=BST_Delete(treeroot,(void*)(&deletename));
             	
                if(del)
                {
                	cout<<"Delete successful"<<endl;
				}
				else
				{
					cout<<"Error!"<<endl;
				}
                break;

            }
        case 4:
			preorder(temp);
            break;

        }
    }
	return 0;
} 
