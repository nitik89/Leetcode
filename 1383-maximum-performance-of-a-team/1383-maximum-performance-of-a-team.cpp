class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
       
        vector<pair<int,int>>vec;
        for(int i=0;i<speed.size();i++){
            vec.push_back({speed[i],eff[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long sum=0;
        long long ans=LONG_MIN;
        for(int i=0;i<vec.size();i++){
            sum+=vec[i].first;
                pq.push({vec[i].second,vec[i].first});
            if(pq.size()>k){
                sum-=pq.top().second;
                pq.pop();
            }
            if(pq.size()<=k){
                ans=max(sum*pq.top().first,ans);
            }
        }
        while(!pq.empty()){
            sum-=pq.top().second;
                pq.pop();
            ans=max(sum*pq.top().first,ans);
        }
        int mod=1e9+7;
        return ans%mod;
    }
};