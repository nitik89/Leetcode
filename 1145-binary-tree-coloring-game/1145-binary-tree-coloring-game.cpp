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
    vector<int>dp;
    TreeNode* my;
    int getAns(TreeNode* root,int x){
        if(root==NULL){
            return 0;
        }
        int l=getAns(root->left,x);
        int r=getAns(root->right,x);
        dp[root->val-1]=l+r+1;
        if(x==root->val){
            my=root;
            return 0;
        }
        return l+r+1;
    }
    bool check(TreeNode* my,int v ){
        
        if(my==NULL){
            return false;
        }
        // cout<<my->val<<" "<<v<<"\n";
        if(my->val==v){
            // cout<<my->val<<" ";
            return true;
        }
        return check(my->left,v)||check(my->right,v);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dp.resize(n,0);
        getAns(root,x);
        int a=0,b=0,idx=-1;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<" ";
            if(x-1==i){
                a=dp[i];
            }
            else{
                if(dp[i]>b){
                    idx=i+1;
                    b=dp[i];
                }
            }
        }
        // cout<<idx<<" ";
        // cout<<my->val<<" "<<idx<<"\n";
        if(check(my,idx)){
            // cout<<"y";
            a=a-b+(root->val!=x?dp[root->val-1]:0);
        }
        return b>a;
    }
};