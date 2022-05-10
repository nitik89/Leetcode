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
    int ans=0;
    pair<int,int> getAns(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int>lf=getAns(root->left);
        pair<int,int>rgt=getAns(root->right);
        int sum=lf.first+rgt.first+root->val;
        int cnt=lf.second+rgt.second+1;
        // cout<<sum<<" "<<cnt<<" "<<root->val<<"\n";
        int temp=cnt;
        if(cnt==0){
            temp=1;
        }
        int val=sum/temp;
        if(val==root->val){
            ans++;
        }
        return {sum,cnt};
        
    }
    int averageOfSubtree(TreeNode* root) {
        getAns(root);
        return ans;
    }
};