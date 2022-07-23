class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long curr=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                curr++;
                ans+=curr;
            }
            else{
                curr=0;
            }
        }
        // ans+=curr;
        return ans;
    }
};