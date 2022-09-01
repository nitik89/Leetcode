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

    int getAns(TreeNode* root,int val){
        
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        if(val<=root->val){
            cnt++;
        }
        if(root->val >val ){
            val=root->val;
        }
        return getAns(root->left,val)+getAns(root->right,val)+cnt;
        
    }
    int goodNodes(TreeNode* root) {
       return getAns(root,root->val);
        
    }
};