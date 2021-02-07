#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring> 
using namespace std;
void display(int array[], int length) 
{ 
    for (int i=0;i<length;i++) 
    {
	    cout<<array[i]<<" ";
	}
} 
void increment_sort(int array[], int length,int increment)
{
	for(int j=increment;j<length;j++) 
    { 
        int temp= array[j]; 
        int k;
	//cout<<j<<endl;
        for(k=j;(k>=increment)&&(array[k-increment]>temp);k-=increment) 
        {
            //	cout<<k<<endl;
			array[k]=array[k-increment]; 
		}   
        array[k]=temp; 
    }
    
} 
int shell_sort(int array[], int length) 
{ 
    int increment=0;
    int i=0;
	for(i=2;length/i>1;i++) 
    { 
    	increment=length/i;
		cout<<"increment = "<<length<<" / "<<i<<" = "<<increment<<endl;
    	increment_sort(array,length,increment);
		display(array,length); 
    	cout<<endl; 
    }
    increment=1;
    cout<<"increment = "<<length<<" / "<<i<<" = "<<increment<<endl;
	increment_sort(array,length,increment);
    display(array,length); 
    cout<<endl; 
    return 0; 
}

int main()
{
	FILE *fp;
	fp=fopen("12_22_input.txt","r");
	char buffer[100];
	int count=0;
	int array[100];
	while (fgets(buffer, sizeof(buffer), fp)) 
	{	
		//cout<<buffer;
		char * token;
		token = strtok(buffer," ");
		
		while( token != NULL ) 
		{
      	//		printf( "%s\n", token );
    		array[count]=atoi(token);
      		token = strtok(NULL," ");
      		count++;
   		}
  	}
  	//cout<<count<<endl;
    cout<<"Original array"<<endl;
	display(array,count); 
	cout<<endl;
	shell_sort(array,count);
}
