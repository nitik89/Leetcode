class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
      int prev=nums[0];
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=prev){
                cnt++;
            }
            else{
                prev=nums[i];
            }
        }
        prev=nums[nums.size()-1];
        int cnt1=0;
         for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=prev){
                cnt1++;
            }
            else{
                prev=nums[i];
            }
        }
        
        
        return cnt<=1 or cnt1<=1;
    }
};