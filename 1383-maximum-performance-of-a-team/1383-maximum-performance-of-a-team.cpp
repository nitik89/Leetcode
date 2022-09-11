class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
       
        vector<pair<int,int>>vec;
        for(int i=0;i<speed.size();i++){
            vec.push_back({eff[i],speed[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long ans=LONG_MIN;
        
        for(int i=0;i<n;i++){
            
           
            if(pq.size()==k){
                sum-=pq.top();
               pq.pop(); 
            }
            pq.push(vec[i].second);
            sum+=vec[i].second;
            ans=max(ans,sum*vec[i].first);
            
        }
        int mod=1e9+7;
        return ans%mod;
    }
};