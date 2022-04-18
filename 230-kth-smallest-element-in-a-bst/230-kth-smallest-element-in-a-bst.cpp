class Solution {
public:
    int m;
    int value;
    void getAns(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        getAns(root->left);
        m--;
        if(m==0){
            value=root->val;
            return;
        }
        
        getAns(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        m=k;
        getAns(root);
        return value;
    }
};