class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
       
        
        long long ans=0;
        // int n=nums.size();
        for(int i=0;i<nums.size();i++){
            long long gc=__gcd(nums[i],k);
          
            for(auto x:mp){
                if(gc%x.first==0){
                    ans+=x.second;
                }
            }
              mp[k/gc]++;
        }
        return ans;
    }
};