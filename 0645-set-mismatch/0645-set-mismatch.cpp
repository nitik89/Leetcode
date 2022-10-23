class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>st;
        int sum1=0;
        for(auto x:nums){
            st.insert(x);
            sum1+=x;
        }
        int n=nums.size();
        int s=(n*(n+1))/2;
        int sum=0;
        for(auto x:st){
            sum+=x;
        }
        // cout<<s<<" "<<sum1<<" "<<sum<<"\n";
        return {sum1-sum,s-sum};
        
    }
};