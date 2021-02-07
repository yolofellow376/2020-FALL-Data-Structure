#include<stdio.h>
#include<iostream>
#include <queue>
#include<stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
bool isendcase(char c[])
{
    if (c[0]=='!') 
		return true;
    else
    	return false;
}
void print_queue(queue<char*> q)
{
  while (!q.empty())
  {
    if (isendcase(q.front()))
		{q.pop();
		continue;}
	cout << q.front() << " ";
    q.pop();
  }

}
bool isblank(char c[])
{
    if (c[0]==' ') 
		  return true;
    else
    	return false;

}

bool isopera(char c[])
{
    switch(c[0])
    {
        case '+':
          return true;
        case '-':
          return true;
        case '*':
          return true;
        case '/':
          return true;
    }
    return false;

}
bool isnum(char c[])
{
    if (!isopera(c)) 
		  return true;
    else
    	return false;

}
bool isint(char c[])
{
	double f=atof(c);
	if (round(f) == f) 
	{
		return true;
	} 
	else 
	{
		return false;
  }
}
bool isnexttwonumber(queue<char *> q)
{
    if(q.size()<3)
        return false;
    queue <char *>temp;
    char *num1,*num2;
    num1=new char[10];
    num2=new char[10];
    temp=q;
    temp.pop();//remove operator
    num1=temp.front();
    temp.pop();
    num2=temp.front();

    if(isnum(num1)&&isnum(num2))
        return true;
    else
        return false;

}
void solve(queue<char *> q)
{
	queue<char *> buffer;
  	while(buffer.size()!=2||q.size()!=0)
  	{
	  //cout<<q2.size()<<","<<q1.size()<<endl;
		if(q.size()==0)
    {
      //print_queue(q2);
			q=buffer;
      while(!buffer.empty())
      {
        buffer.pop();
      }
    }
		if(isopera(q.front()))
    {
      if(isnexttwonumber(q))
      {
        double num1,num2;
        double total;
        char *getstring=q.front();
        q.pop();
        char opera;
				opera=getstring[0];
        
        num1=atof(q.front());
        q.pop();
        num2=atof(q.front());
        q.pop();
				//cout<<num1<<num2;
        char *result=new char[10];
        switch(opera)
        {
          case '+':
            total=num1+num2;
         	  sprintf(result,"%f",total);
         	  //cout<<result;
            buffer.push(result);
            break;
          case '-':
            total=num1-num2;
            sprintf(result,"%f",total);
            buffer.push(result);
            break;
          case '*':
            total=num1*num2;
            sprintf(result,"%f",total);
            buffer.push(result);
            break;
          case '/':
            total=num1/num2;
             
            sprintf(result,"%f",total);
            //cout<<result;
            buffer.push(result);
            break;
        }
      }
      else
      {
        buffer.push(q.front());
        q.pop();
      }
    }
		else
    {
      buffer.push(q.front());
      q.pop();
    }
  }
  q=buffer;
  char *final=q.front();
  if(isint(final))
  {
  	int a=atoi(final);
		cout<<a<<endl;
	}
	else
	{
		cout<<final<<endl;
	}
	
}

int main()
{
  	
  	char cases[10][100];
  	queue<char *> q1;
  	FILE *fp;
  	fp=fopen("4_20.txt","r");
  	int i=0;
	
  	while (fgets(cases[i], sizeof(cases[i]), fp)) {
  		i++;
  	}
  	int cases_count=i;
  	char * pch;
  	for(i=0;i<cases_count;i++)
  	{
  		pch = strtok (cases[i]," ");
  		while (pch != NULL)
  		{
    		//printf ("%s\n",pch);
    		q1.push(pch);
    		pch = strtok (NULL, " ,.-");
  		}
  		cout<<"case"<<i+1<<":";
		//print_queue(q1);
  		solve(q1);
    	q1 = queue<char *>(); //new
	}

  fclose(fp);
}
