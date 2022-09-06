class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        priority_queue<pair<int,int>>pq;
        int s=0,e=0;
        long long sum=0;
        int ans=0;
        int n=ct.size();
        while(e<n){
            sum+=rc[e];
            pq.push({ct[e],e});
            while(s<e&&((pq.top().first+(long long)(e-s+1)*sum)>budget)){
                sum-=rc[s];
                while(!pq.empty()&&pq.top().second<s){
                    pq.pop();
                }
                s++;
                
            }
            while(!pq.empty()&&pq.top().second<s){
                    pq.pop();
                }
            long long t=(pq.top().first+(e-s+1)*sum);
            if(t<=budget){
                ans=max(e-s+1,ans);
            }
            e++;
            
        }
        return ans;
    }
};