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
	_reheapDown (heap, 0,step); //��ʳ��� 
	return true;
}	// heapDelete
