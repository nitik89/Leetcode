class Solution {
public:   
    int height(TreeNode* root){
        if(root == NULL)
            return 0; 
        int l=height(root->right);
        int r=height(root->left);
        return 1+max(l,r);
    }
    
    void helper(int &x,TreeNode * root, int curr,int &h){
        if(root==NULL) return;
            if(curr==h)
            {
                x+=root->val;
            }
            helper(x,root->right,curr+1,h);
            helper(x,root->left,curr+1,h);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        int x=0;
        helper(x,root,1,h);
        return x;
    }
};