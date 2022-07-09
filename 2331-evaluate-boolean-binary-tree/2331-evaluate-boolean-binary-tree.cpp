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
    bool getAns(TreeNode* root){
        if(root->left==NULL&&root->right==NULL){
            return root->val;
        }
        bool lf=getAns(root->left);
        bool rgt=getAns(root->right);
        if(root->val==3){
            return lf&rgt;
        }
        return lf|rgt;

    }
    bool evaluateTree(TreeNode* root) {
      return  getAns(root);
    }
};