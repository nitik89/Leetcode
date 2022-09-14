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
   
    vector<int>vec;
    int getAns(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int count=0;
        vec[root->val]++;
        int lf=getAns(root->left);
        int rg=getAns(root->right);
           if(root->left==NULL&&root->right==NULL){
               int flag=0;
               for(auto x:vec){
                   if(x%2!=0){
                       flag++;
                   }
               }
               if(flag==0||flag==1){
                   count+=1;
               }
           }
        vec[root->val]--;
        return lf+rg+count;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vec.resize(10,0);
       return getAns(root);
        // return count;
    }
};