class Solution {
public:
    int count=0;
    int getAns(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        
        int lft=getAns(root->left);
        int rgt=getAns(root->right);
        // cout<<lft<<" "<<rgt<<"\n";
        
        if(rgt==0||lft==0){
            count++;
            return 1;
        }
        else if(lft==1||rgt==1){
            return -1;
        }
        else{
            return 0;
        }
        
        
        
       
       
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(getAns(root)==0){
            count++;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        return count;
    }
};