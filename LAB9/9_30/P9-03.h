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
	_reheapUp (heap, heap->last,step); //��ʳ��� 
	return true;
}	// heapInsert
