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
    vector<int> postorderTraversal(TreeNode* root) {
     stack<pair<TreeNode*,int>>stk;
        vector<int>ans;
        if(root==NULL){
            return {};
        }
        stk.push({root,0});
        while(!stk.empty()){
            auto pr=stk.top();
            stk.pop();
            if(pr.second==0){
               stk.push({pr.first,1});
                if(pr.first->left!=NULL){
                stk.push({pr.first->left,0});
                }
                
            }
           else if(pr.second==1){
                stk.push({pr.first,2});
               if(pr.first->right!=NULL){
                stk.push({pr.first->right,0});
               }
                
            }
            else{
                ans.push_back(pr.first->val);
                // stk.pop();
            }
        }
        return ans;
    }
};