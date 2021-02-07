#include <iostream>
//#include"P9-heap.h"
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include"graphADT.h"
#include <bits/stdc++.h>
#include <iomanip>
#include <string.h>
using namespace std;
char start[100],end[100]; 
struct data
{
    int key;
    char name[20];
    int intree;
    int pathLength;
};
void findend (void* dataPtr)
{
//	cout<<"name: "<<((data*)dataPtr)->name<<endl;
//	cout<<end<<endl;
   if(strcmp(((data*)dataPtr)->name,end)==0)
   {
   		cout<<((data*)dataPtr)->pathLength;
   }
}
int compare(void *argu1,void *argu2)
{
    if(((data*)argu1)->key>((data*)argu2)->key)
        return 1;
    else if(((data*)argu1)->key<((data*)argu2)->key)
        return -1;
    else
        return 0;
}
int mini_weight=0;
void shortestpath(GRAPH *graph)
{
    bool treeComplete;
    int minEdge,newPathLen,minPath;
    ARC *minEdgeLoc,*pathLoc;
    ARC *arc,*edgeLoc;

    VERTEX *vert=graph->first;
 //   cout<<((data*)(vert->dataPtr))->key;
 
	if(graph->count==0)
        return;
    while(vert!=NULL)
    {
        ((data*)(vert->dataPtr))->intree=0;
        ((data*)(vert->dataPtr))->pathLength=INT_MAX;
        arc=vert->pArc;
        while(arc!=NULL)
        {
            arc->intree=0;
            arc=arc->pNextArc;
        }
        vert=vert->pNextVertex;
    }
    ((data*)(graph->first->dataPtr))->intree=1;
    ((data*)(graph->first->dataPtr))->pathLength=0;
    treeComplete=false;
    while(treeComplete==false)
    {
        treeComplete=true;
        minEdgeLoc=NULL;
        pathLoc=NULL;
        newPathLen=INT_MAX;
        vert=graph->first;
        while(vert!=NULL)
        {
      //      cout<<((data*)(vert->dataPtr))->intree<<endl;
            if(((data*)(vert->dataPtr))->intree==1&&vert->outDegree>0)
            {
                edgeLoc=vert->pArc;
                minPath=((data*)(vert->dataPtr))->pathLength;
                minEdge=INT_MAX;
                arc=vert->pArc;
                while(arc!=NULL)
                {
                    if(((data*)(arc->destination->dataPtr))->intree==0)
                    {
                     //   cout<<((data*)(vert->dataPtr))->name<<"wtf"<<((data*)(arc->destination->dataPtr))->name<<endl;
                        treeComplete=false;
                        if(arc->weight<minEdge)
                        {
                            minEdge=arc->weight;
                            minEdgeLoc=edgeLoc;
                         //   cout<< minEdge<<endl;
                        }
                    }
                    edgeLoc=edgeLoc->pNextArc;
                    arc=arc->pNextArc;
                }
				if (minEdge!=INT_MAX)
					mini_weight+=minEdge; 

                if(minEdge<newPathLen&&minPath+minEdge<newPathLen)//overflow!!!!!!!!!!!!!!!!!!!!!!!
                {
                    newPathLen=minPath+minEdge;
                    pathLoc=minEdgeLoc;
                    //cout<<minEdgeLoc<<endl;
                }

            }
            vert=vert->pNextVertex;
        }
        if(pathLoc!=NULL)
        {
            pathLoc->intree=1;
            ((data*)(pathLoc->destination->dataPtr))->intree=1;
            ((data*)(pathLoc->destination->dataPtr))->pathLength=newPathLen;

        }
    }
 
	


}

