class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,currmax=0,reached=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i]>currmax){
                currmax=i+nums[i];
            }
            if(i==reached){
                reached=currmax;
                jump++;
            }
            
        }
        return jump;
    }
};