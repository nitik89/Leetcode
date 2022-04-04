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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
           return head;
        }
        if(head->next->next==NULL){
             int t=head->val;
        head->val=head->next->val;
        head->next->val=t;
            return head;
        }
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(k!=1){
            fast=fast->next;
           
            k--;
        }
        temp=fast;
        while(slow!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        // cout<<temp->val<<" "<<slow->val<<" ";
        int t=temp->val;
        temp->val=slow->val;
        slow->val=t;
        
        return head;
        
    }
};