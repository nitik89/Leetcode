class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long curr=1;
        long long ans=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i]==prices[i-1]-1){
                curr++;
                ans+=curr;
            }
            else{
                curr=1;
                ans++;
            }
        }
        return ans;
    }
};