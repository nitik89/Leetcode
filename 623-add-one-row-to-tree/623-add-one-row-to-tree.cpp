class Solution {
public:
    void solve(TreeNode * root,int val,int dep)
    {    if(root==NULL) return;
        if(dep==1)
        {
            TreeNode* head=new TreeNode(val);
            head->left=root->left;
            root->left=head;
            TreeNode * jo=new TreeNode(val);
            jo->right=root->right;
            root->right=jo;
            return ;
        }
        else{
            solve(root->left,val,dep-1);
            solve(root->right,val,dep-1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* head=new TreeNode(val);
            head->left=root;
            return head;
        }
        depth-=1;
        solve(root,val,depth);
        return root;
    }
};