class Solution {
public:
    //1 for curr red go for blue, -1 for curr blue now go for red
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        queue<pair<int,pair<char,int>>>q;
        vector<vector<int>>red(n);
        vector<vector<int>>blue(n);
        vector<int>vis1(n,0);
        vector<int>vis2(n,0);
        for(auto x:red_edges){
            red[x[0]].push_back(x[1]);
        }
        for(auto x:blue_edges){
            blue[x[0]].push_back(x[1]);
        }
        q.push({0,{'R',0}});
        q.push({0,{'B',0}});
        
        vector<int>ans(n,INT_MAX);
        ans[0]=0;
        while(!q.empty()){
            int node=q.front().first;
            char clr=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            
            if(clr=='R'){
                
                for(auto x:blue[node]){
                    
                  if(!vis1[x]){
                      vis1[x]=1;
                        ans[x]=min(ans[x],dis+1);
                        q.push({x,{'B',dis+1}});
                  }
                }
            }
            else if(clr=='B'){
                for(auto x:red[node]){
                    if(!vis2[x]){
                        vis2[x]=1;
                       ans[x]=min(ans[x],dis+1);
                        q.push({x,{'R',dis+1}});
                    }
                }
            }
            
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
        
        
    }
};