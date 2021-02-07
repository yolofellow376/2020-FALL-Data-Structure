#include <iostream>
//#include"P9-heap.h"
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int compare (void *n1,void *n2)
{
    if((*(int*)n1)==(*(int*)n2))
        return 0;
    else if((*(int*)n1)>(*(int*)n2))
        return 1;

    return -1;
}
/*	Data Structures for heap ADT
	   Created by:
	   Date:
*/
#include <stdbool.h>

typedef struct
{
   void** heapAry;
   int    last;
   int    size;
   int    (*compare) (void* argu1, void* argu2);
   int    maxSize;
} HEAP;
int  heapCount (HEAP* heap);
bool heapFull  (HEAP* heap);
bool heapEmpty (HEAP* heap);
//	Prototype Definitions
HEAP* heapCreate (int maxSize,
            int (*compare) (void* arg1, void* arg2));
bool  heapInsert  (HEAP* heap, void*  dataPtr,int *step);
bool  heapDelete  (HEAP* heap, void** dataOutPtr,int *step);
int   heapCount   (HEAP* heap);
bool  heapFull    (HEAP* heap);
bool  heapEmpty   (HEAP* heap);
void  heapDestroy (HEAP* heap);

static void _reheapUp   (HEAP* heap, int childLoc,int *step);
static void _reheapDown (HEAP* heap, int root,int *step);
/*	==================== heapCreate ====================
	Allocates memory for heap and returns address of
	heap head structure.
	   Pre  Nothing
	   Post heap created and address returned
	             if memory overflow, NULL returned
*/
#include <math.h>

