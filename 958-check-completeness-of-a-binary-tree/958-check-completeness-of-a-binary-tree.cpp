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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
         bool yes=false;
        while(!q.empty()){
           
            int x=q.size();
            while(x--){
                TreeNode* node=q.front();
               if(node->left==NULL){
                   yes=true;
               }
                else{
                    if(yes){
                        return false;
                    }
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    if(node->left==NULL){
                        return false;
                    }
                    q.push(node->right);
                }
                else{
                    yes=true;
                    
                }
               
                q.pop();
                
            }
        }
        return true;
    }
};