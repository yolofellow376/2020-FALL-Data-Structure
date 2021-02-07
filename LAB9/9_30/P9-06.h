/*	=================== reheapDown ===================
	Reestablishes heap by moving data in root down to its
	correct location in the heap.
	   Pre  heap is array of data
	        root is root of heap or subheap
	        last is an index to last element in heap
	   Post heap has been restored
*/
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
	         (*step)++; //�s�W���� 
	         _reheapDown (heap, largeLoc,step);
	        } // if root <
	} // if root
	return;
}	// reheapDown
