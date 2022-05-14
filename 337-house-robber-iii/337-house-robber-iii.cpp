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
     pair<int,int> getAns(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int>lf=getAns(root->left);
        pair<int,int>rgt=getAns(root->right);
        int inc=lf.second+rgt.second+root->val;
        int exc=max({lf.first+rgt.second,lf.second+rgt.first,lf.second+rgt.second,lf.first+rgt.first});
        return {inc,exc};
    }
    int rob(TreeNode* root) {
        pair<int,int>pr=getAns(root);
       return max(pr.first,pr.second);
    }
};