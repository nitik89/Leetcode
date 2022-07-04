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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* node=root;
        vector<int>ans;
        while(node!=NULL){
            if(node->left==NULL){
                ans.push_back(node->val);
                node=node->right;
            }
            else{
                TreeNode* temp=node->left;
                while(temp->right!=NULL && temp->right!=node){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=node;
                    ans.push_back(node->val);
                    node=node->left;
                }
                else{
                    temp->right=NULL;
                    node=node->right;
                }
            }
        }
        return ans;
    }
};