class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int a=INT_MAX,b=INT_MAX;
        for(int i=0;i<nums.size();i++){
           if(nums[i]>a&&nums[i]>b){
               return true;
           }
            else if(nums[i]<a){
                a=nums[i];
            }
            else if(nums[i]>a&&nums[i]<b){
                b=nums[i];
            }
        }
        return false;
    }
};