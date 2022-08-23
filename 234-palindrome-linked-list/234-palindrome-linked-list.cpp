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
    ListNode* reverse(ListNode* temp){
       
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* save=temp->next;
            temp->next=prev;
            prev=temp;
            temp=save;
            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* mid=head;
        int len=0;
        ListNode* temp=head;
        
        while(fast!=NULL&&fast->next!=NULL&&slow!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        mid=slow;
        ListNode* t=mid->next;
          
        ListNode* head2=reverse(mid);
        
        // cout<<head->val<<" ";
        while(head2!=NULL&&head!=NULL){
            if(head2->val!=head->val){
                return false;
            }
            
            head2=head2->next;
            head=head->next;
        }
        return true;
        
        
       
        
    }
};