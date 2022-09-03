class Solution {
public:
    int dfs(int i,unordered_map<int,vector<int>>&mp,vector<int>&vis){
        if(vis[i]){
            return 0;
        }
        // cout<<i<<" ";
        vis[i]=1;
        int cnt=0;
        for(auto x:mp[i]){
           cnt+=dfs(x,mp,vis);
        }
        return cnt+1;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>>mp;
        int n=bombs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    long double x1=bombs[i][0];
                    long double y1=bombs[i][1];
                    long double  r1=bombs[i][2];
                    long double  x2=bombs[j][0];
                    long double  y2=bombs[j][1];
                    long double  r2=bombs[j][2];
                    long double  dis=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
                    long double  d=sqrt(dis);

                    if(d<=r1){
                        mp[i].push_back(j);
                    }
                }
            }
        }
        // for(auto x:mp){
        //     cout<<x.first<<" ";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"y"<<" ";
        int cnt=1;
        for(int i=0;i<n;i++){
           vector<int>vis(n,0);
            cnt=max(cnt,dfs(i,mp,vis));
        }
        return cnt;
    }
};