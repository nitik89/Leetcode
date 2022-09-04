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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>>ans;
            return ans;
        }
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second.second;
            int lv=q.front().second.first;
            mp[level][lv].insert(node->val);
            q.pop();
            if(node->right!=NULL){
                q.push({node->right,{lv+1,level+1}});
            }
            if(node->left!=NULL){
                q.push({node->left,{lv+1,level-1}});
            }
            
        }
        vector<vector<int>>ans;
        for(auto x:mp){
            vector<int>an;
            for(auto y:x.second){
                
                for(auto m:y.second){
                    an.push_back(m);
                }
            }
            ans.push_back(an);
            
        }
        
        
        return ans;
        
    }
};