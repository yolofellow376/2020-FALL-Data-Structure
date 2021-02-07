#include <iostream>
 
using namespace std;
int count=0;
void print_heap(int heap[],int length)
{
    for (int i=0;i<length; i++)
    {
	    cout<<heap[i]<<" ";
	}
	cout<<"\n";
}
 
void make_heap(int heap[],int length,int index)
{
    //cout<<index<<endl;
	int max=index; 
    int temp;
	int left_index=2*index+1;
    int right_index=2*index+2;
    bool flag=false;
 	if ((heap[right_index]>heap[max])&&(right_index<length))
    {
	    max=right_index;
        //count++; data沒有移動 所以我認為不用加 
 	}
    
    if ((heap[left_index]>heap[max])&&(left_index<length))
    {
	    max=left_index;
		//count++; data沒有移動 所以我認為不用加 
	}
 
    if (index!=max) 
	{
        temp=heap[index];
        heap[index]=heap[max];
        heap[max]=temp;
 		count+=3;
        make_heap(heap,length,max);
    }
}
 
void heap_sort(int heap[], int n)
{
    // Build heap
    for (int i=n/2-1;i>=0;i--)
    {
	    make_heap(heap,n,i);
  	}
  	//print_heap(heap, n);
	int temp;
	for (int j=n-1;j>0;j--) 
	{
        temp=heap[0];
		heap[0]=heap[j];
		heap[j]=temp;
		count+=3;
 	    make_heap(heap,j,0);
 	    //cout<<count<<" ";
    }
}
 

int main()
{
    int heap_array[]={47,80,42,37,45,4,52,39,65,32,54,71,82,20,99,55,30,96,2,56};
    int length=sizeof(heap_array)/sizeof(int);
 	//cout<<n<<endl;
 	cout<<"Original array: ";
 	print_heap(heap_array,length);
    heap_sort(heap_array,length);
 
    cout<<"Sorted array:    ";
    print_heap(heap_array,length);
    cout<<"Total exchanges: ";
    cout<<count<<endl; //數目與助教給的不同 應該是make_heap裡面方法不同的關係 我的演算法是參考網路上的heap sortㄈㄤ法
	 
}
