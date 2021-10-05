#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	/*
	======
	GRAPHS
	======

	-complexity in terms of graphs - NOT N
			in terms V and E

	-complete graphs have v * (v-1)/2 edges
		-every vertex connected to every other vertex
		-not connected to itself, so we get the -1
		-connection a-b, and b-a are both counted, so 
		 essentially each connection is counted twice, 
		 therefore we get the *1/2

	-can represent graphs as 2d matrix, or with adjacency list
	-representations only show DIRECT LINKS, for indirect links
	 we need to use some algorithms

	-for unweighted graphs the matrix is just 1/0 values
	-for weighted its the weights

	-any algorithm that requires computation essentially just computes
		once, and values are stored in the matrix, lookups v fast

	-DEGREE of vertex - how many other vertices can we directly
		reach from this vertex
	-checking connection between A-B vertices is contant time in matrix
	-in adjacency list checking complexity is highest out degree in graph
		-in SPARSE graphs - small
		-in DENSE (like complete) - O(V-1) = O(V)

	=====
	EDGES -> E = V (sparse) / V^2 (dense)
	=====
	-sparse graph we can have approx V edges
	-dense graph edges approx V^2 (V*(V-1)/2)
	
	==========
	REPN SIZES
	==========
	-matrix - O(V^2) by design
	-adj list - O(V+E)

	When graph is sparse, adjacency list size is 2V approx
	as E is appox V

	When dense, E is approx V^2, so size approaches V^2 + V
	hence adjaceny lists are a bit worse in dense case
	
	=================================================
	          WE BEGIN WITH TREE TRAVERSAL
	=================================================

	=========
	TRAVERSAL
	=========
	-its hard uwu
		-possible cycles
		-not necessarily connected, can have some
			unconnected components
	-we have already covered RECURSIVE tree traversal, when we discussed
		-pre order
		-post order
		-in order 
		traversals.

	-QUICK REVISION OF PRE ORDER TRAVERSAL

*/
	return 0;
}

	void preorder(node* t){
		if(!t) return; //if t == NULL
		visit(t);
		preorder(t->left);
		preorder(t->right);
	}

	// LRV
	void postorder(node *t){
		if(!t) return; //if t == NULL
		postorder(t->left);
		postorder(t->right);
		visit(t);
	}

	// inorder - LVR
	void inorder(node *t){
		if(!t) return; //if t == NULL
		inorder(t->left);
		visit(t);
		inorder(t->right);
	}

/*	==========================
	BFS - BREADTH FIRST SEARCH
	==========================
		-expand along levels first, then head down slowly
		-pre order traverse with explicit queue structure

*/
	void preorder(queue_t* q, node_t* t){

		enQ(q, t); //insert root node
		while(!queueempty(q)){

			//Dequeue, visit the node first (preorder)
			t = deQ(q); visit(t);

			//same as if t->left!=null
			if(t->left)  enQ(st, t->left);
			if(t->right) enQ(st, t->right);
		}
	}

	//perform demonstration of this


/*
	==========================
	DFS - DEPTH FIRST SEARCH
	==========================
		-expand along the deepest nodes first
		-NON RECURSIVE PRE ORDER
		-pre order traverse with explicit stack structure

	*/

	void preorder(stack_t* st, node_t* t){

		push(st, t); //insert root node
		while(!stackempty(st)){

			//pop the stack, visit the node first (preorder)
			t = pop(st); visit(t);

			//same as if t->left!=null
			if(t->left)  push(st, t->left);
			if(t->right) push(st, t->right);
		}
	}

	//perform demonstration for this
