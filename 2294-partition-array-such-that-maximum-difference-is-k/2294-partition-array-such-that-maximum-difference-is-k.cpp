class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mn=INT_MAX,mx=INT_MIN;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                mn=nums[i];
                mx=nums[i];
                cnt++;
            }
            else{
                mx=max(nums[i],mx);
                mn=min(nums[i],mn);
                if(mx-mn>k){
                    cnt++;
                    mn=nums[i];
                mx=nums[i];
                }
                
            }
        }
        return cnt;
    }
};