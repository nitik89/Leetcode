class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        //brute force method
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int p=nums[i];
            for(int j=i;j<n;j++){
                if(p%k!=0)break;
                p=__gcd(p,nums[j]);
                if(p==k){
                 ans++;   
                }
            }
        }
        return ans;
    }
};