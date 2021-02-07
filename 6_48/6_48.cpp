#include <fstream>
#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string.h>
#include <list>
using namespace std;
class Node
{
public:
    string alphabet;
    string code;
};

class treenode
{
public:
    char c;
    int weight;
    treenode *left;
    treenode *right;
	
	treenode(char cc,int w,treenode *l,treenode *r)
    {
        c=cc;
        weight=w;
        right=r;
        left=l;
    }
   
};
void display(list<treenode*> r)
{
	while(!r.empty())
	{
		cout<<r.front()->c<<"   "<<r.front()->weight<<endl;
		r.pop_front();
	}
	
}
bool compare(treenode *a,treenode *b)
{
    return ((a->weight) < (b->weight));
}
void createchart(treenode* root,string encode,Node chart[])
{
    if((root->left==NULL)||(root->right==NULL))
    {
        chart[(root->c)-65].alphabet=root->c;
        chart[(root->c)-65].code=encode;
        return;
    }
    if(root->left) 
	{
		string temp=encode+"0";
		createchart(root->left,temp,chart);
    }
	if(root->right)
	{
		string temp=encode+"1";
		createchart(root->right,temp,chart);
	}	
    return ;
}
void printchart(Node chart[])
{
	for(int i=0;i<26;i++)
	{
		cout<<chart[i].alphabet<<" = "<<chart[i].code<<endl;
	}
}
void wordtohuff(string text,Node chart[])
{
	cout<<"Encode result = ";
	for(int i=0;i<text.size();i++)
    {
        cout<<chart[(text[i]-65)].code;
    }
    cout<<endl;
}
void hufftoword(string code,Node chart[])
{
	cout<<"Decode result = ";
	string temp;
	bool found;
   	for(int i=0;i<code.size();i++)
    {
        temp=temp+code[i];
        //cout<<temp;
		for(int j=0;j<26;j++)
        {
            found=false;
            if(temp.compare(chart[j].code)==0)
            {
                //cout<<temp;
				cout<<chart[j].alphabet;
                found=true;
                break;
            }
        }
        if(found==true)
        {
		    temp="";
		}
    }
}
string alwaysuppercase(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<=122&&s[i]>=97)
            s[i]-=32;
    }
    return s;
}
int main()
{
	list<treenode*>root;
 
    //int data[4];
    char buffer[20];
	FILE *fp;
	fp=fopen("Hw6.txt","r");
	treenode *input;
   	while (fgets(buffer, sizeof(buffer), fp)) //READ
	{
		
		char * pch;
  		pch = strtok (buffer," ");
  		char c=pch[0];
		pch = strtok (NULL," ");
		int temp=atoi(pch);
		//cout<<c<<temp;
		input=new treenode(c,temp,NULL,NULL);
		root.push_back(input);
		//cout<<root.back()->c<<"   "<<root.back()->weight<<endl;
	}
	//display(root);
	//cout<<endl;
	treenode *huffhead;
    while(root.front()->weight!=100)//MAKE TREE
    {
		//display(root);
        root.sort(compare);
        //display(root);
        //break;
		list<treenode*>::iterator left,right;
        right=root.begin();
        right++;
        left=root.begin();
        treenode *parents;
		//cout<<(*second)->c<<"   "<<(*second)->weight<<endl;
        parents=new treenode('\0',(*left)->weight+(*right)->weight,(*left),(*right));

        root.push_back(parents);
      //  cout<<endl<<"left right "<<&(*first)<<&(*second)<<&(root.front())<<endl;
   //     print(root);
        root.pop_front();
		root.pop_front();
        
        //cout<<root.front()->c<<"   "<<root.front()->weight<<endl;
    }
    root.sort(compare);
    //display(root);
    huffhead= (root.front()); 
    root.clear();
    string s="";
    
    Node chart[26];

    createchart(huffhead,s,chart); 
	printchart(chart);
	string  text;
	
	cout<<"Enter any word that you want to encode:(!ONLY UPPERCASE!)"<<endl;
    cin>>text;
    text=alwaysuppercase(text);
    wordtohuff(text,chart);
    
 
    string  code;
    cout<<"Enter any code that you want to decode:"<<endl;
	cin>>code;
	hufftoword(code,chart);
	 //display list

  

    return 0;

}
