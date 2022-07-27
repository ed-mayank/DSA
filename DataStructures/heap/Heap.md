# Heap  

* Heap is a complete binary tree.  
    `A complete binary tree is a tree which has two    nodes at all levels except last. At last level nodes should be filled from leftmost side.`

**Max Heap**  
A complete binary tree whose parent is always greater than its children.  

**Min Heap**  
A complete binary tree whose parent is less than its children.  

__Heap Property__  
If number of nodes are n then height of heap is always log(n) due to complete binary tree.  

* Heap is filled in array by its level order traversal.  
if i is index of node:  
Parent of node i = i/2  
left child = i*2  
right child = i*2 + 1  

__Insertion in Max Heap__  
Always insert the new element at the end of node and then compare it with its parent. If parent is less than new element then swap it with its parent. Do this again till you reach the root or no swap condition.  

__Extract max in Max Heap__  
To extract max element from max heap:  
since root is max element in max heap, swap max element (first index) with last element of array. Then to satisfy heap property, start from root and compare parent with both of its children. If max(lchild, rchild)>parent then swap(max(lchild,rchild),parent). Repeat this step till either you hit to the leaf or no swap condition.  


