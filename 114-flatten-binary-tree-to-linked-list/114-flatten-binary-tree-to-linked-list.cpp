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
         if(root!=NULL&&root->left==NULL&&root->right==NULL){
            return root;
        }
        if(root==NULL){
            return NULL;
        }
       
        TreeNode* lft=getAns(root->left);
        TreeNode* rgt=getAns(root->right);
        
       TreeNode* temp=root->left;
        
        if(root->left==NULL){
            return root;
        }
        while(temp!=NULL&&temp->right!=NULL){
            temp=temp->right;
        }
      
        
        temp->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode* root) {
      getAns(root);
    }
};