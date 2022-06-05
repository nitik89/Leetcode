class Solution {
public:
    int minMaxGame(vector<int>& nums) {
       
        while(nums.size()!=1){
             vector<int>temp;
        for(int i=0;i<nums.size()/2;i++){
            if(i%2==0){
               int val=min(nums[2 * i], nums[2 * i + 1]); 
                temp.push_back(val);
            }
            else{
               int val=max(nums[2 * i], nums[2 * i + 1]);
                 temp.push_back(val);
            }
            
        }
            nums=temp;
        }
        if(nums.size()>1){
        return min(nums[0],nums[1]);
        }
        else{
            return nums[0];
        }
    }
};