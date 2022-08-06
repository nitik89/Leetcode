class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            long long v=i-nums[i];
            if(mp.count(v)){
                cnt+=mp[v];
            }
            mp[v]++;
        }
        long long n=nums.size();
        long long ans=(n*(n-1))/2-cnt;
        return ans;
    }
};