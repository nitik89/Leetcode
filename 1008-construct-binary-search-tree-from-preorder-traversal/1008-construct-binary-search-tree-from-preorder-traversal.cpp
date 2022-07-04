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
    int idx;
    TreeNode* helper(vector<int>&preorder,int lr,int rr){
        if(idx>=preorder.size()||lr>preorder[idx]||rr<preorder[idx]){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[idx]);
        idx++;
        root->left=helper(preorder,lr,root->val);
        root->right=helper(preorder,root->val,rr);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx=0;
        return helper(preorder,INT_MIN,INT_MAX);
    }
};