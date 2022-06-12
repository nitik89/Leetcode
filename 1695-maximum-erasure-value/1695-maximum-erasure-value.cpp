class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int start=0,sum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            while(mp[nums[i]]>1){
                mp[nums[start]]--;
                sum-=nums[start];
                start++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};