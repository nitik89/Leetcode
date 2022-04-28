class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                j=i;
                break;
            }
        }
       
        if(j==-1){
            j=nums.size();
        }
        
        int i=j-1;
        int n=j;
        vector<int>ans;
        while(i>=0&&j<nums.size()){
            if(abs(nums[i])>abs(nums[j])){
                ans.push_back(abs(nums[j]*nums[j]));
                j++;
            }
            else{
                ans.push_back(abs(nums[i]*nums[i]));
                i--;
            }
        }
        while(i>=0){
           ans.push_back(nums[i]*nums[i]);
            i--;
        }
         while(j<nums.size()){
           ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
      
        
    }
};