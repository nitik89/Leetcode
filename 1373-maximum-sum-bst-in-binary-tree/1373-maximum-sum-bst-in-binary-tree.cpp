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
class My{
    public:
    int mx,mn,sum,isBst,mxans;
    My(){
        mx=INT_MIN;
        mn=INT_MAX;
        sum=INT_MIN;
        isBst=true;
        mxans=INT_MIN;
    }
};
class Solution {
public:
    int as;
    My getAns(TreeNode* root){
        if(root==NULL){
            return  My();
        }
        My lf=getAns(root->left);
        My rgt=getAns(root->right);
        My ans;
        
        if(lf.isBst&&rgt.isBst&&root->val>lf.mx&&root->val<rgt.mn){
            // cout<<root->val<<" ";
            ans.sum=0;
            ans.mx=max(rgt.mx,max(root->val,lf.mx));
            ans.mn=min(rgt.mn,min(root->val,lf.mn));
            ans.sum+=root->val+(lf.sum==INT_MIN?0:lf.sum)+(rgt.sum==INT_MIN?0:rgt.sum);
            ans.mxans=max(ans.mxans,ans.sum);
            
        }
        else{
            ans.mxans=max(lf.mxans,rgt.mxans);
            ans.isBst=false;
        }
        as=max(as,ans.mxans);
        return ans;
    }
    int maxSumBST(TreeNode* root) {
                as=INT_MIN;

        getAns(root);
        return as<0?0:as;
    }
};














