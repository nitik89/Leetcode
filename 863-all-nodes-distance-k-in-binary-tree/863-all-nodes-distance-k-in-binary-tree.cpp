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
    void makePar(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left!=NULL){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=NULL){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    void findNodes(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp,vector<int>&collect,int dis,int k,unordered_map<TreeNode*,int>&vis){
        if(root==NULL){
            return;
        }
        if(vis.find(root)!=vis.end()){
            return;
        }
        if(dis==k){
            collect.push_back(root->val);
        }
        vis[root]=1;
        findNodes(root->left,mp,collect,dis+1,k,vis);
        findNodes(root->right,mp,collect,dis+1,k,vis);
        findNodes(mp[root],mp,collect,dis+1,k,vis);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        makePar(root,mp);
        vector<int>collect;
        // vector<int>vis;
        unordered_map<TreeNode*,int>vis;
        findNodes(target,mp,collect,0,k,vis);
        // cout<<mp[target]->val;
        return collect;
    }
};





