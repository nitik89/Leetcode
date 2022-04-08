class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n==0){
            return 0;
        }
        vector<vector<pair<int,int>>>mp(n+1);
        for(auto x:times){
            // cout<<x[0]<<" "<<x[1]<<"\n";
            mp[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int>time(n+1,INT_MAX);
         q.push({0,k});
        time[k]=0;
        
        while(!q.empty()){
            int x=q.top().first;
            int y=q.top().second;
            q.pop();
            // cout<<y<<" ";
          
            for(auto z:mp[y]){
                if(x+z.second<time[z.first]){
                    time[z.first]=x+z.second;
                 q.push({x+z.second,z.first});
            }
               
            }
        }
        int mx=INT_MIN;
       for(int i=0;i<n;i++){
           // cout<<time[i+1]<<" ";
           if(time[i+1]==INT_MAX){
               return -1;
           }
           else{
               mx=max(mx,time[i+1]);
           }
       }
        return mx;
    }
};