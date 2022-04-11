class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<vector<int>>mp(100000);
    int yes=1;
        for(int i=0;i<routes.size();i++){
            for(auto x:routes[i]){
                mp[x].push_back(i);
                if(x==target){
                    yes=0;
                }
            }
        }
        if(yes){
            return -1;
        }
        
        queue<pair<int,int>>q;
        q.push({source,0});
        unordered_set<int>seen;
        // seen.insert(0);
        int ans=-1;
        while(!q.empty()){
            int node=q.front().first;
            int x=q.front().second;
            q.pop();
            if(node==target){
                return x;
            }
            for(auto y:mp[node]){
                for(auto m:routes[y]){
                    if(seen.find(m)==seen.end()){
                        seen.insert(m);
                        q.push({m,x+1});
                    }
                }
                routes[y].clear();
            }
            
        }
        return -1;
    }
};