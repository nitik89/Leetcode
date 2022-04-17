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
    TreeNode* myroot=NULL,*saveroot;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(myroot==NULL){
            myroot=new TreeNode(root->val);
            // cout<<myroot;
            saveroot=myroot;
        }
        else{
            myroot->right=new TreeNode(root->val);
            myroot->left=NULL;
            myroot=myroot->right;
        }
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return saveroot;
    }
};