#include <stdio.h>
#include <stdlib.h>

//BST STRUCT
typedef struct bst_node{
	int data;
	struct bst_node* left;
	struct bst_node* right;
}node;

//FUNCTION DECLARATIONS
void insert_node(int data, node* head);
void traverse_bst(node* head);
void visit(node* n);
void free_bst(node* head);

//MAIN function
int main(int argc, char* argv[]){

	/*
	===================
	Binary Search Trees
	===================

	Think linked lists, but point left and right both
	structure is like this:
						x
					   / \
					  y   z
					 / \ / \
					a  b c  d
	
	COMPLETE TREE - nodes filled at every level,
	except the last, and all nodes as far left as possible

	the height of such a tree is approx log(n)
	insertion
	search
	lookup
		are all log(n) operations, this a very favourable DS
		IF the tree is well balanced

	if the tree is poorly balanced, this degrades to a worse
	case of stick - ll, all operations now become O(n)

	Look at the two complexities on a graph
	
	*/				

	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->left = NULL;
	head->right = NULL;

	insert_node(2, head);
	insert_node(3, head);
	insert_node(-3, head);
	insert_node(-2, head);
	insert_node(-4, head);

	// printf("%d\n", (head->left)->data);


	traverse_bst(head);
	free_bst(head);

	return 0;
}

void free_bst(node* head){
	/* 
	POST ORDER traversal
	Traverses and frees all nodes of bst
	I will use the recursive approach here
	*/
	if(head->left!=NULL)  free_bst(head->left);
	if(head->right!=NULL) free_bst(head->right);
	free(head);
}

void traverse_bst(node* head){
	/* 
	IN ORDER traversal
	Traverses and prints all nodes of bst
	I will use the recursive approach here   ***********DISCUSS ALL 3 TRAVERSALS
	*/
	if(head->left!=NULL) traverse_bst(head->left);
	visit(head);
	if(head->right!=NULL) traverse_bst(head->right);

}

void visit(node* n){
	//helper function, here visiting can mean ANYTHING
	printf("\n%d", n->data);
}

void insert_recursive(int data, node* head){
	//in main i already made a starting node

	if(data < head->data){
		//data should go to left subtree

		//if there is a left subtree
		if(head->left){
			insert_recursive(int data, head->left);
		} else {
			head->left = (node*)malloc(sizeof(node));
			head = head->left;
			head->data = data;
			head->left = NULL;
			head->right= NULL;
		}
	} else if (data > head->data) {
		//data should go to right subtree

		//if there is a right subtree
		if(head->right){
			insert_recursive(int data, head->right);
		} else {
			head->right = (node*)malloc(sizeof(node));
			head = head->right;
			head->data = data;
			head->left = NULL;
			head->right= NULL;
		}
	}
}

void insert_node(int data, node* head){
	/*
	This function traverses BST, finds appropriate insert
	spot, creates new node, and inserts given data into bst
	*/

	//keep traversing bst till we find where to insert
	while(head){
		if(data>head->data){
			if(head->right){
				head=head->right;
			}
			else{
				//create node, insert data
				head->right = (node*)malloc(sizeof(node));
				head = head->right;
				head->data = data;
				head->right = NULL;
				head->left = NULL;
				break;
			}

		}else if(data<head->data){

			if (head->left){
				head=head->left;
			}
			else {
				head->left = (node*)malloc(sizeof(node));
				head = head->left;
				head->data = data;
				head->right = NULL;
				head->left = NULL;
				break;
			}
		}
	}

	
}



/*
==========
AVL trees
==========

- so binary trees are endlessly flexible
- their overhead is accepted cost
- but worst case is O(n), might as well use an unsorted array
  at this point, or a linked list

- so during insertion we can make sure that a tree stays balanced
	right when we insert, we check if balanced, if not, perform
	something called rotations

7.1 AVL trees.png
=================
these are binary trees which are pretty bad, the whole point
is to keep the trees complete and balanced
only then are we able to get log(n) complexity, HOWEVER
as we get more and more unabalnced, we end up as a stick (worst case)
degrading our complexity to a linked list! a stick!

so let's take a look at some of these cases in the image.

- pay close attention to the type of imbalance there is
- this is a key exam question, they will ask you to do this
  by hand
- learn how to calculate depth, and learn how to identify which
  way the imabalance goes

show youtube video of avl balance animation

refer to 7.2, 7.3, draw out the tree and show imabalances

the rotations ->
7.4
7.5
7.6
7.7


and there's a few other trees like 2-3-4, red black, splay trees
you can learn that yourself, once you understand binary and avl you are
golden

*/