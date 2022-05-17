/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans=NULL;
    void getAns( TreeNode* cloned, TreeNode* target){
        if(cloned==NULL){
            return;
        }
        if(cloned->val==target->val){
            ans=cloned;
            return;
        }
        getAns(cloned->left,target);
        getAns(cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        getAns(cloned,target);
        return ans;
    }
};