class Solution {
private:
    void recoverTreeUtil(TreeNode* root, TreeNode*& prevNode, TreeNode*& firstNode, TreeNode*& secondNode) {
        if(root == nullptr) {
            return;
        }
        
        recoverTreeUtil(root->left, prevNode, firstNode, secondNode);
        
        if((prevNode != nullptr) && (prevNode->val > root->val)) {
            if(firstNode == nullptr) {
                firstNode = prevNode;
                secondNode = root;
            }
            else {
                secondNode = root;
            }
        }
        
        prevNode = root;
        
        recoverTreeUtil(root->right, prevNode, firstNode, secondNode);
    }
    
public:
    void recoverTree(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        
        TreeNode* prevNode = nullptr;
        TreeNode* firstNode = nullptr;
        TreeNode* secondNode = nullptr;
        
        recoverTreeUtil(root, prevNode, firstNode, secondNode);
        
        if((firstNode != nullptr) && (secondNode != nullptr)) {
            cout<<"\nHere";
            int temp = firstNode->val;
            
            firstNode->val = secondNode->val;
            secondNode->val = temp;
        }
    }
};