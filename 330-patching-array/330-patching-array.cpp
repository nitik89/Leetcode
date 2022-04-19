class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long i=0,sum=0,patch=0;
        while(sum<n){
            if(i<nums.size()&&sum+1>=nums[i]){
                sum+=nums[i];
                i++;
            }
            else{
                sum=sum+(sum+1);
                //like as we have su
                patch++;
            }
        }
        return patch;
    }
};