HEAP* heapCreate (int maxSize,
                  int  (*compare) (void* argu1, void* argu2))
{
//	Local Definitions
	HEAP* heap;

//	Statements 
	heap = (HEAP*)malloc(sizeof (HEAP));
	if (!heap)
	   return NULL;

	heap->last    = -1;
	heap->compare = compare;

	// Force heap size to power of 2 -1
	heap->maxSize = (int) pow (2, ceil(log2(maxSize))) - 1;
	heap->heapAry = (void**) 
	                 calloc(heap->maxSize, sizeof(void*));
	return heap;
}	// createHeap 
/*	================== heapInsert ===================
	Inserts data into heap.
	   Pre    Heap is a valid heap structure
	          last is pointer to index for last element
	          data is data to be inserted
	   Post   data have been inserted into heap
	   Return true if successful; false if array full
*/
bool heapInsert (HEAP* heap, void* dataPtr,int *step)
{
//	Statements
    *step=0;
	if (heap->size == 0)                 // Heap empty
	   {
	    heap->size                = 1;
	    heap->last                = 0;
	    heap->heapAry[heap->last] = dataPtr;
	    return true;
	   } // if
	if (heap->last == heap->maxSize - 1)
	  return false;
	++(heap->last);
	++(heap->size);
	heap->heapAry[heap->last] = dataPtr;
	_reheapUp (heap, heap->last,step); //更動部分 
	return true;
}	// heapInsert
/*	 ================== heapDelete ===================
	Deletes root of heap and passes data back to caller.
	   Pre    heap is a valid heap structure
	          last is reference to last node in heap
	          dataOut is reference to output area
	   Post   last deleeted and heap rebuilt
	          deleted data passed back to user
	   Return true if successful; false if array empty
*/
bool heapDelete (HEAP* heap, void** dataOutPtr,int *step)
{
//	Statements
    *step=0;
	if (heap->size == 0)
	    // heap empty
	    return false;
	*dataOutPtr = heap->heapAry[0];
	heap->heapAry[0]  = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	_reheapDown (heap, 0,step); //更動部分 
	return true;
}	// heapDelete
/*	=================== reheapDown ===================
	Reestablishes heap by moving data in root down to its
	correct location in the heap.
	   Pre  heap is array of data
	        root is root of heap or subheap
	        last is an index to last element in heap
	   Post heap has been restored
*/
/*	==================== reheapUp ====================
	Reestablishes heap by moving data in child up to
	correct location heap array.
	   Pre  heap is array containing an invalid heap
	        newNode is index to new data in heap
	   Post newNode inserted into heap
*/
void  _reheapUp  (HEAP* heap, int childLoc,int *step)
{
//	Local Definitions
	int    parent;
	void** heapAry;
	void*  hold;

//	Statements
	// if not at root of heap -- index 0
	if (childLoc)
	   {
	    heapAry = heap->heapAry;
	    parent = (childLoc - 1)/ 2;
	    if (heap->compare(heapAry[childLoc],
	                      heapAry[parent]) > 0)
	        // child is greater than parent -- swap
	        {
	         hold             = heapAry[parent];
	         heapAry[parent]  = heapAry[childLoc];
	         heapAry[childLoc] = hold;
	         (*step)++; //新增部分 
	        _reheapUp (heap, parent,step);
	       } // if heap[]
	   } // if newNode
	return;
}	// reheapUp
void _reheapDown (HEAP* heap, int root,int *step)
{
//	Local Definitions
	void* hold;
	void* leftData;
	void* rightData;
	int   largeLoc;
	int   last;

//	Statements
	last = heap->last;
	if ((root * 2 + 1) <= last)         // left subtree
	    // There is at least one child
	   {
	    leftData   = heap->heapAry[root * 2 + 1];
	    if ((root * 2 + 2) <= last)  // right subtree
	       rightData = heap->heapAry[root * 2 + 2];
	    else
	       rightData = NULL;

	    // Determine which child is larger
	    if ((!rightData)
	         || heap->compare (leftData, rightData) > 0)
	       {
	        largeLoc = root * 2 + 1;
	       } // if no right key or leftKey greater
	    else
	       {
	        largeLoc = root * 2 + 2;
	       } // else
	    // Test if root > larger subtree
	    if (heap->compare (heap->heapAry[root],
	        heap->heapAry[largeLoc]) < 0)
	        {
	         // parent < children
	         hold                = heap->heapAry[root];
	         heap->heapAry[root] = heap->heapAry[largeLoc];
	         heap->heapAry[largeLoc] = hold;
	         (*step)++; //新增部分 
	         _reheapDown (heap, largeLoc,step);
	        } // if root <
	} // if root
	return;
}	// reheapDown
int main()
{
    HEAP * heap_100,* heap_200,* heap_500,* heap_1000,* heap_2000;
    int *dataOut;
    int step;
   
    heap_100=heapCreate(100,compare);
    heap_200=heapCreate(200,compare);
    heap_500=heapCreate(500,compare);
    heap_1000=heapCreate(1000,compare);
    heap_2000=heapCreate(2000,compare);
    int *temp;
	fstream fin;
	fin.open("data.csv");
	string line;
	getline(fin,line,'\n');
	while(getline(fin,line,'\n'))
	{
		istringstream templine(line);
		string data;
		int count=0;
		while(getline(templine,data,','))
		{
			int* num;
			num = new int;
			*num=atoi(data.c_str());
			//cout<<*num<<endl;
			count=count%5;
			//cout<<count;
			switch(count){
				case(0):
					if(*num>0)
					{
					//	cout<<count<<"insert100"<<endl;
						heapInsert(heap_100,num,&step);
					}
					count++;
					break;
				case(1):
					if(*num>0)
					{
					//	cout<<count<<"insert200"<<endl;
						heapInsert(heap_200,num,&step);
					}
					count++;
					break;
				case(2):
					if(*num>0)
					{
						//cout<<count<<"insert500"<<endl;
						heapInsert(heap_500,num,&step);
					}
					count++;
					break;
				case(3):
					if(*num>0)
					{
						//cout<<count<<"insert1000"<<endl;
						heapInsert(heap_1000,num,&step);
					}
					count++;
					break;
				case(4):
					if(*num>0)
					{
					//	cout<<count<<"insert2000"<<endl;
						heapInsert(heap_2000,num,&step);
					}
					count++;
					break;			 
			}
			 
		}
	}
	//------results
	int up_100=0,up_200=0,up_500=0,up_1000=0,up_2000=0;
	int down_100=0,down_200=0,down_500=0,down_1000=0,down_2000=0;
	//----------------------process
	
	srand(time(NULL));
	for(int i=0;i<100;i++)
	{
		heapDelete(heap_100, (void**)&dataOut,&step);
		down_100+=step;
		int *input;
        input=new int;
        *input=rand();
        heapInsert(heap_100,input,&step);
        up_100+=step;
	}
	cout<<"Average reheap up   for  100: "<<up_100/100<<endl;
	cout<<"Average reheap down for  100: "<<down_100/100<<endl;
	for(int i=0;i<100;i++)
	{
		heapDelete(heap_200, (void**)&dataOut,&step);
		down_200+=step;
		int *input;
        input=new int;
        *input=rand();
        heapInsert(heap_200,input,&step);
        up_200+=step;
	}
	cout<<"Average reheap up   for  200: "<<up_200/100<<endl;
	cout<<"Average reheap down for  200: "<<down_200/100<<endl;
	for(int i=0;i<100;i++)
	{
		heapDelete(heap_500, (void**)&dataOut,&step);
		down_500+=step;
		int *input;
        input=new int;
        *input=rand();
        heapInsert(heap_500,input,&step);
        up_500+=step;
	}
	cout<<"Average reheap up   for  500: "<<up_500/100<<endl;
	cout<<"Average reheap down for  500: "<<down_500/100<<endl;
	for(int i=0;i<100;i++)
	{
		heapDelete(heap_1000, (void**)&dataOut,&step);
		down_1000+=step;
		int *input;
        input=new int;
        *input=rand();
        heapInsert(heap_1000,input,&step);
        up_1000+=step;
	}
	cout<<"Average reheap up   for 1000: "<<up_1000/100<<endl;
	cout<<"Average reheap down for 1000: "<<down_1000/100<<endl;
	for(int i=0;i<100;i++)
	{
		heapDelete(heap_2000, (void**)&dataOut,&step);
		down_2000+=step;
		int *input;
        input=new int;
        *input=rand();
        heapInsert(heap_2000,input,&step);
        up_2000+=step;
	}
	cout<<"Average reheap up   for 2000: "<<up_2000/100<<endl;
	cout<<"Average reheap down for 2000: "<<down_2000/100<<endl;
	 
	cout<<"Reheap up   的 BIG O 是 log N"<<endl; 
	cout<<"Reheap down 的 BIG O 是 log N"<<endl;
	int result=1;
	/*for(int i=1;i<20;i++)
	{
		int temp=1;
		for(int j=0;j<i;j++)
		{
			temp=temp*2;
		}
		result+=temp;
		cout<<result<<endl;
	}*/
  	cout<<"可以看出 N_heap 每 N 乘以兩倍, Reheap up 和 Reheap down 的平均次數都有約略加一的趨勢"<<endl;
	cout<<"(平均值有浮動是因為 N_heap 有可能是 nearly complete heaps)"<<endl;
	cout<<"因此可以得出reheap up / reheap down 次數 = log 底為 2 真數為2 ^ n 的關係\n"<<"因此兩者的 Big O 皆為 log N"<<endl; 
  	
    return 0;
}
