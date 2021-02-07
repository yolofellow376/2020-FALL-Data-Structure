#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct node
{
    int num;
    int quan;
    node* next;
};
class hashArray
{
public:
    node array[10];
    int collision;
    int array_size;
    hashArray()
    {
        array_size=10;
        collision=0;
        for(int i=0;i<10;i++)
        {
		    array[i].num=-1;
			array[i].quan=-1;
    		array[i].next=NULL;
		}
	}
};
void printlist(node* key)
{
	key=key->next;
	while(key!=NULL)
	{
		cout<<key->num<<"/"<<key->quan<<", ";
		key=key->next;
	}
}
int main()
{

    class hashArray hasharray;
    fstream fp;
    int quant,invent;
    int choice=1;
    fp.open("13_19_input.txt", ios::in);

    while(fp>>invent)
    {
        

		int address;
        fp>>quant;
        address=invent%10;
        if(hasharray.array[address].num==-1)
        {
            hasharray.array[address].num=invent;
            hasharray.array[address].quan=quant;
            hasharray.array[address].next=NULL; 
        }
        else
        {
			node* new_d;
            new_d=(node*)malloc(sizeof(node));
            new_d->num=invent;
            new_d->quan=quant;
            new_d->next=NULL;
         //   cout<<new_d->num;
			node* temp;
			temp=(node*)malloc(sizeof(node));
		//	cout<<"hew?";
			temp=&hasharray.array[address];
		//	cout<<temp->num<<"ckp";
			while(temp->next!=NULL)
			{
				temp=temp->next;
		//		cout<<"ckp";
			//	cout<<temp->num<<endl;
			}
			//hasharray.array[address].next=new_d;
			
			temp->next=new_d; 
		//	cout<<address<<" "<<hasharray.array[address].next->num<<endl;
        }

    }

    while(1)
    {
        cout<<"Options:"<<endl
		<<"(1)search for an inventory item and report its quantity sold"<<endl
        <<"(2)analize the efficiency of the hashing algorithm"<<endl
        <<"(3)print the inventory parts and their quantity sold"<<endl
        <<"(4)exit"<<endl
        <<"Enter your choices: "; 
        cin>>choice;

        if(choice==1)//search key
        {
            int key;
            int step=0,address;
            cout<<"input inventory number"<<endl;
            cin>>key;
            address=key%10;
            
            if(hasharray.array[address].num==key)
            {
                cout<<"found at address="<<address<<" inventory number = "<<hasharray.array[address].num<<
                " quantity = "<<hasharray.array[address].quan<<endl;
            }
            else
            {
            	node* tmp=hasharray.array[address].next;
				while(tmp!=NULL)
				{
					if(tmp->num==key)
					{
						break;
					}
					tmp=tmp->next;
					
				}
            	cout<<"found at address="<<address<<" inventory number = "<<key<<
                " quantity = "<<tmp->quan<<endl;
			}
                cout<<"not found"<<endl;

        }
        else if (choice==3)
        {
            cout<<"Home addr   "<<"Prime Area   "<<"    OverFlow list"<<endl;
            for(int i=0;i<10;i++)
            {
             	if(hasharray.array[i].num==-1)
				{
					cout<<setw(2)<<i<<endl;
					continue;
				 } 
				 cout<<setw(2)<<i<<setw(15)<<hasharray.array[i].num<<"/"<<hasharray.array[i].quan<<"           ";
             	//cout<<endl;
             	printlist(&hasharray.array[i]);
             	cout<<endl;
			}  
        }
        else if (choice==2)
        {
            double occ_count=0;
            for(int i=0;i<10;i++)
            {
            //	cout<<hasharray.array[i].num<<endl;
				if((hasharray.array[i].num)>0)
            	{
            		//cout<<hasharray.array[i].num<<endl;
            		occ_count++;
				}
			}
			
			cout<<"percentage of prime area filled:"<< occ_count/10*100<<"%"<<endl;
			double list_count=0;
			double real_c=0;
			for(int i=0;i<10;i++)
            {
            //	cout<<hasharray.array[i].num<<endl;
				node* key=hasharray.array[i].next;
				if(key!=NULL)
				{
					real_c++;
				}
				while(key!=NULL)
				{
					key=key->next;
					list_count++;
				}
			}
			cout<<"Average nodes in linked list:"<<list_count/real_c<<endl; 
			int long_count=0;
			for(int i=0;i<10;i++)
            {	
            	int l_count=0;
            //	cout<<hasharray.array[i].num<<endl;
				node* key=hasharray.array[i].next;
				while(key!=NULL)
				{
					key=key->next;
					l_count++;
				}
				if(l_count>long_count)
				{
					long_count=l_count;
				}
			}
			cout<<"Longest length of list:"<<long_count<<endl; 
        }
        else if (choice==4)
        {
        	break;
		}


        
    }
    return 0;
}
