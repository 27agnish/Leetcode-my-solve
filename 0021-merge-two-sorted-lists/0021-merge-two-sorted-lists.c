/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *p1=list1, *p2=list2, *newNode, *temp=NULL, *result=NULL;
    while(p1!=NULL && p2!=NULL){
        newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(p1->val==p2->val){
            newNode->val=p1->val;
            p1=p1->next;
        }
        else if(p1->val<p2->val){
            newNode->val=p1->val;
            p1=p1->next;
        }
        else{
            newNode->val=p2->val;
            p2 =p2->next;
        }
        newNode->next=NULL;
        if(result==NULL){
            result=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    while(p1!=NULL){
        newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=p1->val;
        newNode->next=NULL;
        p1=p1->next;
        if(result==NULL){
            result=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    while(p2!=NULL){
        newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=p2->val;
        newNode->next=NULL;
        p2=p2->next;
        if(result==NULL){
            result=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    return result;
}