class Solution {
public:
    vector<int>xr;
    vector<vector<int>>par;
    vector<int>vis;
    vector<int>vis2;
    vector<vector<int>>adj;
    int dfs(vector<int>&nums,int i,int p){
       int myxr=0;
        if(vis[i]){
            return 0;
        }
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]&&x!=p){
            myxr^=dfs(nums,x,i);
            }
        }
        myxr^=nums[i];
        xr[i]=myxr;
        return myxr;
    }
     void dfs2(int i,int p){
         int myxr=0;
        if(vis2[i]){
            return ;
        }
         if(p!=-1){
             // cout<<p<<" "
             for(int j=0;j<par[p].size();j++){
                 par[i][j]=par[p][j];
             }
             par[i][p]=1;
         }
         
        vis2[i]=1;
        for(auto x:adj[i]){
            if(!vis2[x]&&x!=p){
            dfs2(x,i);
            }
        }
        // if(p!=-1){
        //     par[i][p]=0;
        // }
     }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n=nums.size();
        xr.resize(n,0);
        par.resize(n,vector<int>(n,0));
        vis.resize(n,0);
        vis2.resize(n,0);
        adj.resize(n,vector<int>(n,0));
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        
        dfs(nums,0,-1);
        
        dfs2(0,-1);
        
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t1,t2,t3;
               if (par[j][i]) {
                    // i is the parent of j
                    t1 = xr[0] ^ xr[i];
                    
                    t2 = xr[j];
                    t3 = xr[0] ^ t1 ^ t2;
                   
                } else if (par[i][j]) {
                    // j is the parent of i
                    t1 = xr[i];
                    t2 = xr[0] ^ xr[j];
                    t3 = xr[0] ^ t1 ^ t2;
                } else {
                    t1 = xr[j];
                    t2 = xr[i];
                    t3 = xr[0] ^ t1 ^ t2;
                }
                
                ans=min(ans,max({t1,t2,t3})-min({t1,t2,t3}));
                
            }
        }
  
        return ans;
    }
};