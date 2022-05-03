class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX,end=-1,start=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            if(mx>nums[i]){
                end=i;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            mn=min(mn,nums[i]);
            if(mn<nums[i]){
                start=i;
            }
        }
        return end-start+1;
    }
};