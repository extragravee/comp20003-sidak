#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/*
	Quick revision of queue and stack DS
	Implementations, best one we pick Linked Lists

	What if we want to order our key not based on the only value that is in there,
	but based on some arbitray attribute?
	
	===============
	PRIORITY QUEUES
	===============

	- super basic data structure
	- heaps of fun algorithms are based on this concept
	- it is a queue, so first in first out / first come first served holds
	- jpeg files use this, this is a form of compression btw, the more times
		you compress a file, or save as a jpeg, the more it will degrade like a mf

	QUEUES
	======
	Supports:
		-makeQ()
		-enQ(Q, ITEM)
		-deQ(Q)
		-emptyQ(Q)

	PRIORITY Q
	==========
	Supports:
		-makeQ()
		-enQ(Q, ITEM)
		-deQ(Q, FIRST)
		-emptyQ()
		-DELETEMAX(PQ)                   <-----
		-CHANGWEIGHT(PQ, ITEM)           <-----
		-DELETE(PQ, ITEM)				 <-----
		-REPLACE(PQ, ITEM)				 <-----

	IMPLEMENTATIONS
	===============
		Unsorted Array
			construct: O(n)
			get highest priority: O(n)

		Sorted Array
			construct: O(n^2) (search?  moving n items?) [assume not using any extra ds]
			get highest priority: O(1)
		
		Unsorted List:
			construct: O(n)
			get highest priority: O(n)

		Sorted List:
			construct: O(n^2) (as for n items, worst cases is to traverse
							the whole list (n) and put it at the end)
			get highest priority: O(1) [assuming tracking head and tail]

	BETTER IMPLEMENTATION
	=====================
	
	========
	THE HEAP 
	========
		- this is just a complete tree
			-every layer fully filled in
			-everything as far left as possible
		- NOT A BINARY SEARCH TREE
		- BST has no conditions, heap has conditions!
			--every child must be smaller than the parent node
				--how is this different from a bst?
			--does not matter which one is on the left or right

		- therefore root is always the largest in the set
		- we can represent a complete tree as an array!!!

	Binary Heaps - we study bin heaps, but ofcourse they need not be binary
	============


				X
		     /     \
		    T       O
		   / \     / \
		  G   S   M   N
		 / \ / \ / 
        A  E R A I  

    To represent this as heap as an array, we read across levels

    |$$$| X | T | O | G | S | M | N | A | E | R | A | I 
	  ^   
	index 0, keep "blank"
	
	The arithmetic is easier if we keep the index at 1.



	The children of a node at index i are nodes at 
		- 2i
		- 2i+1

	Because of the nature of binary trees, n/2 nodes are parents,
	and n/2 nodes are leaves.
	So first half of the array is all parents, last half is all leaves

	BECAUSE OF THE HEAP CONDITION
	=============================
	A[i] > A[2i] && A[i] > A[2i+1]
	As the parent node is always greater than both its children

	
	==================
	HEAP FUNCTIONALITY
	==================

	deletemax()
	===========
	-returns highest priority item
		-return root

	-FIX heap
		-put last item into root position
		-reduce size of PQ by one
		-fix heap condition for root (downheap())
			--when you are doing these by hand, represent the heap
			  as a tree, and do the swaps, it's easier than doing on
			  the array
	
	deletemax() on this heap
	-------------------------

	|$$|X  | T | O | G | S | M | N | A | E | R | A | I
	
	1. return X
	2. Put I in the root position, reduce size of pq by one
	
	|$$|I  | T | O | G | S | M | N | A | E | R | A ||||| I

	Now the heap is imbalanced, need to downheap() to FIX HEAP CONDITION
	*/

	char keys[] = "0XTOGSMNAERAI";
	int size = strlen(heap);


	/*
	DOWNHEAP
	========
	this downheap is called within the deletemax function

	algorithm
	---------

	1. the item is at root, first find it's largest child
	2. then check if the item is smaller than that child, if yes, swap positions
	3. repeat this process until we find that we have a node where the item
	   is larger than both children
	4. this is the location where item sits.
	*/


	//keys ; index of last item being downheaped ; size of array_indexes
	downheap(keys,size);

	//for an array of chars
	char deletemax(char[] PQ, int size){
		//tracks index of the largest child
		int j=0;

		//index of the item being downheaped, moving it forward has
		//already happened
		int i = 1;

		//value / priority of that last index
		char v = PQ[i]; 

		//only need to check the first n/2 elements, as rest are leaf!
		while (i < size/2){

			//child one, child two would just be j+1
			j = 2*i;

			//check if j is at end of PQ, and if current child is smaller than 
			//next child, aim is to set j to the HIGHEST child
			if(j<size && PQ[j]<PQ[j+1]) j++;

			//if the current item v is larger than the largest child, stop
			//checking if heap is OK (condition met)
			if(v>=PQ[j]) break;

			//if we are here, v < PQ[j], so we need to swap them
			PQ[i] = PQ[j];
			//after the swap, now we are considering the new index
			//of the item that we are downheaping, namely v, so k is now
			//j (largest child index)
			i=j;
		}

		//once broken, the i index is the right position
		PQ[i] = v;

		// return v;
	}

	/*
	DELETEMAX
	=========
	this is the main deletemax function, for PQ of integers

	algorithm
	---------
	1. first item saved in aux variable
	2. let first item in PQ be the last item, reduce size of PQ by one
	3. downheap the root item
	4. return the aux variable which has the root item saved to be returned

	*/

	int deletemax(int[] PQ, int n){
		int v = PQ[1];
		PQ[1] = PQ[n--]; 
		//return; ends the function
		downheap(PQ, size); //here we have fixed the heap

		//can return after the heap is fixed
		return(v);
	}


	/*

	INSERTING AN ITEM IN A ALREADY FORMED HEAP
	==========================================

	UPHEAP
	======
	-reverse of downheap
	-have to put the item at the end, as that is the only free spot at the start
	-then we find it's location by working UPWARDS this time
	-parent is just k/2
	
	*/

	void upheap(int *PQ, int k){
		int v;

		//index of item to be upheaped
		v=PQ[k];

		//set first item to large int for convenient arithmetic
		PQ[0] = INT_MAX;

		//while the parent node is less than the current node
		while(PQ[k/2]<=v){

			//child is now equal to the parent
			//note here that both child node, and parent node both
			//are equal to the parent node, so what even has stored the
			//value of the child node being upheaped? v!
			PQ[k] = PQ[k/2];

			//now we look at the parent location where we just performed
			//the swap
			k=k/2;
		}

		//once loop ends, we have the location k where PQ[k/2]>v,
		//or the parent value is larger than the upheaping value
		//therefore we have the correct location

		PQ[k] = v; 

	}



	/*
	COMPLEXITY
	==========
	UPHEAP - add new item in last place, work your way up
	O(logn)

	DOWNHEAP - move item to root, work way down
	O(logn)


PRIORITY QUEUES
===============
back to PQs, now we have a structure that gives us a maximum priority
element in O(log(n)) time!

algorithm
---------
	1. first item saved in aux variable
	2. let first item in PQ be the last item, reduce size of PQ by one
	3. downheap the root item
	4. return the aux variable which has the root item saved to be returned

1,2 is constant time
3   downheap is log(n)
4   constant time

THIS SUGGESTS A SORTING METHOD! - HEAPSORT
==========================================

1. construct heap
2. swap root with last item
3. decrease size of heap by 1
4. fix heap with downheap()
5. repeat till finished!

--remember the root item is always the highest priority, what priority
  do we care about? do smaller items have higher priority or do larger 
  ones? we decide in the implementation of our algo.

COMPLEXITY
==========
1. CONSTRUCT HEAP???? - we don't yet know
2. Succesfully move max to end, then fix with downheap
	=n items * deletemax()
	=n*O(logn)
	=O(nlogn)

if the 1. constuct heap is more expensive than mergesort, then this is a 
bad idea, as mergesort is nlogn in total!


CONSTRUCT HEAP
==============

Strategy 1 - one by one
-----------------------

insert items one by one into the array
upheap() as each item is inserted

O(logn) per uphead (per insert)
doing it for n items
O(nlogn) for the CONSTRUCTION of the heap before we even sort anything


So both construction and sorting takes O(nlogn) each
need O(nlogn) twice!


Strategy 2 - all at once
------------------------

insert items in an unsorted array
once all items are inserted, downheap for each subheap with roots from
A[n/2] to A[1] (as those are the only parent nodes! rest are leaves)

how dis work??????
==================
2.1.PQ.pdf

1. insert all items to unordered array - O(n)
2. once all items inserted, downheap() for half the items

   o.5nlogn - loose bound

   BUT
   ===
   the second lowest level (n/4 nodes) only needs 1 comparison,
   third lowest level (n/8 nodes) needs 2 comparisons;
   .
   .
   .
   only the root node (1 node) needs logn comparisons!

   n/2 leaves have 0 WORK FOR DOWNHEAP()!

   AT MOST
   -------
   ceil(n/2^(h+1)) nodes exist at height h
   when h=0, n/2 nodes (leaves)
   		h=1, n/4 nodes
   		h=floor(logn), 1 node

   Total cost is a converging geometric series
   Sum of (h=0 -> floor(logn)) ceil(n/2^(h+1))*O(h)
   converges to N!

   so this strategy to build heap is n!

   total cost to construct and sort is n + nlogn, O(nlogn) 



















