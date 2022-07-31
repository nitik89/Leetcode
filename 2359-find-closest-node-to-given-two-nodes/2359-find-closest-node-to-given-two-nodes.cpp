class Solution {
public:
    vector<int>dp1;
    vector<int>dp2;
    void dfs1(int node,vector<int>&vis,vector<vector<int>>&grp,int dis){
        if(vis[node]||node==-1){
           return; 
        }
        // cout<<node<<" ";
        vis[node]=1;
        dp1[node]=dis;
        for(auto x:grp[node]){
        if(x!=-1){
            dfs1(x,vis,grp,dis+1);
        }
        }
    }
    void dfs2(int node,vector<int>&vis,vector<vector<int>>&grp,int dis){
        if(vis[node]){
           return; 
        }
        vis[node]=1;
        dp2[node]=dis;
        for(auto x:grp[node]){
            if(x!=-1){
            dfs2(x,vis,grp,dis+1);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>grp(n);
        int i=0;
        for(auto x:edges){
            grp[i++].push_back(x);
        }
        
        dp1.resize(n,INT_MAX);
        dp2.resize(n,INT_MAX);
        vector<int>vis(n,0);
        vector<int>vis1(n,0);
        dfs1(node1,vis,grp,0);
        dfs2(node2,vis1,grp,0);
        int ans=INT_MAX;
        int node=-1;
        for(int i=0;i<n;i++){
              // cout<<dp1[i]<<" "<<dp2[i]<<"\n";
           

                   int mx=max(dp1[i],dp2[i]);
                 // cout<<mx<<" ";
                if(mx<ans){
                    ans=mx;
                    node=i;
                
                }
            
        }
        return node;
    }
};