class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int op=0;
        while(true){
            int val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                val=nums[i];
            }
        }
            if(val==0){
                return op;
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    nums[i]=nums[i]-val;
                }
            }
            op++;
            sort(nums.begin(),nums.end());
    }
        return op;
    }
};