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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t=head;
        int len=0;
        while(t!=NULL){
            len++;
            t=t->next;
        }
      ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* preHead=head;
        ListNode* ans=NULL;
        ListNode* save=NULL;
        int i=0;
        while(len>=k){
            // cout<<preHead->val<<" ";
            // cout<<temp->val<<" ";
            ListNode* sv=temp;
            for(int i=0;i<k;i++){
                ListNode* save=temp->next;
                temp->next=prev;
                prev=temp;
                temp=save;
            }
            if(ans==NULL){
                ans=prev;
                preHead=sv;
                
            }
            else{
                // cout<<sv->val<<" ";
                if(preHead!=NULL){
                preHead->next=prev;
                }
                preHead=sv;
                
                // cout<<"h";
            }
            save=sv;
           prev=NULL;
            
            len-=k;
            
        }
        if(save!=NULL){
        save->next=temp;
        }
        // prev->next=temp;
        return ans;
    }
};