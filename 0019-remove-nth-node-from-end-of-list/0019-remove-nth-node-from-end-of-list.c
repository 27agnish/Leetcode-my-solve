/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp=head;
    struct ListNode *delNode=NULL;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    for(int i=1;i<count-n;i++){
        temp=temp->next;
    }
    if(count==n){
        delNode=head;
        head=head->next;
        free(delNode);
        return head;
    }
    delNode=temp->next;
    temp->next=delNode->next;
    free(delNode);
    return head;
}