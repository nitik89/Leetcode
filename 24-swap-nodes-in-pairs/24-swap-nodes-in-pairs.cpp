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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* t=head;
        ListNode* p=head->next;
        ListNode* ans=p;
        ListNode* last=NULL;
        while(t!=NULL&&p!=NULL){
            ListNode* save=p->next;
            p->next=t;
            t->next=(save!=NULL)?save->next:NULL;
            last=t;
            t=save;
            p=(save!=NULL)?save->next:NULL;
        }
        if(t!=NULL){
            last->next=t;
        }
        
        
        return ans;
    }
};