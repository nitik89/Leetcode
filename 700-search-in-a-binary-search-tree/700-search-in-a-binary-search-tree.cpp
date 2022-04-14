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
    TreeNode* getAns(TreeNode* root,int val){
        if(root==NULL){
            return NULL;
        }
        if(root->val>val){
            return getAns(root->left,val);
        }
        else if(root->val<val){
            return getAns(root->right,val);
        }
        else{
            return root;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
       return getAns(root,val);
    }
};