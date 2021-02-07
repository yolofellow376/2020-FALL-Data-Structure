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
