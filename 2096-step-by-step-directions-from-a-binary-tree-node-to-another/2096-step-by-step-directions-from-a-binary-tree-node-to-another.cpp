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
    TreeNode* st;
    TreeNode* en;
    TreeNode* getAns(TreeNode* root,int s,int e){
        if(root==NULL){
            return NULL;
        }
            if(root->val==s){
                return root;
            }
            if(root->val==e){
                return root;
            }
            
      
        TreeNode* lft=getAns(root->left,s,e);
        TreeNode* rgt=getAns(root->right,s,e);
            
        if(lft&&rgt){
            return root;
        }
            if(lft){
                return lft;
            }
            return rgt;
      
    }
    
    string ans;
  bool getFromStart(TreeNode* st,int des){
        if(st==NULL){
            return false;
        }
        if(st->val==des){
            
            return true;
        }
      ans.push_back('L');
        if(getFromStart(st->left,des)){
            return true;
        }
            ans.pop_back();
            ans.push_back('R');
        if(getFromStart(st->right,des)){
            return true;
        }
            ans.pop_back();
      return false;
        
    }
    // string ans;
        bool getFromEnd(TreeNode* st,int des){
        if(st==NULL){
            return false;
        }
        if(st->val==des){
        
            return true;
        }
        ans.push_back('U');
        if(getFromEnd(st->left,des)){
            return true;
        }
            ans.pop_back();
            ans.push_back('U');
        if(getFromEnd(st->right,des)){
            return true;
        }
            ans.pop_back();
       return false;
        
    }
    string getDirections(TreeNode* root, int start, int dest) {
       TreeNode* node= getAns(root,start,dest);
        // cout<<node->val<<"\n";
        if(node->val!=start&&node->val!=dest){
           getFromEnd(node,start);
            getFromStart(node,dest);
        }
        else if(node->val==start){
            getFromStart(node,dest);
        }
        else{
            getFromEnd(node,start);
        }
        
        return ans;
    }
};
