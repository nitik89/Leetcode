class Solution {
public:
    int maxSumRangeQuery(vector<int>& vec, vector<vector<int>>& req) {
        int n=vec.size();
      
        int t=n;
        int mod=1e9+7;
        //line sweep
        vector<int>cnt(n+1,0);
        for(int i=0;i<req.size();i++){
            cnt[req[i][0]]++;
            cnt[req[i][1]+1]--;
        }
        vector<int>temp(n+1,0);
        for(int i=1;i<=n;i++){
            cnt[i]=(cnt[i]%mod+cnt[i-1]%mod)%mod;
            cnt[i]=cnt[i]%mod;
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            // cout<<cnt[i]<<" ";
            pq.push({cnt[i],i});
        }
        t=n-1;
        while(!pq.empty()){
            temp[pq.top().second]=vec[t];
            t--;
            pq.pop();
        }
        // for(auto x:temp){
        //     cout<<x<<" ";
        // }
        int sum=0;
        for(int i=1;i<n;i++){
            temp[i]=(temp[i]%mod+temp[i-1]%mod)%mod;
        }
        
        for(int i=0;i<req.size();i++){
            int l=req[i][0];
            int r=req[i][1];
            sum=sum%mod+temp[r]-(l-1>=0?temp[l-1]:0);
            
        }
        return sum%mod;
        
    }
};