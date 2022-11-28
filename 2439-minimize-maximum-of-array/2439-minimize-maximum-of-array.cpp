class Solution {
public:
    bool isPos(vector<int>&nums,int mid){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum> (long long) mid*(i+1)) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int e=*max_element(nums.begin(),nums.end());
        int s=0,ans=-1;
        while(s<=e){
            int mid=((e-s)/2)+s;
            if(isPos(nums,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};