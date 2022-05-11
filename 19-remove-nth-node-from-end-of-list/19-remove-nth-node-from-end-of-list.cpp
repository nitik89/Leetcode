/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
      while(n!=1)
      {
          fast=fast->next;
          n--;
      }
        ListNode* prev=NULL;
        while(fast->next!=NULL&&slow!=NULL){
            prev=slow;
            slow=slow->next;
            
            fast=fast->next;
        }
   if(prev==NULL){
       head=head->next;
   }
        else{
            
        
        prev->next=slow->next;
        slow->next=NULL;
        }
        return head;
    }
};