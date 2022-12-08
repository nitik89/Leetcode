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
    void getAns(TreeNode* root,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            res.push_back(root->val);
        }
        getAns(root->left,res);
        getAns(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>lf,rg;
        getAns(root1,lf);
        getAns(root2,rg);
        
        return lf==rg;
    }
};










