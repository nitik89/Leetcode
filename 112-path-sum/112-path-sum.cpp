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
    bool getAns(TreeNode* root,int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==sum+root->val){
                return true;
            }
            else{
                return false;
            }
        }
       
        bool left=getAns(root->left,targetSum,sum+root->val);
        bool right=getAns(root->right,targetSum,sum+root->val);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
       return getAns(root,targetSum,0);
    }
};