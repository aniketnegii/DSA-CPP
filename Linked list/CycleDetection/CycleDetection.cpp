 
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
SinglyLinkedListNode* s = head, * f = head;
   
    while(f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
        if(s == f) {
            return 1;
        }
    }
    return 0; 
 
}
