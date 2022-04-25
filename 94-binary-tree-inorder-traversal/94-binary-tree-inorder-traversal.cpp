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
    TreeNode* getRightNode(TreeNode* curr,TreeNode* temp){
        TreeNode* t=curr;
        while(t->right!=NULL&&t->right!=temp){
            t=t->right;
        }
        return t;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            TreeNode* temp=curr->left;
            if(temp==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*rn=getRightNode(temp,curr);
                if(rn->right==NULL){
                   rn->right=curr;
                    curr=curr->left;
                }
                else{
                    rn->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            
        }
        return ans;
    }
};