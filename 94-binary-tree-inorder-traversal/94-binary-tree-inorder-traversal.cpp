/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk;
        vector<int>ans;
        TreeNode* node=root;
        while(true){
            while(node!=NULL){
                stk.push(node);
                node=node->left;
            }
            if(stk.empty()){
                break;
            }
            if(!stk.empty()){
            node=stk.top();
            stk.pop();
            ans.push_back(node->val);
            node=node->right;
            }
            
        }
        return ans;
    }
};