#include <iostream>
#include<queue>
#include<stdlib.h>
#include<ctime>
#include <iomanip>

using namespace std;
typedef struct cust
{
    int num;
    int arrive;
    int start;
    int last;
}CUSTOMER;

typedef struct all
{
    int amountofcall;
    int workingtime;
    int waitingtime;
    int qmax;
    int idletime;
}TOTAL;
struct node
{
    int call;
    int lasttime;
    int num;
    int arrivetime;
};



void print_queue(queue<node> q)
{
  while (!q.empty())
  {
  
	cout<<q.front().call<<" "<<q.front().lasttime<<" "<<q.front().num<<" "<<q.front().arrivetime<<endl;
    q.pop();
  }

}
void process(int clock,queue<node> &q,CUSTOMER &customer, TOTAL &overall)
{
	struct node temp;
	if(clock>customer.start+customer.last-1)
  	{
		if(q.empty())
    	{
       	overall.idletime++;   
    	}
    	else
      {
        temp=q.front();
        customer.start=clock;
        customer.arrive=temp.arrivetime;
        customer.last=temp.lasttime;
        customer.num=temp.num;
        q.pop();
      }  	
	     
  	}
}
void total(int clock,queue<node> &q,CUSTOMER &customer,TOTAL &overall)
{
    int waittime;
    int queueSize;
    if(clock==customer.start+customer.last-1)
    {
        overall.amountofcall++;
        waittime=customer.start-customer.arrive;
        overall.workingtime+=customer.last;
        overall.waitingtime+=waittime;
        //print when call end
        cout<<setw(5)<<clock;
        cout<<setw(12)<<overall.amountofcall;
        cout<<setw(13)<<customer.arrive;
        cout<<setw(10)<<waittime;
        cout<<setw(11)<<customer.start;
        cout<<setw(13)<<customer.last;
        cout<<setw(11)<<q.size()<<endl;
        
        if(overall.qmax<q.size())
        {
          overall.qmax=q.size();
        }    
       
    }


}
int main()
{
	FILE *fp;
	queue<node> q;
	fp=fopen("4_22.txt","r");
	char buffer[100];
	int i=0;
	int num=0;
  	int endtime;
  	int clock;
	while (fgets(buffer, sizeof(buffer), fp)) //readfile
	{
		//cout<<buffer;
		struct node temp;
		temp.call=buffer[0]-'0';
		temp.lasttime=buffer[2]-'0';
		//cout<<temp.call<<" "<<temp.lasttime<<endl;
		if (temp.call!=0)
		{
			temp.arrivetime=i;
			temp.num=num;
			q.push(temp);
			num++;
		}
		i++;
  	}
  	//print_queue(q);
  	CUSTOMER customer;
  	TOTAL overall;
    //initialize overall record
    overall.amountofcall=0;
    overall.idletime=0;
    overall.waitingtime=0;
    overall.workingtime=0;
    overall.qmax=0;
    //initialize customer
    customer.arrive=0;
    customer.num=0;
    customer.start=0;
    customer.last=0;
	
  	endtime=120;

  	queue<node> waiting;
  	cout<<"clock time "<<"call number "<<"arrival time ";
  	cout<<"wait time "<<"start time "<<"service time ";
  	cout<<"queue size "<<endl;
  	for(clock=0;clock<=endtime;clock++)
  	{
    	if (clock==q.front().arrivetime)
    	{
    		waiting.push(q.front());
    		q.pop();	
		}
		process(clock,waiting,customer,overall);
		total(clock,waiting,customer,overall);
	}
  	cout<<"Total calls:  "<<overall.amountofcall<<endl;
  	cout<<"Total idle time:  "<<overall.idletime<<endl;
  	cout<<"Total wait time:  "<<overall.waitingtime<<endl;
  	cout<<"Total service time:  "<<overall.workingtime<<endl;
  	cout<<"Maximum queue size:  "<<overall.qmax<<endl;
  	double temp;
  	temp=double(overall.waitingtime)/overall.amountofcall;
  	cout<<"Average wait time:  "<<temp<<endl;
  	temp=double(overall.workingtime)/overall.amountofcall;
  	cout<<"Average service time:  "<<temp<<endl;
	//print_queue(q);
	
	return 0;
}
