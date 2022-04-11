class Solution {
public:
    int mod=1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>>mp(n);
        for(auto x:edges){
            mp[x[0]-1].push_back({x[1]-1,x[2]});
            mp[x[1]-1].push_back({x[0]-1,x[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[n-1]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,n-1});
        while(!q.empty()){
            int node=q.top().second;
            int cost=q.top().first;
            q.pop();
            for(auto x:mp[node]){
                if(x.second+cost<dist[x.first]){
                    dist[x.first]=x.second+cost;
                    q.push({dist[x.first],x.first});
                }
            }
        }
        vector<int>mem(n,-1);
        return dfs(mp,n,dist,0,mem);
       
    }
    int dfs(vector<vector<pair<int,int>>>&mp,int n,vector<int>&dist,int curr,vector<int>&mem){
        if(curr==n-1){
            return 1;
        }
        if(mem[curr]!=-1){
            return mem[curr];
        }
        int ans=0;
        for(auto x:mp[curr]){
            if(dist[x.first]<dist[curr]){
             ans=(ans%mod+dfs(mp,n,dist,x.first,mem)%mod)%mod;
             
            }
        }
        return mem[curr]=ans%mod;
    }
};















