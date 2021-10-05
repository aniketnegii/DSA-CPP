## HackerRank Problem: Insert a node at a specific position in a linked list
```
Given the pointer to the head node of a linked list and an integer to insert at a certain position, create 
a new node with the given integer as its data attribute, insert this node at the desired position and return 
the head node.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. 
The head pointer given may be null meaning that the initial list is empty.
```
### Example
```
head refers to the first node in the list 1->2->3->NULL
data=4
position=2

Insert a node at 2nd position with data 4. 
List become:  1->2->4->3->NULL

```
### Constraints

* 1<=n<=1000
* 1<=list[i].data.data<=1000 where list[i] is the ith element of the linked list.

### Sample Input
```
3
16
13
7
1
2
```
### Sample Output
```
16 13 1 7
```
