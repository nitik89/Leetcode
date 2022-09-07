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
    string getAns(TreeNode* root){
        if(root==NULL){
            return "";
        }
        string lf=getAns(root->left);
        string rgt=getAns(root->right);
        string ans=to_string(root->val);
        if((rgt!=""&&lf=="")||(lf!=""&&rgt=="")||(lf!=""&&rgt!="")){
            ans.push_back('(');
            ans+=(lf);
            ans.push_back(')');
        }
        
        if(rgt!=""){
            ans.push_back('(');
            ans+=(rgt);
            ans.push_back(')');
        }
        
        return ans;
    }
    string tree2str(TreeNode* root) {
       return getAns(root);
    }
};