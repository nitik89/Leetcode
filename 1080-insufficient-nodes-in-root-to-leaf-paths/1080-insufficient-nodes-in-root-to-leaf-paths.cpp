/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    TreeNode* getAns(TreeNode* root,int limit,int sum){
        if(root==NULL){
            return NULL;
        }
        if(root->right==NULL&&root->left==NULL){
            return sum+root->val>=limit?root:NULL;
        }
        TreeNode* lf=getAns(root->left,limit,sum+root->val);
        TreeNode* rg=getAns(root->right,limit,sum+root->val);
        if(!lf&&!rg){
            return NULL;
        }
        else if(!lf){
            root->left=NULL;
        }
        else if(!rg){
            root->right=NULL;
        }
        return root;
        
    }
        TreeNode* sufficientSubset(TreeNode *root, int limit) {
            if(root==NULL){
                return NULL;
            }
            return getAns(root,limit,0);
        }
};