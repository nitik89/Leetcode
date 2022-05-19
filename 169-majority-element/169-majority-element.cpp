class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,can;
        for(auto x:nums){
            if(count==0){
                can=x;
                count++;
            }
            else if(x==can){
                count++;
            }
            else{
                count--;
            }
        }
        return can;
    }
};