class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto x:operations){
            int idx=mp[x[0]];
            int val=x[1];
            nums[idx]=val;
            mp[val]=idx;
        }
        return nums;
    }
};