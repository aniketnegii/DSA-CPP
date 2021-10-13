## Hackerrank problem: Cycle Detection


```
A linked list is said to contain a cycle if any node is visited more than once while traversing the list. 
Given a pointer to the head of a linked list, determine if it contains a cycle.
If it does, return 1 Otherwise, return 0.
```
## Example
```
head refers to the list of nodes 1->2->3->NULL

The numbers shown are the node numbers, not their data values. There is no cycle in this list so return 0.

head refers to the list of nodes 1->2->3->1->NULL

There is a cycle where node 3 points back to node 1, so return 1.

##EXPLANATION

We are declaring two node type pointer . One pointer will  traverse nodes one by one whereas the other pointer will traverse two nodes at a time . So at sometime if the two pointers are at same node , it means there's a cycle in the linked list . 
```
## Constraints

* 0<=list size<=1000
