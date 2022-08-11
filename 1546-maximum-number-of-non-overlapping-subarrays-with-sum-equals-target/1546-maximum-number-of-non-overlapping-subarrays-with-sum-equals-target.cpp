class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
        sum+=nums[i];
            if(mp.count(sum-target)){
                cnt++;
                sum=0;
                mp.clear();
                mp[0]=1;
            }
            else{
                mp[sum]++;
            }
        }
        return cnt;
    }
};