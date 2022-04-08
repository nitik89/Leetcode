class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>q;
        vector<vector<pair<long long,long long>>>mp(n);
        int mod=1e9+7;
        for(auto x:roads){
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        q.push({0,0});
        vector<long long>path(n,0);
        path[0]=1;
        vector<long long>cost(n,LONG_MAX);
        int count=0;
        while(!q.empty()){
            long long x=q.top().second;
            long long y=q.top().first;
            // cout<<x<<" ";
            q.pop();
            
            for(auto z:mp[x]){
                if(z.second+y<cost[z.first]){
                    cost[z.first]=z.second+y;
                    q.push({z.second+y,z.first});
                    path[z.first]=path[x]%mod;
                    path[z.first]=path[z.first]%mod;
                }
                else if(z.second+y==cost[z.first]){
                   path[z.first]=path[z.first]%mod+path[x]%mod;
                    path[z.first]=path[z.first]%mod;
                }
            }
        }
        return path[n-1];
        
    }
};