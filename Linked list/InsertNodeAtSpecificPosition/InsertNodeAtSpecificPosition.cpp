
/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */
 
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
SinglyLinkedListNode* temp1=llist;
SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
 int i=1;
        if(llist == NULL) {
            return newNode;
        }
  while(temp1->next != NULL && i<position) {
            temp1 = temp1->next;
            i++;
        }
        newNode->next=temp1->next;
        temp1->next  = newNode;
         
         return llist; 
}