int main()
{
	string s;
	//cin>>s;
	s="graph.txt";
	int n = s.length();
    char filename[n + 1];
    strcpy(filename, s.c_str());
	//cout<<filename;
	fstream fin;
	fin.open(filename);
	string line;
	cout<<"請輸入起點城市:";
	
	cin>>start;
	cout<<"請輸入終點城市:";
	cin>>end;
	
	GRAPH *graph;
	graph=(GRAPH*)malloc(sizeof(GRAPH));
    graph->count=0;
    graph->first=NULL;
    graph->compare=compare;
    int vertex_no[100]={0};
    int index=0;
	while(getline(fin,line,'\n'))
	{
	//	cout<<endl;
		char buffer[100];
		strcpy(buffer, line.c_str());
		char *v1,*weight,*v2;
		char * pch;
  		pch = strtok (buffer," ");
  		v1=pch;
  		
  		pch = strtok (NULL, " ,.-");
  		v2=pch;
  		pch = strtok (NULL, " ,.-");
  		weight=pch;
  		bool flag;
  		//cout<<atoi(v1)<<" "<<atoi(v2)<<" "<<weight;
  		for(int i=0;i<100;i++)
  		{
  			if (atoi(v1)==vertex_no[i])
  			{
  				flag=true;
			}
		}
		if (flag==true)
			cout<<"";
		else 
		{
			vertex_no[index]=atoi(v1);
			index++;
		}	
			
		flag=false;
		for(int i=0;i<100;i++)
  		{
  			if (atoi(v2)==vertex_no[i])
  			{
  				flag=true;
			}
		}
		if (flag==true)
			cout<<"";
		else
		{
			vertex_no[index]=atoi(v2);
			index++;
		}
		
	}
	fin.close();
//	cout<<endl;
	int offset=0;
	int in_no,out_no;
	int count=1;
	bool ff=false;
	int map[1000]={0};
	for(int j=0;j<index;j++)
	{
		char tmp[100];
		itoa(vertex_no[j],tmp,10);
		if (strcmp(start,tmp)==0)
		{
			data *v;
			v=(data*)malloc(sizeof(data));
			v->key=count;
			char tmp[100];
			itoa (vertex_no[(j+offset)%index],tmp,10);
			string t=string(tmp);
			itoa (vertex_no[(j+offset)%index],(v->name),10);
		//	cout<<v->key<<v->name;
	    	graphInsVrtx(graph,(void*)v);
	    	map[vertex_no[(j)]]=count;
	    	count++;
	    	
	    	ff=true;
	    	in_no=j;
		}
		else if (strcmp(end,tmp)==0&&ff==true)
		{
			data *v;
			v=(data*)malloc(sizeof(data));
			v->key=count;
			char tmp[100];
			itoa (vertex_no[(j+offset)%index],tmp,10);
			string t=string(tmp);
			itoa (vertex_no[(j+offset)%index],(v->name),10);
	    	graphInsVrtx(graph,(void*)v);
	    	out_no=j;
	    	map[vertex_no[(j)]]=count;
	    	count++;
		}
		 

	}
	for(int i=0;i<index;i++)
	{
		
		if(i==in_no||i==out_no)
		{
			continue;
		}
		else
		{
				data *v;
	//	cout<<vertex_no[i]<<endl;
		v=(data*)malloc(sizeof(data));
		v->key=count;
		char tmp[100];
		itoa (vertex_no[(i+offset)%index],tmp,10);
	//	cout<<tmp<<endl;
		string t=string(tmp);
		//cout<<t<<endl;
		itoa (vertex_no[(i+offset)%index],(v->name),10);
	//	cout<<v->name<<endl;
    	graphInsVrtx(graph,(void*)v);
    	map[vertex_no[(i)]]=count;
    	count++;
    	
		}
	
	}
	fin.open(filename);
	while(getline(fin,line,'\n'))
	{
		//cout<<endl;
		char buffer[100];
		strcpy(buffer, line.c_str());
		char *v1,*weight,*v2;
		char * pch;
  		pch = strtok (buffer," ");
  		v1=pch;
  		
  		pch = strtok (NULL, " ,.-");
  		v2=pch;
  		pch = strtok (NULL, " ,.-");
  		weight=pch;
  		bool flag;
  	//	cout<<atoi(v1)<<" "<<atoi(v2)<<" "<<weight<<endl;
  		data *vv1,*vv2;
  		vv1=(data*)malloc(sizeof(data));
		vv1->key=map[atoi(v1)];

		string t=string(v1);
	//	cout<<v1<<" "<<t<<endl;
		itoa (atoi(v1),(vv1->name),10);
    	//cout<<vv1->name;
    	vv2=(data*)malloc(sizeof(data));
		vv2->key=map[atoi(v2)];
		string t2=string(v1);
	//	cout<<v2<<" "<<t2<<endl;
    	itoa (atoi(v2),(vv2->name),10);
		graphInsArc(graph,(void*)vv1,(void*)vv2,atoi(weight));
		graphInsArc(graph,(void*)vv2,(void*)vv1,atoi(weight));
		
	}
   
    shortestpath(graph);
	graphDpthFrst(graph,findend);
	
	

}
