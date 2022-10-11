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
            set<int> st;
            for (auto x: nums)
            {
                st.insert(x);
            }
            ListNode *temp = head;
            int ans = 0;
            while (temp != NULL)
            {
                if ((temp->next==NULL&&st.find(temp->val) != st.end())||(temp->next != NULL && st.find(temp->val) != st.end()
                    &&st.find(temp->next->val) == st.end()))
                {
                    ans++;
                }
                temp = temp->next;
            }

            return ans ;
        }
};