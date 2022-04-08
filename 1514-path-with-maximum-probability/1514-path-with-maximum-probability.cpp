class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>mp(n);
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,-1);
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        int ans=-1;
        while(!pq.empty()){
            
            double pro=pq.top().first;
            int val=pq.top().second;
            pq.pop();
            // cout<<val<<" ";
            if(val==end){
                return pro;
            }
            for(auto x:mp[val]){
                if(pro*x.second>prob[x.first]){
                    // cout<<pro*x.second<<" "<<prob[x.first]<<"\n";
                    prob[x.first]=pro*x.second;
                    pq.push({pro*x.second,x.first});
                }
            }
        }
        return 0;
    }
};