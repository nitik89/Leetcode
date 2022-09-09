typedef long long ll;
class Solution {
public:
    
    long long kSum(vector<int>& nums, int k) {
        priority_queue<pair<ll,ll>>pq;
        ll sum=0;
        for(auto &x:nums){
            if(x>0){
            sum+=x;    
            }
            else{
                x*=-1;
            }
            
        }
        if(k==1){
            return sum;
        }
        k--;
        sort(nums.begin(),nums.end());
        pq.push({sum-nums[0],0});
        while(!pq.empty()){
            auto x=pq.top();
            ll i=x.second;
            sum=x.first;
           // cout<<sum<<" "<<k<<"\n";
            pq.pop();
            if(k==1){
                return sum; 
            }
            if(i+1<nums.size()){
                pq.push({sum-nums[i+1]+nums[i],i+1});
                pq.push({sum-nums[i+1],i+1});
            }
            k--;
            
        }
        return 0;
    }
};





