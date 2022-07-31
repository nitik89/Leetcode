class Solution {
public:
    vector<int>dp1;
   vector<int>d;
    void dfs1(int node,int pr,vector<int>&vis,vector<int>&grp,int dis,vector<int>&curr){
        if(vis[node]||node==-1){
            if(vis[node]){
            int a=0;
             for(int i=0;i<curr.size();i++){
                 if(curr[i]==node)
                 {
                     a=1;
                     break;
                 }
             }
            if(a){
             dp1[node]=max(dis-d[node],dp1[node]);
            }
             
            }
           return; 
        }
        // cout<<node<<" ";
        // curr[node]=1;
        vis[node]=1;
       
         curr.push_back(node);
        d[node]=dis;
        
        if(grp[node]!=-1){
            dfs1(grp[node],pr,vis,grp,dis+1,curr);
        
        }
    }
    int longestCycle(vector<int>& edges) {
                int n=edges.size();
        
        dp1.resize(n,-1);
        d.resize(n,0);
        int i=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>curr;
                // unordered_set<int>mp;
        dfs1(i,i,vis,edges,0,curr);
            }
        }
        int mx=-1;
        for(auto x:dp1){
            // cout<<x<<" ";
            mx=max(x,mx);
        }
        return mx;
    }
};