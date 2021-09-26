/*
Let's see if we can figure out the complexities of the following:

Concrete implementations:
Unsorted Arrays
search		: n
insertion	: 1, n -> have to realloc
build		: n

Sorted Arrays
search		: log n 
insertion	: logn + n => n
build		: n(log n + n) => nlogn + n^2 => n^2

Unsorted Linked List
search		: n
insertion	: 1
build		: n*1 = n

Sorted Linked list
search		: n
insertion	: n + k
build		: n*(n+n+k) => n^2

Best case Binary Tree - balanced case
search		: log n
insertion	: log n + 1 = log n
build		: n * log n

Worst case Binary Tree -> 
search		: n
insertion	: n
build		: n*(n + 1) => n^2

AVL tree
search		: logn -> 1.44logn 
insertion	: logn
build		: nlogn

=======================
Abstracts DS:

Stack
implementation? -> LIFO, linked list
search		: -> no, the point is to get the first item / last inserted
insertion	: -> O(1)
build		: -> O(n)
pop         : -> O(1)

Queue
implementation? -> FIFO, linked list
search		: -> no, point is to get the first inserted element
insertion	: -> depends on implementation, O(1)
build		: -> O(1)*n = O(n)
pop         : -> O(1)

Dictionary
implementation?
search		:
insertion	:
build		:

PriorityQ
implementation?
search		:
insertion	:
build		:


*/