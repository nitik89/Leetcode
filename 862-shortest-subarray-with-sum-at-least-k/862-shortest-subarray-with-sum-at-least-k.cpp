class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        long long i=0,n=nums.size(),sum=0,mn=INT_MAX;
        while(i<n){
            sum+=nums[i];
            if(sum>=k){
                mn=min(i+1,mn);
            }
            long long tm=sum;
            
            while(!pq.empty()&&tm-pq.top().first>=k){
                pair<long long,long long>pr=pq.top();
                pq.pop();
                long long j=pr.second;
                mn=min(i-j,mn);
            }
            pq.push({sum,i});
            
            i++;
        }
        return mn==INT_MAX?-1:mn;
        
    }
};