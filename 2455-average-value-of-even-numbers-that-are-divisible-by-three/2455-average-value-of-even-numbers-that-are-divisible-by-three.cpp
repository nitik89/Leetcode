class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt=0;
        int sum=0;
        for(auto x:nums){
            if(x%2==0&&x%3==0){
                cnt++;
                sum+=x;
            }
        }
        if(cnt==0){
            return 0;
        }
        return sum/cnt;
    }
};