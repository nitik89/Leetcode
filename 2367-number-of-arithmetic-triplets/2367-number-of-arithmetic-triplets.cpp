class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt=0;
         
        for(int i=0;i<nums.size();i++){
           unordered_map<int,int>mp;
            for(int j=i+1;j<nums.size();j++){
               
                    int calc=nums[j]-nums[i];
                if(calc==diff){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[k]-nums[j]==diff){
                        cnt++;
                    }
                }
                }
                
            }
        }
        return cnt;
    }
};