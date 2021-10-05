// Complete the insertNodeAtTail function below.
 
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
 SinglyLinkedListNode *temp = head;
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
 
        if(head == NULL) {
            return newNode;
        }
 
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next  = newNode;
        newNode->next = NULL;
 
        return head;
 
 
 
}
 
