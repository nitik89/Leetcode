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
    unordered_map<int,int>mp;
    int i;
    TreeNode* getAns(vector<int>&preorder,int s,int e,int& idx){
        
        if(s>e){
            return NULL;
        }
        // cout<<i<<" ";
        
        TreeNode* root=new TreeNode(preorder[idx]);
        int curr=mp[preorder[i]];
        idx++;
       
        root->left=getAns(preorder,s,curr-1,idx);
        root->right=getAns(preorder,curr+1,e,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
         i=0;
        return getAns(preorder,0,preorder.size()-1,i);
    }
};