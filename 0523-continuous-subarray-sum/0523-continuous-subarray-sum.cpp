class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       if(nums.size()==1){
           return false;
       }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==0&&nums[i-1]==0){
                return true;
            }
            if(nums[i]!=0){
            sum+=nums[i];
            if(sum%k==0&&i>=1){
                 return true;
            }
            if(mp.find(sum%k)!=mp.end()&&i-mp[sum%k]-1!=0){
                 // cout<<"E "<<i;
                return true;
            }
            else{
                mp[sum%k]=i;
            }
            }
        }
        return false;
    }
};