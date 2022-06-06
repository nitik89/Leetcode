/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
            }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len=getLen(headA);
        int l=getLen(headB);
        if(len>l){
            while(len>l){
                headA=headA->next;
                len--;
            }
        }
        else if(len<l){
            while(len<l){
                headB=headB->next;
                l--;
            }
        }
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL&&temp2!=NULL&&temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1==temp2){
            return temp1;
        }
        return NULL;
    }
};