class Solution {
public:
    int ans;
    void dfs( vector<vector<pair<int,int>>>&vec,int x,vector<int>&vis){
        if(vis[x]){
            return;
        }
        vis[x]=1;
        for(auto y:vec[x]){
            ans=min(ans,y.second);
            dfs(vec,y.first,vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>vec(n+1);
        for(auto x:roads){
            vec[x[0]].push_back({x[1],x[2]});
            vec[x[1]].push_back({x[0],x[2]});
        }
        ans=INT_MAX;
        vector<int>vis(n+1,0);
        dfs(vec,1,vis);
        return ans;
    }
};