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
    TreeNode* getAns(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL&&root->right==NULL){
            if(root->val==1){
                return root;
            }
            else{
                return NULL;
            }
        }
        root->left=getAns(root->left);
        root->right=getAns(root->right);
        if(root->val==0&&root->left==NULL&&root->right==NULL){
            return NULL;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
       return getAns(root);
    }
};