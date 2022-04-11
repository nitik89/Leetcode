class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<int>mx(n,0);
        vector<vector<int>>mp(n);
        vector<int>indeg(n,0);
        for(auto x:rel){
            mp[x[0]-1].push_back(x[1]-1);
            indeg[x[1]-1]++;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push({i,time[i]});
                mx[i]=time[i];
            }
        }
        int ans=0;
        while(!q.empty()){
            int x=q.front().first;
            int t=q.front().second;
            // cout<<x+1<<" "<<t<<"\n";
            ans=max(t,ans);
            q.pop();
            for(auto y:mp[x]){
                indeg[y]--;
                mx[y]=max(mx[y],t);
                if(indeg[y]==0){
                    // cout<<time[y]+mx[y]<<"\n";
                    q.push({y,time[y]+mx[y]});
                }
            }
            
        }
        // for(auto x:mx){
        //     cout<<x<<" ";
        // }
        return ans;
    
    }
};