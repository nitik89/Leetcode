/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int numComponents(ListNode *head, vector<int> &nums)
        {
            unordered_map<int, ListNode*> mp;
            ListNode *temp = head;
            for (auto x: nums)
            {
                mp[x] = NULL;
            }
            while (temp != NULL)
            {

                if (mp.count(temp->val))
                {

                    mp[temp->val] = temp;
                }
                temp = temp->next;
            }
            for (auto x: nums)
            {
                
                ListNode *t = mp[x];

                while (t != NULL && t->next != NULL && mp.find(t->next->val) != mp.end())
                {
                   

                    t = t->next;
                    mp[t->val] = NULL;
                }
            }
            int ans = 0;
            for (auto x: mp)
            {
                if (x.second != NULL)
                {
                    ans++;
                }
            }

            return ans;
        }
};