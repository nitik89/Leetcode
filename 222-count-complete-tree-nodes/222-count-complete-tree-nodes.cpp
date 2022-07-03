class Solution {
public:
    int count=0;
     int getHeightR(TreeNode* root){
        int cnt=0;
        while(root!=NULL){
            cnt++;
            root=root->right;
        }
        return cnt;
    }
    int getHeightL(TreeNode* root){
        int cnt=0;
        while(root!=NULL){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int getAns(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=getHeightL(root);
        int rg=getHeightR(root);
        if(lh==rg){
            return pow(2,lh)-1;
        }
        int lt=getAns(root->left);
        int rt=getAns(root->right);
        return lt+rt+1;
    }
    int countNodes(TreeNode* root) {
        return getAns(root);
    }
};