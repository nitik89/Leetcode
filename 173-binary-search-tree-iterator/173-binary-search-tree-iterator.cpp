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
class BSTIterator {
public:
    vector<int>inorder;
    int i=0;
    void getAns(TreeNode* root){
        if(root==NULL){
            return;
        }
        getAns(root->left);
        inorder.push_back(root->val);
        getAns(root->right);
    }
    BSTIterator(TreeNode* root) {
        getAns(root);
    }
    
    int next() {
        if(i<inorder.size()){
      return inorder[i++];
        }
        return -1;
    }
    
    bool hasNext() {
        if(i!=inorder.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */