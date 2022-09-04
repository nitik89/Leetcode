class Solution {
public:
    bool valid(vector<int>&vec){
        for(auto x:vec){
            if(x>1){
                return false;
            }
            
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int s=0,e=0;
        int ans=nums[0];
        vector<int>vec(32,0);
         
        int len=1;
        while(e<nums.size()){
        for (int i = 31; i >= 0; i--) {
        int k = nums[e] >> i;
        if (k & 1)
            vec[i]++;
         }
            while(s<=e&&!valid(vec)){
                for (int i = 31; i >= 0; i--) {
                    int k = nums[s] >> i;
                    if (k & 1)
                        vec[i]--;
                }
                s++;
            }
            len=max(e-s+1,len);
            e++;
        }
        
        return len;
    }
};